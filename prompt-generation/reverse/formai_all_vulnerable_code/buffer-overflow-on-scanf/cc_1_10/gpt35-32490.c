//FormAI DATASET v1.0 Category: Banking Record System ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define RECORD_SIZE 50

typedef struct {
    int acc_number;
    char name[20];
    double balance;
} Record;

//Function prototypes
void addRecord(Record* bankRecords, int* numRecords);
void displayRecord(Record* bankRecords, int numRecords);
void searchRecord(Record* bankRecords, int numRecords);
void editRecord(Record* bankRecords, int numRecords);

int main() {
    Record* bankRecords;
    int numRecords = 0;
    char choice;

    do {
        printf("Banking Record System\n");
        printf("1. Add record\n");
        printf("2. Display record\n");
        printf("3. Search record\n");
        printf("4. Edit record\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
        case '1':
            addRecord(bankRecords, &numRecords);
            break;
        case '2':
            displayRecord(bankRecords, numRecords);
            break;
        case '3':
            searchRecord(bankRecords, numRecords);
            break;
        case '4':
            editRecord(bankRecords, numRecords);
            break;
        case '5':
            printf("Exiting program...");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != '5');

    free(bankRecords); //freeing allocated memory

    return 0;
}

void addRecord(Record* bankRecords, int* numRecords) {
    int i;
    if (*numRecords == 0) {
        bankRecords = (Record*)malloc(sizeof(Record) * RECORD_SIZE);
    }
    else {
        bankRecords = (Record*)realloc(bankRecords, sizeof(Record) * (*numRecords + RECORD_SIZE));
    }

    if (bankRecords == NULL) {
        printf("Memory allocation failed! Exiting program...\n");
        exit(1);
    }

    for (i = *numRecords; i < *numRecords + RECORD_SIZE; i++) {
        printf("Enter the account number: ");
        scanf("%d", &bankRecords[i].acc_number);

        printf("Enter the account holder name: ");
        scanf("%s", bankRecords[i].name);

        printf("Enter the account balance: ");
        scanf("%lf", &bankRecords[i].balance);
    }

    printf("%d record(s) added successfully.\n", RECORD_SIZE);
    *numRecords += RECORD_SIZE;
}

void displayRecord(Record* bankRecords, int numRecords) {
    int i;

    if (numRecords == 0) {
        printf("No records found.\n");
        return;
    }

    printf("Account Number\tAccount Holder Name\t\tAccount Balance\n");
    for (i = 0; i < numRecords; i++) {
        printf("%d\t\t%s\t\t\t%.2f\n", bankRecords[i].acc_number, bankRecords[i].name, bankRecords[i].balance);
    }
}

void searchRecord(Record* bankRecords, int numRecords) {
    int i, accNum, flag = 0;

    if (numRecords == 0) {
        printf("No records found.\n");
        return;
    }

    printf("Enter the account number to search: ");
    scanf("%d", &accNum);

    for (i = 0; i < numRecords; i++) {
        if (bankRecords[i].acc_number == accNum) {
            printf("Record found!\n");
            printf("Account Number\tAccount Holder Name\t\tAccount Balance\n");
            printf("%d\t\t%s\t\t\t%.2f\n", bankRecords[i].acc_number, bankRecords[i].name, bankRecords[i].balance);
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("Record not found.\n");
    }
}

void editRecord(Record* bankRecords, int numRecords) {
    int i, accNum, flag = 0;

    if (numRecords == 0) {
        printf("No records found.\n");
        return;
    }

    printf("Enter the account number to edit: ");
    scanf("%d", &accNum);

    for (i = 0; i < numRecords; i++) {
        if (bankRecords[i].acc_number == accNum) {
            printf("Account Number\tAccount Holder Name\t\tAccount Balance\n");
            printf("%d\t\t%s\t\t\t%.2f\n", bankRecords[i].acc_number, bankRecords[i].name, bankRecords[i].balance);

            printf("Enter the new account holder name: ");
            scanf("%s", bankRecords[i].name);

            printf("Enter the new account balance: ");
            scanf("%lf", &bankRecords[i].balance);

            printf("Record updated successfully.\n");
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("Record not found.\n");
    }
}