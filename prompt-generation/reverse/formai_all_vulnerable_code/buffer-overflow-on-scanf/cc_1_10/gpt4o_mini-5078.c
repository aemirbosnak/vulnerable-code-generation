//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define ADDRESS_LENGTH 100
#define CURRENCY_SYMBOL "$"

typedef struct {
    char name[NAME_LENGTH];
    char address[ADDRESS_LENGTH];
    int accountNumber;
    double balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void displayNeonMessage(const char *message) {
    printf("\033[1;32m%s\033[0m\n", message); // Neon green text
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        displayNeonMessage("Account limit reached!");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // Assign an account number
    char buffer[100];

    displayNeonMessage("Welcome to the Neon Banking System!");

    printf("Enter your name: ");
    fgets(newAccount.name, NAME_LENGTH, stdin);
    newAccount.name[strcspn(newAccount.name, "\n")] = 0; // Remove the newline character

    printf("Enter your address: ");
    fgets(newAccount.address, ADDRESS_LENGTH, stdin);
    newAccount.address[strcspn(newAccount.address, "\n")] = 0; // Remove the newline character

    newAccount.balance = 0.0; // Initialize balance

    accounts[accountCount++] = newAccount; // Add to account list
    displayNeonMessage("Account created successfully!");
    printf("Your account number is: %d\n", newAccount.accountNumber);
}

void displayAccount(int accountNumber) {
    if (accountNumber < 1 || accountNumber > accountCount) {
        displayNeonMessage("Account not found!");
        return;
    }

    Account account = accounts[accountNumber - 1];
    printf("\n=== Account Details ===\n");
    printf("Account Number: %d\n", account.accountNumber);
    printf("Name: %s\n", account.name);
    printf("Address: %s\n", account.address);
    printf("Balance: %s%.2f\n", CURRENCY_SYMBOL, account.balance);
}

void depositFunds(int accountNumber, double amount) {
    if (accountNumber < 1 || accountNumber > accountCount) {
        displayNeonMessage("Account not found!");
        return;
    }

    if (amount <= 0) {
        displayNeonMessage("Invalid deposit amount!");
        return;
    }

    accounts[accountNumber - 1].balance += amount;
    displayNeonMessage("Funds deposited successfully!");
    printf("New balance: %s%.2f\n", CURRENCY_SYMBOL, accounts[accountNumber - 1].balance);
}

void withdrawFunds(int accountNumber, double amount) {
    if (accountNumber < 1 || accountNumber > accountCount) {
        displayNeonMessage("Account not found!");
        return;
    }

    if (amount <= 0 || amount > accounts[accountNumber - 1].balance) {
        displayNeonMessage("Invalid withdrawal amount!");
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    displayNeonMessage("Funds withdrawn successfully!");
    printf("New balance: %s%.2f\n", CURRENCY_SYMBOL, accounts[accountNumber - 1].balance);
}

void menu() {
    int choice, accountNumber;
    double amount;

    while (1) {
        printf("\n--- Neon Banking Menu ---\n");
        printf("1. Create Account\n");
        printf("2. View Account\n");
        printf("3. Deposit Funds\n");
        printf("4. Withdraw Funds\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                printf("Enter your account number: ");
                scanf("%d", &accountNumber);
                getchar();
                displayAccount(accountNumber);
                break;
            case 3:
                printf("Enter your account number: ");
                scanf("%d", &accountNumber);
                printf("Enter amount to deposit: ");
                scanf("%lf", &amount);
                getchar();
                depositFunds(accountNumber, amount);
                break;
            case 4:
                printf("Enter your account number: ");
                scanf("%d", &accountNumber);
                printf("Enter amount to withdraw: ");
                scanf("%lf", &amount);
                getchar();
                withdrawFunds(accountNumber, amount);
                break;
            case 5:
                displayNeonMessage("Thank you for using Neon Banking! Goodbye!");
                exit(0);
            default:
                displayNeonMessage("Invalid option! Please try again.");
                break;
        }
    }
}

int main() {
    menu();
    return 0;
}