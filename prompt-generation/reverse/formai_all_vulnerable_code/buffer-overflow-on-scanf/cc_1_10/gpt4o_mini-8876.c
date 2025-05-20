//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: immersive
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
void deposit();
void withdraw();
void displayAccount();
void displayAllAccounts();

int main() {
    int choice;
    do {
        printf("\n--- Welcome to the C Banking Record System ---\n");
        printf("1. Create New Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Account\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Please choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: displayAccount(); break;
            case 5: displayAllAccounts(); break;
            case 6: printf("Thank you for using our banking system! Goodbye!\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts! Maximum limit reached.\n");
        return;
    }
    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // Simple account number generation
    printf("Enter the account holder's name: ");
    scanf("%s", newAccount.name);
    newAccount.balance = 0.0;

    accounts[accountCount++] = newAccount;
    printf("Account created successfully! Your account number is %d.\n", newAccount.accountNumber);
}

void deposit() {
    int accountNo;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNo);
    
    if (accountNo <= 0 || accountNo > accountCount) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    
    if (amount <= 0) {
        printf("Deposit amount must be positive!\n");
        return;
    }

    accounts[accountNo - 1].balance += amount;
    printf("Successfully deposited $%.2f to account number %d. New balance is $%.2f.\n",
           amount, accountNo, accounts[accountNo - 1].balance);
}

void withdraw() {
    int accountNo;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNo);
    
    if (accountNo <= 0 || accountNo > accountCount) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    
    if (amount <= 0) {
        printf("Withdrawal amount must be positive!\n");
        return;
    }

    if (accounts[accountNo - 1].balance < amount) {
        printf("Insufficient balance! Current balance is $%.2f.\n", accounts[accountNo - 1].balance);
        return;
    }

    accounts[accountNo - 1].balance -= amount;
    printf("Successfully withdrew $%.2f from account number %d. Remaining balance is $%.2f.\n",
           amount, accountNo, accounts[accountNo - 1].balance);
}

void displayAccount() {
    int accountNo;
    printf("Enter account number: ");
    scanf("%d", &accountNo);
    
    if (accountNo <= 0 || accountNo > accountCount) {
        printf("Account not found!\n");
        return;
    }

    Account acc = accounts[accountNo - 1];
    printf("\n--- Account Details ---\n");
    printf("Account Number: %d\n", acc.accountNumber);
    printf("Account Holder: %s\n", acc.name);
    printf("Account Balance: $%.2f\n", acc.balance);
}

void displayAllAccounts() {
    if (accountCount == 0) {
        printf("No accounts available to display.\n");
        return;
    }
    printf("\n--- All Accounts ---\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d | Name: %s | Balance: $%.2f\n",
               accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}