//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a bank account
typedef struct {
    char name[50];
    char account_number[10];
    double balance;
} account;

// Function to create a new bank account
void create_account(account *a) {
    printf("Enter your name: ");
    scanf("%s", a->name);
    printf("Enter your account number: ");
    scanf("%s", a->account_number);
    a->balance = 0;
    printf("Account created successfully!\n");
}

// Function to deposit money into an account
void deposit(account *a, double amount) {
    a->balance += amount;
    printf("Deposit successful! New balance: $%.2f\n", a->balance);
}

// Function to withdraw money from an account
void withdraw(account *a, double amount) {
    if (a->balance >= amount) {
        a->balance -= amount;
        printf("Withdrawal successful! New balance: $%.2f\n", a->balance);
    } else {
        printf("Insufficient funds.\n");
    }
}

// Function to check the balance of an account
void check_balance(account *a) {
    printf("Current balance: $%.2f\n", a->balance);
}

// Function to close an account
void close_account(account *a) {
    printf("Account closed.\n");
}

// Main function to interact with the user
int main() {
    account my_account;
    int choice;
    char option;

    // Create a new account
    create_account(&my_account);

    // Main menu loop
    do {
        printf("\nWelcome to the Romantic Banking System!\n");
        printf("Please select an option:\n");
        printf("1. Deposit\n2. Withdraw\n3. Check Balance\n4. Close Account\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the amount to deposit: ");
                scanf("%lf", &option);
                deposit(&my_account, option);
                break;
            case 2:
                printf("Enter the amount to withdraw: ");
                scanf("%lf", &option);
                withdraw(&my_account, option);
                break;
            case 3:
                check_balance(&my_account);
                break;
            case 4:
                close_account(&my_account);
                break;
            default:
                printf("Invalid option.\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &option);
    } while (option == 'y' || option == 'Y');

    return 0;
}