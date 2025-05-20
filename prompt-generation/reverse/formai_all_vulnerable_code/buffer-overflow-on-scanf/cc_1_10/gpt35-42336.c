//FormAI DATASET v1.0 Category: Banking Record System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure for the bank record
struct BankRecord {
    int accountNumber;
    char accountHolderName[30];
    float balance;
};

int main() {
    int option, numRecords = 0, accountNumber, index;
    float balance;
    char accountHolderName[30];
    //Allocating memory for the array of bank records
    struct BankRecord *bankRecords = (struct BankRecord*) malloc(numRecords * sizeof(struct BankRecord));
    while (1) {
        printf("Welcome to the Bank Record System!\n");
        printf("Enter your choice:\n");
        printf("1. Add a new record\n");
        printf("2. Search for a record\n");
        printf("3. Display all records\n");
        printf("4. Exit\n");
        scanf("%d", &option);
        switch(option) {
            case 1:
                printf("Enter the Account Holder Name: ");
                scanf("%s", accountHolderName);
                printf("Enter the Account Number: ");
                scanf("%d", &accountNumber);
                printf("Enter the Account Balance: ");
                scanf("%f", &balance);
                //Adding a new bank record to the array
                bankRecords = (struct BankRecord*) realloc(bankRecords, (numRecords+1) * sizeof(struct BankRecord));
                bankRecords[numRecords].accountNumber = accountNumber;
                strcpy(bankRecords[numRecords].accountHolderName, accountHolderName);
                bankRecords[numRecords].balance = balance;
                numRecords++;
                printf("New record added successfully!\n");
                break;
            case 2:
                printf("Enter the Account Number to search: ");
                scanf("%d", &accountNumber);
                //Searching for the bank record with the given account number
                for (index = 0; index < numRecords; index++) {
                    if (bankRecords[index].accountNumber == accountNumber) {
                        printf("Account Number: %d\n", bankRecords[index].accountNumber);
                        printf("Account Holder Name: %s\n", bankRecords[index].accountHolderName);
                        printf("Account Balance: %.2f\n", bankRecords[index].balance);
                        break;
                    }
                }
                if (index >= numRecords) {
                    printf("Record not found with the given account number!\n");
                }
                break;
            case 3:
                printf("Displaying all records:\n");
                for (index = 0; index < numRecords; index++) {
                    printf("Account Number: %d\n", bankRecords[index].accountNumber);
                    printf("Account Holder Name: %s\n", bankRecords[index].accountHolderName);
                    printf("Account Balance: %.2f\n\n", bankRecords[index].balance);
                }
                break;
            case 4:
                printf("Goodbye!\n");
                //Freeing the memory allocated for the bank records array
                free(bankRecords);
                return 0;
            default:
                printf("Invalid option selected. Please try again.\n");
                break;
        }
    }
}