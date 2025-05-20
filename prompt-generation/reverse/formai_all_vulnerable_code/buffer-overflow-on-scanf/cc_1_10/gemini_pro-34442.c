//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts
#define MAX_ACCOUNTS 100

// Define the account struct
typedef struct {
    int account_number;
    char name[50];
    double balance;
} account_t;

// Define the function prototypes
void create_account(account_t *accounts, int *num_accounts);
void deposit(account_t *accounts, int num_accounts);
void withdraw(account_t *accounts, int num_accounts);
void transfer(account_t *accounts, int num_accounts);
void print_accounts(account_t *accounts, int num_accounts);

// Main function
int main() {
    // Create an array of accounts
    account_t accounts[MAX_ACCOUNTS];

    // Initialize the number of accounts to 0
    int num_accounts = 0;

    // Create a menu
    int choice;
    do {
        printf("1. Create account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Transfer\n");
        printf("5. Print accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                create_account(accounts, &num_accounts);
                break;
            case 2:
                deposit(accounts, num_accounts);
                break;
            case 3:
                withdraw(accounts, num_accounts);
                break;
            case 4:
                transfer(accounts, num_accounts);
                break;
            case 5:
                print_accounts(accounts, num_accounts);
                break;
            case 6:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to create a new account
void create_account(account_t *accounts, int *num_accounts) {
    // Get the account number
    printf("Enter the account number: ");
    scanf("%d", &accounts[*num_accounts].account_number);

    // Get the account name
    printf("Enter the account name: ");
    scanf("%s", accounts[*num_accounts].name);

    // Get the initial balance
    printf("Enter the initial balance: ");
    scanf("%lf", &accounts[*num_accounts].balance);

    // Increment the number of accounts
    (*num_accounts)++;
}

// Function to deposit money into an account
void deposit(account_t *accounts, int num_accounts) {
    // Get the account number
    int account_number;
    printf("Enter the account number: ");
    scanf("%d", &account_number);

    // Find the account
    int index = -1;
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            index = i;
            break;
        }
    }

    // If the account was not found, print an error message
    if (index == -1) {
        printf("Account not found\n");
        return;
    }

    // Get the amount to deposit
    double amount;
    printf("Enter the amount to deposit: ");
    scanf("%lf", &amount);

    // Deposit the money
    accounts[index].balance += amount;
}

// Function to withdraw money from an account
void withdraw(account_t *accounts, int num_accounts) {
    // Get the account number
    int account_number;
    printf("Enter the account number: ");
    scanf("%d", &account_number);

    // Find the account
    int index = -1;
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            index = i;
            break;
        }
    }

    // If the account was not found, print an error message
    if (index == -1) {
        printf("Account not found\n");
        return;
    }

    // Get the amount to withdraw
    double amount;
    printf("Enter the amount to withdraw: ");
    scanf("%lf", &amount);

    // Withdraw the money
    accounts[index].balance -= amount;
}

// Function to transfer money between two accounts
void transfer(account_t *accounts, int num_accounts) {
    // Get the source account number
    int source_account_number;
    printf("Enter the source account number: ");
    scanf("%d", &source_account_number);

    // Find the source account
    int source_index = -1;
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == source_account_number) {
            source_index = i;
            break;
        }
    }

    // If the source account was not found, print an error message
    if (source_index == -1) {
        printf("Source account not found\n");
        return;
    }

    // Get the destination account number
    int destination_account_number;
    printf("Enter the destination account number: ");
    scanf("%d", &destination_account_number);

    // Find the destination account
    int destination_index = -1;
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == destination_account_number) {
            destination_index = i;
            break;
        }
    }

    // If the destination account was not found, print an error message
    if (destination_index == -1) {
        printf("Destination account not found\n");
        return;
    }

    // Get the amount to transfer
    double amount;
    printf("Enter the amount to transfer: ");
    scanf("%lf", &amount);

    // Transfer the money
    accounts[source_index].balance -= amount;
    accounts[destination_index].balance += amount;
}

// Function to print the accounts
void print_accounts(account_t *accounts, int num_accounts) {
    for (int i = 0; i < num_accounts; i++) {
        printf("Account number: %d\n", accounts[i].account_number);
        printf("Account name: %s\n", accounts[i].name);
        printf("Balance: %.2lf\n\n", accounts[i].balance);
    }
}