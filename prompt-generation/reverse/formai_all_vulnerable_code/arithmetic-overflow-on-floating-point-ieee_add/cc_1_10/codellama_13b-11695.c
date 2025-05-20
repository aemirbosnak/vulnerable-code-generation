//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: real-life
// Banking Record System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Defining the structure of a bank account
struct account {
    char account_no[10];
    char account_name[50];
    char account_type[10];
    float balance;
};

// Defining the structure of a transaction
struct transaction {
    char account_no[10];
    char transaction_type[10];
    float amount;
    char timestamp[20];
};

// Function to print the menu
void print_menu() {
    printf("Banking Record System\n");
    printf("1. Create a new account\n");
    printf("2. Deposit money into an account\n");
    printf("3. Withdraw money from an account\n");
    printf("4. Check the balance of an account\n");
    printf("5. Transfer money between accounts\n");
    printf("6. Exit\n");
}

// Function to create a new account
void create_account() {
    struct account account;

    printf("Enter the account number: ");
    scanf("%s", account.account_no);

    printf("Enter the account name: ");
    scanf("%s", account.account_name);

    printf("Enter the account type (savings/current): ");
    scanf("%s", account.account_type);

    printf("Enter the initial balance: ");
    scanf("%f", &account.balance);

    printf("Account created successfully!\n");
}

// Function to deposit money into an account
void deposit_money() {
    struct account account;
    float amount;

    printf("Enter the account number: ");
    scanf("%s", account.account_no);

    printf("Enter the amount to deposit: ");
    scanf("%f", &amount);

    account.balance += amount;

    printf("Deposited successfully!\n");
}

// Function to withdraw money from an account
void withdraw_money() {
    struct account account;
    float amount;

    printf("Enter the account number: ");
    scanf("%s", account.account_no);

    printf("Enter the amount to withdraw: ");
    scanf("%f", &amount);

    if (account.balance < amount) {
        printf("Insufficient balance!\n");
        return;
    }

    account.balance -= amount;

    printf("Withdrawn successfully!\n");
}

// Function to check the balance of an account
void check_balance() {
    struct account account;

    printf("Enter the account number: ");
    scanf("%s", account.account_no);

    printf("The balance is: %.2f\n", account.balance);
}

// Function to transfer money between accounts
void transfer_money() {
    struct account from_account;
    struct account to_account;
    float amount;

    printf("Enter the account number to transfer from: ");
    scanf("%s", from_account.account_no);

    printf("Enter the account number to transfer to: ");
    scanf("%s", to_account.account_no);

    printf("Enter the amount to transfer: ");
    scanf("%f", &amount);

    if (from_account.balance < amount) {
        printf("Insufficient balance!\n");
        return;
    }

    from_account.balance -= amount;
    to_account.balance += amount;

    printf("Transferred successfully!\n");
}

// Function to exit the program
void exit_program() {
    printf("Exiting the program...\n");
    exit(0);
}

// Main function
int main() {
    int choice;

    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                deposit_money();
                break;
            case 3:
                withdraw_money();
                break;
            case 4:
                check_balance();
                break;
            case 5:
                transfer_money();
                break;
            case 6:
                exit_program();
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}