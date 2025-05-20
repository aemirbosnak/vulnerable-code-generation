//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

typedef struct {
    int accountNumber;
    char name[NAME_LENGTH];
    float balance;
    int isActive;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount();
void deposit(int accountNumber);
void withdraw(int accountNumber);
void displayAccounts();
int findAccount(int accountNumber);
void clearScreen();

int main() {
    int choice;

    do {
        clearScreen();
        printf("***** Banking Record System *****\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display All Accounts\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                printf("Enter your account number: ");
                {
                    int accountNumber;
                    scanf("%d", &accountNumber);
                    deposit(accountNumber);
                }
                break;
            case 3:
                printf("Enter your account number: ");
                {
                    int accountNumber;
                    scanf("%d", &accountNumber);
                    withdraw(accountNumber);
                }
                break;
            case 4:
                displayAccounts();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
        printf("Press Enter to continue...");
        while(getchar() != '\n'); // To pause before clearing screen
        getchar();
    } while (choice != 5);

    return 0;
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Account creation limit reached.\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // simple account number increment
    printf("Enter your name: ");
    scanf(" %[^\n]", newAccount.name);
    newAccount.balance = 0.0;
    newAccount.isActive = 1; // account is active by default

    accounts[accountCount] = newAccount;
    accountCount++;

    printf("Account created successfully! Your account number is %d\n", newAccount.accountNumber);
}

void deposit(int accountNumber) {
    int index = findAccount(accountNumber);
    if (index == -1) {
        printf("Account not found.\n");
        return;
    }

    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount < 0) {
        printf("Invalid deposit amount.\n");
        return;
    }

    accounts[index].balance += amount;
    printf("Amount deposited successfully. New balance: %.2f\n", accounts[index].balance);
}

void withdraw(int accountNumber) {
    int index = findAccount(accountNumber);
    if (index == -1) {
        printf("Account not found.\n");
        return;
    }

    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount < 0 || amount > accounts[index].balance) {
        printf("Invalid withdrawal amount.\n");
        return;
    }

    accounts[index].balance -= amount;
    printf("Amount withdrawn successfully. New balance: %.2f\n", accounts[index].balance);
}

void displayAccounts() {
    printf("***** Account List *****\n");
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].isActive) {
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Name: %s\n", accounts[i].name);
            printf("Balance: %.2f\n", accounts[i].balance);
            printf("-------------------------------\n");
        }
    }
}

int findAccount(int accountNumber) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber && accounts[i].isActive) {
            return i; // return the index of the account
        }
    }
    return -1; // account not found
}

void clearScreen() {
    printf("\033[H\033[J");  // ANSI escape code to clear the terminal
}