//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: mind-bending
/*
 * Banking Record System
 *
 * A program that manages banking records of customers.
 *
 * Input:
 *  - Customer ID
 *  - Account type (savings/current)
 *  - Amount to deposit/withdraw
 *
 * Output:
 *  - Confirmation message
 *  - Updated account balance
 *
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to hold customer information
typedef struct {
    int id;
    char name[256];
    char email[256];
    char address[256];
    char phone[256];
} Customer;

// Structure to hold account information
typedef struct {
    int id;
    char type; // 's' for savings, 'c' for current
    double balance;
} Account;

// Function to create a new account
void createAccount(Customer *customer, Account *account) {
    // Generate a random ID for the account
    account->id = (int)time(NULL);

    // Prompt the user for account type
    char type;
    printf("Enter account type (s/c): ");
    scanf("%c", &type);

    // Set account type
    if (type == 's') {
        account->type = 's';
    } else if (type == 'c') {
        account->type = 'c';
    } else {
        printf("Invalid account type. Try again.\n");
        return;
    }

    // Prompt the user for initial deposit amount
    double amount;
    printf("Enter initial deposit amount: ");
    scanf("%lf", &amount);

    // Set account balance
    account->balance = amount;
}

// Function to deposit money into an account
void deposit(Account *account, double amount) {
    // Add amount to account balance
    account->balance += amount;
}

// Function to withdraw money from an account
void withdraw(Account *account, double amount) {
    // Check if amount is valid
    if (amount > account->balance) {
        printf("Insufficient funds.\n");
        return;
    }

    // Subtract amount from account balance
    account->balance -= amount;
}

// Function to print account information
void printAccount(Account *account) {
    printf("Account ID: %d\n", account->id);
    printf("Account Type: %c\n", account->type);
    printf("Balance: $%.2f\n", account->balance);
}

int main() {
    // Initialize customer and account structures
    Customer customer;
    Account account;

    // Create a new account
    createAccount(&customer, &account);

    // Print account information
    printAccount(&account);

    // Deposit money into the account
    deposit(&account, 100.00);

    // Print account information again
    printAccount(&account);

    // Withdraw money from the account
    withdraw(&account, 50.00);

    // Print account information again
    printAccount(&account);

    return 0;
}