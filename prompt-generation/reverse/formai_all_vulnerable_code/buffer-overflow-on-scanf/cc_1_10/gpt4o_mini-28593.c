//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME_LENGTH 100
#define FILE_NAME "accounts.dat"

typedef struct {
    int accountNumber;
    char name[MAX_NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void saveAccountsToFile() {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file != NULL) {
        fwrite(accounts, sizeof(Account), accountCount, file);
        fclose(file);
    } else {
        printf("Error saving accounts to file.\n");
    }
}

void loadAccountsFromFile() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file != NULL) {
        accountCount = fread(accounts, sizeof(Account), MAX_ACCOUNTS, file);
        fclose(file);
    } else {
        printf("No previous accounts found.\n");
    }
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Account limit reached. Cannot create new account.\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // Simple account number generation
    printf("Enter name: ");
    scanf("%s", newAccount.name);
    newAccount.balance = 0.0;

    accounts[accountCount] = newAccount;
    accountCount++;
    saveAccountsToFile();
    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
}

void depositMoney() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    
    if (amount <= 0) {
        printf("Invalid deposit amount.\n");
        return;
    }

    accounts[accountNumber - 1].balance += amount;
    saveAccountsToFile();
    printf("Deposited %.2f to account number %d. New balance: %.2f\n", amount, accountNumber, accounts[accountNumber - 1].balance);
}

void withdrawMoney() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0 || amount > accounts[accountNumber - 1].balance) {
        printf("Invalid withdrawal amount.\n");
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    saveAccountsToFile();
    printf("Withdrew %.2f from account number %d. New balance: %.2f\n", amount, accountNumber, accounts[accountNumber - 1].balance);
}

void viewAccountDetails() {
    int accountNumber;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }

    Account acc = accounts[accountNumber - 1];
    printf("Account Number: %d\n", acc.accountNumber);
    printf("Name: %s\n", acc.name);
    printf("Balance: %.2f\n", acc.balance);
}

void showMenu() {
    printf("\n=== Simple Banking System ===\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. View Account Details\n");
    printf("5. Exit\n");
    printf("=============================\n");
    printf("Choose an option: ");
}

int main() {
    loadAccountsFromFile();
    
    int choice;
    while (1) {
        showMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                viewAccountDetails();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}