//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LEN 50

typedef struct {
    int accountNumber;
    char name[NAME_LEN];
    double balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts. Limit reached.\n");
        return;
    }
    
    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // Simple account number generation
    printf("Enter name for account holder: ");
    scanf("%s", newAccount.name);
    newAccount.balance = 0.0;

    accounts[accountCount] = newAccount;
    accountCount++;

    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
}

void depositMoney() {
    int accountNumber;
    double deposit;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%lf", &deposit);

    accounts[accountNumber - 1].balance += deposit;
    printf("Deposited %.2f to account number %d. New balance: %.2f\n", deposit, accountNumber, accounts[accountNumber - 1].balance);
}

void withdrawMoney() {
    int accountNumber;
    double withdrawal;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%lf", &withdrawal);

    if (withdrawal > accounts[accountNumber - 1].balance) {
        printf("Insufficient funds! Current balance: %.2f\n", accounts[accountNumber - 1].balance);
    } else {
        accounts[accountNumber - 1].balance -= withdrawal;
        printf("Withdrew %.2f from account number %d. New balance: %.2f\n", withdrawal, accountNumber, accounts[accountNumber - 1].balance);
    }
}

void viewBalance() {
    int accountNumber;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Current balance for account number %d: %.2f\n", accountNumber, accounts[accountNumber - 1].balance);
}

void displayAccounts() {
    printf("Account List:\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d, Name: %s, Balance: %.2f\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nBanking Record System\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. View Balance\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
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
                viewBalance();
                break;
            case 5:
                displayAccounts();
                break;
            case 6:
                printf("Exiting the Banking Record System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}