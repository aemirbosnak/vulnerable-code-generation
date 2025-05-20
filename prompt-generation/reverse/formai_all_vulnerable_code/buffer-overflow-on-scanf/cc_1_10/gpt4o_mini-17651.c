//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

typedef struct {
    int accountNumber;
    char name[NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount();
void deposit(int accountNumber);
void withdraw(int accountNumber);
void viewAccount(int accountNumber);
void displayMenu();
int findAccountIndex(int accountNumber);

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Please choose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                printf("Enter account number: ");
                int accNumberDeposit;
                scanf("%d", &accNumberDeposit);
                deposit(accNumberDeposit);
                break;
            case 3:
                printf("Enter account number: ");
                int accNumberWithdraw;
                scanf("%d", &accNumberWithdraw);
                withdraw(accNumberWithdraw);
                break;
            case 4:
                printf("Enter account number: ");
                int accNumberView;
                scanf("%d", &accNumberView);
                viewAccount(accNumberView);
                break;
            case 5:
                printf("Exiting the banking system. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n******** Banking System Menu ********\n");
    printf("1. Create New Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. View Account\n");
    printf("5. Exit\n");
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts. Maximum limit reached.\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // Simple account number assignment
    printf("Enter your name: ");
    scanf("%s", newAccount.name);
    newAccount.balance = 0.0; // Initial balance
    accounts[accountCount++] = newAccount;

    printf("Account created successfully! Your account number is %d.\n", newAccount.accountNumber);
}

void deposit(int accountNumber) {
    int index = findAccountIndex(accountNumber);
    if (index == -1) {
        printf("Account not found.\n");
        return;
    }

    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid deposit amount.\n");
        return;
    }

    accounts[index].balance += amount;
    printf("Deposit successful! New balance: %.2f\n", accounts[index].balance);
}

void withdraw(int accountNumber) {
    int index = findAccountIndex(accountNumber);
    if (index == -1) {
        printf("Account not found.\n");
        return;
    }

    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= 0 || amount > accounts[index].balance) {
        printf("Invalid withdrawal amount.\n");
        return;
    }

    accounts[index].balance -= amount;
    printf("Withdrawal successful! New balance: %.2f\n", accounts[index].balance);
}

void viewAccount(int accountNumber) {
    int index = findAccountIndex(accountNumber);
    if (index == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("Account Number: %d\n", accounts[index].accountNumber);
    printf("Account Holder: %s\n", accounts[index].name);
    printf("Account Balance: %.2f\n", accounts[index].balance);
}

int findAccountIndex(int accountNumber) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            return i;
        }
    }
    return -1; // Account not found
}