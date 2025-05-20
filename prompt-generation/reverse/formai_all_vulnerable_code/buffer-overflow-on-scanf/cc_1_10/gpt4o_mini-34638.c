//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_ACCOUNTS 100
#define ACCOUNT_NUMBER_LENGTH 10
#define NAME_LENGTH 50

// Struct to hold account information
typedef struct {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    char name[NAME_LENGTH];
    double balance;
} Account;

// Global array to store accounts
Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

// Function prototypes
void createAccount();
void displayAccounts();
void deposit();
void withdraw();
void paranoidCheck(const char *message);

// Main function
int main() {
    int choice;
    while (1) {
        paranoidCheck("Displaying menu");
        printf("\nBanking Record System\n");
        printf("1. Create Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice < 1 || choice > 5) {
            paranoidCheck("Invalid menu selection");
            printf("Invalid choice! Please try again.\n");
            continue;
        }

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                displayAccounts();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                paranoidCheck("Exiting the program");
                printf("Thank you for using the Banking Record System. Goodbye!\n");
                exit(0);
            default:
                paranoidCheck("Unknown error in menu selection");
                break;
        }
    }
    return 0;
}

// Function to create a new account
void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        paranoidCheck("Account limit reached");
        printf("Cannot create more accounts. Please delete some accounts first.\n");
        return;
    }

    paranoidCheck("Creating a new account");
    Account newAccount;
    printf("Enter account number: ");
    scanf("%s", newAccount.accountNumber);
    printf("Enter account holder's name: ");
    scanf("%s", newAccount.name);
    newAccount.balance = 0.0;

    accounts[accountCount++] = newAccount;
    printf("Account created successfully!\n");
}

// Function to display all accounts
void displayAccounts() {
    if (accountCount == 0) {
        paranoidCheck("No accounts to display");
        printf("No accounts have been created yet.\n");
        return;
    }

    paranoidCheck("Displaying all accounts");
    printf("Account Number\tAccount Holder\tBalance\n");
    for (int i = 0; i < accountCount; i++) {
        printf("%s\t%s\t%.2f\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}

// Function to deposit money into an account
void deposit() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    double amount;

    paranoidCheck("Depositing money");
    printf("Enter account number to deposit into: ");
    scanf("%s", accountNumber);
    
    // Find account
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);
            if (amount <= 0) {
                paranoidCheck("Invalid deposit amount");
                printf("Please enter a valid amount to deposit.\n");
            } else {
                accounts[i].balance += amount;
                printf("Deposit successful! New balance: %.2f\n", accounts[i].balance);
            }
            return;
        }
    }
    paranoidCheck("Account number not found during deposit");
    printf("Account number not found!\n");
}

// Function to withdraw money from an account
void withdraw() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    double amount;

    paranoidCheck("Withdrawing money");
    printf("Enter account number to withdraw from: ");
    scanf("%s", accountNumber);
    
    // Find account
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);
            if (amount <= 0) {
                paranoidCheck("Invalid withdrawal amount");
                printf("Please enter a valid amount to withdraw.\n");
            } else if (amount > accounts[i].balance) {
                paranoidCheck("Insufficient balance for withdrawal");
                printf("Insufficient balance!\n");
            } else {
                accounts[i].balance -= amount;
                printf("Withdrawal successful! New balance: %.2f\n", accounts[i].balance);
            }
            return;
        }
    }
    paranoidCheck("Account number not found during withdrawal");
    printf("Account number not found!\n");
}

// Function to simulate a paranoid check
void paranoidCheck(const char *message) {
    printf("[PARANOIA ALERT] %s\n", message);
}