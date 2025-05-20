//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Account limit reached!\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // Incremental account number
    printf("Enter your name: ");
    scanf(" %[^\n]", newAccount.name);
    newAccount.balance = 0.0f;

    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
}

void viewAccount(int accountNumber) {
    if(accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found!\n");
        return;
    }
    Account account = accounts[accountNumber - 1];
    printf("Account Number: %d\n", account.accountNumber);
    printf("Name: %s\n", account.name);
    printf("Balance: %.2f\n", account.balance);
}

void deposit(int accountNumber, float amount) {
    if(accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found!\n");
        return;
    } 
    if (amount <= 0) {
        printf("Deposit amount must be positive!\n");
        return;
    }

    accounts[accountNumber - 1].balance += amount;
    printf("Successfully deposited %.2f into Account Number: %d\n", amount, accountNumber);
}

void withdraw(int accountNumber, float amount) {
    if(accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found!\n");
        return;
    } 
    if (amount <= 0) {
        printf("Withdraw amount must be positive!\n");
        return;
    } 
    if (accounts[accountNumber - 1].balance < amount) {
        printf("Insufficient balance! Account Balance: %.2f\n", accounts[accountNumber - 1].balance);
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    printf("Successfully withdrew %.2f from Account Number: %d\n", amount, accountNumber);
}

void deleteAccount(int accountNumber) {
    if(accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found!\n");
        return;
    }

    for (int i = accountNumber - 1; i < accountCount - 1; i++) {
        accounts[i] = accounts[i + 1];
    }
    accountCount--;
    printf("Account Number: %d deleted successfully!\n", accountNumber);
}

void displayMenu() {
    printf("\n--- Banking Record System ---\n");
    printf("1. Create Account\n");
    printf("2. View Account\n");
    printf("3. Deposit Money\n");
    printf("4. Withdraw Money\n");
    printf("5. Delete Account\n");
    printf("6. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice, accountNumber;
    float amount;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                viewAccount(accountNumber);
                break;
            case 3:
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(accountNumber, amount);
                break;
            case 4:
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(accountNumber, amount);
                break;
            case 5:
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                deleteAccount(accountNumber);
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }

    return 0;
}