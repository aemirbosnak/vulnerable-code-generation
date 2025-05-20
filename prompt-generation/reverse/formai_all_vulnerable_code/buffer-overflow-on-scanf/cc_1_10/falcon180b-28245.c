//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a bank account
struct account {
    int account_number;
    char name[50];
    float balance;
};

// Function to create a new account
void create_account(struct account *accounts, int num_accounts) {
    printf("Enter account number: ");
    scanf("%d", &accounts[num_accounts].account_number);
    printf("Enter account holder name: ");
    scanf("%s", accounts[num_accounts].name);
    accounts[num_accounts].balance = 0;
    num_accounts++;
}

// Function to deposit money into an account
void deposit(struct account *accounts, int num_accounts) {
    int account_number;
    printf("Enter account number to deposit into: ");
    scanf("%d", &account_number);
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Enter amount to deposit: ");
            scanf("%f", &accounts[i].balance);
            break;
        }
    }
}

// Function to withdraw money from an account
void withdraw(struct account *accounts, int num_accounts) {
    int account_number;
    printf("Enter account number to withdraw from: ");
    scanf("%d", &account_number);
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &accounts[i].balance);
            break;
        }
    }
}

// Function to display account information
void display_account(struct account *accounts, int num_accounts) {
    printf("Account Number\tName\t\tBalance\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%d\t\t%s\t\t%.2f\n", accounts[i].account_number, accounts[i].name, accounts[i].balance);
    }
}

int main() {
    struct account accounts[100];
    int num_accounts = 0;

    // Create initial accounts
    create_account(accounts, num_accounts);
    create_account(accounts, num_accounts);
    create_account(accounts, num_accounts);

    // Deposit money into an account
    deposit(accounts, num_accounts);

    // Withdraw money from an account
    withdraw(accounts, num_accounts);

    // Display account information
    display_account(accounts, num_accounts);

    return 0;
}