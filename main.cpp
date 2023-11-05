#include<iostream>

#include<cstring>

#include<cstdlib>

#include<iomanip>

#include<windows.h>

//#include <ctime>

#include <dos.h>

#include<dos.h>

#include<conio.h>

#include<cstdio>

#define max 20


using namespace std;

struct employee

{

    char name[20];

    long int code;

    char designation[20];

    int exp;

    int age;

};

int num;

employee emp[max], tempemp[max], sortemp[max], sortemp1[max];

int main()

{

    system("cls");

    void build();

    void list();

    void insert();

    void deletes();

    void edit();

    void search();

    void sort();

    char option;

    void menu();

    menu();

    while ((option = cin.get()) != 'q')

    {

        switch (option)

        {

        case 'b':

            build();

            break;

        case 'l':

            list();

            break;

        case 'i':

            insert();

            break;

        case 'd':

            deletes();

            break;

        case 'e':

            edit();

            break;

        case 's':

            search();

            break;

        case 'n':

            sort();

            break;

        }

        menu();

    }

    return 0;

}

void menu()

{

    system("cls");

    cout << "          ";

    cout<<"\n*****  Staff Management System In C++ ***** ";
    
    cout << endl;

    cout << "             ";

    cout << "\n\t\t Press  b---->Built The Staff Table ";

    cout << "             ";

    cout << "\n\t\t Press  l---->List The Staff Table  ";

    cout << "             ";

    cout << "\n\t\t Press  i---->Add New Entry        ";

    cout << "             ";

    cout << "\n\t\t Press  d---->Delete An Entry         ";

    cout << "             ";

    cout << "\n\t\t Press  e---->Edit An Entry           ";

    cout << "             ";

    cout << "\n\t\t Press  s---->Search Arecord          ";

    cout << "             ";

    cout << "\n\t\t Press  n---->Sort The Table          ";

    cout << "             ";

    cout << "\n\t\t Press  q---------->Quit Program              ";

    cout << "             ";

    cout << "\n\n \t\t Select Your Option Please ====> ";

}


//void build()
//
//{
//
//
//    system("cls");
//
//    cout<<"Build The Table";
//
//    cout << endl;
//    
//    cout << "maximum number of entries  -----  >  20" << endl;
//
//    cout << "how many do you want    ----->";
//
//    cin >> num;
//
//    cout << "Enter The Following Items" << endl;
//
//    for (int i = 0; i <= num - 1; i++)
//
//    {
//
//        cout << " Name  ";
//
//        cin >> emp[i].name;
//
//        cout << "Code  ";
//
//        cin >> emp[i].code;
//
//        cout << "Designation  ";
//
//        cin >> emp[i].designation;
//
//        cout << "Years of Experience  ";
//
//        cin >> emp[i].exp;
//
//        cout << "Age  ";
//
//        cin >> emp[i].age;
//
//    }
//
//    cout << "going to main menu";
//
//    Sleep(500);
//
//}

void build() {
    system("cls");
    cout << "Build The Table" << endl;
    cout << "maximum number of entries ----- > 20" << endl;
    cout << "how many do you want -----> ";
    int requestedEntries;
    cin >> requestedEntries;

    if (requestedEntries > max) {
        cout << "Error: The number of entries exceeds the maximum allowed." << endl;
        Sleep(2000); // Delay for 2 seconds
        return;
    }

    cout << "Enter The Following Items" << endl;
    for (int i = 0; i < requestedEntries; i++) {
        int newCode;
        bool codeExists;
        
        do {
            cout << " Name (up to 20 characters): ";
            cin.ignore(); // Xóa bộ nhớ đệm
            string inputName;
            getline(cin, inputName);

            // Kiểm tra độ dài tên và yêu cầu nhập lại nếu quá 20 kí tự
            if (inputName.length() > 20) {
                cout << "Name is too long. Please enter a name up to 20 characters." << endl;
            } else {
                // Sao chép tên vào cấu trúc emp[]
                strncpy(emp[num].name, inputName.c_str(), sizeof(emp[num].name));
                emp[num].name[sizeof(emp[num].name) - 1] = '\0';
                break; // Kết thúc vòng lặp khi tên hợp lệ
            }
        } while (true);

        do {
            codeExists = false;
            cout << " Code: ";
            cin >> newCode;

            // Kiểm tra xem mã đã tồn tại trong danh sách emp[] chưa
            for (int j = 0; j < num; j++) {
                if (emp[j].code == newCode) {
                    codeExists = true;
                    break;
                }
            }

            if (codeExists) {
                cout << " This code is already exist, enter another code: ";
            } else {
                emp[num].code = newCode;
            }
        } while (codeExists);

        cout << " Designation: ";
        cin >> emp[num].designation;
        cout << " Years of Experience: ";
        cin >> emp[num].exp;
        cout << " Age: ";
        cin >> emp[num].age;
        num++;
    }

    cout << "Going to the main menu" << endl;
    Sleep(500);
}


