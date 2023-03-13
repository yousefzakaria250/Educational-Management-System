
#include <iostream>
#include<string>
#include<process.h>
#include<cstring>
#include<windows.h>
struct student ;
struct Course ;
struct doctor ;
using namespace std;
//const int s = 10 ;
void unregisterCourse() ;
void Register() ;
void viewCourse() ;
void methodStudent() ;
void check(string, string ) ;
void checkDoc(string, string ) ;
void setStudent();
void setDoctor() ;
void LogIn() ;
void signUp() ;
void basicPage() ;
int checkCourse(int);
void DeleteCourse( int ) ;
void listCourse() ;
void loadAssignment(int) ;
void gradeReports() ;
void doctorPage() ;
void choice_in_view_Course();
void View_Course() ;
void __course__(int ) ;
void listAssignment( int ) ;
string Courses[100]= {"prog1", "prog2", "prog3", "prog4", "prog5", "prog6", "Math1", "Math2", "Math3","phys1", "phys2", "phys3"};
string codes[100] = {"CS111", "CS112", "CS113", "CS114", "IS111","CS555", "IS222", "It121", "MM123","phy212","phy665", "phy444"};
string Snames[100] = {"yousef", "alaa", "mostafa", "mohamed", "Ahmed", "salah", "hossam"};
string Spassword[100] = {"123asd", "123qwe", "123zxc", "456asd", "456qwe", "456zxc","112233"};
string Dnames[100] = {"zakaria", "mamdoh", "Samy", "lotfy", "zain"} ;
string str_stdu[100];
//int Assignment[50] ={ 4 , 3 , 2 , 1 , 5 , 2 , 1 , 3 , 6 , 3 , 2 };

//string Dzak[50] = { "porg1" , "prog2" , "prog3"} ;
//string Dmam[50] = { "porg4" , "prog5" , "prog6"} ;
//string Dsam[50] = { "Math1" , "Math2" , "Math3"} ;
//string Dlot[50] = { "phys1" , "phys2" , "phys3"} ;
//string Dzai[50] = {} ;
//string Doc[50] = { "Dzak" , "Dmam" , "Dsam" , "Dlot" , "Dzai"} ;
string Dpassword[100] = {"zak123", "mad123", "sam123", "lot123", "zai123"};
string RegCourse[100] ;
string RegCode[100] ;
int Rgcode = 0 ; // For Register Codes
int j = 0 ; // For Register Courses .
int s = 12;
int SR = 7 ; // To number of student sign up .
int DR = 5 ; // To number of Doctor Sign up .
int Nsub = 9 ; //To Know number of subjects.
int l = 0 ; // used to counter Assignment Solutions
struct student
{
    int id ;
    string username ;
    string password;
    string whoIs ;
    string fullnam ;
    string email ;
    // int Assignment ;
    //string Assign[10] ;
    string subject ;
    int Count ;
};
struct doctor
{
    string username ;
    string name ;
    string password;
    string whoIs;
    string fullnam ;
    string email ;
};
struct code
{
    string cod ;
};

struct Assignment
{


    int submit;
    string Assign ;

};
struct Course
{
    int Assignment ;
    //Assignment as[100];
    code coco ;
    string name ;
    string Assign[10] ;
    int number_of_register_student ;
    int number_of_assignment ;
    int Count;

};
doctor doc[50] ;
doctor d1;
student stdu[50] ;
Assignment ass[100];
Course cors[100] ;
code cc[100] ;


int main()
{
    //  Assignment c ;
//    c.s.Cname
    basicPage() ;
    //unregisterCourse() ;
    //Register();
    //unregisterCourse();
    //unregisterCourse() ;
    //Register() ;
    //Register() ;
    //Register() ;
    //string arr[3] ={"sdsd" , "ass" , "sdsd"} ;
//  cout << arr.size();
    return 0;
}

void unregisterCourse()
{

    cout << "Un Register Courses : " << endl;
    for( int i = 0 ; i < s ; i++)
    {
        cout <<"\n" <<"   " << i + 1 <<"- " << Courses[i] ;
    }
    //Register() ;
}
//void Back()

