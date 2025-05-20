//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define ACCOUNT_FILE "accounts.txt"

typedef struct {
    char name[50];
    int accountNumber;
    float balance;
} Account;

void createAccount(Account *accounts, int *accountCount);
void viewAccountDetails(Account *accounts, int accountCount);
void deposit(Account *accounts, int accountCount);
void withdraw(Account *accounts, int accountCount);
void saveAccountsToFile(Account *accounts, int accountCount);
void loadAccountsFromFile(Account *accounts, int *accountCount);
void displayMenu();

int main() {
    Account accounts[MAX_ACCOUNTS];
    int accountCount = 0;
    int choice;

    loadAccountsFromFile(accounts, &accountCount);

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &accountCount);
                break;
            case 2:
                viewAccountDetails(accounts, accountCount);
                break;
            case 3:
                deposit(accounts, accountCount);
                break;
            case 4:
                withdraw(accounts, accountCount);
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 5);

    saveAccountsToFile(accounts, accountCount);
    return 0;
}

void displayMenu() {
    printf("\n--- Bank Account Management System ---\n");
    printf("1. Create Account\n");
    printf("2. View Account Details\n");
    printf("3. Deposit Money\n");
    printf("4. Withdraw Money\n");
    printf("5. Exit\n");
}

void createAccount(Account *accounts, int *accountCount) {
    if (*accountCount >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached.\n");
        return;
    }

    Account newAccount;
    
    printf("Enter account holder's name: ");
    scanf("%s", newAccount.name);
    
    newAccount.accountNumber = *accountCount + 1; // Simple account number generation
    newAccount.balance = 0.0;
    
    accounts[*accountCount] = newAccount;
    (*accountCount)++;
    
    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
}

void viewAccountDetails(Account *accounts, int accountCount) {
    int accountNumber;

    printf("Enter account number to view details: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found.\n");
        return;
    }

    Account account = accounts[accountNumber - 1];
    printf("Account Holder: %s\n", account.name);
    printf("Account Number: %d\n", account.accountNumber);
    printf("Current Balance: %.2f\n", account.balance);
}

void deposit(Account *accounts, int accountCount) {
    int accountNumber;
    float amount;

    printf("Enter account number to deposit to: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid deposit amount.\n");
        return;
    }

    accounts[accountNumber - 1].balance += amount;
    printf("Successfully deposited %.2f to account number %d.\n", amount, accountNumber);
}

void withdraw(Account *accounts, int accountCount) {
    int accountNumber;
    float amount;

    printf("Enter account number to withdraw from: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid withdrawal amount.\n");
        return;
    }

    if (amount > accounts[accountNumber - 1].balance) {
        printf("Insufficient funds.\n");
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    printf("Successfully withdrew %.2f from account number %d.\n", amount, accountNumber);
}

void saveAccountsToFile(Account *accounts, int accountCount) {
    FILE *file = fopen(ACCOUNT_FILE, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < accountCount; i++) {
        fprintf(file, "%s %d %.2f\n", accounts[i].name, accounts[i].accountNumber, accounts[i].balance);
    }

    fclose(file);
    printf("Account details saved to file successfully.\n");
}

void loadAccountsFromFile(Account *accounts, int *accountCount) {
    FILE *file = fopen(ACCOUNT_FILE, "r");
    if (!file) {
        printf("No existing account records found.\n");
        return;
    }

    while (fscanf(file, "%s %d %f", accounts[*accountCount].name, &accounts[*accountCount].accountNumber, &accounts[*accountCount].balance) != EOF) {
        (*accountCount)++;
    }

    fclose(file);
    printf("Account details loaded from file successfully.\n");
}