void  list()

{

    system("cls");


    cout <<"       ********List The Table********";

    cout << endl;


    cout << "     Name     Code     Designation     Years(EXP)     Age " << endl;

    cout << "    ------------------------------------------------------" << endl;

    for (int i = 0; i <= num - 1; i++)

    {

        cout << setw(13) << emp[i].name;

        cout << setw(6) << emp[i].code;

        cout << setw(15) << emp[i].designation;

        cout << setw(10) << emp[i].exp;

        cout << setw(15) << emp[i].age;

        cout << endl;

    }

    cout << "going to main menu";

    getch();

}

//void insert()
//
//{
//
//    system("cls");
//
//    int i = num;
//
//    num += 1;
//
//    cout<<"Insert New Record";
//
//    cout << endl;
//
//    cout << "Enter The Following Items" << endl;
//
//    cout << "Name  ";
//
//    cin >> emp[i].name;
//
//    cout << "Code  ";
//
//    cin >> emp[i].code;
//
//    cout << "Designation  ";
//
//    cin >> emp[i].designation;
//
//    cout << "Years of Experience  ";
//
//    cin >> emp[i].exp;
//
//    cout << "Age  ";
//
//    cin >> emp[i].age;
//
//    cout << endl << endl;
//
//    cout << "going to main menu";
//
//    Sleep(500);
//
//
//}

void insert() {
    system("cls");
    cout << "Insert New Record" << endl;

    if (num >= max) {
        cout << "Error: The table is full, cannot insert more records." << endl;
        Sleep(2000); // Delay for 2 seconds
        return;
    }

    cout << "Enter The Following Items" << endl;

    int newCode;
    bool codeExists;
    do {
        codeExists = false;
        cout << "Name (up to 20 characters): ";
        cin.ignore(); // Xóa bộ nhớ đệm
        string inputName;
        getline(cin, inputName);

        // Kiểm tra độ dài tên và yêu cầu nhập lại nếu tên quá dài
        if (inputName.length() > 20) {
            cout << "Name is too long. Please enter a name up to 20 characters." << endl;
        } else {
            // Sao chép tên vào cấu trúc emp[]
            strncpy(emp[num].name, inputName.c_str(), sizeof(emp[num].name));
            emp[num].name[sizeof(emp[num].name) - 1] = '\0';
            break; // Kết thúc vòng lặp khi tên hợp lệ
        }
    } while (true);

    do {
        codeExists = false;
        cout << "Code: ";
        cin >> newCode;

        // Kiểm tra xem mã đã tồn tại trong danh sách emp[] chưa
        for (int i = 0; i < num; i++) {
            if (emp[i].code == newCode) {
                codeExists = true;
                break;
            }
        }

        if (codeExists) {
            cout << "This code is already exist, enter another code: ";
        } else {
            emp[num].code = newCode;
        }
    } while (codeExists);

    cout << "Designation: ";
    cin >> emp[num].designation;
    cout << "Years of Experience: ";
    cin >> emp[num].exp;
    cout << "Age: ";
    cin >> emp[num].age;
    num++;

    cout << endl << "Going to the main menu" << endl;
    Sleep(500);
}


