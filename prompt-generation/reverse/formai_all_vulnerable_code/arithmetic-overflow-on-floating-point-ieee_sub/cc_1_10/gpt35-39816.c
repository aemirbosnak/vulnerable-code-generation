//FormAI DATASET v1.0 Category: Banking Record System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

struct BankAccount {
    int accountNumber;
    char accountName[50];
    float balance;
};

struct BankAccount accounts[MAX_ACCOUNTS];
int numAccounts = 0;

void showMainMenu();
void showAccountMenu();
void addAccount();
void deposit();
void withdraw();
void viewBalance();
void viewAllAccounts();

int main() {
    showMainMenu();
    return 0;
}

void showMainMenu() {
    int choice;

    while (1) {
        printf("\n=========== MAIN MENU ===========\n");
        printf("1. Add Account\n");
        printf("2. Log In to Account\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAccount();
                break;
            case 2:
                showAccountMenu();
                break;
            case 3:
                printf("\nThank you for using our system!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    }
}

void showAccountMenu() {
    int accountNumber, choice;

    printf("\nEnter your account number: ");
    scanf("%d", &accountNumber);

    struct BankAccount *account;

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            account = &accounts[i];
            break;
        }
        if (i == numAccounts - 1) {
            printf("\nAccount not found! Please try again.\n");
            showMainMenu();
        }
    }

    printf("\n=========== ACCOUNT MENU ===========\n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. View Balance\n");
    printf("4. Log Out\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            deposit(account);
            break;
        case 2:
            withdraw(account);
            break;
        case 3:
            viewBalance(account);
            break;
        case 4:
            printf("\nLogged out successfully!\n");
            showMainMenu();
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
            showAccountMenu();
            break;
    }
}

void addAccount() {
    if (numAccounts == MAX_ACCOUNTS) {
        printf("\nCannot add account! Maximum limit reached.\n");
        showMainMenu();
    }

    struct BankAccount account;

    printf("\nEnter account number: ");
    scanf("%d", &account.accountNumber);

    printf("Enter account name: ");
    scanf("%s", account.accountName);

    printf("Enter initial balance: ");
    scanf("%f", &account.balance);

    accounts[numAccounts++] = account;

    printf("\nAccount added successfully!\n");
}

void deposit(struct BankAccount *account) {
    float amount;

    printf("\nEnter deposit amount: ");
    scanf("%f", &amount);

    account->balance += amount;

    printf("\nDeposit successful! New balance = %.2f\n", account->balance);
    showAccountMenu();
}

void withdraw(struct BankAccount *account) {
    float amount;

    printf("\nEnter withdrawal amount: ");
    scanf("%f", &amount);

    if (amount > account->balance) {
        printf("\nInsufficient balance! Please try again.\n");
        showAccountMenu();
    }

    account->balance -= amount;

    printf("\nWithdrawal successful! New balance = %.2f\n", account->balance);
    showAccountMenu();
}

void viewBalance(struct BankAccount *account) {
    printf("\nAccount Number: %d\n", account->accountNumber);
    printf("Account Name: %s\n", account->accountName);
    printf("Balance: %.2f\n", account->balance);
    showAccountMenu();
}

void viewAllAccounts() {
    printf("\n===== LIST OF ACCOUNTS =====\n");

    for (int i = 0; i < numAccounts; i++) {
        printf("Account Number: %d\n", accounts[i].accountNumber);
        printf("Account Name: %s\n", accounts[i].accountName);
        printf("Balance: %.2f\n", accounts[i].balance);
        printf("\n");
    }
}