//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

typedef struct {
    int accountNumber;
    char name[NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void displayMenu() {
    printf("\nBanking Record System\n");
    printf("1. Create Account\n");
    printf("2. View Account\n");
    printf("3. Deposit Money\n");
    printf("4. Withdraw Money\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts. Limit reached!\n");
        return;
    }
    
    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // Simple account number generation
    printf("Enter account holder's name: ");
    scanf("%s", newAccount.name);
    newAccount.balance = 0.0f;
    
    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
}

void viewAccount() {
    int accountNumber;
    printf("Enter account number to view: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found!\n");
        return;
    }

    Account account = accounts[accountNumber - 1];
    printf("Account Number: %d\n", account.accountNumber);
    printf("Account Holder: %s\n", account.name);
    printf("Current Balance: %.2f\n", account.balance);
}

void depositMoney() {
    int accountNumber;
    float amount;
    printf("Enter account number to deposit: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter deposit amount: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid deposit amount!\n");
        return;
    }

    accounts[accountNumber - 1].balance += amount;
    printf("Deposit successful! New Balance: %.2f\n", accounts[accountNumber - 1].balance);
}

void withdrawMoney() {
    int accountNumber;
    float amount;
    printf("Enter account number to withdraw: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found!\n");
        return;
    }

    Account *account = &accounts[accountNumber - 1];
    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);
    
    if (amount <= 0) {
        printf("Invalid withdrawal amount!\n");
        return;
    }

    if (amount > account->balance) {
        printf("Insufficient balance!\n");
        return;
    }

    account->balance -= amount;
    printf("Withdrawal successful! New Balance: %.2f\n", account->balance);
}

int main() {
    int option;
    
    while (1) {
        displayMenu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                createAccount();
                break;
            case 2:
                viewAccount();
                break;
            case 3:
                depositMoney();
                break;
            case 4:
                withdrawMoney();
                break;
            case 5:
                printf("Exiting the Banking Record System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    
    return 0;
}