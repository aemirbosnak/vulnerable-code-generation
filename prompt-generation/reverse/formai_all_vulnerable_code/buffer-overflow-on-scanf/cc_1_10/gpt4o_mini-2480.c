//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define ACCOUNT_NUMBER_LENGTH 10
#define NAME_LENGTH 50
#define FILE_NAME "accounts.dat"

typedef struct {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    char name[NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void saveAccounts() {
    FILE *file = fopen(FILE_NAME, "wb");
    fwrite(accounts, sizeof(Account), accountCount, file);
    fclose(file);
}

void loadAccounts() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file) {
        accountCount = fread(accounts, sizeof(Account), MAX_ACCOUNTS, file);
        fclose(file);
    }
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Account limit reached. Cannot create a new account.\n");
        return;
    }
    
    Account newAccount;
    printf("Enter account number: ");
    scanf("%s", newAccount.accountNumber);
    printf("Enter account holder's name: ");
    scanf(" %[^\n]", newAccount.name);
    newAccount.balance = 0.0;

    accounts[accountCount++] = newAccount;
    printf("Account created successfully!\n");
    
    saveAccounts();
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
            printf("Successfully deposited %.2f to account %s. New balance: %.2f\n", amount, accounts[i].accountNumber, accounts[i].balance);
            saveAccounts();
            return;
        }
    }
    printf("Account not found!\n");
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
            if (amount > accounts[i].balance) {
                printf("Insufficient balance!\n");
            } else {
                accounts[i].balance -= amount;
                printf("Successfully withdrew %.2f from account %s. New balance: %.2f\n", amount, accounts[i].accountNumber, accounts[i].balance);
                saveAccounts();
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void displayAccounts() {
    printf("\nList of all accounts:\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %s, Name: %s, Balance: %.2f\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}

void menu() {
    int choice;
    
    do {
        printf("\nBanking Record System Menu:\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display All Accounts\n");
        printf("5. Exit\n");
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
                printf("Thank you for using the Banking Record System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    loadAccounts();
    menu();
    return 0;
}