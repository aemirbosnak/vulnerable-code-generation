//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define NAME_LENGTH 50

typedef struct {
    int accountNumber;
    char name[NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_USERS];
int accountCount = 0;

// Function prototypes
void createAccount();
void viewAccounts(int index);
void deposit(int index);
void withdraw(int index);
void manageAccount(int index);
void displayAccounts();
void menu();

// Function to create a new account
void createAccount() {
    if (accountCount >= MAX_USERS) {
        printf("Maximum number of accounts reached.\n");
        return;
    }
    
    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // Assigning a new account number
    printf("Enter the name for the new account: ");
    scanf("%s", newAccount.name);
    newAccount.balance = 0.0f;
    
    accounts[accountCount] = newAccount;
    accountCount++;
    
    printf("Account created successfully with account number: %d\n", newAccount.accountNumber);
    menu();
}

// Function to view account details
void viewAccounts(int index) {
    if (index < 0 || index >= accountCount) {
        printf("Invalid account number.\n");
        return;
    }
    
    printf("Account Number: %d\n", accounts[index].accountNumber);
    printf("Name: %s\n", accounts[index].name);
    printf("Balance: %.2f\n", accounts[index].balance);
    manageAccount(index);
}

// Function to deposit money
void deposit(int index) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    
    if (amount > 0) {
        accounts[index].balance += amount;
        printf("Successfully deposited %.2f to account %d.\n", amount, accounts[index].accountNumber);
    } else {
        printf("Invalid deposit amount.\n");
    }
    manageAccount(index);
}

// Function to withdraw money
void withdraw(int index) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    
    if (amount > 0 && amount <= accounts[index].balance) {
        accounts[index].balance -= amount;
        printf("Successfully withdrew %.2f from account %d.\n", amount, accounts[index].accountNumber);
    } else {
        printf("Invalid withdrawal amount or insufficient funds.\n");
    }
    manageAccount(index);
}

// Function to manage account options
void manageAccount(int index) {
    int choice;
    printf("\nManage Account Menu:\n");
    printf("1. View Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Return to Main Menu\n");
    printf("Choose an option: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            viewAccounts(index);
            break;
        case 2:
            deposit(index);
            break;
        case 3:
            withdraw(index);
            break;
        case 4:
            menu();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            manageAccount(index);
            break;
    }
}

// Function to display all accounts
void displayAccounts() {
    printf("List of Accounts:\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d, Name: %s, Balance: %.2f\n", 
                accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
    menu();
}

// Main menu function
void menu() {
    int choice;
    printf("\nBanking System Menu:\n");
    printf("1. Create New Account\n");
    printf("2. View All Accounts\n");
    printf("3. Manage Existing Account\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            createAccount();
            break;
        case 2:
            displayAccounts();
            break;
        case 3: {
            int accountNum;
            printf("Enter account number to manage: ");
            scanf("%d", &accountNum);
            manageAccount(accountNum - 1);
            break;
        }
        case 4:
            printf("Exiting the banking system. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            menu();
            break;
    }
}

int main() {
    printf("Welcome to the Banking Record System!\n");
    menu();
    return 0;
}