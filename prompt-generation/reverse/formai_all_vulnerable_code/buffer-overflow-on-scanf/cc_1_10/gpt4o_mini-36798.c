//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define ACCOUNT_NUMBER_LENGTH 10
#define NAME_LENGTH 50
#define INITIAL_BALANCE 0

typedef struct {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    char name[NAME_LENGTH];
    float balance;
} BankAccount;

BankAccount accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached. Cannot create more accounts.\n");
        return;
    }

    BankAccount newAccount;
    printf("Enter account number: ");
    scanf("%s", newAccount.accountNumber);
    printf("Enter account holder's name: ");
    scanf(" %[^\n]", newAccount.name);
    newAccount.balance = INITIAL_BALANCE;

    accounts[accountCount++] = newAccount;
    printf("Account created successfully for %s!\n", newAccount.name);
}

void deposit() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float amount;

    printf("Enter account number: ");
    scanf("%s", accountNumber);
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            accounts[i].balance += amount;
            printf("Successfully deposited %.2f to account %s. New balance: %.2f\n",
                   amount, accountNumber, accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void withdraw() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float amount;

    printf("Enter account number: ");
    scanf("%s", accountNumber);
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Successfully withdrew %.2f from account %s. New balance: %.2f\n",
                       amount, accountNumber, accounts[i].balance);
            } else {
                printf("Insufficient funds in account %s.\n", accountNumber);
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void viewAccount() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    
    printf("Enter account number: ");
    scanf("%s", accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Account Number: %s\n", accounts[i].accountNumber);
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Account Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void showMenu() {
    printf("\n------ Banking Record System ------\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. View Account Details\n");
    printf("5. Exit\n");
    printf("-----------------------------------\n");
}

int main() {
    int choice;

    while (1) {
        showMenu();
        printf("Choose an option: ");
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
                viewAccount();
                break;
            case 5:
                printf("Thank you for using the Banking Record System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}