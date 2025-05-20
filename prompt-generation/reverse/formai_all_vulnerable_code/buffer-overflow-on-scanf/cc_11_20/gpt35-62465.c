//FormAI DATASET v1.0 Category: Banking Record System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BankAccount {
    int accNumber;
    char name[25];
    float balance;
};

int main() {
    int bankAccSize = 0;
    struct BankAccount *bankAccounts = NULL;

    while (1) {
        printf("Banking Record System\n"
               "1. Add an account\n"
               "2. Display all accounts\n"
               "3. Search for an account\n"
               "4. Remove an account\n"
               "5. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            bankAccSize++;
            bankAccounts = (struct BankAccount *)
                    realloc(bankAccounts, bankAccSize * sizeof(struct BankAccount));

            if (bankAccounts == NULL) {
                printf("Error allocating memory!\n");
                return 1;
            }

            printf("Enter account number: ");
            scanf("%d", &bankAccounts[bankAccSize-1].accNumber);

            printf("Enter name: ");
            scanf("%s", bankAccounts[bankAccSize-1].name);

            printf("Enter balance: ");
            scanf("%f", &bankAccounts[bankAccSize-1].balance);

            printf("Account added successfully!\n\n");

        } else if (choice == 2) {
            printf("Banking Record System - All Accounts\n"
                   "Account No.\tName\t\tBalance\n");

            for (int i = 0; i < bankAccSize; i++) {
                printf("%-12d\t%-15s\t%.2f\n",
                       bankAccounts[i].accNumber, bankAccounts[i].name, bankAccounts[i].balance);
            }

            printf("\n");

        } else if (choice == 3) {
            int accNumber;
            printf("Enter account number: ");
            scanf("%d", &accNumber);

            for (int i = 0; i < bankAccSize; i++) {
                if (bankAccounts[i].accNumber == accNumber) {
                    printf("Banking Record System - Search Result\n"
                           "Account No.\tName\t\tBalance\n"
                           "%-12d\t%-15s\t%.2f\n\n",
                           bankAccounts[i].accNumber, bankAccounts[i].name, bankAccounts[i].balance);

                    break;
                }
            }

        } else if (choice == 4) {
            int accNumber;
            printf("Enter account number: ");
            scanf("%d", &accNumber);

            int found = 0;
            int removeIndex = 0;
            for (int i = 0; i < bankAccSize; i++) {
                if (bankAccounts[i].accNumber == accNumber) {
                    found = 1;
                    removeIndex = i;
                    break;
                }
            }

            if (found) {
                for (int i = removeIndex; i < bankAccSize-1; i++) {
                    bankAccounts[i] = bankAccounts[i+1];
                }

                bankAccSize--;
                bankAccounts = (struct BankAccount *)
                        realloc(bankAccounts, bankAccSize * sizeof(struct BankAccount));

                printf("Account removed successfully!\n\n");
            } else {
                printf("Account not found!\n\n");
            }

        } else if (choice == 5) {
            printf("Exiting program...\n");
            free(bankAccounts);
            return 0;

        } else {
            printf("Invalid choice!\n\n");
        }
    }
}