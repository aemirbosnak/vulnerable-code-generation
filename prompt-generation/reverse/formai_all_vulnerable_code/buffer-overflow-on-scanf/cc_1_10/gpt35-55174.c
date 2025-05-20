//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining Constants
#define MAX_MEDICINE_NAME 50
#define MAX_COMPANY_NAME 50
#define MAX_STOCK 1000

// Defining Global Variables
int countMedicine = 0;
int countCompany = 0;

// Defining Structures
typedef struct medicine{
    char name[MAX_MEDICINE_NAME];
    int stock;
    float price;
    char company[MAX_COMPANY_NAME];
    int code;
}medicine;

typedef struct company{
    char name[MAX_COMPANY_NAME];
    char address[100];
    char email[100];
    char contact[20];
}company;

// Function Prototypes
void addMedicine(medicine *med);
void addCompany(company *comp);
void updateStock(medicine *med);
void displayAll(medicine *med);
void searchByMedicine(medicine *med);
void searchByCompany(medicine *med);
void deleteMedicine(medicine *med);

// Main Function
int main(){
    int choice, i, flag = 0;

    // Defining Structure Variables
    medicine med[MAX_STOCK];
    company comp[100];

    // Menu
    while(1){
        printf("\n\n\tMEDICAL STORE MANAGEMENT SYSTEM");
        printf("\n\t================================");
        printf("\n\n\t1. Add Medicine");
        printf("\n\t2. Add Company");
        printf("\n\t3. Update Stock");
        printf("\n\t4. Display All Medicines");
        printf("\n\t5. Search by Medicine");
        printf("\n\t6. Search by Company");
        printf("\n\t7. Delete Medicine");
        printf("\n\t8. Exit");
        printf("\n\n\tEnter your choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addMedicine(&med[countMedicine]);
                countMedicine++;
                break;

            case 2:
                addCompany(&comp[countCompany]);
                countCompany++;
                break;

            case 3:
                updateStock(&med[0]);
                break;

            case 4:
                displayAll(&med[0]);
                break;

            case 5:
                searchByMedicine(&med[0]);
                break;

            case 6:
                searchByCompany(&med[0]);
                break;

            case 7:
                deleteMedicine(&med[0]);
                break;

            case 8:
                printf("\n\tExiting....\n");
                exit(0);
                break;

            default:
                printf("\n\tInvalid choice!");
        }
    }
}

// Functions

// Function to Add Medicine
void addMedicine(medicine *med){

    printf("\n\n\tAdd Medicine : ");

    // Setting Medicine Details
    printf("\n\tEnter Medicine Name : ");
    scanf("%s", med->name);
    printf("\tEnter Stock : ");
    scanf("%d", &med->stock);
    printf("\tEnter Price : ");
    scanf("%f", &med->price);
    printf("\tEnter Company Name : ");
    scanf("%s", med->company);
    printf("\tEnter Code : ");
    scanf("%d", &med->code);

    printf("\n\tMedicine Added Successfully!");
}

// Function to Add Company
void addCompany(company *comp){

    printf("\n\n\tAdd Company : ");

    // Setting Company Details
    printf("\n\tEnter Company Name : ");
    scanf("%s", comp->name);
    printf("\tEnter Address : ");
    scanf("%s", comp->address);
    printf("\tEnter Email : ");
    scanf("%s", comp->email);
    printf("\tEnter Contact : ");
    scanf("%s", comp->contact);

    printf("\n\tCompany Added Successfully!");
}

// Function to Update Stock
void updateStock(medicine *med){

    int code, stock, i, flag = 0;

    printf("\n\n\tUpdate Stock : ");

    // Asking for Medicine Code
    printf("\n\tEnter Medicine Code : ");
    scanf("%d", &code);

    // Searching for Medicine with Code
    for(i = 0; i < countMedicine; i++){
        if(med[i].code == code){
            flag = 1;
            printf("\n\tMedicine Found!");
            printf("\n\tMedicine Name : %s", med[i].name);
            printf("\n\tCurrent Stock : %d", med[i].stock);
            printf("\n\tEnter Additional Stock : ");
            scanf("%d", &stock);
            med[i].stock += stock;
            printf("\n\tStock Updated Successfully!");
            break;
        }
    }

    if(flag == 0)
        printf("\n\tMedicine not found!");


}

// Function to Display all Medicines
void displayAll(medicine *med){

    int i;

    printf("\n\n\tDisplaying All Medicines : \n");

    // Displaying all Medicines
    for(i = 0; i < countMedicine; i++){
        printf("\n\tMedicine Name : %s", med[i].name);
        printf("\n\tStock : %d", med[i].stock);
        printf("\n\tPrice : %.2f", med[i].price);
        printf("\n\tCompany Name : %s", med[i].company);
        printf("\n\tCode : %d", med[i].code);
        printf("\n");
    }
}

// Function to Search Medicine by Name
void searchByMedicine(medicine *med){

    char name[MAX_MEDICINE_NAME];
    int i, flag = 0;

    printf("\n\n\tSearch Medicine by Name : ");

    // Asking for Medicine Name
    printf("\n\tEnter Medicine Name : ");
    scanf("%s", name);

    // Searching for Medicine with Name
    for(i = 0; i < countMedicine; i++){
        if(strcmp(med[i].name, name) == 0){
            flag = 1;
            printf("\n\tMedicine Found!");
            printf("\n\tStock : %d", med[i].stock);
            printf("\n\tPrice : %.2f", med[i].price);
            printf("\n\tCompany Name : %s", med[i].company);
            printf("\n\tCode : %d", med[i].code);
            printf("\n");
        }
    }

    if(flag == 0)
        printf("\n\tMedicine not found!");

}

// Function to Search Medicine by Company Name
void searchByCompany(medicine *med){

    char company[MAX_COMPANY_NAME];
    int i, flag = 0;

    printf("\n\n\tSearch Medicine by Company Name : ");

    // Asking for Company Name
    printf("\n\tEnter Company Name : ");
    scanf("%s", company);

    // Searching for Medicines with Company Name
    for(i = 0; i < countMedicine; i++){
        if(strcmp(med[i].company, company) == 0){
            flag = 1;
            printf("\n\tMedicine Name : %s", med[i].name);
            printf("\n\tStock : %d", med[i].stock);
            printf("\n\tPrice : %.2f", med[i].price);
            printf("\n\tCode : %d", med[i].code);
            printf("\n");
        }
    }

    if(flag == 0)
        printf("\n\tNo Medicines found for Company : %s", company);

}

// Function to Delete Medicine
void deleteMedicine(medicine *med){

    int code, i, flag = 0;

    printf("\n\n\tDelete Medicine : ");

    // Asking for Medicine Code
    printf("\n\tEnter Medicine Code : ");
    scanf("%d", &code);

    // Searching for Medicine with Code
    for(i = 0; i < countMedicine; i++){
        if(med[i].code == code){
            flag = 1;
            printf("\n\tMedicine Found!");
            printf("\n\tMedicine Name : %s", med[i].name);
            printf("\n\tCurrent Stock : %d", med[i].stock);
            printf("\n\tPrice : %.2f", med[i].price);
            printf("\n\tCompany Name : %s", med[i].company);
            printf("\n\tCode : %d", med[i].code);
            printf("\n");
            for(; i < countMedicine - 1; i++)
                med[i] = med[i+1];
            countMedicine--;
            printf("\n\tMedicine Deleted Successfully!");
            break;
        }
    }

    if(flag == 0)
        printf("\n\tMedicine not found!");

}