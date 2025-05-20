//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char name[100];
    float balance;
} Account;

Account bankAccounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached. Cannot create new account.\n");
        return;
    }
    
    Account newAccount;
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);
    
    printf("Enter name: ");
    getchar(); // Consume newline left by scanf
    fgets(newAccount.name, sizeof(newAccount.name), stdin);
    newAccount.name[strcspn(newAccount.name, "\n")] = 0; // Remove newline

    newAccount.balance = 0.0;
    bankAccounts[accountCount] = newAccount;
    accountCount++;

    printf("Account created successfully!\n");
}

void deposit() {
    int accountNumber;
    float amount;

    printf("Enter account number to deposit into: ");
    scanf("%d", &accountNumber);
    
    Account *account = NULL;
    for (int i = 0; i < accountCount; i++) {
        if (bankAccounts[i].accountNumber == accountNumber) {
            account = &bankAccounts[i];
            break;
        }
    }

    if (account == NULL) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    
    if (amount <= 0) {
        printf("Invalid deposit amount. Must be greater than zero.\n");
        return;
    }

    account->balance += amount;
    printf("Deposited %.2f to account number %d. New balance: %.2f\n", amount, accountNumber, account->balance);
}

void withdraw() {
    int accountNumber;
    float amount;

    printf("Enter account number to withdraw from: ");
    scanf("%d", &accountNumber);
    
    Account *account = NULL;
    for (int i = 0; i < accountCount; i++) {
        if (bankAccounts[i].accountNumber == accountNumber) {
            account = &bankAccounts[i];
            break;
        }
    }

    if (account == NULL) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    
    if (amount <= 0) {
        printf("Invalid withdrawal amount. Must be greater than zero.\n");
        return;
    }

    if (amount > account->balance) {
        printf("Insufficient funds. Current balance: %.2f\n", account->balance);
        return;
    }

    account->balance -= amount;
    printf("Withdrew %.2f from account number %d. New balance: %.2f\n", amount, accountNumber, account->balance);
}

void displayAccount() {
    int accountNumber;
    printf("Enter account number to display: ");
    scanf("%d", &accountNumber);
    
    Account *account = NULL;
    for (int i = 0; i < accountCount; i++) {
        if (bankAccounts[i].accountNumber == accountNumber) {
            account = &bankAccounts[i];
            break;
        }
    }

    if (account == NULL) {
        printf("Account not found.\n");
        return;
    }

    printf("Account Number: %d\n", account->accountNumber);
    printf("Account Holder: %s\n", account->name);
    printf("Current Balance: %.2f\n", account->balance);
}

void displayAllAccounts() {
    if (accountCount == 0) {
        printf("No accounts available.\n");
        return;
    }
    printf("Listing all accounts:\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d, Account Holder: %s, Balance: %.2f\n", 
               bankAccounts[i].accountNumber, bankAccounts[i].name, bankAccounts[i].balance);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nBanking System Menu:\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display Account\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
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
                displayAccount();
                break;
            case 5:
                displayAllAccounts();
                break;
            case 6:
                printf("Exiting the banking system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}