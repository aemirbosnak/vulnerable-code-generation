//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 30
#define PASSWORD_LENGTH 20

typedef struct {
    int accountNumber;
    char name[NAME_LENGTH];
    float balance;
    char password[PASSWORD_LENGTH];
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void addAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Account limit reached. No new accounts can be created.\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = accountCount + 1;
    printf("Enter your name: ");
    scanf("%s", newAccount.name);
    printf("Set your password: ");
    scanf("%s", newAccount.password);
    newAccount.balance = 0.0;

    accounts[accountCount] = newAccount;
    accountCount++;

    printf("Account created successfully! Your account number is %d\n", newAccount.accountNumber);
}

int findAccount(int accountNumber, const char *password) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber && 
            strcmp(accounts[i].password, password) == 0) {
                return i;
        }
    }
    return -1; // Not found
}

void deposit(int accountIndex) {
    float amount;
    printf("Enter deposit amount: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid deposit amount.\n");
        return;
    }

    accounts[accountIndex].balance += amount;
    printf("Deposit successful! New balance: %.2f\n", accounts[accountIndex].balance);
}

void withdraw(int accountIndex) {
    float amount;
    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);

    if (amount <= 0 || amount > accounts[accountIndex].balance) {
        printf("Invalid withdrawal amount.\n");
        return;
    }

    accounts[accountIndex].balance -= amount;
    printf("Withdrawal successful! New balance: %.2f\n", accounts[accountIndex].balance);
}

void viewBalance(int accountIndex) {
    printf("Your balance is: %.2f\n", accounts[accountIndex].balance);
}

void displayMenu() {
    printf("\n=== Banking System ===\n");
    printf("1. Create Account\n");
    printf("2. Login\n");
    printf("3. Exit\n");
    printf("=======================\n");
}

void userMenu(int accountIndex) {
    int choice;
    do {
        printf("\n=== User Menu ===\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. View Balance\n");
        printf("4. Logout\n");
        printf("==================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deposit(accountIndex);
                break;
            case 2:
                withdraw(accountIndex);
                break;
            case 3:
                viewBalance(accountIndex);
                break;
            case 4:
                printf("Logging out...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 4);
}

int main() {
    int mainChoice;

    do {
        displayMenu();
        printf("\nSelect an option: ");
        scanf("%d", &mainChoice);

        switch (mainChoice) {
            case 1:
                addAccount();
                break;
            case 2: {
                int accountNumber;
                char password[PASSWORD_LENGTH];
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter password: ");
                scanf("%s", password);

                int accountIndex = findAccount(accountNumber, password);
                if (accountIndex == -1) {
                    printf("Invalid account number or password.\n");
                } else {
                    printf("Login successful!\n");
                    userMenu(accountIndex);
                }
                break;
            }
            case 3:
                printf("Exiting the banking system. Have a paranoid day!\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    } while (mainChoice != 3);

    return 0;
}