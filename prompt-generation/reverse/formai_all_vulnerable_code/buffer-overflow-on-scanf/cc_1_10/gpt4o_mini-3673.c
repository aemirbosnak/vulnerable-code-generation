//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define FILE_NAME "accounts.dat"

typedef struct {
    int accountNumber;
    char name[100];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void loadAccounts();
void saveAccounts();
void createAccount();
void deposit();
void withdraw();
void viewAccount();
int findAccount(int accountNumber);
void displayMenu();

int main() {
    loadAccounts();
    
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: viewAccount(); break;
            case 5: saveAccounts(); printf("Exiting system...\n"); exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n========== Banking Record System ==========\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. View Account\n");
    printf("5. Exit\n");
    printf("===========================================\n");
}

void loadAccounts() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file) {
        fread(&accountCount, sizeof(int), 1, file);
        fread(accounts, sizeof(Account), accountCount, file);
        fclose(file);
    }
}

void saveAccounts() {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file) {
        fwrite(&accountCount, sizeof(int), 1, file);
        fwrite(accounts, sizeof(Account), accountCount, file);
        fclose(file);
        printf("Accounts saved successfully!\n");
    } else {
        printf("Error saving accounts.\n");
    }
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Account limit reached. Cannot create more accounts.\n");
        return;
    }
    Account newAccount;
    newAccount.balance = 0.0;

    printf("Enter name for new account: ");
    scanf(" %[^\n]", newAccount.name);
    newAccount.accountNumber = accountCount + 1; // Simple increment for unique account number

    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
}

void deposit() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    int index = findAccount(accountNumber);
    if (index != -1) {
        printf("Enter amount to deposit: ");
        scanf("%f", &amount);
        if (amount > 0) {
            accounts[index].balance += amount;
            printf("Deposited %.2f to account %d. New balance: %.2f\n",
                   amount, accountNumber, accounts[index].balance);
        } else {
            printf("Invalid amount. Please enter a positive number.\n");
        }
    } else {
        printf("Account not found.\n");
    }
}

void withdraw() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    int index = findAccount(accountNumber);
    if (index != -1) {
        printf("Enter amount to withdraw: ");
        scanf("%f", &amount);
        if (amount > 0 && amount <= accounts[index].balance) {
            accounts[index].balance -= amount;
            printf("Withdrew %.2f from account %d. New balance: %.2f\n",
                   amount, accountNumber, accounts[index].balance);
        } else {
            printf("Invalid amount. Please ensure you have sufficient balance.\n");
        }
    } else {
        printf("Account not found.\n");
    }
}

void viewAccount() {
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    int index = findAccount(accountNumber);
    if (index != -1) {
        printf("Account Number: %d\n", accounts[index].accountNumber);
        printf("Account Holder: %s\n", accounts[index].name);
        printf("Current Balance: %.2f\n", accounts[index].balance);
    } else {
        printf("Account not found.\n");
    }
}

int findAccount(int accountNumber) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            return i;
        }
    }
    return -1; // Account not found
}