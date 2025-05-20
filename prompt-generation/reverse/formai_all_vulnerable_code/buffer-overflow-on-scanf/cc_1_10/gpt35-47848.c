//FormAI DATASET v1.0 Category: Banking Record System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

struct BankRecord {
    char name[50];
    int account_number;
    float balance;
};

void addRecord(struct BankRecord* records, int* num_records) {
    printf("Enter name: ");
    scanf("%s", records[*num_records].name);
    printf("Enter account number: ");
    scanf("%d", &records[*num_records].account_number);
    printf("Enter balance: ");
    scanf("%f", &records[*num_records].balance);

    printf("Record added successfully!\n");
    (*num_records)++;
}

void displayRecords(struct BankRecord* records, int num_records) {
    if (num_records == 0) {
        printf("No records found!\n");
        return;
    }

    printf("Account Number\tName\tBalance\n");
    for (int i = 0; i < num_records; i++) {
        printf("%d\t%s\t%.2f\n", records[i].account_number, records[i].name, records[i].balance);
    }
}

int main() {
    struct BankRecord records[100];
    int num_records = 0;
    int choice;

    while(1) {
        printf("Bank Record System\n");
        printf("------------------\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Quit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(records, &num_records);
                break;
            case 2:
                displayRecords(records, num_records);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}