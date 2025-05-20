//FormAI DATASET v1.0 Category: Banking Record System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// define structure for bank account
typedef struct Account {
    int accountNumber;
    char name[50];
    double balance;
    bool active;
} Account;

// function to create a new account
void createNewAccount(Account **accounts, int *numberOfAccounts) {
    int newAccountNumber;
    char newName[50];
    double newBalance;

    printf("Enter new account number: ");
    scanf("%d", &newAccountNumber);

    // check if account number already exists
    for (int i = 0; i < *numberOfAccounts; i++) {
        if (newAccountNumber == accounts[i]->accountNumber) {
            printf("Account number already exists.\n");
            return;
        }
    }

    printf("Enter account holder name: ");
    // clear input buffer
    while(getchar() != '\n');
    fgets(newName, 50, stdin);
    strtok(newName, "\n");

    printf("Enter account balance: ");
    scanf("%lf", &newBalance);

    // allocate memory for new account
    Account *newAccount = (Account*) malloc(sizeof(Account));
    newAccount->accountNumber = newAccountNumber;
    strcpy(newAccount->name, newName);
    newAccount->balance = newBalance;
    newAccount->active = true;

    // add new account to accounts array
    accounts[*numberOfAccounts] = newAccount;
    (*numberOfAccounts)++;

    printf("New account created successfully.\n");
}

// function to deposit money into an account
void deposit(Account **accounts, int numberOfAccounts) {
    int accountNumber;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    // find account with the given account number
    for (int i = 0; i < numberOfAccounts; i++) {
        if (accountNumber == accounts[i]->accountNumber) {
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);
            accounts[i]->balance += amount;
            printf("Deposit successful.\n");
            return;
        }
    }

    printf("Account not found.\n");
}

// function to withdraw money from an account
void withdraw(Account **accounts, int numberOfAccounts) {
    int accountNumber;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    // find account with the given account number
    for (int i = 0; i < numberOfAccounts; i++) {
        if (accountNumber == accounts[i]->accountNumber) {
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);
            if (amount <= accounts[i]->balance) {
                accounts[i]->balance -= amount;
                printf("Withdrawal successful.\n");
                return;
            }
            else {
                printf("Insufficient balance.\n");
                return;
            }
        }
    }

    printf("Account not found.\n");
}

// function to display account details
void displayAccountDetails(Account **accounts, int numberOfAccounts) {
    int accountNumber;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    // find account with the given account number
    for (int i = 0; i < numberOfAccounts; i++) {
        if (accountNumber == accounts[i]->accountNumber) {
            printf("Account Number: %d\n", accounts[i]->accountNumber);
            printf("Account Holder Name: %s\n", accounts[i]->name);
            printf("Account Balance: %.2f\n", accounts[i]->balance);
            printf("Account Status: %s\n", accounts[i]->active ? "Active" : "Inactive");
            return;
        }
    }

    printf("Account not found.\n");
}

// function to close an account
void closeAccount(Account **accounts, int *numberOfAccounts) {
    int accountNumber;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    // find account with the given account number
    for (int i = 0; i < *numberOfAccounts; i++) {
        if (accountNumber == accounts[i]->accountNumber) {
            accounts[i]->active = false;
            printf("Account closed successfully.\n");

            // move remaining accounts up in the array
            for (int j = i; j < (*numberOfAccounts) - 1; j++) {
                accounts[j] = accounts[j+1];
            }

            // reduce the size of the accounts array
            (*numberOfAccounts)--;
            accounts = (Account**) realloc(accounts, sizeof(Account*) * (*numberOfAccounts));
            return;
        }
    }

    printf("Account not found.\n");
}

int main() {
    Account **accounts = NULL; // array of account pointers
    int numberOfAccounts = 0;

    while (true) {
        printf("\n1. Create new account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Display account details\n");
        printf("5. Close account\n");
        printf("6. Exit\n\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createNewAccount(accounts, &numberOfAccounts);
                break;
            case 2:
                deposit(accounts, numberOfAccounts);
                break;
            case 3:
                withdraw(accounts, numberOfAccounts);
                break;
            case 4:
                displayAccountDetails(accounts, numberOfAccounts);
                break;
            case 5:
                closeAccount(accounts, &numberOfAccounts);
                break;
            case 6:
                // free memory allocated for accounts array and account structures
                for (int i = 0; i < numberOfAccounts; i++) {
                    free(accounts[i]);
                }
                free(accounts);
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}