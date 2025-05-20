//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: puzzling
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
        printf("Account limit reached! Cannot create more accounts.\n");
        return;
    }
    
    Account newAccount;
    newAccount.accountNumber = accountCount + 1;
    
    printf("Enter Name: ");
    scanf(" %[^\n]", newAccount.name);
    
    newAccount.balance = 0.0;
    accounts[accountCount++] = newAccount;

    printf("Account created successfully! Your account number is %d\n", newAccount.accountNumber);
}

void deposit() {
    int accNum;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &accNum);

    if (accNum < 1 || accNum > accountCount) {
        printf("Invalid Account Number!\n");
        return;
    }

    printf("Enter Deposit Amount: ");
    scanf("%f", &amount);
    
    if (amount <= 0) {
        printf("Deposit amount should be positive!\n");
        return;
    }

    accounts[accNum - 1].balance += amount;
    printf("Successfully deposited %.2f into account number %d.\n", amount, accNum);
}

void withdraw() {
    int accNum;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &accNum);

    if (accNum < 1 || accNum > accountCount) {
        printf("Invalid Account Number!\n");
        return;
    }

    printf("Enter Withdrawal Amount: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Withdrawal amount should be positive!\n");
        return;
    }

    if (amount > accounts[accNum - 1].balance) {
        printf("Insufficient balance!\n");
        return;
    }

    accounts[accNum - 1].balance -= amount;
    printf("Successfully withdrew %.2f from account number %d.\n", amount, accNum);
}

void displayAccounts() {
    printf("\n--- Account Details ---\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d\n", accounts[i].accountNumber);
        printf("Name: %s\n", accounts[i].name);
        printf("Balance: %.2f\n", accounts[i].balance);
        printf("-----------------------\n");
    }
}

void displayMenu() {
    printf("\n--- Banking System Menu ---\n");
    printf("1. Create Account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Display Accounts\n");
    printf("5. Exit\n");
    printf("---------------------------\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
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
                displayAccounts();
                break;
            case 5:
                printf("Thank you for using the Banking System!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}