//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 100

typedef struct {
    int accountNumber;
    char nome[NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount == MAX_ACCOUNTS) {
        printf("Maximum account limit reached.\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // starting account number from 1
    printf("Enter name: ");
    scanf("%s", newAccount.nome);
    newAccount.balance = 0.0;

    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account created successfully! Your account number is %d\n", newAccount.accountNumber);
}

void depositMoney() {
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    accounts[accountNumber - 1].balance += amount;
    printf("Successfully deposited %.2f to account %d\n", amount, accountNumber);
}

void withdrawMoney() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    
    if (amount > accounts[accountNumber - 1].balance) {
        printf("Insufficient balance.\n");
    } else {
        accounts[accountNumber - 1].balance -= amount;
        printf("Successfully withdrew %.2f from account %d\n", amount, accountNumber);
    }
}

void viewBalance() {
    int accountNumber;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found.\n");
    } else {
        printf("Account Number: %d\n", accountNumber);
        printf("Name: %s\n", accounts[accountNumber - 1].nome);
        printf("Balance: %.2f\n", accounts[accountNumber - 1].balance);
    }
}

void displayAllAccounts() {
    if (accountCount == 0) {
        printf("No accounts available.\n");
        return;
    }

    printf("List of Accounts:\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d, Name: %s, Balance: %.2f\n", 
               accounts[i].accountNumber, accounts[i].nome, accounts[i].balance);
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
                displayAllAccounts();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}