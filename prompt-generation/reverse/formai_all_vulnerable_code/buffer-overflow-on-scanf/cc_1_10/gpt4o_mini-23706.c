//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_SIZE 50

typedef struct {
    int accountNumber;
    char name[NAME_SIZE];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

// Function prototypes
void createAccount();
void depositMoney();
void withdrawMoney();
void viewAccount();
void listAccounts();

int main() {
    int choice;

    while (1) {
        printf("\n----- Banking Record System -----\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. View Account\n");
        printf("5. List All Accounts\n");
        printf("6. Exit\n");
        printf("Select an option: ");
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
                viewAccount();
                break;
            case 5:
                listAccounts();
                break;
            case 6:
                printf("Exiting the system...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Account limit reached. Cannot create more accounts.\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = accountCount + 1;

    printf("Enter account holder name: ");
    scanf(" %[^\n]", newAccount.name);

    newAccount.balance = 0.0;

    accounts[accountCount] = newAccount;
    accountCount++;

    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
}

void depositMoney() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Deposit amount must be positive!\n");
        return;
    }

    accounts[accountNumber - 1].balance += amount;
    printf("Deposit successful! New balance: %.2f\n", accounts[accountNumber - 1].balance);
}

void withdrawMoney() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0 || amount > accounts[accountNumber - 1].balance) {
        printf("Invalid withdrawal amount!\n");
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    printf("Withdrawal successful! New balance: %.2f\n", accounts[accountNumber - 1].balance);
}

void viewAccount() {
    int accountNumber;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    printf("\n--- Account Details ---\n");
    printf("Account Number: %d\n", accounts[accountNumber - 1].accountNumber);
    printf("Holder Name: %s\n", accounts[accountNumber - 1].name);
    printf("Balance: %.2f\n", accounts[accountNumber - 1].balance);
}

void listAccounts() {
    printf("\n--- List of Accounts ---\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d, Holder Name: %s, Balance: %.2f\n",
               accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
    if (accountCount == 0) {
        printf("No accounts available.\n");
    }
}