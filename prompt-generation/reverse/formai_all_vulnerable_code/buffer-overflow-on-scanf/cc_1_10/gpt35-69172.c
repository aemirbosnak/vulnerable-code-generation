//FormAI DATASET v1.0 Category: Banking Record System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

struct Record {
    int accountNumber;
    char name[50];
    float balance;
};

struct Record records[MAX_RECORDS];
int numRecords = 0;

void addRecord() {
    if (numRecords >= MAX_RECORDS) {
        printf("Error: Maximum number of records reached.\n");
        return;
    }

    int accountNumber;
    char name[50];
    float balance;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter name: ");
    getchar(); // Clear newline from buffer
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline from name string
    printf("Enter balance: ");
    scanf("%f", &balance);

    struct Record newRecord = { accountNumber, name, balance };
    records[numRecords++] = newRecord;
    printf("Record added.\n");
}

void printRecords() {
    if (numRecords == 0) {
        printf("No records to display.\n");
        return;
    }

    for (int i = 0; i < numRecords; i++) {
        struct Record record = records[i];
        printf("Account Number: %d\n", record.accountNumber);
        printf("Name: %s\n", record.name);
        printf("Balance: %.2f\n", record.balance);
    }
}

void searchRecordByName() {
    char query[50];
    printf("Enter name to search: ");
    getchar(); // Clear newline from buffer
    fgets(query, sizeof(query), stdin);
    query[strcspn(query, "\n")] = '\0'; // Remove newline from query string

    for (int i = 0; i < numRecords; i++) {
        struct Record record = records[i];
        if (strcmp(record.name, query) == 0) {
            printf("Record found.\n");
            printf("Account Number: %d\n", record.accountNumber);
            printf("Name: %s\n", record.name);
            printf("Balance: %.2f\n", record.balance);
            return;
        }
    }

    printf("Record not found.\n");
}

int main() {
    int choice;

    do {
        printf("========== Banking Record System ==========\n");
        printf("1. Add Record\n");
        printf("2. Print Records\n");
        printf("3. Search Record by Name\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                printRecords();
                break;
            case 3:
                searchRecordByName();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}