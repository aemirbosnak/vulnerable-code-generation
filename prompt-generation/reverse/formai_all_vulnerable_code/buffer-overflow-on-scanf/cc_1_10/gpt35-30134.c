//FormAI DATASET v1.0 Category: Banking Record System ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure to store banking record
struct bank_record{
    char name[50];
    long int account_number;
    float balance;
}customer[100];

int count=0;

//Function to add a new record
void addRecord(){
    char name[50];
    long int account_number;
    float balance;

    printf("Enter customer name: ");
    scanf("%s", name);

    printf("Enter account number: ");
    scanf("%ld", &account_number);

    printf("Enter balance: ");
    scanf("%f", &balance);

    //Add new record to the database
    strcpy(customer[count].name, name);
    customer[count].account_number = account_number;
    customer[count].balance = balance;

    count++;
    printf("\nRecord added successfully!\n");
}

//Function to display all the records in the database
void displayRecords(){
    int i;
    printf("Name\tAccount Number\tBalance\n");
    for(i=0; i<count; i++){
        printf("%s\t%ld\t%.2f\n", customer[i].name, customer[i].account_number, customer[i].balance);
    }
}

//Function to search for a record by account number
void searchByAccount(){
    long int account_number;
    int i, flag=0;

    printf("Enter account number to search: ");
    scanf("%ld", &account_number);

    //Search for the record in the database
    for(i=0; i<count; i++){
        if(customer[i].account_number == account_number){
            printf("Name: %s\n", customer[i].name);
            printf("Balance: %.2f\n", customer[i].balance);
            flag = 1;
            break;
        }
    }

    if(flag == 0){
        printf("Record not found.\n");
    }
}

//Function to delete a record by account number
void deleteRecord(){
    long int account_number;
    int i, j, flag=0;

    printf("Enter account number to delete: ");
    scanf("%ld", &account_number);

    //Search for the record in the database
    for(i=0; i<count; i++){
        if(customer[i].account_number == account_number){
            for(j=i; j<count-1; j++){
                //Shift all other records up by 1
                strcpy(customer[j].name, customer[j+1].name);
                customer[j].account_number = customer[j+1].account_number;
                customer[j].balance = customer[j+1].balance;
            }
            count--;
            flag = 1;
            printf("\nRecord deleted successfully!\n");
            break;
        }
    }

    if(flag == 0){
        printf("Record not found.\n");
    }
}

int main(){
    int choice;

    do{
        printf("Welcome to the Banking Record System\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search By Account Number\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: addRecord();
                    break;

            case 2: displayRecords();
                    break;

            case 3: searchByAccount();
                    break;

            case 4: deleteRecord();
                    break;

            case 5: exit(0);
                    break;

            default: printf("Invalid choice.\n");
                    break;
        }

    }while(choice != 5);

    return 0;
}