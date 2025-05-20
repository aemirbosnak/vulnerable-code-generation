//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: intelligent
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
void checkBalance(int accountNumber);
int findAccount(int accountNumber);
void displayMenu();

int main() {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                {
                    int accountNumber;
                    printf("Enter account number: ");
                    scanf("%d", &accountNumber);
                    deposit(accountNumber);
                    break;
                }
            case 3:
                {
                    int accountNumber;
                    printf("Enter account number: ");
                    scanf("%d", &accountNumber);
                    withdraw(accountNumber);
                    break;
                }
            case 4:
                {
                    int accountNumber;
                    printf("Enter account number: ");
                    scanf("%d", &accountNumber);
                    checkBalance(accountNumber);
                    break;
                }
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n=== Banking Record System ===\n");
    printf("1. Create Account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Account limit reached! Cannot create more accounts.\n");
        return;
    }
    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // Simple account number generation
    newAccount.balance = 0.0;
    newAccount.isActive = 1;

    printf("Enter your name: ");
    getchar(); // Clear input buffer
    fgets(newAccount.name, NAME_LENGTH, stdin);
    newAccount.name[strcspn(newAccount.name, "\n")] = 0; // Remove newline character

    accounts[accountCount] = newAccount;
    accountCount++;
    
    printf("Account created successfully! Your account number is: %d\n", newAccount.accountNumber);
}

int findAccount(int accountNumber) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber && accounts[i].isActive) {
            return i;
        }
    }
    return -1;
}

void deposit(int accountNumber) {
    int index = findAccount(accountNumber);
    if (index == -1) {
        printf("Account not found or inactive.\n");
        return;
    }
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid amount! Please enter a positive value.\n");
        return;
    }
    accounts[index].balance += amount;
    printf("Deposit successful! New balance: $%.2f\n", accounts[index].balance);
}

void withdraw(int accountNumber) {
    int index = findAccount(accountNumber);
    if (index == -1) {
        printf("Account not found or inactive.\n");
        return;
    }
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid amount! Please enter a positive value.\n");
        return;
    } else if (amount > accounts[index].balance) {
        printf("Insufficient funds! Current balance: $%.2f\n", accounts[index].balance);
        return;
    }
    accounts[index].balance -= amount;
    printf("Withdrawal successful! New balance: $%.2f\n", accounts[index].balance);
}

void checkBalance(int accountNumber) {
    int index = findAccount(accountNumber);
    if (index == -1) {
        printf("Account not found or inactive.\n");
        return;
    }
    printf("Current balance: $%.2f\n", accounts[index].balance);
}