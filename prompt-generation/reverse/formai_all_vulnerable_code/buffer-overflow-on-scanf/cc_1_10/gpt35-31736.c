//FormAI DATASET v1.0 Category: Banking Record System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Account structure
typedef struct {
    int accNum;
    char name[50];
    double balance;
} Account;

// Function prototypes
void readAccounts(Account *accounts, int numAccounts);
void writeAccounts(Account *accounts, int numAccounts);
void deposit(Account *accounts, int numAccounts);
void withdraw(Account *accounts, int numAccounts);
void printAccounts(Account *accounts, int numAccounts);
void printAccount(Account account);

int main() {
    int numAccounts, choice;
    Account *accounts;

    // Read in number of accounts
    printf("How many accounts do you want to create? ");
    scanf("%d", &numAccounts);
    accounts = (Account*) malloc(numAccounts * sizeof(Account));

    // Read in account details
    readAccounts(accounts, numAccounts);

    // User menu
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Print all accounts\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deposit(accounts, numAccounts);
                break;
            case 2:
                withdraw(accounts, numAccounts);
                break;
            case 3:
                printAccounts(accounts, numAccounts);
                break;
            case 4:
                writeAccounts(accounts, numAccounts);
                free(accounts);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Read in account details from user
void readAccounts(Account *accounts, int numAccounts) {
    for (int i = 0; i < numAccounts; i++) {
        printf("\nEnter account %d details:\n", i+1);
        printf("Account number: ");
        scanf("%d", &accounts[i].accNum);
        printf("Name (max 50 characters): ");
        scanf("%s", accounts[i].name);
        printf("Initial balance: ");
        scanf("%lf", &accounts[i].balance);
    }
}

// Write out account details to file
void writeAccounts(Account *accounts, int numAccounts) {
    FILE *file = fopen("accounts.txt", "w");
    if (file != NULL) {
        for (int i = 0; i < numAccounts; i++) {
            fprintf(file, "%d %s %.2lf\n", accounts[i].accNum, accounts[i].name, accounts[i].balance);
        }
        fclose(file);
    }
}

// Deposit money into an account
void deposit(Account *accounts, int numAccounts) {
    int accNum;
    double amount;
    printf("\nEnter account number: ");
    scanf("%d", &accNum);

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accNum == accNum) {
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);
            accounts[i].balance += amount;
            printf("Deposit successful.\n");
            printAccount(accounts[i]);
            return;
        }
    }

    printf("Account not found.\n");
}

// Withdraw money from an account
void withdraw(Account *accounts, int numAccounts) {
    int accNum;
    double amount;
    printf("\nEnter account number: ");
    scanf("%d", &accNum);

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accNum == accNum) {
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);

            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful.\n");
                printAccount(accounts[i]);
            }
            else {
                printf("Insufficient funds.\n");
            }

            return;
        }
    }

    printf("Account not found.\n");
}

// Print out all account details
void printAccounts(Account *accounts, int numAccounts) {
    for (int i = 0; i < numAccounts; i++) {
        printAccount(accounts[i]);
    }
}

// Print out individual account details
void printAccount(Account account) {
    printf("\nAccount number: %d\n", account.accNum);
    printf("Name: %s\n", account.name);
    printf("Balance: %.2lf\n", account.balance);
}