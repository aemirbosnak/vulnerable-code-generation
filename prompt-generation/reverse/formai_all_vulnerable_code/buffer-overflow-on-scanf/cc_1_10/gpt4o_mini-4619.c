//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LEN 50

typedef struct {
    int accountNumber;
    char name[NAME_LEN];
    float balance;
    int isActive; // 1 for active, 0 for inactive
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void printMenu() {
    printf("\n--- Wasteland Banking System ---\n");
    printf("1. Create Account\n");
    printf("2. View Account\n");
    printf("3. Deposit\n");
    printf("4. Withdraw\n");
    printf("5. Deactivate Account\n");
    printf("6. Exit\n");
    printf("---------------------------------\n");
    printf("Choose an option: ");
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached!\n");
        return;
    }

    Account *newAccount = &accounts[accountCount++];
    newAccount->accountNumber = accountCount; // Simple way to generate unique number
    newAccount->balance = 0;
    newAccount->isActive = 1; // Active by default

    printf("Enter name for account holder: ");
    scanf(" %[^\n]%*c", newAccount->name);

    printf("Account created! Account Number: %d\n", newAccount->accountNumber);
}

void viewAccount() {
    int accNum;
    printf("Enter Account Number to view: ");
    scanf("%d", &accNum);

    if (accNum <= 0 || accNum > accountCount || !accounts[accNum - 1].isActive) {
        printf("Account not found or inactive!\n");
        return;
    }

    Account *acc = &accounts[accNum - 1];
    printf("Account Number: %d\n", acc->accountNumber);
    printf("Account Holder: %s\n", acc->name);
    printf("Balance: %.2f\n", acc->balance);
}

void deposit() {
    int accNum;
    float amount;

    printf("Enter Account Number to deposit into: ");
    scanf("%d", &accNum);

    if (accNum <= 0 || accNum > accountCount || !accounts[accNum - 1].isActive) {
        printf("Account not found or inactive!\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid deposit amount!\n");
        return;
    }

    accounts[accNum - 1].balance += amount;
    printf("Deposit successful! New balance: %.2f\n", accounts[accNum - 1].balance);
}

void withdraw() {
    int accNum;
    float amount;

    printf("Enter Account Number to withdraw from: ");
    scanf("%d", &accNum);

    if (accNum <= 0 || accNum > accountCount || !accounts[accNum - 1].isActive) {
        printf("Account not found or inactive!\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0 || amount > accounts[accNum - 1].balance) {
        printf("Invalid withdraw amount!\n");
        return;
    }
    
    accounts[accNum - 1].balance -= amount;
    printf("Withdrawal successful! New balance: %.2f\n", accounts[accNum - 1].balance);
}

void deactivateAccount() {
    int accNum;
    printf("Enter Account Number to deactivate: ");
    scanf("%d", &accNum);

    if (accNum <= 0 || accNum > accountCount || !accounts[accNum - 1].isActive) {
        printf("Account not found or already inactive!\n");
        return;
    }

    accounts[accNum - 1].isActive = 0; // Setting account as inactive
    printf("Account Number %d has been deactivated.\n", accNum);
}

int main() {
    int choice;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                viewAccount();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                deactivateAccount();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}