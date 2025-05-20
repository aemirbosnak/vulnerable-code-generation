//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Bank account structure
typedef struct account {
    int account_number;
    char name[50];
    double balance;
} account_t;

// Bank database
account_t database[100];
int num_accounts = 0;

// Function to create a new account
void create_account() {
    // Get account details from user
    printf("Enter account number: ");
    scanf("%d", &database[num_accounts].account_number);
    printf("Enter name: ");
    scanf("%s", database[num_accounts].name);
    printf("Enter initial balance: ");
    scanf("%lf", &database[num_accounts].balance);

    // Increment the number of accounts
    num_accounts++;
}

// Function to deposit money into an account
void deposit() {
    // Get account number and amount from user
    int account_number;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);

    // Find the account in the database
    int i;
    for (i = 0; i < num_accounts; i++) {
        if (database[i].account_number == account_number) {
            // Deposit the amount into the account
            database[i].balance += amount;
            break;
        }
    }

    // Print a message to the user
    if (i == num_accounts) {
        printf("Account not found!\n");
    } else {
        printf("Deposit successful!\n");
    }
}

// Function to withdraw money from an account
void withdraw() {
    // Get account number and amount from user
    int account_number;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);

    // Find the account in the database
    int i;
    for (i = 0; i < num_accounts; i++) {
        if (database[i].account_number == account_number) {
            // Withdraw the amount from the account
            if (database[i].balance >= amount) {
                database[i].balance -= amount;
                break;
            } else {
                printf("Insufficient funds!\n");
                break;
            }
        }
    }

    // Print a message to the user
    if (i == num_accounts) {
        printf("Account not found!\n");
    }
}

// Function to print all accounts
void print_all_accounts() {
    // Print the details of each account
    int i;
    for (i = 0; i < num_accounts; i++) {
        printf("Account Number: %d\n", database[i].account_number);
        printf("Name: %s\n", database[i].name);
        printf("Balance: %.2lf\n", database[i].balance);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new account
    create_account();

    // Deposit money into the account
    deposit();

    // Withdraw money from the account
    withdraw();

    // Print all accounts
    print_all_accounts();

    return 0;
}