void Register()
{
    char ch ;   // For Choice
    do
    {

        int num ;
        cout << "\n\n Enter a Choice : " ;
        cin >> num ;
        RegCourse[j] = Courses[num-1];
        RegCode[Rgcode] = codes[num -1] ;
        //cout << RegCode[Rgcode] << endl;
        j++ ;
        Rgcode++;

        for( int k = num -1 ; k < s ; k++)
        {
            Courses[k] = Courses[k+1] ;
            codes[k] = codes[k+1];

        }
        s-- ;
        cout <<"Do you want register in another course ( y , n ) : ";
        cin >> ch ;
        if( ch == 'y' && s == 0)
        {
            system("cls") ;
            cout <<" Not Courses for Register ! " << endl;
            cout <<"Enter 1 for previous list : " ;
            int n ;
            cin >> n ;
            methodStudent() ;
        }
        if( ch =='y' &&  s!=0)
            unregisterCourse() ;
        else
            methodStudent() ;

    }
    while( ch == 'y' || ch == 'Y') ;
}
void loadAssignment(int x)
{

    cout <<"Course have " << cors[x].Assignment << " Assignment" << endl;
    for( int h = 0 ; h < cors[x].Assignment ; h++ )
    {
        if( cors[x].Assign[h] =="")
            cout <<"\nAssignment " << h + 1 << " Not Submitted " << "NA / 35 " << endl;
        else
        {
            cout <<"\nAssignment " << h + 1 << "  Submitted " << "NA / 35 " << endl;
            //stdu[x].Count++;
        }
    }

    /*
    cout <<"Course have " << stdu[x].Assignment << " Assignment" << endl;
    for( int h = 0 ; h < stdu[x].Assignment ; h++ ){
    if( stdu[x].Assign[h] =="")
        cout <<"\nAssignment " << h + 1 << " Not Submitted " << "NA / 35 " << endl;
    else{
        cout <<"\nAssignment " << h + 1 << "  Submitted " << "NA / 35 " << endl;
        //stdu[x].Count++;
        }
    } */
}
void submitAssign(int w )
{

    if( cors[w].Assignment == 0)
    {
        cout <<"\nNot Assignment to Submit ! " << endl;
        cout << "\nEnter 1 for main menue : " ;
        int n1 ;
        cin >> n1;
        methodStudent() ;
    }
    else
    {
        int n ;
        cout <<"\nAny Assignment [ 1 , "  << cors[w].Assignment <<"]"<<" you want to submit : \n" ;
        cin >> n ;
        if(cors[w].Assign[n-1] != "" )
        {
            char ch ;
            cout <<"\n Do You submit on previouis solution ? " ;
            cin >> ch ;
            if( ch =='y' || ch =='Y')
            {
                cout <<"Enter a new solution : " << endl;
                cin >> cors[w].Assign[n-1] ;
            }
            else
                choice_in_view_Course();
        }
        else
        {
            cin >> cors[w].Assign[n-1] ;
            cors[w].Count++;
        }
    }

    cout <<"\nYou are Submitted your solution  ^_^ \n " ;

    /*
    if( stdu[w].Assignment == 0){
        cout <<"\nNot Assignment to Submit ! " << endl;
        cout << "\nEnter 1 for main menue : " ;
        int n1 ;
        cin >> n1;
        methodStudent() ;
    }
    else{
    int n ;
    cout <<"\nAny Assignment [ 1 , "  << stdu[w].Assignment <<"]"<<" you want to submit : \n" ;
    cin >> n ;
    if(stdu[w].Assign[n-1] !="" )
    {
        char ch ;
        cout <<"\n Do You submit on previouis solution ? " ;
        cin >> ch ;
        if( ch =='y' || ch =='Y')
        {
            cout <<"Enter a new solution : " << endl;
            cin >> stdu[w].Assign[n-1] ;
        }
        else
            choice_in_view_Course();
    }
    else{
    cin >> stdu[w].Assign[n-1] ;
    stdu[w].Count++;
    }
    }

    cout <<"\nYou are Submitted your solution  ^_^ \n " ; */
}
void choice_in_view_Course( )
{
    int choice ;
    cout <<" \n Which [1 , " << j <<"] Course to View ?" << endl;
    cin >> choice ;

    int  z = checkCourse(choice-1);
    if( z == -1)
        cout <<"\nCourse " <<RegCourse[choice -1] <<" With Code " << RegCode[choice - 1] <<" - No Doctor To Now " << endl;
    else
    {
        cout <<"\n\nCourse " <<RegCourse[choice -1] <<" With Code " << RegCode[choice - 1] <<" - Taugh by doctor " << doc[z].name << endl;
        loadAssignment(z);
    }
    cout <<"Please make a choise : " << endl;
    cout <<"1- Un Register From Courses " << endl;
    cout <<"2- Submit Assignment " << endl;
    cout <<"3- Back " << endl;
    int cho ;
    cin >> cho ;
    switch(cho)
    {
    case 1 :
        DeleteCourse( choice - 1 ) ;
        break ;
    case 2 :
        submitAssign(z) ;
        methodStudent() ;
        break ;
    case 3 :
        methodStudent() ;
        break;
    }
}
void viewCourse()
{
    if( j == 0 )
    {
        cout <<"\n You Don't Register in any Course ^_^ \n" << endl;
        int n ;
        cout<<"\nEnter 1 To Main Menue\n "<< endl;

        cin >> n ;
        system("cls") ;
        methodStudent() ;
    }
    int choice; // For Choice
    cout <<"My Courses List :\n" ;
    for( int i = 0 ; i < j ; i++)
    {
        cout << i + 1 <<"- " << "Course " << RegCourse[i] <<" - " << "Code " << RegCode[i] << endl;
    }
    choice_in_view_Course(  );
    /*cout <<" \n Which [1 , " << j <<"] Course to View ?" << endl;
    cin >> choice ;

    int  z = checkCourse(choice-1);
    if( z == -1)
        cout <<"\nCourse " <<RegCourse[choice -1] <<" With Code " << RegCode[choice - 1] <<" - No Doctor To Now " << endl;
    else{
        cout <<"\n\nCourse " <<RegCourse[choice -1] <<" With Code " << RegCode[choice - 1] <<" - Taugh by doctor " << doc[z].name << endl;
        loadAssignment(z);
    }
     cout <<"Please make a choise : " << endl;
     cout <<"1- Un Register From Courses " << endl;
     cout <<"2- Submit Assignment " << endl;
     cout <<"3- Back " << endl;
     int cho ;
     cin >> cho ;
     switch(cho)
     {
         case 1 :   DeleteCourse( choice - 1 ) ; break ;
         case 2 :   submitAssign(z) ; methodStudent() ;   break ;
         case 3 : methodStudent() ; break;
     }*/
}

