//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define ACCOUNT_NUMBER_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void displayMenu();
int createAccount();
void deposit();
void withdraw();
void displayAccounts();
void searchAccount();
void exitProgram();

int main() {
    int choice;

    while (1) {
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
                displayAccounts();
                break;
            case 5:
                searchAccount();
                break;
            case 6:
                exitProgram();
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void displayMenu() {
    printf("\n----- C Banking Record System -----\n");
    printf("1. Create a new account\n");
    printf("2. Deposit money\n");
    printf("3. Withdraw money\n");
    printf("4. Display all accounts\n");
    printf("5. Search for an account\n");
    printf("6. Exit\n");
}

int createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached.\n");
        return -1;
    }

    Account newAccount;
    printf("Enter account holder name: ");
    scanf("%s", newAccount.name);
    printf("Enter account number: ");
    scanf("%s", newAccount.accountNumber);
    newAccount.balance = 0;

    accounts[accountCount++] = newAccount;
    printf("Account created successfully.\n");
    return 0;
}

void deposit() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float amount;
    printf("Enter account number to deposit into: ");
    scanf("%s", accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Deposit successful. New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float amount;
    printf("Enter account number to withdraw from: ");
    scanf("%s", accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > accounts[i].balance) {
                printf("Insufficient funds. Current balance: %.2f\n", accounts[i].balance);
            } else {
                accounts[i].balance -= amount;
                printf("Withdrawal successful. New balance: %.2f\n", accounts[i].balance);
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void displayAccounts() {
    printf("\n----- Account List -----\n");
    if (accountCount == 0) {
        printf("No accounts to display.\n");
        return;
    }
    for (int i = 0; i < accountCount; i++) {
        printf("Account Holder: %s, Account Number: %s, Balance: %.2f\n",
               accounts[i].name, accounts[i].accountNumber, accounts[i].balance);
    }
}

void searchAccount() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    printf("Enter account number to search: ");
    scanf("%s", accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Account found!\n");
            printf("Account Holder: %s, Balance: %.2f\n",
                   accounts[i].name, accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void exitProgram() {
    printf("Exiting the banking system. Goodbye!\n");
}