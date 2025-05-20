//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define ACCOUNT_NUMBER_LENGTH 20
#define NAME_LENGTH 50

typedef struct {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    char name[NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount();
void viewAccount();
void depositMoney();
void withdrawMoney();
void displayMenu();
void clearBuffer();

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
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
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n--- Banking Record System ---\n");
    printf("1. Create Account\n");
    printf("2. View Account\n");
    printf("3. Deposit Money\n");
    printf("4. Withdraw Money\n");
    printf("5. Exit\n");
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Account limit reached. Cannot create more accounts.\n");
        return;
    }
    Account newAccount;
    printf("Enter account number: ");
    fgets(newAccount.accountNumber, ACCOUNT_NUMBER_LENGTH, stdin);
    strtok(newAccount.accountNumber, "\n"); // Remove newline character
    printf("Enter account holder's name: ");
    fgets(newAccount.name, NAME_LENGTH, stdin);
    strtok(newAccount.name, "\n"); // Remove newline character
    newAccount.balance = 0.0;

    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account created successfully.\n");
}

void viewAccount() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    printf("Enter account number to view: ");
    fgets(accountNumber, ACCOUNT_NUMBER_LENGTH, stdin);
    strtok(accountNumber, "\n"); // Remove newline character

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Account Number: %s\n", accounts[i].accountNumber);
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Current Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void depositMoney() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float amount;
    printf("Enter account number to deposit money: ");
    fgets(accountNumber, ACCOUNT_NUMBER_LENGTH, stdin);
    strtok(accountNumber, "\n"); // Remove newline character

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            clearBuffer();
            if (amount < 0) {
                printf("Amount must be non-negative. Try again.\n");
                depositMoney(); // Recursive call on invalid input
            } else {
                accounts[i].balance += amount;
                printf("Successfully deposited %.2f. New Balance: %.2f\n", amount, accounts[i].balance);
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void withdrawMoney() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float amount;
    printf("Enter account number to withdraw money: ");
    fgets(accountNumber, ACCOUNT_NUMBER_LENGTH, stdin);
    strtok(accountNumber, "\n"); // Remove newline character

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            clearBuffer();
            if (amount < 0) {
                printf("Amount must be non-negative. Try again.\n");
                withdrawMoney(); // Recursive call on invalid input
            } else if (amount > accounts[i].balance) {
                printf("Insufficient balance. Try again.\n");
                withdrawMoney(); // Recursive call on insufficient funds
            } else {
                accounts[i].balance -= amount;
                printf("Successfully withdrew %.2f. New Balance: %.2f\n", amount, accounts[i].balance);
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void clearBuffer() {
    // Clear the input buffer to avoid residual newline characters
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}