void DeleteCourse( int z)
{
    // s++;
    //cout << "REG = " << RegCourse[z] << endl;
    Courses[s] = RegCourse[z] ;
    //cout <<"Course[s] = " << Courses[s] << endl;
    codes[s] = RegCode[z] ;
    for( int k = z ; k < j ; k++)
    {
        RegCourse[k] = RegCourse[k+1] ;
        RegCode[k] = RegCode[k+1];

    }
    j-- ;
    s++;
    cout <<"\nCourse Is Deleted Successful From Courses ^_^ \n" << endl;
    system("cls") ;
    methodStudent() ;
}
void listCourse()
{
    if(j == 0)
        cout <<"\n\nYou Are not Register in any Course\n" << endl;
    else
    {
        cout <<"You Are Registered In :\n";
        for( int i = 0 ; i < j ; i++)
        {
            cout <<"\n" << i + 1 <<"- " << RegCourse[i] << endl;
        }
    }
    int n ;
    cout <<"\nEnter 1 for main menue ^_^ \n " ;
    cin >> n ;
    system("cls") ;
    methodStudent() ;
}
void gradeReports()
{
    for( int i = 0 ; i < j ; i++)
    {
        cout <<"\n Course " << RegCourse[i] <<" - Code " << RegCode[i] <<" - have total Assignment " << stdu[i].Count <<" Submitted - Grade 21 / 84" << endl;
    }
}
int checkCourse(int c)
{
    int y = 0 ;
// bool v = false ;

    cors[0].name = "prog1" ;
    cors[0].Assignment = 1 ;
    doc[0].name="zakaria" ;

    cors[1].name = "prog2" ;
    cors[1].Assignment = 2 ;
    doc[1].name="zakaria" ;

    cors[2].name = "prog3" ;
    cors[2].Assignment = 3 ;
    doc[2].name="zakaria" ;

    cors[3].name = "prog4" ;
    cors[3].Assignment = 4 ;
    doc[3].name="Ali" ;

    cors[4].name = "prog5" ;
    cors[4].Assignment = 5 ;
    doc[4].name="Ali" ;

    cors[5].name = "prog6" ;
    cors[5].Assignment = 6 ;
    doc[5].name="Ali" ;

    cors[6].name = "math1" ;
    cors[6].Assignment = 3 ;
    doc[6].name="Zain" ;

    cors[7].name = "math2" ;
    cors[7].Assignment = 4 ;
    doc[7].name="Zain" ;

    cors[8].name ="math3" ;
    cors[8].Assignment = 3 ;
    doc[8].name="Zain" ;

    cors[9].name = "pyhs1" ;
    cors[9].Assignment = 2 ;
    doc[9].name="Ramy" ;

    cors[10].name = "pyhs2" ;
    cors[10].Assignment = 3 ;
    doc[10].name="Ramy" ;

    cors[11].name = "pyhs3" ;
    cors[11].Assignment = 2 ;
    doc[11].name="Ramy" ;

    /*
    stdu[0].subject ="prog1";
    stdu[1].subject ="prog2";
    stdu[2].subject ="prog3";
    doc[0].name ="zakaria" ;
    doc[1].name ="zakaria" ;
    doc[2].name ="zakaria" ;
    stdu[0].Assignment = 1 ;
    stdu[1].Assignment = 2 ;
    stdu[2].Assignment = 3 ;
    //stdu[1].Assign[0]="aaaaaaaaaaa" ;
    //stdu[2].Assign[1] ="bbbbb";
    //----------------------------
    stdu[3].subject ="prog4";
    stdu[4].subject ="prog5";
    stdu[5].subject ="prog6";
    doc[3].name ="samy" ;
    doc[4].name ="samy" ;
    doc[5].name ="samy" ;
    stdu[3].Assignment = 4 ;
    stdu[4].Assignment = 5 ;
    stdu[5].Assignment = 6 ;
    //-----------------------------
    stdu[6].subject = "Math1";
    stdu[7].subject = "Math2";
    stdu[8].subject = "Math3";
    doc[6].name = "mamdoh";
    doc[7].name = "mamdoh";
    doc[8].name = "mamdoh";
    //------------------------------
    stdu[9].subject="phys1";
    stdu[10].subject="phys2";
    stdu[11].subject="phys3";
    doc[9].name = "zain";
    doc[10].name = "zain";
    //doc[11].name = "zain";
    */
    /*
    for(  y  ; y <= Nsub ; y++)
        {
            if(stdu[y].subject == RegCourse[c] && doc[y].name !="")
            {
            //    v = true ;
                return y ;
                break ;
            }
        }
        return -1 ; */

    for(  y  ; y < s; y++)
    {
        if(cors[y].name == RegCourse[c] && doc[y].name !="")
        {
            //    v = true ;
            return y ;
            break ;
        }
    }
    return -1 ;
}

