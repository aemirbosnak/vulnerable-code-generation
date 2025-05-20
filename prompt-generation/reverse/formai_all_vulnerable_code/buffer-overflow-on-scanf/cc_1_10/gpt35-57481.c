//FormAI DATASET v1.0 Category: Banking Record System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BankRecord {
    char name[50];
    int accountNumber;
    float balance;
} BankRecord;

void addRecord(BankRecord* records, int* numOfRecords);
void displayAllRecords(BankRecord* records, int numOfRecords);
void updateRecord(BankRecord* records, int numOfRecords);
void deleteRecord(BankRecord* records, int* numOfRecords);

int main() {
    BankRecord records[100];
    int numOfRecords = 0;
    int choice;

    do {
        printf("Bank Record System\n");
        printf("1. Add Record\n");
        printf("2. Display All Records\n");
        printf("3. Update Record\n");
        printf("4. Delete Record\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addRecord(records, &numOfRecords);
                break;
            case 2:
                displayAllRecords(records, numOfRecords);
                break;
            case 3:
                updateRecord(records, numOfRecords);
                break;
            case 4:
                deleteRecord(records, &numOfRecords);
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 0);

    return 0;
}

void addRecord(BankRecord* records, int* numOfRecords) {
    printf("Enter name: ");
    scanf("%s", records[*numOfRecords].name);

    printf("Enter account number: ");
    scanf("%d", &records[*numOfRecords].accountNumber);

    printf("Enter balance: ");
    scanf("%f", &records[*numOfRecords].balance);

    (*numOfRecords)++;
    printf("Record added successfully.\n");
}

void displayAllRecords(BankRecord* records, int numOfRecords) {
    if(numOfRecords == 0) {
        printf("No records found.\n");
        return;
    }

    printf("Name\tAccount Number\tBalance\n");
    for(int i = 0; i < numOfRecords; i++) {
        printf("%s\t%d\t%.2f\n", records[i].name, records[i].accountNumber, records[i].balance);
    }
}

void updateRecord(BankRecord* records, int numOfRecords) {
    int accountNumber, choice, index = -1;

    if(numOfRecords == 0) {
        printf("No records found to update.\n");
        return;
    }

    printf("Enter account number to update: ");
    scanf("%d", &accountNumber);

    for(int i = 0; i < numOfRecords; i++) {
        if(records[i].accountNumber == accountNumber) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Record not found.\n");
        return;
    }

    printf("Record found.\n");
    printf("1. Update name\n");
    printf("2. Update balance\n");
    printf("0. Cancel\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter new name: ");
            scanf("%s", records[index].name);
            printf("Record updated successfully.\n");
            break;
        case 2:
            printf("Enter new balance: ");
            scanf("%f", &records[index].balance);
            printf("Record updated successfully.\n");
            break;
        case 0:
            printf("Update cancelled.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }
}

void deleteRecord(BankRecord* records, int* numOfRecords) {
    int accountNumber, index = -1;

    if(*numOfRecords == 0) {
        printf("No records found to delete.\n");
        return;
    }

    printf("Enter account number to delete: ");
    scanf("%d", &accountNumber);

    for(int i = 0; i < *numOfRecords; i++) {
        if(records[i].accountNumber == accountNumber) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Record not found.\n");
        return;
    }

    for(int i = index; i < *numOfRecords - 1; i++) {
        strcpy(records[i].name, records[i+1].name);
        records[i].accountNumber = records[i+1].accountNumber;
        records[i].balance = records[i+1].balance;
    }

    (*numOfRecords)--;
    printf("Record deleted successfully.\n");
}