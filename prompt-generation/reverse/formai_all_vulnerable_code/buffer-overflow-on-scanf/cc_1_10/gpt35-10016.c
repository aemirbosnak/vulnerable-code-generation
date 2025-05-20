//FormAI DATASET v1.0 Category: Banking Record System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold banking records
struct BankRecord {
    int account_no;
    char name[50];
    float balance;
};

// Function to display menu
void displayMenu() {
    printf("\n\nWelcome to Banking Record System\n");
    printf("1. Add Record\n");
    printf("2. Search Record\n");
    printf("3. Update Record\n");
    printf("4. Delete Record\n");
    printf("5. Display All Records\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

// Function to add a new record
void addRecord(struct BankRecord *records, int *num_of_records) {

    printf("\nEnter Account Number: ");
    scanf("%d", &records[*num_of_records].account_no);

    printf("Enter Name: ");
    scanf("%s", records[*num_of_records].name);

    printf("Enter Balance: ");
    scanf("%f", &records[*num_of_records].balance);

    printf("\nRecord added successfully\n");
    (*num_of_records)++;
}

// Function to search for a record
void searchRecord(struct BankRecord *records, int num_of_records) {

    int account_no;
    int found = 0;

    printf("\nEnter Account Number to search: ");
    scanf("%d", &account_no);

    for(int i=0;i<num_of_records;i++) {
        if(records[i].account_no == account_no) {
            printf("\nRecord found:\n");
            printf("Account Number: %d\n", records[i].account_no);
            printf("Name: %s\n", records[i].name);
            printf("Balance: %.2f\n", records[i].balance);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("\nRecord not found\n");
    }
}

// Function to update a record
void updateRecord(struct BankRecord *records, int num_of_records) {

    int account_no;
    int found = 0;

    printf("\nEnter Account Number to update: ");
    scanf("%d", &account_no);

    for(int i=0;i<num_of_records;i++) {
        if(records[i].account_no == account_no) {
            printf("\nCurrent Record:\n");
            printf("Account Number: %d\n", records[i].account_no);
            printf("Name: %s\n", records[i].name);
            printf("Balance: %.2f\n", records[i].balance);

            printf("\nEnter New Name: ");
            scanf("%s", records[i].name);

            printf("Enter New Balance: ");
            scanf("%f", &records[i].balance);

            printf("\nRecord updated successfully\n");
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("\nRecord not found\n");
    }
}

// Function to delete a record
void deleteRecord(struct BankRecord *records, int *num_of_records) {

    int account_no;
    int found = 0;

    printf("\nEnter Account Number to delete: ");
    scanf("%d", &account_no);

    for(int i=0;i<*num_of_records;i++) {
        if(records[i].account_no == account_no) {
            for(int j=i;j<*num_of_records-1;j++) {
                records[j] = records[j+1];
            }

            printf("\nRecord deleted successfully\n");
            found = 1;
            (*num_of_records)--;
            break;
        }
    }

    if(!found) {
        printf("\nRecord not found\n");
    }
}

// Function to display all records
void displayAllRecords(struct BankRecord *records, int num_of_records) {

    printf("\nAll Records:\n");
    for(int i=0;i<num_of_records;i++) {
        printf("Account Number: %d\n", records[i].account_no);
        printf("Name: %s\n", records[i].name);
        printf("Balance: %.2f\n", records[i].balance);
        printf("\n");
    }
}

int main() {

    struct BankRecord records[100];
    int num_of_records = 0;
    int choice;

    while(1) {
        displayMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addRecord(records, &num_of_records);
                break;
            case 2:
                searchRecord(records, num_of_records);
                break;
            case 3:
                updateRecord(records, num_of_records);
                break;
            case 4:
                deleteRecord(records, &num_of_records);
                break;
            case 5:
                displayAllRecords(records, num_of_records);
                break;
            case 6:
                printf("\nExiting...");
                exit(0);
            default:
                printf("\nInvalid Choice... Try Again");
        }
    }

    return 0;
}