void checkCourse1()
{


// bool v = false ;

    cors[0].name = "prog1" ;
    cors[0].Assignment = 2 ;
    doc[0].name="zakaria" ;
    cors[0].Assign[0]="aaaaaaaaaaaaa" ;
    cors[0].Assign[1]="aaaaaaaaaaaaa" ;
    cors[1].name = "prog2" ;
    cors[1].Assignment = 2 ;
    doc[1].name="zakaria" ;
    cors[1].Assign[1] ="bbbbbbbbbbbbb" ;
    cors[1].Assign[0] ="ddddddddddddd" ;
    cors[1].Assign[2] ="xxxxxxxxxxxx" ;
    cors[2].name = "prog3" ;
    cors[2].Assignment = 3 ;
    doc[2].name="zakaria" ;
    cors[2].Assign[1] ="cccccccccccc" ;
    cors[3].name = "prog4" ;
    cors[3].Assignment = 4 ;
    doc[3].name="Ali" ;

    cors[4].name = "prog5" ;
    cors[4].Assignment = 5 ;
    doc[4].name="Ali" ;

    cors[5].name = "prog6" ;
    cors[5].Assignment = 6 ;
    doc[5].name="Ali" ;

    cors[6].name = "math1" ;
    cors[6].Assignment = 3 ;
    doc[6].name="Zain" ;

    cors[7].name = "math2" ;
    cors[7].Assignment = 4 ;
    doc[7].name="Zain" ;

    cors[8].name ="math3" ;
    cors[8].Assignment = 3 ;
    doc[8].name="Zain" ;

    cors[9].name = "pyhs1" ;
    cors[9].Assignment = 2 ;
    doc[9].name="Ramy" ;

    cors[10].name = "pyhs2" ;
    cors[10].Assignment = 3 ;
    doc[10].name="Ramy" ;

    cors[11].name = "pyhs3" ;
    cors[11].Assignment = 2 ;
    doc[11].name="Ramy" ;

    /*
    stdu[0].subject ="prog1";
    stdu[1].subject ="prog2";
    stdu[2].subject ="prog3";
    doc[0].name ="zakaria" ;
    doc[1].name ="zakaria" ;
    doc[2].name ="zakaria" ;
    stdu[0].Assignment = 1 ;
    stdu[1].Assignment = 2 ;
    stdu[2].Assignment = 3 ;
    //stdu[1].Assign[0]="aaaaaaaaaaa" ;
    //stdu[2].Assign[1] ="bbbbb";
    //----------------------------
    stdu[3].subject ="prog4";
    stdu[4].subject ="prog5";
    stdu[5].subject ="prog6";
    doc[3].name ="samy" ;
    doc[4].name ="samy" ;
    doc[5].name ="samy" ;
    stdu[3].Assignment = 4 ;
    stdu[4].Assignment = 5 ;
    stdu[5].Assignment = 6 ;
    //-----------------------------
    stdu[6].subject = "Math1";
    stdu[7].subject = "Math2";
    stdu[8].subject = "Math3";
    doc[6].name = "mamdoh";
    doc[7].name = "mamdoh";
    doc[8].name = "mamdoh";
    //------------------------------
    stdu[9].subject="phys1";
    stdu[10].subject="phys2";
    stdu[11].subject="phys3";
    doc[9].name = "zain";
    doc[10].name = "zain";
    //doc[11].name = "zain";
    */
    /*
    for(  y  ; y <= Nsub ; y++)
        {
            if(stdu[y].subject == RegCourse[c] && doc[y].name !="")
            {
            //    v = true ;
                return y ;
                break ;
            }
        }
        return -1 ; */
    int counter = 0 ;
    int t = 0 ;

    for( int i = 0 ; i < s ; i++)
    {

        //  cout <<"d1.username = " << d1.username << endl;
        //   cout <<"doc[i].name = " << doc[i].name << endl;
        if(doc[i].name == d1.username)
        {
            //cout <<"j = " << j << endl;

            cout << t + 1 <<"- " << cors[i].name << endl;
            counter++;
            t++;
        }

    }
    int choice ;
    cout <<"which course will choice[1 , " << counter <<" ] : " ;
    cin >> choice ;
    __course__(choice) ;



}
void __course__(int c)
{
    cout <<"\n1- List Assignment " << endl;
    cout <<"\n2- Create Assignment " << endl;
    cout <<"\n3- View Assignment " << endl;
    cout <<"\n4- Back " << endl;
    int ele ;
    cin >> ele ;
    if( ele == 1)
        listAssignment(c) ;


}
void listAssignment( int c )
{
    cout << "cors[1].Assignment = " << cors[1].Assignment << endl;
    for( int i = 0 ; i < cors[c - 1].Assignment ; i++ )
    {
        cout << 1 << endl;
        cout << cors[i].Assign[i]  << endl;
    }

}

