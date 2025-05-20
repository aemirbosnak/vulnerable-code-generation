//MISTRAL-7B DATASET v1.0 Category: Banking Record System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 30
#define MAX_ACCOUNT_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char accountNumber[MAX_ACCOUNT_NUMBER_LENGTH];
    float balance;
} Record;

Record records[MAX_RECORDS];
int numRecords = 0;

void addRecord() {
    if (numRecords >= MAX_RECORDS) {
        printf("Record limit exceeded!\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", records[numRecords].name);
    printf("Enter account number: ");
    scanf("%s", records[numRecords].accountNumber);
    printf("Enter balance: ");
    scanf("%f", &records[numRecords].balance);

    numRecords++;
}

void displayRecords() {
    printf("\nCurrent records:\n");

    for (int i = 0; i < numRecords; i++) {
        printf("\nName: %s", records[i].name);
        printf("\nAccount Number: %s", records[i].accountNumber);
        printf("\nBalance: %.2f", records[i].balance);
    }
}

void searchRecord() {
    char accountNumber[MAX_ACCOUNT_NUMBER_LENGTH];
    int found = 0;

    printf("Enter account number to search: ");
    scanf("%s", accountNumber);

    for (int i = 0; i < numRecords; i++) {
        if (strcmp(records[i].accountNumber, accountNumber) == 0) {
            printf("\nName: %s", records[i].name);
            printf("\nBalance: %.2f", records[i].balance);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nAccount not found.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add Record\n2. Display Records\n3. Search Record\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}