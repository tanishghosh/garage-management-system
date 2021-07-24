    ///////////////////********* ONLINE GARAGE **********\\\\\\\\\\\\\\\\


  #include<conio.h>
  #include<string.h>
  #include<fstream.h>
  #include<stdio.h>
  #include<process.h>
  #include<dos.h>



  void menu();
  void acc();
  void cars();
  void others1();
  void sedan();
  void suv();
  void allcars();
  void access();
  int password0();
  void date();
  void search_no();
  void search_type();
  void carssearch();
  void design();


  class car
  {
    char type[15], comp[30], cname[30];
    int sno;
    float price;

    public:
    void get()
    {
      gotoxy(30,8);
       cout<<"Enter serial no.   :  ";
       cin>>sno;
       gotoxy(30,9);
       cout<<"Enter company name :  ";
       gets(comp);
       gotoxy(30,10);
       cout<<"Enter product name :  ";
       gets(cname);
       gotoxy(30,11);
       cout<<"Enter price        :  ";
       cin>>price;
       gotoxy(30,12);
       cout<<"Enter type         :  ";
       gets(type);
    }
    void disp()
    {
      gotoxy(30,7);
      cout<<"Serial no.      :  "<<sno;
      gotoxy(30,8);
      cout<<"Name of company :  "<<comp;
      gotoxy(30,9);
      cout<<"Name of car     :  "<<cname;
      gotoxy(30,10);
      cout<<"Price           :  "<<price;
      gotoxy(30,11);
      cout<<"Type            :  "<<type<<endl;

    }



   void modi()
  {  gotoxy(20,4);
     cout<<"Serial no. : "<<sno;
     cout<<"\t\tCompany Name: "<<comp;
     gotoxy(20,5);
     cout<<"Product Name: "<<cname;
     cout<<"\t\tType : "<<type;
     gotoxy(20,6);
     cout<<"Price : " <<price;
     gotoxy(20,8);
     cout<<"Enter new details..\n";
     char cn[30]=" "; char cp[30]=" "; char tp[15]=" ";
     float p;
     gotoxy(8,10);
     cout<<"New Company Name (Press '.' to retain old one): ";
     gets(cp);
     gotoxy(8,11);
     cout<<"New Product Name (Press '.' to retain old one): ";
     gets(cn);
     gotoxy(8,12);
     cout<<"New Type (Press '.' to retain old one): ";
     gets(tp);
     gotoxy(8,13);
     cout<<"New Price (Press -1 to retain old one): ";
     cin>>p;
     if(strcmp(cp,".")!=0)
	strcpy(comp,cp);
     if(strcmp(cn,".")!=0)
	strcpy(cname,cn);
     if(strcmp(tp,".")!=0)
	strcpy(type,tp);
     if(p!=-1)
	price=p;
   }


    int ret_sno()
   { return(sno);
     }


   int ret_type()
   {
    if((strcmp(type,"Sedan")==0)||(strcmp(type,"sedan")==0))
      return 1;
    if((strcmp(type,"SUV")==0)||(strcmp(type,"suv")==0))
      return 2;
    if((strcmp(type,"Other")==0)||(strcmp(type,"other")==0))
      return 3;
    return 0;
   }

  }s,a;



    const char code[20]="password";

   //**********************Cars IMP functions Initialising*********************
      void write()                                         //Write car
      {
       clrscr();
       design();
       char ch='y';
       gotoxy(30,5);
       cout<<"Section Cars : Entering Data...";
	gotoxy(26,7);
       cout<<"Enter details of items you want to insert... ";
	getch();
       ofstream fout;
	fout.open("car.dat",ios::binary|ios::app);

	while(ch=='y')
	{ clrscr();
	  design();
	  s.get();
	  fout.write((char*)&s,sizeof(s));
	  gotoxy(10,13);
	  cout<<"Want to enter more records (y/n): ";
	  cin>>ch;

	}
	fout.close();
       }

       void read()                                         //Read car
       {   clrscr();
	 design();
	  gotoxy(30,7);
	  cout<<"Section Cars : Reading Data... ";
	  getch();
	  ifstream fin;
	  fin.open("car.dat",ios::binary);
	  while(fin.read((char*)&s,sizeof(s)))
	  { clrscr();
	    design();
	    s.disp();
	    getch();
	   }
	  fin.close();
	 }

       void searchsno()                                      //Search car
      {  clrscr();
	 design();
	 int f=0;
	char p[10];
	int no;
	ifstream fin;
	fin.open("car.dat",ios::binary|ios::app);
	gotoxy(30,5);
	cout<<"Section Cars : Searching by Serial no. ...";
	gotoxy(8,7);
	cout<<"Enter the serial no. u want to search: ";
       cin>>no;

       //	strcpy(p,s.ret_sno());
	while(fin.read((char*)&s,sizeof(s)))
       {
	  if (s.ret_sno()==no)//strcmp(p,no)==0)
	   { clrscr();
	     design();
	     s.disp();
	     f=1;
	     getch();
	    }


	  }
	  if(f==0)
	{  gotoxy(8,9);
	  cout<<"Record not found!!";
	 }
	fin.close();

       }


       void searchtype()                                     // Search cars by type
      {  clrscr();
	design();
	int f=0;
	char p[10];
	int no;
	ifstream fin;
	fin.open("car.dat",ios::binary|ios::app);
	gotoxy(30,5);
	cout<< "Section Cars : Searching by Type... ";
	gotoxy(27,7);
	cout<<"1. Sedan";
	gotoxy(27,8);
	cout<<"2. SUV";
	gotoxy(27,9);
	cout<<"3. Others";
	gotoxy(20,11);
	cout<<"Enter the type u want to search: ";
	cin>>no;


	while(fin.read((char*)&a,sizeof(a)))
       {
	  if (no==a.ret_type())//strcmp(p,no)==0)
	   { clrscr();
	     design();
	     a.disp();
	     f=1;
	     getch();
	    }
	  }
	  if(f==0)
	 { gotoxy(30,13);
	   cout<<"Record not found!!";
	 }
	fin.close();

       }


  void modify()                                         // modify car
 { clrscr();
   design();
   fstream fio("car.dat",ios::in|ios::out|ios::binary);
   int sl;	long pos;	char found='f';
   gotoxy(30,5);
   cout<<"Section Cars : Modifying Data..";
   gotoxy(8,7);
   cout<<"Enter serial no. whose record is to be modified: ";
   cin>>sl;
   while(!fio.eof())
  { pos=fio.tellg();
    fio.read((char*)&s,sizeof(s));
    if(s.ret_sno()==sl)
   { clrscr();
     design();
     s.modi();
     fio.seekg(pos);
     fio.write((char*)&s,sizeof(s));
     found='t';
     break;
    }
   }

   if(found=='f')
   { clrscr();
     design();
     gotoxy(30,7);
     cout<<"Record not found!!";
     gotoxy(30,9);
     cout<<"Direct to main menu: ";
     char ch='y';
     cin>>ch;
     if(ch=='y')
    { clrscr();
      menu();
     }
    }

    fio.seekg(0);
    clrscr();

    while(!fio.eof())
   { fio.read((char*)&s,sizeof(s));
     clrscr();
     design();
     gotoxy(30,5);
     cout<<"Now the file contains: ";
     s.disp();
     getch();                              //last record is displayed twice
    }
    fio.close();
   }



	void del()                                            //Delete car
     {
	 clrscr();
	 design();
	  int r;
	  char found='f',confirm='n';
	  gotoxy(30,5);
	  cout<<"Section Cars : Deleting Data...";
	  gotoxy(25,7);
	  cout<<"Enter the serial no. of the item to be deleted= ";
	  cin>>r;
	  ifstream fin("car.dat",ios::binary);
	  ofstream fout("temp.dat",ios::binary);
	 while(fin.read((char*)&s,sizeof(s)))
	 {
	   if(s.ret_sno()==r)
	    { clrscr();
	      design();
	      s.disp();
	      found='t';
	      gotoxy(30,14);
	   cout<<"Confirm delete(y/n): ";
	   cin>>confirm;
	     if(confirm=='n')
	     fout.write((char*)&s,sizeof(s));
	    }
	    else
	    fout.write((char*)&s,sizeof(s));
	    }
	    if(found=='f')
	    {
	    clrscr();
	    design();
	    gotoxy(30,7);
	    cout<<"Record not found!!!";
	    }
	    fin.close();
	    fout.close();
	    remove("car.dat");
	    rename("temp.dat","car.dat");
	 }

   //***************Accessories IMP functions Initialising******************

       void writea()                                      //Write acc
     { clrscr();
       design();
       char ch='y';
       gotoxy(30,5);
       cout<<"Section Accessories : Entering Data...";
       gotoxy(26,7);
       cout<<"Enter details of items you want insert... ";
       getch();
       ofstream fout;
	fout.open("acc.dat",ios::binary|ios::app);
	while(ch=='y')
	{ clrscr();
	  design();
	  a.get();
	  fout.write((char*)&a,sizeof(a));
	  gotoxy(8,13);
	  cout<<"Want to enter more records (y/n): ";
	  cin>>ch;
	}
	fout.close();
       }

       void reada()                                         // Read acc
       {   clrscr();
	   design();
	   gotoxy(30,7);
	   cout<<"Section Accessories : Reading Data.. ";
	  getch();
	  ifstream fin;
	  fin.open("acc.dat",ios::binary);
	  while(fin.read((char*)&a,sizeof(a)))
	  { clrscr();
	    design();
	    a.disp();
	    getch();
	   }
	  fin.close();
	 }

       void searchsnoa()                                     // Search acc
      {  clrscr();
	design();
	int f=0;
	char p[10];
	int no;
	ifstream fin;
	fin.open("acc.dat",ios::binary|ios::app);
	gotoxy(25,5);
	cout<<"Section Accessories : Searching Accesories...";
	gotoxy(8,7);
	cout<<"Enter the serial no. u want to search: ";
       cin>>no;

	while(fin.read((char*)&a,sizeof(a)))
       {   if (a.ret_sno()==no)
	   { clrscr();
	     design();
	     a.disp();
	     getch();
	     f=1;
	    }

	  }
	  if(f==0)
	 { gotoxy(30,8);
	  cout<<"Record not found!!!";
	  }
	fin.close();
      }


   void modifya()                                     // modify acc
 { clrscr();
   design();
   fstream fio("acc.dat",ios::in|ios::out|ios::binary);
   int sl;	long pos;	char found='f';
   gotoxy(25,5);
   cout<<"Section Accessories : Modifying Data...";
   gotoxy(8,7);
   cout<<"Enter serial no. whose record is to be modified: ";
   cin>>sl;
   while(!fio.eof())
  { pos=fio.tellg();
    fio.read((char*)&a,sizeof(a));
    if(a.ret_sno()==sl)
   { clrscr();
     design();
     a.modi();
     fio.seekg(pos);
     fio.write((char*)&a,sizeof(a));
     found='t';
     break;
    }
   }

   if(found=='f')
   {
     gotoxy(27,9);
     cout<<"Record not found!!";
     gotoxy(27,11);
     cout<<"Direct to main menu: ";
     char ch='y';
     cin>>ch;
     if(ch=='y')
    { clrscr();
      menu();
     }
    }

    fio.seekg(0);


    while(!fio.eof())
   { fio.read((char*)&a,sizeof(a));
     clrscr();
     design();
     gotoxy(27,5);
     cout<<"Now the file contains:";
     a.disp();
     getch();
    }
    fio.close();
   }

	void dela()                                         // Delete acc
     {
	 clrscr();
	 design();
	  int r;
	  char found='f',confirm='n';
	  gotoxy(25,5);
	  cout<<"Section Accessories : Deleting Data...";
	  gotoxy(20,7);
	  cout<<"Enter the serial no. of the item to be deleted: ";
	  cin>>r;
	  ifstream fin("acc.dat",ios::binary);
	  ofstream fout("temp1.dat",ios::binary);
	 while(fin.read((char*)&a,sizeof(a)))
	 {
	   if(a.ret_sno()==r)
	    { clrscr();
	      design();
	      a.disp();
	      found='t';
	      gotoxy(30,13);
	   cout<<"Confirm delete(y/n): ";
	   cin>>confirm;
	     if(confirm=='n')
	     fout.write((char*)&a,sizeof(a));
	    }
	    else
	    fout.write((char*)&a,sizeof(a));
	    }
	    if(found=='f')
	    {

	    gotoxy(30,9);
	    cout<<"Record not found!!!";
	    }
	    fin.close();
	    fout.close();
	    remove("acc.dat");
	    rename("temp1.dat","acc.dat");
	 }


	int error=0;

       void menu()                                          // main menu
      {
	 int c1;
	 design();
	 date() ;
	 gotoxy(35,5);
	 cout<<"WELCOME";
	 gotoxy(30,7);
	 cout<<"1. Cars";
	 gotoxy(30,8);
	 cout<<"2. Acessories";
	 gotoxy(30,9);
	 cout<<"3. Exit";
	 gotoxy(30,11);
	 cout<<"Your Choice:  ";
	 cin>>c1;
	 error=0;
	 if(c1==1)
	  { clrscr();
	    design();
	    cars();
	   }
	  else if(c1==2)
	   { clrscr();
	     design();
	     acc();
	    }

	    else if(c1==3)
	      exit(0);
	     else
	      { clrscr();
		gotoxy(5,4);
		cout<<"Invalid option!! Try again..";
		error=1;
	       }
	   if(error==1)
	    menu();
       }

					  // inside all car
      void cars()
      { int sn;
	design();
	date();
	gotoxy(30,5);
	cout<<"Section : ALL CARS";
	gotoxy(25,7);
	cout<<"1. Enter Records";
	gotoxy(25,8);
	cout<<"2. Display all Records";
	gotoxy(25,9);
	cout<<"3. Search a Record";
	gotoxy(25,10);
	cout<<"4. Modify a Record";
	gotoxy(25,11);
	cout<<"5. Delete a Record";
	gotoxy(25,12);
	cout<<"6. Previous Page";
	gotoxy(30,14);
	cin>>sn;

	error=0;

       if(sn==1)
	{
	  int value=password0();
	  if(value==1)
	 {
	  write();
	  char cy='y';
	  gotoxy(25,15);
	  cout<<"Direct to Main Menu: ";
	  cin>>cy;
	  if(cy=='y')
	    { clrscr();
	      menu();
	    }
	  else
	     exit(0);
	 }
	 else
       {
	  clrscr();
	  design();
	  gotoxy(30,6);
	  cout<<"Wrong Password!!!" ;
	  getch();
	  clrscr();
	  cars();
	}

     }

	else if(sn==2)
	 {
	   read();
	   char cy='y';
	   gotoxy(25,15);
	   cout<<"Direct to Main Menu: ";
	   cin>>cy;
	   if(cy=='y')
	     { clrscr();
	       menu();
	     }
	   else
	     exit(0);
	 }

	 else if(sn==3)
	 {
	   clrscr();
	   carssearch();
	 }

	  else if(sn==4)
	  {
	     int value=password0();
	     if(value==1)
	       {
		 modify();
		 char cy='y';
		 gotoxy(25,15);
		 cout<<"Direct to Main Menu: ";
		 cin>>cy;
		 if(cy=='y')
		  { clrscr();
		    menu();
		  }
	     else
	     exit(0);
	       }
	   else
	   {  clrscr();
	  design();
	  gotoxy(30,6);
	  cout<<"Wrong Password!!!" ;
	  getch();
	  clrscr();
	  cars();
	}


	}
	   else if(sn==5)
	  {
	    int value=password0();
	  if(value==1)
	 {
	    del();

	      char cy='y';
	      gotoxy(25,15);
	      cout<<"Direct to main menu: ";
	  cin>>cy;
	  if(cy=='y')
	  { clrscr();
	    menu();
	   }
	    else
	     exit(0);
	     }

	     else
	   {  clrscr();
	  design();
	  gotoxy(30,6);
	  cout<<"Wrong Password!!!" ;
	  getch();
	  clrscr();
	  cars();
	}
      }
	    else if(sn==6)
	     { clrscr();
	       menu();
	     }
	     else
	    { clrscr();
	      gotoxy(25,4);
	      cout<<"Invalid Choice!! Try again...\n";
	      error=1;
	     }
	   if(error==1)
	    cars();
	 }





	void acc()                                  // accessories menu
      {  error=0;
	int sn;
	design();
	date();
	gotoxy(30,5);
	cout<<"Section : ACCESSORIES";
	gotoxy(25,7);
	cout<<"1. Enter Records";
	gotoxy(25,8);
	cout<<"2. Display all Records";
	gotoxy(25,9);
	cout<<"3. Search a Record";
	gotoxy(25,10);
	cout<<"4. Modify a Record";
	gotoxy(25,11);
	cout<<"5. Delete a Record";
	gotoxy(25,12);
	cout<<"6. Previous Page\t\t\t";
	cin>>sn;

       char cho='y';

       if(sn==1)
	{

	  int value=password0();
	  if(value==1)
	 { writea();
	   gotoxy(25,15);
	   cout<<"Direct to Main Menu: ";
	    cin>>cho;
	    if(cho=='y')
	   { clrscr();
	    menu();
	   }
	  }
	  else
       {  clrscr();
	  design();
	  gotoxy(30,6);
	  cout<<"Wrong Password!!!" ;
	  getch();
	  clrscr();
	  acc();
	}
       }

	else if(sn==2)
	 { reada();
	   gotoxy(25,15);
	   cout<<"Direct to Main Menu: ";
	    cin>>cho;
	    if(cho=='y')
	    { clrscr();
	      menu();
	     }

	  }
	 else if(sn==3)
	  { searchsnoa();
	    gotoxy(25,15);
	    cout<<"Direct to Main Menu: ";
	    cin>>cho;
	    if(cho=='y')
	   { clrscr();
	     menu();
	    }

	   }
	  else if(sn==4)
	  {
	       int value=password0();
	  if(value==1)
	 {
	     modifya();
	     gotoxy(25,15);
	     cout<<"Direct to Main Menu: ";
	    cin>>cho;
	    if(cho=='y')
	   { clrscr();
	     menu();
	    }
	  }
	     else
	   {  clrscr();
	  design();
	  gotoxy(30,6);
	  cout<<"Wrong Password!!!" ;
	  getch();
	  clrscr();
	  acc();
	}

	   }
	   else if(sn==5)
	{
	  int value=password0();
	  if(value==1)
	 {
	     dela();
	     gotoxy(25,15);
	      cout<<"Direct to Main Menu: ";
	    cin>>cho;
	    if(cho=='y')
	   { clrscr();
	     menu();
	    }
	   }
	     else
	   {  clrscr();
	  design();
	  gotoxy(30,6);
	  cout<<"Wrong Password!!!" ;
	  getch();
	  clrscr();
	  acc();
	}

	   }
	    else if(sn==6)
	   { clrscr();
	     menu();
	    }
	     else
	    {
	      clrscr();
	      gotoxy(5,4);
	      cout<<"Invalid Choice!! Try again...";
	      error=1;
	     }
	   if(error==1)
	    acc();


       }


	 void search_no()
	 { searchsno();
	    char cy='y';cout<<"\n  \t\tDirect to main menu: ";
	  cin>>cy;
	  if(cy=='y')
	   { clrscr();
	     menu();
	    }
	     else
	     exit(0);
	  }

	 void search_type()
	{  searchtype();
	     char cy='y';cout<<"\n  \t\tDirect to main menu: ";
	  cin>>cy;
	  if(cy=='y')
	   { clrscr();
	     menu();
	    }
	     else
	     exit(0);
	  }

	void carssearch()
      {  error=0;
      int ch;
       design();
       gotoxy(27,6);
       cout<<"1.Search by serial no";
       gotoxy(27,9);
       cout<<"2.Search by type\t\t";
       cin>>ch;
       if(ch==1)
       { clrscr();
	search_no();
	}
	else if(ch==2)
      {  clrscr();
	search_type();
       }
	 else
	    { clrscr();
	      gotoxy(5,5);
	      cout<<"Invalid Choice!! Try again...";
	      error=1;
	     }
	   if(error==1)
	    carssearch();
     }

       void design()
 { clrscr();
   int n;
   for(n=3;n<80;n++)
   { gotoxy(n,2);
     cout<<"";
    }
   for(n=3;n<25;n++)
  { gotoxy(3,n);
    cout<<"";
   }
   for(n=3;n<80;n++)
  { gotoxy(n,24);
    cout<<"";
   }
   for(n=3;n<24;n++)
  { gotoxy(79,n);
    cout<<"";
   }


 }

	 void date()                                      //To display
{                                                      // current date
   struct date d;

   getdate(&d);
   gotoxy(5,3);
   printf("Date: %d /", d.da_day);
   printf(" %d /", d.da_mon);
   printf(" %d\n\n", d.da_year);

}

       int password0()
  {  clrscr();
    design();
     char a[20];
     gotoxy(20,7);
     cout<<"Enter the 8 character password: ";
     for(int i=0;i<=8;i++)
    {
      a[i]=getch();
	cout<<"*";
     }
       int j,f=0;
     for(i=0, j=0;code[j]!='\0';i++,j++)
    { if(a[i]==code[j])
	f++;
     }
     if(f==8)
       return 1;
       else return 0;

   getch();

   }

	void main()
      { clrscr();
	textbackground(BLUE);
	textcolor(LIGHTGREEN);

	menu();
	getch();
       }

