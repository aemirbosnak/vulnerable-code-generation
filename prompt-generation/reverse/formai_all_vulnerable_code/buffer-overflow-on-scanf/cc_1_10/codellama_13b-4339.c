//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store banking records
struct BankRecord {
    char name[50];
    char address[50];
    char accountNumber[50];
    float balance;
    time_t date;
};

// Function to add a new bank record
void addRecord(struct BankRecord *record) {
    // Get input from user
    printf("Enter name: ");
    scanf("%s", record->name);
    printf("Enter address: ");
    scanf("%s", record->address);
    printf("Enter account number: ");
    scanf("%s", record->accountNumber);
    printf("Enter balance: ");
    scanf("%f", &record->balance);
    record->date = time(NULL);
}

// Function to display all bank records
void displayAllRecords(struct BankRecord *records, int numRecords) {
    int i;
    for (i = 0; i < numRecords; i++) {
        printf("Name: %s\n", records[i].name);
        printf("Address: %s\n", records[i].address);
        printf("Account number: %s\n", records[i].accountNumber);
        printf("Balance: %f\n", records[i].balance);
        printf("Date: %s\n", ctime(&records[i].date));
        printf("\n");
    }
}

// Function to search for a specific bank record
void searchRecord(struct BankRecord *records, int numRecords, char *searchName) {
    int i;
    for (i = 0; i < numRecords; i++) {
        if (strcmp(records[i].name, searchName) == 0) {
            printf("Name: %s\n", records[i].name);
            printf("Address: %s\n", records[i].address);
            printf("Account number: %s\n", records[i].accountNumber);
            printf("Balance: %f\n", records[i].balance);
            printf("Date: %s\n", ctime(&records[i].date));
            return;
        }
    }
    printf("Record not found.\n");
}

// Function to update a bank record
void updateRecord(struct BankRecord *records, int numRecords, char *searchName) {
    int i;
    for (i = 0; i < numRecords; i++) {
        if (strcmp(records[i].name, searchName) == 0) {
            printf("Enter new balance: ");
            scanf("%f", &records[i].balance);
            records[i].date = time(NULL);
            return;
        }
    }
    printf("Record not found.\n");
}

// Function to delete a bank record
void deleteRecord(struct BankRecord *records, int *numRecords, char *searchName) {
    int i;
    for (i = 0; i < *numRecords; i++) {
        if (strcmp(records[i].name, searchName) == 0) {
            *numRecords -= 1;
            memmove(&records[i], &records[i + 1], (*numRecords - i) * sizeof(struct BankRecord));
            return;
        }
    }
    printf("Record not found.\n");
}

int main() {
    struct BankRecord records[100];
    int numRecords = 0;
    char command[50];

    while (1) {
        printf("Enter command (add, display, search, update, delete, quit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            addRecord(&records[numRecords++]);
        } else if (strcmp(command, "display") == 0) {
            displayAllRecords(records, numRecords);
        } else if (strcmp(command, "search") == 0) {
            char searchName[50];
            printf("Enter name to search: ");
            scanf("%s", searchName);
            searchRecord(records, numRecords, searchName);
        } else if (strcmp(command, "update") == 0) {
            char searchName[50];
            printf("Enter name to update: ");
            scanf("%s", searchName);
            updateRecord(records, numRecords, searchName);
        } else if (strcmp(command, "delete") == 0) {
            char searchName[50];
            printf("Enter name to delete: ");
            scanf("%s", searchName);
            deleteRecord(records, &numRecords, searchName);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}