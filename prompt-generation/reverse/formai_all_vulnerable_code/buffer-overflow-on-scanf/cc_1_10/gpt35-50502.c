//FormAI DATASET v1.0 Category: Banking Record System ; Style: complex
#include <stdio.h>
#include <stdlib.h> // required for dynamic memory allocation

typedef struct {
    int accNo;
    char name[50];
    float balance;
} Account; // defining the account structure

void createAccount(Account *acc); // function to create a new account
void viewAccount(Account acc); // function to view an account
void updateAccount(Account *acc); // function to update an account
void deleteAccount(Account *acc); // function to delete an account

int main() {
    int choice, index = 0, numAccounts = 0;
    Account *accounts = NULL; // initializing accounts pointer to NULL

    do {
        printf("1. Create new account\n");
        printf("2. View an account\n");
        printf("3. Update an account\n");
        printf("4. Delete an account\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                numAccounts++; // incrementing number of accounts
                accounts = (Account *)realloc(accounts, numAccounts * sizeof(Account)); // allocating memory for the new account
                createAccount(&accounts[index]); // creating the new account and passing the account address
                index++; // incrementing index for the next account to be added
                break;
            case 2:
                if (numAccounts > 0) {
                    int accNo;
                    printf("Enter account number to view: ");
                    scanf("%d", &accNo);
                    for (int i = 0; i < numAccounts; i++) {
                        if (accounts[i].accNo == accNo) { // account found
                            viewAccount(accounts[i]); // view the account details
                            break;
                        }
                        if (i == numAccounts - 1) printf("Account not found.\n"); // account not found
                    }
                } else {
                    printf("No accounts found.\n");
                }
                break;
            case 3:
                if (numAccounts > 0) {
                    int accNo;
                    printf("Enter account number to update: ");
                    scanf("%d", &accNo);
                    for (int i = 0; i < numAccounts; i++) {
                        if (accounts[i].accNo == accNo) { // account found
                            updateAccount(&accounts[i]); // update account details
                            break;
                        }
                        if (i == numAccounts - 1) printf("Account not found.\n"); // account not found
                    }
                } else {
                    printf("No accounts found.\n");
                }
                break;
            case 4:
                if (numAccounts > 0) {
                    int accNo;
                    printf("Enter account number to delete: ");
                    scanf("%d", &accNo);
                    for (int i = 0; i < numAccounts; i++) {
                        if (accounts[i].accNo == accNo) { // account found
                            deleteAccount(&accounts[i]); // delete account
                            for (int j = i; j < numAccounts - 1; j++) {
                                accounts[j] = accounts[j + 1]; // shifting remaining accounts up
                            }
                            accounts = (Account *)realloc(accounts, (numAccounts - 1) * sizeof(Account)); // deallocating memory for the deleted account
                            numAccounts--; // decrementing number of accounts
                            index--; // decrementing index
                            break;
                        }
                        if (i == numAccounts - 1) printf("Account not found.\n"); // account not found
                    }
                } else {
                    printf("No accounts found.\n");
                }
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
        printf("\n");
    } while (choice != 5);

    return 0;
}

void createAccount(Account *acc) {
    printf("Enter account number: ");
    scanf("%d", &acc->accNo);
    printf("Enter name: ");
    scanf("%s", acc->name);
    printf("Enter balance: ");
    scanf("%f", &acc->balance);
    printf("Account created successfully.\n");
}

void viewAccount(Account acc) {
    printf("Account number: %d\n", acc.accNo);
    printf("Name: %s\n", acc.name);
    printf("Balance: %.2f\n", acc.balance);
}

void updateAccount(Account *acc) {
    int choice;
    do {
        printf("1. Update name\n");
        printf("2. Update balance\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter new name: ");
                scanf("%s", acc->name);
                printf("Name updated successfully.\n");
                break;
            case 2:
                printf("Enter new balance: ");
                scanf("%f", &acc->balance);
                printf("Balance updated successfully.\n");
                break;
            case 3:
                printf("Exiting update mode.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
        printf("\n");
    } while (choice != 3);
}

void deleteAccount(Account *acc) {
    printf("Deleting account with account number %d...\n", acc->accNo);
}