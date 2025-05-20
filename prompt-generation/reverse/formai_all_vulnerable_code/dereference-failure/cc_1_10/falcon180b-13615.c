//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a bank account
typedef struct {
    int account_number;
    char account_holder[50];
    float balance;
} BankAccount;

// Function to create a new bank account
BankAccount* create_account(int account_number, char* account_holder, float balance) {
    BankAccount* new_account = (BankAccount*) malloc(sizeof(BankAccount));
    new_account->account_number = account_number;
    strcpy(new_account->account_holder, account_holder);
    new_account->balance = balance;
    return new_account;
}

// Function to deposit money into a bank account
void deposit(BankAccount* account, float amount) {
    account->balance += amount;
    printf("Deposit of $%.2f made to account %d\n", amount, account->account_number);
}

// Function to withdraw money from a bank account
void withdraw(BankAccount* account, float amount) {
    if (account->balance >= amount) {
        account->balance -= amount;
        printf("Withdrawal of $%.2f made from account %d\n", amount, account->account_number);
    } else {
        printf("Insufficient funds in account %d\n", account->account_number);
    }
}

// Function to print the details of a bank account
void print_account(BankAccount* account) {
    printf("Account Number: %d\n", account->account_number);
    printf("Account Holder: %s\n", account->account_holder);
    printf("Balance: $%.2f\n", account->balance);
}

int main() {
    // Create a new bank account
    BankAccount* account1 = create_account(12345, "John Doe", 1000.00);

    // Deposit money into the account
    deposit(account1, 500.00);

    // Withdraw money from the account
    withdraw(account1, 200.00);

    // Print the details of the account
    print_account(account1);

    return 0;
}