void methodStudent()
{
    int n1 ; // For Choice .
    cout <<"Please Make a choice :\n\n" ;
    cout <<" 1- Register In Course . \n " ;
    cout <<"2- List My Courses . \n " ;
    cout <<"3- View Course . \n " ;
    cout <<"4- Grade Reports  . \n " ;
    cout <<"5- Log Out . \n " ;
    cin >> n1 ;
    if( n1 == 1)
    {
        unregisterCourse();
        Register() ;
    }
    else if( n1 == 2)
    {
        listCourse() ;
    }
    else if(n1 == 3 )
    {
        viewCourse();
    }
    else if( n1 == 4)
    {
        gradeReports() ;
    }

    else
    {
        system("cls") ;
        basicPage() ;

    }
}

void check(string uname, string pass)
{
    bool b = true;
    for( int ss = 0 ; ss < SR ; ss++)
    {
        if( uname == Snames[ss] && pass == Spassword[ss])
        {
            cout <<"Welcome " << uname <<" You are logged successfully .\n "<<endl ;
            b = false ;
            methodStudent() ;
            break ;
        }
    }
    if(b)
        cout <<"You Entered False username or password !" << endl;
}
void checkDoc(string uname, string pass)
{
    bool b = true;
    for( int ss = 0 ; ss < DR ; ss++)
    {
        if( uname == Dnames[ss] && pass == Dpassword[ss])
        {
            cout <<"Welcome " << uname <<" You are logged successfully . " <<"^_^"<<endl ;
            b = false ;
            doctorPage();
            break ;
        }
    }
    if(b)
        cout <<"You Entered False username or password !" <<" :(" << endl;
}
void setStudent()
{
    student s1 ;
    cout << "Enter Username : " ;
    cin >> s1.username ;
    cout <<"Enter Password : " ;
    cin >> s1.password ;
    cout << endl;
    check( s1.username, s1.password) ;
}
void setDoctor()
{
    // doctor d1 ;
    cout << "Enter Username : " ;
    cin >> d1.username ;
    cout <<"Enter Password : " ;
    cin >> d1.password ;
    checkDoc( d1.username, d1.password) ;


}

