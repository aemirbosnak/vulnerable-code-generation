//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: lively
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

// Function Prototypes
void createAccount();
void viewAccounts();
void depositMoney();
void withdrawMoney();
void showMenu();

int main() {
    printf("Welcome to the Lively Banking Record System!\n");
    showMenu();
    return 0;
}

void showMenu() {
    int choice;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Create Account\n");
        printf("2. View Accounts\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                viewAccounts();
                break;
            case 3:
                depositMoney();
                break;
            case 4:
                withdrawMoney();
                break;
            case 5:
                printf("Thank you for using the Lively Banking Record System! Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again!\n");
        }
    } while (choice != 5);
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Error: Maximum account limit reached!\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = accountCount + 1;

    printf("Enter your name: ");
    scanf(" %[^\n]s", newAccount.name);
    newAccount.balance = 0.0f;

    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Successfully created account for %s with Account Number: %d\n", newAccount.name, newAccount.accountNumber);
}

void viewAccounts() {
    if (accountCount == 0) {
        printf("No accounts available! Please create an account first.\n");
        return;
    }

    printf("\n--- List of Accounts ---\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d, Name: %s, Balance: $%.2f\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}

void depositMoney() {
    int accountNumber;
    float amount;

    printf("Enter Account Number to deposit into: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid Account Number. Please try again.\n");
        return;
    }

    printf("Enter amount to deposit: $");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Deposit amount must be positive!\n");
        return;
    }

    accounts[accountNumber - 1].balance += amount;
    printf("Successfully deposited $%.2f into %s's account.\n", amount, accounts[accountNumber - 1].name);
}

void withdrawMoney() {
    int accountNumber;
    float amount;

    printf("Enter Account Number to withdraw from: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid Account Number. Please try again.\n");
        return;
    }

    printf("Enter amount to withdraw: $");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Withdrawal amount must be positive!\n");
        return;
    }

    if (accounts[accountNumber - 1].balance < amount) {
        printf("Insufficient funds in %s's account!\n", accounts[accountNumber - 1].name);
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    printf("Successfully withdrew $%.2f from %s's account.\n", amount, accounts[accountNumber - 1].name);
}