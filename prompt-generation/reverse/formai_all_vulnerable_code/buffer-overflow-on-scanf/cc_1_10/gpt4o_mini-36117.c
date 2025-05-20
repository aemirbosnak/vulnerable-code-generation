//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define TRANSACTION_HISTORY_LENGTH 5

typedef struct {
    int accountNumber;
    char accountHolder[NAME_LENGTH];
    double balance;
    char transactions[TRANSACTION_HISTORY_LENGTH][100];
    int transactionCount;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void registerAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum accounts reached!\n");
        return;
    }
    
    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // Account number starts from 1
    newAccount.balance = 0.0;
    newAccount.transactionCount = 0;
    
    printf("Enter account holder's name: ");
    scanf("%s", newAccount.accountHolder);
    
    accounts[accountCount++] = newAccount;
    printf("Account created! Account Number: %d\n", newAccount.accountNumber);
}

void deposit() {
    int accountNumber;
    double amount;
    
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    printf("Enter deposit amount: ");
    scanf("%lf", &amount);
    
    if (amount <= 0) {
        printf("Invalid deposit amount!\n");
        return;
    }
    
    accounts[accountNumber - 1].balance += amount;
    snprintf(accounts[accountNumber - 1].transactions[accounts[accountNumber - 1].transactionCount++], 
             sizeof(accounts[accountNumber - 1].transactions[accounts[accountNumber - 1].transactionCount++]), 
             "Deposited: %.2lf", amount);
    
    printf("Successfully deposited %.2lf into account %d\n", amount, accountNumber);
}

void withdraw() {
    int accountNumber;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    printf("Enter withdrawal amount: ");
    scanf("%lf", &amount);
    
    if (amount <= 0) {
        printf("Invalid withdrawal amount!\n");
        return;
    }

    if (amount > accounts[accountNumber - 1].balance) {
        printf("Insufficient balance!\n");
        return;
    }
    
    accounts[accountNumber - 1].balance -= amount;
    snprintf(accounts[accountNumber - 1].transactions[accounts[accountNumber - 1].transactionCount++],
             sizeof(accounts[accountNumber - 1].transactions[accounts[accountNumber - 1].transactionCount++]), 
             "Withdrawn: %.2lf", amount);

    printf("Successfully withdrew %.2lf from account %d\n", amount, accountNumber);
}

void checkBalance() {
    int accountNumber;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    printf("Current balance for account %d: %.2lf\n", accountNumber, accounts[accountNumber - 1].balance);
}

void viewTransactionHistory() {
    int accountNumber;
    
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    printf("Transaction history for account %d:\n", accountNumber);
    for (int i = 0; i < accounts[accountNumber - 1].transactionCount; i++) {
        printf("%s\n", accounts[accountNumber - 1].transactions[i]);
    }
}

void displayMenu() {
    printf("\n");
    printf("Banking Record System\n");
    printf("1. Register Account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Check Balance\n");
    printf("5. View Transaction History\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int option;
    
    while (1) {
        displayMenu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                registerAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                viewTransactionHistory();
                break;
            case 6:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}