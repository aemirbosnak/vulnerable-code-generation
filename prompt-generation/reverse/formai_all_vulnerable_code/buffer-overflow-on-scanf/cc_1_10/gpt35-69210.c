//FormAI DATASET v1.0 Category: Banking Record System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 1000

// Structure for bank account
typedef struct Account 
{
    int accountNumber;
    char holderName[100];
    double balance;
} Account;

// Array for bank accounts
Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;

// Function to create a new account
void createAccount()
{
    Account newAccount;
    printf("Enter holder name: ");
    scanf("%s", newAccount.holderName);
    printf("Enter starting balance: ");
    scanf("%lf", &newAccount.balance);
    newAccount.accountNumber = numAccounts;
    accounts[numAccounts] = newAccount;
    printf("Account created successfully with account number %d.\n\n", newAccount.accountNumber);
    numAccounts++;
}

// Function to deposit money into an account
void deposit()
{
    int accountNumber;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    if (accountNumber >= numAccounts || accountNumber < 0) 
    {
        printf("Invalid account number.\n\n");
        return;
    }
    printf("Enter deposit amount: ");
    scanf("%lf", &amount);
    accounts[accountNumber].balance += amount;
    printf("Deposit successful.\n");
    printf("New balance for account %d: %.2f.\n\n", accountNumber, accounts[accountNumber].balance);
}

// Function to withdraw money from an account
void withdraw()
{
    int accountNumber;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    if (accountNumber >= numAccounts || accountNumber < 0) 
    {
        printf("Invalid account number.\n\n");
        return;
    }
    printf("Enter withdrawal amount: ");
    scanf("%lf", &amount);
    if (amount > accounts[accountNumber].balance) 
    {
        printf("Insufficient balance.\n\n");
        return;
    }
    accounts[accountNumber].balance -= amount;
    printf("Withdrawal successful.\n");
    printf("New balance for account %d: %.2f.\n\n", accountNumber, accounts[accountNumber].balance);
}

// Function to display the balance of an account
void displayBalance()
{
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    if (accountNumber >= numAccounts || accountNumber < 0) 
    {
        printf("Invalid account number.\n\n");
        return;
    }
    printf("Current balance for account %d: %.2f.\n\n", accountNumber, accounts[accountNumber].balance);
}

// Main function
int main()
{
    printf("Welcome to the banking record system!\n\n");
    while (1) 
    {
        int choice;
        printf("Enter your choice:\n");
        printf("1. Create new account.\n");
        printf("2. Deposit money.\n");
        printf("3. Withdraw money.\n");
        printf("4. Display balance.\n");
        printf("5. Exit.\n");
        scanf("%d", &choice);
        switch (choice) 
        {
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
                displayBalance();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n\n");
                break;
        }
    }
    return 0;
}