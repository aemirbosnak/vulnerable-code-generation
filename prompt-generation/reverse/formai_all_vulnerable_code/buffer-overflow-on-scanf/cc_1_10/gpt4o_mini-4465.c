//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: introspective
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

void loadAccounts();
void saveAccounts();
void createAccount();
void viewAccounts();
void deposit();
void withdraw();
void menu();

int main() {
    loadAccounts();
    menu();
    saveAccounts();
    return 0;
}

void loadAccounts() {
    FILE *file = fopen("accounts.dat", "rb");
    if (file == NULL) {
        printf("No existing account records found. Starting fresh.\n");
        return;
    }
    fread(&accountCount, sizeof(int), 1, file);
    fread(accounts, sizeof(Account), accountCount, file);
    fclose(file);
}

void saveAccounts() {
    FILE *file = fopen("accounts.dat", "wb");
    fwrite(&accountCount, sizeof(int), 1, file);
    fwrite(accounts, sizeof(Account), accountCount, file);
    fclose(file);
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Account limit reached. Cannot create more accounts.\n");
        return;
    }
    Account newAccount;
    printf("Enter account holder's name: ");
    scanf("%s", newAccount.name);
    printf("Enter account number: ");
    scanf("%s", newAccount.accountNumber);
    newAccount.balance = 0.0f;

    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account created successfully!\n");
}

void viewAccounts() {
    printf("\nList of Accounts:\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Name: %s | Account Number: %s | Balance: $%.2f\n",
               accounts[i].name,
               accounts[i].accountNumber,
               accounts[i].balance);
    }
}

void deposit() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float amount;
    printf("Enter account number for deposit: ");
    scanf("%s", accountNumber);
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            accounts[i].balance += amount;
            printf("Deposited $%.2f into account %s. New balance: $%.2f\n",
                   amount, accounts[i].accountNumber, accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float amount;
    printf("Enter account number for withdrawal: ");
    scanf("%s", accountNumber);
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrew $%.2f from account %s. New balance: $%.2f\n",
                       amount, accounts[i].accountNumber, accounts[i].balance);
            } else {
                printf("Insufficient funds.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void menu() {
    int choice;
    do {
        printf("\nBanking System Menu:\n");
        printf("1. Create Account\n");
        printf("2. View Accounts\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: viewAccounts(); break;
            case 3: deposit(); break;
            case 4: withdraw(); break;
            case 5: printf("Exiting system. Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n"); break;
        }
    } while (choice != 5);
}