//FormAI DATASET v1.0 Category: Banking Record System ; Style: modular
#include<stdio.h>
#include<string.h>

//function declarations
void addRecord();
void viewRecord();
void searchRecord();

//global variables and constants
#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50
struct Record{
    int accountNo;
    char name[MAX_NAME_LENGTH];
    float balance;
};
struct Record records[MAX_RECORDS];
int numRecords = 0;

int main(){
    int choice;
    do{
        printf("Banking Record System\n");
        printf("-----------------------\n");
        printf("1. Add record\n");
        printf("2. View all records\n");
        printf("3. Search record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addRecord();
                break;
            case 2:
                viewRecord();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }while(choice != 4);
    return 0;
}

//adds a new record to the system
void addRecord(){
    if(numRecords < MAX_RECORDS){
        struct Record newRecord;
        printf("Enter account number: ");
        scanf("%d", &newRecord.accountNo);
        printf("Enter name: ");
        getchar(); //consume newline character
        fgets(newRecord.name, MAX_NAME_LENGTH, stdin);
        newRecord.name[strcspn(newRecord.name, "\n")] = 0; //remove newline character
        printf("Enter balance: ");
        scanf("%f", &newRecord.balance);
        records[numRecords++] = newRecord;
        printf("Record added successfully!\n");
    }
    else{
        printf("Maximum number of records reached!\n");
    }
}

//displays all records in the system
void viewRecord(){
    if(numRecords == 0){
        printf("No records found!\n");
    }
    else{
        printf("Account No.\tName\tBalance\n");
        printf("--------------------------------------\n");
        for(int i=0; i<numRecords; i++){
            printf("%d\t\t%s\t%.2f\n", records[i].accountNo, records[i].name, records[i].balance);
        }
    }
}

//searches for a record by account number
void searchRecord(){
    if(numRecords == 0){
        printf("No records found!\n");
    }
    else{
        int accountNo, found = 0;
        printf("Enter account number to search: ");
        scanf("%d", &accountNo);
        for(int i=0; i<numRecords; i++){
            if(records[i].accountNo == accountNo){
                printf("Account No.\tName\tBalance\n");
                printf("--------------------------------------\n");
                printf("%d\t\t%s\t%.2f\n", records[i].accountNo, records[i].name, records[i].balance);
                found = 1;
                break;
            }
        }
        if(!found){
            printf("Record not found!\n");
        }
    }
}