void deletes()

{

    system("cls");

    int code;

    int check;

    cout<<"Delete An Entry";

    cout << endl;

    cout << "Enter An JobCode To Delete That Entry  ";

    cin >> code;

    int i;

    for (i = 0; i <= num - 1; i++)

    {

        if (emp[i].code == code)

        {

            check = i;

        }

    }

    for (i = 0; i <= num - 1; i++)

    {

        if (i == check)

        {

            continue;

        }

        else

        {

            if (i > check)

            {

                tempemp[i - 1] = emp[i];

            }

            else

            {

                tempemp[i] = emp[i];

            }

        }

    }

    num--;


    for (i = 0; i <= num - 1; i++)

    {

        emp[i] = tempemp[i];

    }

}


void edit()

{

    system("cls");

    int jobcode;


    cout<<"          Edit An Entry           ";

    cout << endl;

    cout << endl;

    int i;

    void editmenu();

    void editname(int);

    void editcode(int);

    void editdes(int);

    void editexp(int);

    void editage(int);

    char option;


    cout << "Enter An jobcode To Edit An Entry----  ";

    cin >> jobcode;

    editmenu();

    for (i = 0; i <= num - 1; i++)

    {

        if (emp[i].code == jobcode)

        {


            while ((option = cin.get()) != 'q')

            {

                switch (option)

                {

                case 'n':

                    editname(i);

                    break;

                case 'c':

                    editcode(i);

                    break;

                case 'd':

                    editdes(i);

                    break;

                case 'e':

                    editexp(i);

                    break;

                case 'a':

                    editage(i);

                    break;

                }

                editmenu();

            }

        }

    }

}

void editmenu()

{

    system("cls");

    cout << "        What Do You Want To edit"<<endl;

    cout << "          n--------->Name "<<endl;

    cout << "          c--------->Code "<<endl;

    cout << "          d--------->Designation"<<endl;

    cout << "          e--------->Experience "<<endl;

    cout << "          a--------->Age        "<<endl;

    cout << "              q----->QUIT                            "<<endl;

    cout << "   Options Please ---->>>  ";

}

void editname(int i) {
    int newCode;
    bool codeExists;
    cout << "Enter New Name (up to 20 characters): ";
    cin.ignore(); // Xóa bộ nhớ đệm
    string inputName;

    do {
        codeExists = false;
        getline(cin, inputName);

        // Kiểm tra độ dài tên và yêu cầu nhập lại nếu tên quá dài
        if (inputName.length() > 20) {
            cout << "Name is too long. Please enter a name up to 20 characters: ";
        } else {
            // Sao chép tên vào cấu trúc emp[]
            strncpy(emp[i].name, inputName.c_str(), sizeof(emp[i].name));
            emp[i].name[sizeof(emp[i].name) - 1] = '\0';
            break; // Kết thúc vòng lặp khi tên hợp lệ
        }
    } while (true);
}


//void editcode(int i)
//
//{
//
//    cout << "Enter New Job Code----->  ";
//
//    cin >> emp[i].code;
//
//}

void editcode(int i) {
    int newCode;
    bool codeExists;

    do {
        codeExists = false;
        cout << "Enter New Job Code: ";
        cin >> newCode;

        // Kiểm tra xem mã đã tồn tại trong danh sách emp[] (ngoại trừ mã của bản ghi hiện tại) chưa
        for (int j = 0; j < num; j++) {
            if (j != i && emp[j].code == newCode) {
                codeExists = true;
                break;
            }
        }

        if (codeExists) {
            cout << "This code is already exist, enter another code: ";
        } else {
            emp[i].code = newCode;
        }
    } while (codeExists);
}

void editdes(int i)

{

    cout << "enter new designation----->  ";

    cin >> emp[i].designation;

}

void editexp(int i)

