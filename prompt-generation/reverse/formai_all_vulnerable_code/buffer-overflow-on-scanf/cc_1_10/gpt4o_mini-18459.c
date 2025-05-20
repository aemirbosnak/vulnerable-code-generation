//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

typedef struct {
    int accountNumber;
    char name[NAME_LENGTH];
    float balance;
} BankAccount;

void displayMenu() {
    printf("**********************************************************\n");
    printf("              Welcome to the Banking Record System        \n");
    printf("**********************************************************\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n");
    printf("**********************************************************\n");
    printf("Please select an option (1-5): ");
}

void createAccount(BankAccount accounts[], int *accountCount) {
    if (*accountCount >= MAX_ACCOUNTS) {
        printf("Sorry, maximum account limit reached!\n");
        return;
    }
    BankAccount newAccount;
    newAccount.accountNumber = *accountCount + 1;

    printf("Enter account holder's name: ");
    scanf(" %[^\n]", newAccount.name);
    newAccount.balance = 0.0;

    accounts[*accountCount] = newAccount;
    (*accountCount)++;
    printf("Account created successfully! Your account number is %d.\n", newAccount.accountNumber);
}

void depositMoney(BankAccount accounts[], int accountCount) {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Deposit amount must be greater than zero!\n");
        return;
    }

    accounts[accountNumber - 1].balance += amount;
    printf("Successfully deposited $%.2f to account number %d. New balance is $%.2f.\n",
           amount, accountNumber, accounts[accountNumber - 1].balance);
}

void withdrawMoney(BankAccount accounts[], int accountCount) {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Withdrawal amount must be greater than zero!\n");
        return;
    }

    if (amount > accounts[accountNumber - 1].balance) {
        printf("Insufficient funds to withdraw $%.2f from account number %d.\n",
               amount, accountNumber);
    } else {
        accounts[accountNumber - 1].balance -= amount;
        printf("Successfully withdrew $%.2f from account number %d. New balance is $%.2f.\n",
               amount, accountNumber, accounts[accountNumber - 1].balance);
    }
}

void checkBalance(BankAccount accounts[], int accountCount) {
    int accountNumber;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    printf("Account holder: %s\n", accounts[accountNumber - 1].name);
    printf("Current balance: $%.2f\n", accounts[accountNumber - 1].balance);
}

int main() {
    BankAccount accounts[MAX_ACCOUNTS];
    int accountCount = 0;
    int choice = 0;

    while (choice != 5) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createAccount(accounts, &accountCount);
                break;
            case 2:
                depositMoney(accounts, accountCount);
                break;
            case 3:
                withdrawMoney(accounts, accountCount);
                break;
            case 4:
                checkBalance(accounts, accountCount);
                break;
            case 5:
                printf("Thank you for using the Banking Record System. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice, please select again.\n");
        }
    }

    return 0;
}