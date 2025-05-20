//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define ACCOUNT_NUMBER_LENGTH 20

typedef struct {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    char accountHolder[NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void displayMenu();
void createAccount();
void deposit();
void withdraw();
void viewAccount();
void listAccounts();
int findAccountIndex(char *accountNumber);

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                viewAccount();
                break;
            case 5:
                listAccounts();
                break;
            case 6:
                printf("Exiting the Banking Record System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    printf("\n===== Banking Record System =====\n");
    printf("1. Create Account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. View Account\n");
    printf("5. List Accounts\n");
    printf("6. Exit\n");
    printf("=================================\n");
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Account limit reached. Cannot create more accounts.\n");
        return;
    }

    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    char accountHolder[NAME_LENGTH];

    printf("Enter account number: ");
    scanf("%s", accountNumber);
    if (findAccountIndex(accountNumber) != -1) {
        printf("Account number already exists. Choose a different number.\n");
        return;
    }

    printf("Enter account holder name: ");
    scanf(" %[^\n]s", accountHolder);

    accounts[accountCount].balance = 0.0;
    strcpy(accounts[accountCount].accountNumber, accountNumber);
    strcpy(accounts[accountCount].accountHolder, accountHolder);
    accountCount++;

    printf("Account created successfully for %s with account number %s.\n", accountHolder, accountNumber);
}

void deposit() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float amount;

    printf("Enter account number for deposit: ");
    scanf("%s", accountNumber);

    int index = findAccountIndex(accountNumber);
    if (index == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid amount. Deposit must be greater than zero.\n");
        return;
    }

    accounts[index].balance += amount;
    printf("Successfully deposited %.2f to account number %s. New balance: %.2f\n", amount, accountNumber, accounts[index].balance);
}

void withdraw() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float amount;

    printf("Enter account number for withdrawal: ");
    scanf("%s", accountNumber);

    int index = findAccountIndex(accountNumber);
    if (index == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid amount. Withdrawal must be greater than zero.\n");
        return;
    }
    if (amount > accounts[index].balance) {
        printf("Insufficient funds. Current balance: %.2f\n", accounts[index].balance);
        return;
    }

    accounts[index].balance -= amount;
    printf("Successfully withdrew %.2f from account number %s. New balance: %.2f\n", amount, accountNumber, accounts[index].balance);
}

void viewAccount() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];

    printf("Enter account number to view: ");
    scanf("%s", accountNumber);

    int index = findAccountIndex(accountNumber);
    if (index == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("Account Number: %s\n", accounts[index].accountNumber);
    printf("Account Holder: %s\n", accounts[index].accountHolder);
    printf("Current Balance: %.2f\n", accounts[index].balance);
}

void listAccounts() {
    if (accountCount == 0) {
        printf("No accounts available.\n");
        return;
    }

    printf("\n===== List of Accounts =====\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %s, Account Holder: %s, Balance: %.2f\n", 
            accounts[i].accountNumber, accounts[i].accountHolder, accounts[i].balance);
    }
    printf("============================\n");
}

int findAccountIndex(char *accountNumber) {
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            return i;
        }
    }
    return -1; // Not found
}