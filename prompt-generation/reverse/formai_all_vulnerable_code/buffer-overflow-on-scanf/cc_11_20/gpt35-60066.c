//FormAI DATASET v1.0 Category: Banking Record System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 100

struct BankingRecord {
    int accountNumber;
    char accountHolderName[50];
    double balance;
};

typedef struct BankingRecord Record;

int main() {
    Record records[MAX_RECORDS];
    int numRecords = 0;
    int choice;

    while (1) {
        printf("1. Add record\n");
        printf("2. View all records\n");
        printf("3. Search record\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (numRecords >= MAX_RECORDS) {
                    printf("Error: Maximum number of records reached.\n");
                    break;
                }

                Record record;
                printf("Enter account number: ");
                scanf("%d", &record.accountNumber);
                printf("Enter account holder name: ");
                scanf("%s", record.accountHolderName);
                printf("Enter balance: ");
                scanf("%lf", &record.balance);

                records[numRecords++] = record;
                printf("Record added successfully.\n");
                break;
            }
            case 2: {
                if (numRecords == 0) {
                    printf("No records found.\n");
                    break;
                }

                printf("Account Number\tAccount Holder\tBalance\n");
                for (int i = 0; i < numRecords; i++) {
                    printf("%d\t%s\t%.2lf\n", records[i].accountNumber, records[i].accountHolderName, records[i].balance);
                }
                break;
            }
            case 3: {
                if (numRecords == 0) {
                    printf("No records found.\n");
                    break;
                }

                int accountNumber;
                printf("Enter account number to search: ");
                scanf("%d", &accountNumber);
                int found = 0;
                for (int i = 0; i < numRecords; i++) {
                    if (records[i].accountNumber == accountNumber) {
                        found = 1;
                        printf("Account Number\tAccount Holder\tBalance\n");
                        printf("%d\t%s\t%.2lf\n", records[i].accountNumber, records[i].accountHolderName, records[i].balance);
                        break;
                    }
                }
                if (!found) {
                    printf("Record not found.\n");
                }
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}