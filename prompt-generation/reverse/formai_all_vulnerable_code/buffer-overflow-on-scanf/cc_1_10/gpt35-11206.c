//FormAI DATASET v1.0 Category: Banking Record System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold banking record information
typedef struct {
    char name[50];
    int account_number;
    float balance;
} BankingRecord;

// Function to print banking record information
void printRecord(BankingRecord record) {
    printf("\nName: %s\nAccount number: %d\nBalance: $%.2f\n", record.name, record.account_number, record.balance);
}

// Function to deposit funds into banking record
void deposit(BankingRecord *record, float amount) {
    record->balance += amount;
}

// Function to withdraw funds from banking record
void withdraw(BankingRecord *record, float amount) {
    if (record->balance >= amount) {
        record->balance -= amount;
    } else {
        printf("Insufficient funds. Withdrawal request denied.\n");
    }
}

int main() {
    int choice;
    int num_records = 0;
    BankingRecord *records = malloc(sizeof(BankingRecord));

    if (!records) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }

    do {
        printf("\nWelcome to the Banking Record System\n");
        printf("1. Add new record\n");
        printf("2. View all records\n");
        printf("3. Deposit funds\n");
        printf("4. Withdraw funds\n");
        printf("5. Exit program\n");

        // Get user choice
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                // Add new record
                num_records++;
                records = realloc(records, sizeof(BankingRecord) * num_records);

                if (!records) {
                    printf("Memory allocation failed. Exiting program.\n");
                    return 1;
                }

                BankingRecord newRecord;

                printf("\nEnter name: ");
                scanf("%s", newRecord.name);

                printf("Enter account number: ");
                scanf("%d", &newRecord.account_number);

                printf("Enter balance: ");
                scanf("%f", &newRecord.balance);

                records[num_records-1] = newRecord;

                break;
            }
            case 2: {
                // View all records
                if (num_records == 0) {
                    printf("No records to display.\n");
                } else {
                    for (int i = 0; i < num_records; i++) {
                        printRecord(records[i]);
                    }
                }

                break;
            }
            case 3: {
                // Deposit funds
                int account_num;
                float amount;
                int found_record = 0;

                printf("\nEnter account number: ");
                scanf("%d", &account_num);

                for (int i = 0; i < num_records; i++) {
                    if (records[i].account_number == account_num) {
                        found_record = 1;
                        printf("Enter the amount to deposit: ");
                        scanf("%f", &amount);
                        deposit(&records[i], amount);
                        printf("Deposit successful. New balance: $%.2f\n", records[i].balance);
                    }
                }

                if (!found_record) {
                    printf("Record not found.\n");
                }

                break;
            }
            case 4: {
                // Withdraw funds
                int account_num;
                float amount;
                int found_record = 0;

                printf("\nEnter account number: ");
                scanf("%d", &account_num);

                for (int i = 0; i < num_records; i++) {
                    if (records[i].account_number == account_num) {
                        found_record = 1;
                        printf("Enter the amount to withdraw: ");
                        scanf("%f", &amount);
                        withdraw(&records[i], amount);
                        printf("Withdrawal successful. New balance: $%.2f\n", records[i].balance);
                    }
                }

                if (!found_record) {
                    printf("Record not found.\n");
                }

                break;
            }
            case 5: {
                // Exit program
                printf("Exiting program. Goodbye!\n");
                break;
            }
            default: {
                printf("Invalid choice. Please select a valid option.\n");
                break;
            }
        }
    } while (choice != 5);

    free(records);

    return 0;
}