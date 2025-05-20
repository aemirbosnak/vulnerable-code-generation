//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define ACCOUNT_NUMBER_LENGTH 20

typedef struct {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    char accountHolder[NAME_LENGTH];
    float balance;
} BankAccount;

BankAccount accounts[MAX_ACCOUNTS];
int accountCount = 0;

void initializeSystem() {
    printf("Welcome to the Visionary Banking Record System!\n");
}

int findAccount(const char *accountNumber) {
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            return i;
        }
    }
    return -1;
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts. Maximum limit reached.\n");
        return;
    }
    
    BankAccount newAccount;
    printf("Enter Account Number: ");
    scanf("%s", newAccount.accountNumber);
    
    if (findAccount(newAccount.accountNumber) != -1) {
        printf("Account with this number already exists!\n");
        return;
    }
    
    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]", newAccount.accountHolder);
    newAccount.balance = 0.0; // Initial balance
    accounts[accountCount++] = newAccount;
    printf("Account created successfully!\n");
}

void deposit() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float amount;

    printf("Enter Account Number for deposit: ");
    scanf("%s", accountNumber);
    
    int index = findAccount(accountNumber);
    if (index == -1) {
        printf("Account not found!\n");
        return;
    }
    
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Deposit amount must be greater than zero!\n");
        return;
    }
    
    accounts[index].balance += amount;
    printf("Amount deposited successfully! New balance: %.2f\n", accounts[index].balance);
}

void withdraw() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float amount;

    printf("Enter Account Number for withdrawal: ");
    scanf("%s", accountNumber);
    
    int index = findAccount(accountNumber);
    if (index == -1) {
        printf("Account not found!\n");
        return;
    }
    
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Withdrawal amount must be greater than zero!\n");
        return;
    }
    
    if (accounts[index].balance < amount) {
        printf("Insufficient balance for withdrawal!\n");
        return;
    }
    
    accounts[index].balance -= amount;
    printf("Amount withdrawn successfully! New balance: %.2f\n", accounts[index].balance);
}

void displayAccountDetails() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];

    printf("Enter Account Number to display details: ");
    scanf("%s", accountNumber);
    
    int index = findAccount(accountNumber);
    if (index == -1) {
        printf("Account not found!\n");
        return;
    }
    
    printf("Account Number: %s\n", accounts[index].accountNumber);
    printf("Account Holder: %s\n", accounts[index].accountHolder);
    printf("Account Balance: %.2f\n", accounts[index].balance);
}

void displayAllAccounts() {
    if (accountCount == 0) {
        printf("No accounts available to display!\n");
        return;
    }
    
    printf("Displaying all accounts:\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %s | Account Holder: %s | Balance: %.2f\n",
               accounts[i].accountNumber, accounts[i].accountHolder, accounts[i].balance);
    }
}

int main() {
    int choice;

    initializeSystem();

    while (1) {
        printf("\n1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display Account Details\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
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
                displayAccountDetails();
                break;
            case 5:
                displayAllAccounts();
                break;
            case 6:
                printf("Exiting the Visionary Banking Record System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}