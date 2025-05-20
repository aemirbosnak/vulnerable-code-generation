//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char name[100];
    float balance;
} BankAccount;

BankAccount accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached.\n");
        return;
    }

    BankAccount newAccount;
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);
    getchar(); // consume newline character
    printf("Enter account holder name: ");
    fgets(newAccount.name, sizeof(newAccount.name), stdin);
    newAccount.name[strcspn(newAccount.name, "\n")] = 0; // remove newline
    newAccount.balance = 0.0;

    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account created successfully!\n");
}

void deposit() {
    int accountNumber;
    float amount;

    printf("Enter account number for deposit: ");
    scanf("%d", &accountNumber);
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            accounts[i].balance += amount;
            printf("Deposited %.2f. New balance is %.2f\n", amount, accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw() {
    int accountNumber;
    float amount;

    printf("Enter account number for withdrawal: ");
    scanf("%d", &accountNumber);
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (amount > accounts[i].balance) {
                printf("Insufficient funds. Current balance is %.2f\n", accounts[i].balance);
            } else {
                accounts[i].balance -= amount;
                printf("Withdrew %.2f. New balance is %.2f\n", amount, accounts[i].balance);
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void displayAccountDetails() {
    int accountNumber;

    printf("Enter account number to display details: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("\nAccount Number: %d\n", accounts[i].accountNumber);
            printf("Account Holder Name: %s\n", accounts[i].name);
            printf("Current Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void showMenu() {
    printf("\n--- Banking Record System ---\n");
    printf("1. Create Account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Display Account Details\n");
    printf("5. Exit\n");
    printf("-----------------------------\n");
}

int main() {
    int choice;

    while (1) {
        showMenu();
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
                displayAccountDetails();
                break;
            case 5:
                printf("Exiting the system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}