void LogIn()
{

    int n ;
    cout <<"You are Log in as " << endl;
    cout <<"\t 1- Student " << endl;
    cout <<"\t 2- Doctor " << endl;
    cout <<"\t 3- ShutDown " << endl;
    cin >> n ;
    if( n == 1 )
        setStudent() ;
    else if( n== 2)
        setDoctor();
    else
    {
        cout <<"Thanks For use ^_^" << endl;
        exit(0);
    }
}

void signUp()
{
    cin.ignore(); // To Solve problem in getline() with cin .
    student s ;
    cout <<"Enter a Full Name : "  ;
    getline( cin, s.fullnam);

    cout <<"Enter a username : " ;
    cin >> s.username ;
    cout <<"Enter a password : " ;
    cin >> s.password;
    cout <<"You are sign up as : " ;
    cin >> s.whoIs ;
    if( s.whoIs == "student" || s.whoIs =="Student")
    {

        Snames[SR] = s.username ;
        Spassword[SR] = s.password ;
        SR++;
    }
    else if(s.whoIs == "Doctor" || s.whoIs =="doctor")
    {

        Dnames[DR] = s.username;
        Dpassword[DR] = s.password;
        DR++;
    }
    else
    {
        cout <<"You Entered unknown type !"<<endl;
    }
    cout << s.username <<" You Sign up successfully as " << s.whoIs <<" ^_^" << endl;
}
void basicPage()
{
    int choice ;
    cout <<"You Want To : " << endl;
    cout <<"\t 1- Sign up " << endl;
    cout <<"\t 2- Log In " << endl;
    cout <<"\t 3- ShutDown"<< endl;
    cin >> choice ;
    if( choice == 1)
    {
        signUp() ;
        LogIn() ;
    }
    else if( choice == 2)
    {
        LogIn() ;
    }
    else
    {
        cout <<"Thanks for use ^_^" << endl;
        exit(0);
    }
}

//_______________________________________________________________________________

void Create_Course()
{
    string str ;
    string cod ;
    cout <<"Enter a Name of Course : " << endl;
    cin >> str ;
    cout <<"Enter a Code of Course : " << endl;
    cin >> cod ;
    Courses[s] = str ;
    codes[s] = cod ;
    s++;
    cout <<"Course " << str <<" Is added to List Courses . " << endl;
    cout <<"Enter 1 For Previouis Menue : " ;
    int m ;
    cin >> m ;
    doctorPage();
}

void List_Courses()
{
    for( int i = 0 ; i < s ; i++)
    {
        cout <<"\n" << i + 1 <<"- " << Courses[i] <<" - Code - " << codes[0] << endl;
    }
}

void doctorPage()
{
    int n ;
    cout<<"\n1- List Course " << endl;
    cout<<"\n2- Create Course " << endl;
    cout<<"\n3- View Course " << endl;
    cout<<"\n4- Log out Course " << endl;
    cin >> n ;
    if( n == 1)
        List_Courses() ;
    else if(n == 2)
        Create_Course() ;
    else if(n == 3)
        View_Course() ;

    else
    {
        basicPage() ;
    }
}

void View_Course()
{
    checkCourse1() ;
}
