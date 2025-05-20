//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void displayMenu() {
    printf("\n=== Welcome to the Banking Record System ===\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Check Balance\n");
    printf("5. Display All Accounts\n");
    printf("6. Exit\n");
    printf("==============================================\n");
    printf("Choose an option: ");
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached!\n");
        return;
    }
    
    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // Simple increment for account number
    printf("Enter Account Holder's Name: ");
    scanf("%s", newAccount.name);
    newAccount.balance = 0.0f;

    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
}

void depositMoney() {
    int accountNumber;
    float amount;

    printf("Enter Account Number to Deposit: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid Account Number!\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid deposit amount!\n");
        return;
    }

    accounts[accountNumber - 1].balance += amount;
    printf("Successfully deposited %.2f to account %d. New balance: %.2f\n", amount, accountNumber, accounts[accountNumber - 1].balance);
}

void withdrawMoney() {
    int accountNumber;
    float amount;

    printf("Enter Account Number to Withdraw: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid Account Number!\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid withdrawal amount!\n");
        return;
    }

    if (accounts[accountNumber - 1].balance < amount) {
        printf("Insufficient funds! Current balance: %.2f\n", accounts[accountNumber - 1].balance);
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    printf("Successfully withdrew %.2f from account %d. New balance: %.2f\n", amount, accountNumber, accounts[accountNumber - 1].balance);
}

void checkBalance() {
    int accountNumber;

    printf("Enter Account Number to Check Balance: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid Account Number!\n");
        return;
    }

    printf("The balance for account %d is: %.2f\n", accountNumber, accounts[accountNumber - 1].balance);
}

void displayAllAccounts() {
    if (accountCount == 0) {
        printf("No accounts available!\n");
        return;
    }

    printf("\n=== List of All Accounts ===\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d, Name: %s, Balance: %.2f\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}

int main() {
    int choice;
    
    while (1) {
        displayMenu();
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
                checkBalance();
                break;
            case 5:
                displayAllAccounts();
                break;
            case 6:
                printf("Thank you for using the Banking Record System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}