{

    cout << "Enter new Years of Experience";

    cin >> emp[i].exp;

}

void editage(int i)

{

    cout << "Enter new Age ";

    cin >> emp[i].age;

}


void search()

{

    system("cls");


    cout<<"Welcome To Search Of Staff Database ";

    cout << endl;

    cout << endl;

    int jobcode;

    cout << "You Can Search Only By Jobcode Of the Staff"<<endl;

    cout << "Enter Code Of The Staff                    "<<endl;

    cin >> jobcode;

    for (int i = 0; i <= num - 1; i++)

    {

        if (emp[i].code == jobcode)

        {


            cout << "     Name     Code     Designation     Years(EXP)     Age "<<endl;

            cout << "     ------------------------------------------------------                                  "<<endl;

            cout << setw(13) << emp[i].name;

            cout << setw(6) << emp[i].code;

            cout << setw(15) << emp[i].designation;

            cout << setw(10) << emp[i].exp;

            cout << setw(15) << emp[i].age;

            cout << endl;

        }


    }

    cout << "going to main menu";

    getch();



}

void heapify(struct employee arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].code > arr[largest].code)
        largest = left;

    if (right < n && arr[right].code > arr[largest].code)
        largest = right;

    if (largest != i) {
        struct employee temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(struct employee arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        struct employee temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}


void sort()

{

    system("cls");

    cout<<"Sort The Databse By JobCode";

    void sortmenu();

    void sortname();

    void sortcode();

    void sortdes();

    void sortexp();

    char option;

    void sortage();


    cout << endl;

    cout << endl;

    sortmenu();

    while ((option = cin.get()) != 'q')

    {

        switch (option)

        {

        case 'n':

            sortname();

            break;

        case 'c':

            sortcode();

            break;

        case 'd':

            sortdes();

            break;

        case 'e':

            sortexp();

            break;

        case 'a':

            sortage();

            break;

        }

        sortmenu();

    }

}


void sortmenu()

{

    system("cls");

    cout << "          Sort By:          "<<endl;

    cout << "          n--------->Name         "<<endl;

    cout << "          c--------->Code         "<<endl;

    cout << "          d--------->Designation  "<<endl;

    cout << "          e--------->Experience   "<<endl;

    cout << "          a--------->Age          "<<endl;

    cout << "                               q----->QUIT            "<<endl;

    cout << "   Options Please ---->>>  ";
}




void sortname()

{

    system("cls");

    int i, j;

    struct employee temp[max];

    for (i = 0; i <= num - 1; i++)

    {

        sortemp1[i] = emp[i];

    }

    for (i = 0; i <= num - 1; i++)

    {

        for (j = 0; j <= num - 1; j++)

        {

            if (strcmp(sortemp1[i].name, sortemp1[j].name) <= 0)

            {

                temp[i] = sortemp1[i];

                sortemp1[i] = sortemp1[j];

                sortemp1[j] = temp[i];

            }

        }

    }


    for (i = 0; i <= num - 1; i++)

    {


        cout << "     Name     Code     Designation     Years(EXP)     Age "<<endl;

        cout << "     ------------------------------------------------------                                  "<<endl;

        for (i = 0; i <= num - 1; i++)

        {

            cout << setw(13) << sortemp1[i].name;

            cout << setw(6) << sortemp1[i].code;

            cout << setw(15) << sortemp1[i].designation;

            cout << setw(10) << sortemp1[i].exp;

            cout << setw(15) << sortemp1[i].age;

            cout << endl;

        }

        cout << "Press Any Key To Go Back";

        getch();


    }
}


//void sortcode()
//
//{
//
//    system("cls");
//
//    int i, j;
//
//    struct employee temp[max];
//
//    for (i = 0; i <= num - 1; i++)
//
//    {
//
//        sortemp1[i] = emp[i];
//
//    }
//
//    for (i = 0; i <= num - 1; i++)
//
//    {
//
//        for (j = 0; j <= num - 1; j++)
//
//        {
//
//            if (sortemp1[i].code < sortemp1[j].code)
//
//            {
//
//                temp[i] = sortemp1[i];
//
//                sortemp1[i] = sortemp1[j];
//
//                sortemp1[j] = temp[i];
//
//            }
//
//        }
//
//    }
//
//
//    for (i = 0; i <= num - 1; i++)
//
//    {
//
//
//        cout << "     Name     Code     Designation     Years(EXP)     Age "<<endl;
//
//        cout << "     ------------------------------------------------------                                  "<<endl;
//
//        for (i = 0; i <= num - 1; i++)
//
//        {
//
//            cout << setw(13) << sortemp1[i].name;
//
//            cout << setw(6) << sortemp1[i].code;
//
//            cout << setw(15) << sortemp1[i].designation;
//
//            cout << setw(10) << sortemp1[i].exp;
//
//            cout << setw(15) << sortemp1[i].age;
//
//            cout << endl;
//
//        }
//
//        cout << "Press Any Key To Go Back";
//
//        getch();
//
//
//    }
//}

void sortcode() {
    system("cls");
    struct employee temp[max];
    for (int i = 0; i < num; i++) {
        temp[i] = emp[i];
    }

    heapSort(temp, num);

    cout << "     Name     Code     Designation     Years(EXP)     Age " << endl;
    cout << "     ------------------------------------------------------" << endl;

    for (int i = 0; i < num; i++) {
        cout << setw(13) << temp[i].name;
        cout << setw(6) << temp[i].code;
        cout << setw(15) << temp[i].designation;
        cout << setw(10) << temp[i].exp;
        cout << setw(15) << temp[i].age;
        cout << endl;
    }

    cout << "Press Any Key To Go Back";
    getch();
}

void sortdes()

{

    system("cls");

    int i, j;

    struct employee temp[max];

    for (i = 0; i <= num - 1; i++)

    {

        sortemp1[i] = emp[i];

    }

    for (i = 0; i <= num - 1; i++)

    {

        for (j = 0; j <= num - 1; j++)

        {

            if (strcmp(sortemp1[i].designation, sortemp1[j].designation) <= 0)

            {

                temp[i] = sortemp1[i];

                sortemp1[i] = sortemp1[j];

                sortemp1[j] = temp[i];

            }

        }

    }


    for (i = 0; i <= num - 1; i++)

    {


        cout << "     Name     Code     Designation     Years(EXP)     Age"<<endl;

        cout << "     ------------------------------------------------------                                 "<<endl;

        for (i = 0; i <= num - 1; i++)

        {

            cout << setw(13) << sortemp1[i].name;

            cout << setw(6) << sortemp1[i].code;

            cout << setw(15) << sortemp1[i].designation;

            cout << setw(10) << sortemp1[i].exp;

            cout << setw(15) << sortemp1[i].age;

            cout << endl;

        }

        cout << "Press Any Key To Go Back";

        getch();


    }
}


//void sortage()
//
//{
//
//    system("cls");
//
//    int i, j;
//
//    struct employee temp[max];
//
//    for (i = 0; i <= num - 1; i++)
//
//    {
//
//        sortemp1[i] = emp[i];
//
//    }
//
//    for (i = 0; i <= num - 1; i++)
//
//    {
//
//        for (j = 0; j <= num - 1; j++)
//
//        {
//
//            if (sortemp1[i].age < sortemp1[j].age)
//
//            {
//
//                temp[i] = sortemp1[i];
//
//                sortemp1[i] = sortemp1[j];
//
//                sortemp1[j] = temp[i];
//
//            }
//
//        }
//
//    }
//
//
//    for (i = 0; i <= num - 1; i++)
//
//    {
//
//
//        cout << "     Name     Code     Designation     Years(EXP)     Age"<<endl;
//
//        cout << "     ------------------------------------------------------                                 "<<endl;
//
//        for (i = 0; i <= num - 1; i++)
//
//        {
//
//            cout << setw(13) << sortemp1[i].name;
//
//            cout << setw(6) << sortemp1[i].code;
//
//            cout << setw(15) << sortemp1[i].designation;
//
//            cout << setw(10) << sortemp1[i].exp;
//
//            cout << setw(15) << sortemp1[i].age;
//
//            cout << endl;
//
//        }
//
//        cout << "Press Any Key To Go Back";
//
//        getch();
//
//
//    }
//}

void heapifyAge(struct employee arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].age > arr[largest].age)
        largest = left;

    if (right < n && arr[right].age > arr[largest].age)
        largest = right;

    if (largest != i) {
        struct employee temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapifyAge(arr, n, largest);
    }
}

