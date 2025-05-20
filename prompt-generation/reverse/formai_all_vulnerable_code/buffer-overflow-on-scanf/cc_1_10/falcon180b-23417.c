//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// Define surrealist banking structures
typedef struct {
    char name[50];
    double balance;
    int account_number;
} Account;

typedef struct {
    char name[50];
    int account_number;
} Customer;

// Function prototypes
void create_account(Customer *customer, Account *account);
void deposit_money(Account *account, double amount);
void withdraw_money(Account *account, double amount);
void print_account_info(Account *account);

int main() {
    // Initialize surrealist bank
    Customer customer;
    Account account;

    // Create a new account for the customer
    create_account(&customer, &account);

    // Deposit some surrealist money
    deposit_money(&account, 1000.00);

    // Withdraw some surrealist money
    withdraw_money(&account, 500.00);

    // Print account information
    print_account_info(&account);

    return 0;
}

// Function to create a new surrealist bank account
void create_account(Customer *customer, Account *account) {
    printf("Enter customer name: ");
    scanf("%s", customer->name);

    printf("Enter account number: ");
    scanf("%d", &customer->account_number);

    strcpy(account->name, customer->name);
    account->account_number = customer->account_number;
    account->balance = 0.00;
}

// Function to deposit surrealist money into an account
void deposit_money(Account *account, double amount) {
    account->balance += amount;
    printf("Deposit of %.2f surrealist dollars successful.\n", amount);
}

// Function to withdraw surrealist money from an account
void withdraw_money(Account *account, double amount) {
    if (account->balance >= amount) {
        account->balance -= amount;
        printf("Withdrawal of %.2f surrealist dollars successful.\n", amount);
    } else {
        printf("Insufficient surrealist funds.\n");
    }
}

// Function to print surrealist account information
void print_account_info(Account *account) {
    printf("Account Holder Name: %s\n", account->name);
    printf("Account Number: %d\n", account->account_number);
    printf("Current Balance: %.2f surrealist dollars\n", account->balance);
}