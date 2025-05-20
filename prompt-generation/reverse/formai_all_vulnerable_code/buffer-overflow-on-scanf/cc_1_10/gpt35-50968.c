//FormAI DATASET v1.0 Category: Banking Record System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

struct BankRecord {
    char name[20];
    int accountNumber;
    int balance;
};

struct BankRecord bankRecords[MAX_RECORDS];
int numRecords = 0;

void addRecord() {
    printf("Enter name: ");
    scanf("%s", bankRecords[numRecords].name);

    printf("Enter account number: ");
    scanf("%d", &bankRecords[numRecords].accountNumber);

    printf("Enter balance: ");
    scanf("%d", &bankRecords[numRecords].balance);

    numRecords++;
}

void searchRecord() {
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < numRecords; i++) {
        if (bankRecords[i].accountNumber == accountNumber) {
            printf("Name: %s\n", bankRecords[i].name);
            printf("Balance: %d\n", bankRecords[i].balance);
            return;
        }
    }

    printf("Record not found.\n");
}

void displayRecords() {
    for (int i = 0; i < numRecords; i++) {
        printf("Name: %s\n", bankRecords[i].name);
        printf("Account number: %d\n", bankRecords[i].accountNumber);
        printf("Balance: %d\n", bankRecords[i].balance);
        printf("\n");
    }
}

void deleteRecord() {
    int index;
    printf("Enter index: ");
    scanf("%d", &index);

    if (index < 0 || index >= numRecords) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index; i < numRecords - 1; i++) {
        bankRecords[i] = bankRecords[i + 1];
    }

    numRecords--;
}

int main() {
    int choice;
    while (1) {
        printf("1. Add Record\n");
        printf("2. Search Record\n");
        printf("3. Display Records\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                searchRecord();
                break;
            case 3:
                displayRecords();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
        
        // Securely wipe data from memory after every operation
        memset(bankRecords, 0, sizeof(bankRecords));
        numRecords = 0;
    }
}