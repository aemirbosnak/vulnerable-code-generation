//GPT-4o-mini DATASET v1.0 Category: Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define PASSWORD_LENGTH 20

typedef struct {
    int accountNumber;
    char name[NAME_LENGTH];
    char password[PASSWORD_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount();
void deposit(int accountNumber);
void withdraw(int accountNumber);
void checkBalance(int accountNumber);
int authenticate(int *accountNumber);

int main() {
    int choice, accountNumber;

    while (1) {
        printf("\n===== Banking System =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                if (authenticate(&accountNumber)) {
                    deposit(accountNumber);
                }
                break;
            case 3:
                if (authenticate(&accountNumber)) {
                    withdraw(accountNumber);
                }
                break;
            case 4:
                if (authenticate(&accountNumber)) {
                    checkBalance(accountNumber);
                }
                break;
            case 5:
                printf("Thank you for using the Banking System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
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
    newAccount.accountNumber = accountCount + 1; // Assigning account number
    printf("Enter your name: ");
    scanf(" %[^\n]s", newAccount.name);
    printf("Create a password: ");
    scanf(" %[^\n]s", newAccount.password);
    newAccount.balance = 0.0;

    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account created successfully! Your account number is %d\n", newAccount.accountNumber);
}

int authenticate(int *accountNumber) {
    int accNum;
    char pass[PASSWORD_LENGTH];

    printf("Enter your account number: ");
    scanf("%d", &accNum);
    if (accNum < 1 || accNum > accountCount) {
        printf("Invalid account number.\n");
        return 0;
    }

    printf("Enter your password: ");
    scanf(" %[^\n]s", pass);

    if (strcmp(accounts[accNum - 1].password, pass) != 0) {
        printf("Authentication failed! Incorrect password.\n");
        return 0;
    }

    *accountNumber = accNum - 1; // Store index for further operations
    return 1;
}

void deposit(int accountNumber) {
    float amount;
    printf("Enter deposit amount: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid amount. Please enter a positive value.\n");
        return;
    }
    accounts[accountNumber].balance += amount;
    printf("Successfully deposited %.2f. New balance is %.2f.\n", amount, accounts[accountNumber].balance);
}

void withdraw(int accountNumber) {
    float amount;
    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid amount. Please enter a positive value.\n");
        return;
    }
    if (accounts[accountNumber].balance < amount) {
        printf("Insufficient funds. Current balance is %.2f.\n", accounts[accountNumber].balance);
        return;
    }
    accounts[accountNumber].balance -= amount;
    printf("Successfully withdrew %.2f. New balance is %.2f.\n", amount, accounts[accountNumber].balance);
}

void checkBalance(int accountNumber) {
    printf("Your current balance is: %.2f\n", accounts[accountNumber].balance);
}