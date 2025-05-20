//FormAI DATASET v1.0 Category: Database simulation ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DBSIZE 100   //Maximum number of records in the Database

//The structure for storing Records in the Database
struct Record {
    int id;
    char name[20];
    char address[50];
    char phone[15];
};

//The main Database, which is an Array of Records.
struct Record database[DBSIZE];

//The function to add a Record to the Database
void addRecord(int id, char* name, char* address, char* phone) {
    int i;
    //Check if the ID already exists in the Database
    for(i=0;i<DBSIZE;i++) {
        if(database[i].id==id) {
            printf("\nRecord with ID %d already exists! Cannot add another Record with same ID.\n",id);
            return;
        }
    }
    //Find the first empty spot in the Database to add the Record
    for(i=0;i<DBSIZE;i++) {
        if(database[i].id==0) {
            database[i].id=id;
            strcpy(database[i].name,name);
            strcpy(database[i].address,address);
            strcpy(database[i].phone,phone);
            printf("\nRecord added successfully.\n");
            return;
        }
    }
    //If no empty spots found in the Database
    printf("\nCannot add Record. Database is full!\n");
}

//The function to search for a Record in the Database using ID.
void searchRecord(int id) {
    int i;
    for(i=0;i<DBSIZE;i++) {
        if(database[i].id==id) {
            printf("\nRecord found!\nID: %d\nName: %s\nAddress: %s\nPhone: %s\n",database[i].id,database[i].name,database[i].address,database[i].phone);
            return;
        }
    }
    printf("\nRecord not found!\n");
}

//The function to display all Records in the Database.
void displayRecords() {
    int i;
    for(i=0;i<DBSIZE;i++) {
        if(database[i].id!=0) {
            printf("\nID: %d\nName: %s\nAddress: %s\nPhone: %s\n",database[i].id,database[i].name,database[i].address,database[i].phone);
        }
    }
}

//The function to delete a Record from the Database using ID.
void deleteRecord(int id) {
    int i;
    for(i=0;i<DBSIZE;i++) {
        if(database[i].id==id) {
            database[i].id=0;
            strcpy(database[i].name,"");
            strcpy(database[i].address,"");
            strcpy(database[i].phone,"");
            printf("\nRecord with ID %d deleted successfully.\n",id);
            return;
        }
    }
    printf("\nRecord not found!\n");
}

//The main function, which accepts user commands and acts accordingly.
int main() {
    printf("\nWelcome to the Database simulator!\n");
    char choice=' ';
    while(choice!='5') {
        printf("\nSelect an option from the following:\n1. Add a Record\n2. Search a Record\n3. Display all Records\n4. Delete a Record\n5. Exit\nYour choice: ");
        scanf(" %c",&choice);
        switch(choice) {
            case '1':
                {
                    int id;
                    char name[20];
                    char address[50];
                    char phone[15];
                    printf("\nEnter the ID: ");
                    scanf("%d",&id);
                    printf("Enter the Name: ");
                    scanf("%s",name);
                    printf("Enter the Address: ");
                    scanf(" %[^\n]",address);
                    printf("Enter the Phone: ");
                    scanf("%s",phone);
                    addRecord(id,name,address,phone);
                    break;
                }
            case '2':
                {
                    int id;
                    printf("\nEnter the ID to search: ");
                    scanf("%d",&id);
                    searchRecord(id);
                    break;
                }
            case '3':
                {
                    displayRecords();
                    break;
                }
            case '4':
                {
                    int id;
                    printf("\nEnter the ID to delete: ");
                    scanf("%d",&id);
                    deleteRecord(id);
                    break;
                }
            case '5':
                {
                    printf("\nExiting Database simulator...\n");
                    break;
                }
            default:
                {
                    printf("\nInvalid option selected!\n");
                    break;
                }
        }
    }
    return 0;
}