void heapSortAge(struct employee arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyAge(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        struct employee temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapifyAge(arr, i, 0);
    }
}

void sortage() {
    system("cls");
    struct employee temp[max];
    for (int i = 0; i < num; i++) {
        temp[i] = emp[i];
    }

    heapSortAge(temp, num);

    cout << "     Name     Code     Designation     Years(EXP)     Age" << endl;
    cout << "     ------------------------------------------------------" << endl;

    for (int i = 0; i < num; i++) {
        cout << setw(13) << temp[i].name;
        cout << setw(6) << temp[i].code;
        cout << setw(15) << temp[i].designation;
        cout << setw(10) << temp[i].exp;
        cout << setw(15) << temp[i].age;
        cout << endl;
    }

    cout << "Press Any Key To Go Back";
    getch();
}

//void sortexp()
//
//{
//
//    system("cls");
//
//    int i, j;
//
//    struct employee temp[max];
//
//    for (i = 0; i <= num - 1; i++)
//
//    {
//
//        sortemp1[i] = emp[i];
//
//    }
//
//    for (i = 0; i <= num - 1; i++)
//
//    {
//
//        for (j = 0; j <= num - 1; j++)
//
//        {
//
//            if (sortemp1[i].exp < sortemp1[j].exp)
//
//            {
//
//                temp[i] = sortemp1[i];
//
//                sortemp1[i] = sortemp1[j];
//
//                sortemp1[j] = temp[i];
//
//            }
//
//        }
//
//    }
//
//
//    for (i = 0; i <= num - 1; i++)
//
//    {
//
//
//        cout << "     Name     Code     Designation     Years(EXP)     Age "<<endl;
//
//        cout << "  ------------------------------------------------------ "<<endl;
//
//        for (i = 0; i <= num - 1; i++)
//
//        {
//
//            cout << setw(13) << sortemp1[i].name;
//
//            cout << setw(6) << sortemp1[i].code;
//
//            cout << setw(15) << sortemp1[i].designation;
//
//            cout << setw(10) << sortemp1[i].exp;
//
//            cout << setw(15) << sortemp1[i].age;
//
//            cout << endl;
//
//        }
//
//        cout << "Press Any Key To Go Back";
//
//        getch();
//
//
//    };
//}

void heapifyExp(struct employee arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].exp > arr[largest].exp)
        largest = left;

    if (right < n && arr[right].exp > arr[largest].exp)
        largest = right;

    if (largest != i) {
        struct employee temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapifyExp(arr, n, largest);
    }
}

void heapSortExp(struct employee arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyExp(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        struct employee temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapifyAge(arr, i, 0);
    }
}

void sortexp() {
    system("cls");
    struct employee temp[max];
    for (int i = 0; i < num; i++) {
        temp[i] = emp[i];
    }

    heapSortExp(temp, num);

    cout << "     Name     Code     Designation     Years(EXP)     Age" << endl;
    cout << "     ------------------------------------------------------" << endl;

    for (int i = 0; i < num; i++) {
        cout << setw(13) << temp[i].name;
        cout << setw(6) << temp[i].code;
        cout << setw(15) << temp[i].designation;
        cout << setw(10) << temp[i].exp;
        cout << setw(15) << temp[i].age;
        cout << endl;
    }

    cout << "Press Any Key To Go Back";
    getch();
}
