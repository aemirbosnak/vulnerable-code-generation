//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LEN 50
#define FILE_NAME "accounts.dat"

typedef struct {
    int accountNumber;
    char name[NAME_LEN];
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

int main() {
    loadAccounts();
    int choice;

    do {
        printf("\n--- Banking Record System ---\n");
        printf("1. Create Account\n");
        printf("2. View Accounts\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: viewAccounts(); break;
            case 3: deposit(); break;
            case 4: withdraw(); break;
            case 5: saveAccounts(); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
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
    }
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts!\n");
        return;
    }
    Account newAccount;
    newAccount.accountNumber = accountCount + 1;
    
    printf("Enter name: ");
    scanf("%s", newAccount.name);
    
    newAccount.balance = 0.0;
    accounts[accountCount++] = newAccount;
    
    printf("Account created. Account Number: %d\n", newAccount.accountNumber);
}

void viewAccounts() {
    printf("\nList of Accounts:\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d, Name: %s, Balance: %.2f\n", 
                accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}

void deposit() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber < 1 || accountNumber > accountCount) {
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
    printf("Deposited %.2f into account number %d. New balance: %.2f\n", 
           amount, accountNumber, accounts[accountNumber - 1].balance);
}

void withdraw() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber < 1 || accountNumber > accountCount) {
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
    printf("Withdrew %.2f from account number %d. New balance: %.2f\n", 
           amount, accountNumber, accounts[accountNumber - 1].balance);
}