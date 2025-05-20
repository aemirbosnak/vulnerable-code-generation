//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of accounts
#define MAX_ACCOUNTS 100

// Define the account structure
typedef struct {
    int account_number;
    char *name;
    double balance;
} account_t;

// Create an array of accounts
account_t accounts[MAX_ACCOUNTS];

// Initialize the number of accounts to 0
int num_accounts = 0;

// Function to create a new account
void create_account() {
    // Get the account number from the user
    printf("Enter the account number: ");
    int account_number;
    scanf("%d", &account_number);

    // Get the name of the account holder from the user
    printf("Enter the name of the account holder: ");
    char name[100];
    scanf("%s", name);

    // Get the initial balance of the account from the user
    printf("Enter the initial balance of the account: ");
    double balance;
    scanf("%lf", &balance);

    // Create a new account and add it to the array of accounts
    accounts[num_accounts].account_number = account_number;
    accounts[num_accounts].name = strdup(name);
    accounts[num_accounts].balance = balance;
    num_accounts++;
}

// Function to deposit money into an account
void deposit_money() {
    // Get the account number from the user
    printf("Enter the account number: ");
    int account_number;
    scanf("%d", &account_number);

    // Find the account by its account number
    int i;
    for (i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            break;
        }
    }

    // If the account was not found, print an error message
    if (i == num_accounts) {
        printf("Account not found\n");
        return;
    }

    // Get the amount of money to deposit from the user
    printf("Enter the amount of money to deposit: ");
    double amount;
    scanf("%lf", &amount);

    // Deposit the money into the account
    accounts[i].balance += amount;
    printf("New balance: %lf\n", accounts[i].balance);
}

// Function to withdraw money from an account
void withdraw_money() {
    // Get the account number from the user
    printf("Enter the account number: ");
    int account_number;
    scanf("%d", &account_number);

    // Find the account by its account number
    int i;
    for (i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            break;
        }
    }

    // If the account was not found, print an error message
    if (i == num_accounts) {
        printf("Account not found\n");
        return;
    }

    // Get the amount of money to withdraw from the user
    printf("Enter the amount of money to withdraw: ");
    double amount;
    scanf("%lf", &amount);

    // Withdraw the money from the account
    accounts[i].balance -= amount;
    printf("New balance: %lf\n", accounts[i].balance);
}

// Function to print the balance of an account
void print_balance() {
    // Get the account number from the user
    printf("Enter the account number: ");
    int account_number;
    scanf("%d", &account_number);

    // Find the account by its account number
    int i;
    for (i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            break;
        }
    }

    // If the account was not found, print an error message
    if (i == num_accounts) {
        printf("Account not found\n");
        return;
    }

    // Print the balance of the account
    printf("Balance: %lf\n", accounts[i].balance);
}

// Function to print the list of accounts
void print_accounts() {
    // Print the list of accounts
    for (int i = 0; i < num_accounts; i++) {
        printf("Account number: %d\n", accounts[i].account_number);
        printf("Name: %s\n", accounts[i].name);
        printf("Balance: %lf\n", accounts[i].balance);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new account
    create_account();

    // Deposit money into the account
    deposit_money();

    // Withdraw money from the account
    withdraw_money();

    // Print the balance of the account
    print_balance();

    // Print the list of accounts
    print_accounts();

    return 0;
}