//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent a customer
struct customer {
    char name[50];
    int account_number;
    double balance;
};

// Function to open a new account
void open_account(struct customer *customer) {
    printf("Welcome to the bank! Please enter your name: ");
    fgets(customer->name, 50, stdin);
    printf("Please enter your account number: ");
    scanf("%d", &customer->account_number);
    customer->balance = 0;
}

// Function to deposit money
void deposit(struct customer *customer, double amount) {
    customer->balance += amount;
    printf("Your new balance is: %f\n", customer->balance);
}

// Function to withdraw money
void withdraw(struct customer *customer, double amount) {
    if (customer->balance >= amount) {
        customer->balance -= amount;
        printf("Withdrawn amount: %f\n", amount);
    } else {
        printf("Insufficient funds! Your balance is: %f\n", customer->balance);
    }
}

// Function to check the account balance
void check_balance(struct customer *customer) {
    printf("Your current balance is: %f\n", customer->balance);
}

int main() {
    struct customer customer1, customer2;

    // Open the first account
    open_account(&customer1);

    // Deposit money into the first account
    deposit(&customer1, 1000.0);

    // Withdraw money from the first account
    withdraw(&customer1, 500.0);

    // Open the second account
    open_account(&customer2);

    // Deposit money into the second account
    deposit(&customer2, 2000.0);

    // Withdraw money from the second account
    withdraw(&customer2, 1000.0);

    // Check the balance of the first account
    check_balance(&customer1);

    // Check the balance of the second account
    check_balance(&customer2);

    return 0;
}