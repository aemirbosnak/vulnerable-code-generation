//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define BUFFER_SIZE 100

typedef struct {
    int accountNumber;
    char name[NAME_LENGTH];
    double balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void printMenu() {
    printf("\n==== Banking Record System ====\n");
    printf("1. Create Account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. View Account\n");
    printf("5. Exit\n");
    printf("==============================\n");
    printf("Choose an option: ");
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Account limit reached!\n");
        return;
    }
    Account newAccount;
    newAccount.accountNumber = accountCount + 1;
    printf("Enter Name: ");
    fgets(newAccount.name, NAME_LENGTH, stdin);
    newAccount.name[strcspn(newAccount.name, "\n")] = 0; // Remove newline
    newAccount.balance = 0.0;

    accounts[accountCount] = newAccount;
    accountCount++;

    printf("Account created! Account Number: %d\n", newAccount.accountNumber);
}

void deposit() {
    int accNumber;
    double amount;
    printf("Enter Account Number: ");
    scanf("%d", &accNumber);
    printf("Enter Deposit Amount: ");
    scanf("%lf", &amount);
    getchar(); // To consume newline

    if (accNumber < 1 || accNumber > accountCount) {
        printf("Invalid Account Number!\n");
        return;
    }

    if (amount <= 0) {
        printf("Enter a valid amount!\n");
        return;
    }

    accounts[accNumber - 1].balance += amount;
    printf("Deposited %.2f to Account %d. New Balance: %.2f\n", amount, accNumber, accounts[accNumber - 1].balance);
}

void withdraw() {
    int accNumber;
    double amount;
    printf("Enter Account Number: ");
    scanf("%d", &accNumber);
    printf("Enter Withdraw Amount: ");
    scanf("%lf", &amount);
    getchar(); // To consume newline

    if (accNumber < 1 || accNumber > accountCount) {
        printf("Invalid Account Number!\n");
        return;
    }

    if (amount <= 0) {
        printf("Enter a valid amount!\n");
        return;
    }

    if (accounts[accNumber - 1].balance < amount) {
        printf("Insufficient Balance!\n");
        return;
    }

    accounts[accNumber - 1].balance -= amount;
    printf("Withdrew %.2f from Account %d. New Balance: %.2f\n", amount, accNumber, accounts[accNumber - 1].balance);
}

void viewAccount() {
    int accNumber;
    printf("Enter Account Number: ");
    scanf("%d", &accNumber);
    getchar(); // To consume newline

    if (accNumber < 1 || accNumber > accountCount) {
        printf("Invalid Account Number!\n");
        return;
    }

    Account acc = accounts[accNumber - 1];
    printf("\nAccount Number: %d\n", acc.accountNumber);
    printf("Name: %s\n", acc.name);
    printf("Balance: %.2f\n", acc.balance);
}

int main() {
    int choice;
    while (1) {
        printMenu();
        scanf("%d", &choice);
        getchar(); // To consume newline

        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: viewAccount(); break;
            case 5: printf("Exiting the program. Goodbye!\n"); exit(0);
            default: printf("Invalid choice! Please select again.\n");
        }
    }
    return 0;
}