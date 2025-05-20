//FormAI DATASET v1.0 Category: Banking Record System ; Style: minimalist
#include <stdio.h>

struct BankRecord {
    int accountNumber;
    char name[50];
    double balance;
};

int main() {
    struct BankRecord accounts[100]; // Create an array of BankRecord structs
    int numAccounts = 0; // Keep track of the number of accounts in the array

    // Display menu options and loop until user chooses to exit
    int choice = 0;
    while (choice != 4) {
        printf("Banking Record System\n");
        printf("---------------------\n");
        printf("1. Add an account\n");
        printf("2. Remove an account\n");
        printf("3. Display all accounts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add an account
                printf("Enter account number: ");
                scanf("%d", &accounts[numAccounts].accountNumber);
                printf("Enter account name: ");
                scanf("%s", accounts[numAccounts].name);
                printf("Enter account balance: ");
                scanf("%lf", &accounts[numAccounts].balance);
                numAccounts++;
                printf("Account added successfully!\n");
                break;
            case 2: // Remove an account
                printf("Enter account number to remove: ");
                int accNumToRemove;
                scanf("%d", &accNumToRemove);
                for (int i = 0; i < numAccounts; i++) {
                    if (accounts[i].accountNumber == accNumToRemove) {
                        for (int j = i; j < numAccounts - 1; j++) {
                            accounts[j] = accounts[j + 1];
                        }
                        numAccounts--;
                        printf("Account removed successfully!\n");
                        break; // Exit loop once account is found and removed
                    }
                }
                break;
            case 3: // Display all accounts
                printf("Account Number\tAccount Name\tAccount Balance\n");
                printf("------------------------------------------------\n");
                for (int i = 0; i < numAccounts; i++) {
                    printf("%d\t\t%s\t\t%.2lf\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
                }
                printf("\n");
                break;
            case 4: // Exit
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}