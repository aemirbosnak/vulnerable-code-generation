//FormAI DATASET v1.0 Category: Banking Record System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define a struct for bank record
typedef struct {
    char name[50];
    int acc_no;
    float balance;
}Bank_Record;

//Function to add new record
void AddNewRecord(Bank_Record records[], int *count) {
    //Prompt user for record details
    printf("Enter name: ");
    scanf("%s", records[*count].name);
    printf("Enter account number: ");
    scanf("%d", &records[*count].acc_no);
    printf("Enter balance: ");
    scanf("%f", &records[*count].balance);
    *count += 1; //increment record count
    printf("Record added successfully!\n");
}

//Function to search for record by account number
void SearchRecord(Bank_Record records[], int count, int acc_no) {
    for(int i=0; i<count; i++) {
        if(records[i].acc_no == acc_no) { //if account number matches
            printf("Name: %s\n", records[i].name);
            printf("Account Number: %d\n", records[i].acc_no);
            printf("Balance: $%.2f\n", records[i].balance);
            return; //exit function
        }
    }
    //If record not found
    printf("Record not found!\n");
}

//Function to display all records
void DisplayRecords(Bank_Record records[], int count) {
    if(count == 0) { //if no records present
        printf("No records found!\n");
        return;
    }
    printf("----Bank Records----\n");
    for(int i=0; i<count; i++) {
        printf("Name: %s\n", records[i].name);
        printf("Account Number: %d\n", records[i].acc_no);
        printf("Balance: $%.2f\n", records[i].balance);
        printf("--------------------\n");
    }
}

int main() {
    Bank_Record records[100]; //Array of bank records
    int count = 0; //Count of records

    //Menu-driven program
    while(1) {
        int choice;
        printf("\n1. Add new record\n");
        printf("2. Search record\n");
        printf("3. Display all records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                AddNewRecord(records, &count);
                break;
            case 2: {
                int acc_no;
                printf("Enter account number: ");
                scanf("%d", &acc_no);
                SearchRecord(records, count, acc_no);
                break;
            }
            case 3:
                DisplayRecords(records, count);
                break;
            case 4:
                printf("Thank you for using our system!\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}