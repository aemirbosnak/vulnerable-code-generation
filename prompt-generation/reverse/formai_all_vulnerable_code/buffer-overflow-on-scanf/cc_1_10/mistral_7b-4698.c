//MISTRAL-7B DATASET v1.0 Category: Banking Record System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define some structures and constants
typedef struct {
    char name[50];
    float balance;
} Account;

#define MAX_ACCOUNTS 100

// Global variables
Account accounts[MAX_ACCOUNTS];
int num_accounts = 0;

// Function prototypes
void create_account(const char *name, float initial_balance);
void deposit(const char *name, float amount);
void withdraw(const char *name, float amount);
void print_accounts(void);

// Main function
int main(void) {
    char command[20];
    char name[50];
    float amount;

    while (1) {
        printf("Hello! Welcome to C Banking System, where your money is safer than a pig in a poke!\n");
        printf("Please enter a command (create, deposit, withdraw, print, or exit): ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            printf("Enter account holder's name: ");
            scanf("%s", name);
            printf("Enter initial balance: ");
            scanf("%f", &amount);
            create_account(name, amount);
            printf("Account created successfully!\n");
        } else if (strcmp(command, "deposit") == 0) {
            printf("Enter account holder's name: ");
            scanf("%s", name);
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            deposit(name, amount);
            printf("Deposit successful!\n");
        } else if (strcmp(command, "withdraw") == 0) {
            printf("Enter account holder's name: ");
            scanf("%s", name);
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            withdraw(name, amount);
            printf("Withdrawal successful!\n");
        } else if (strcmp(command, "print") == 0) {
            print_accounts();
        } else if (strcmp(command, "exit") == 0) {
            printf("Goodbye and may your money multiply like rabbits!\n");
            exit(0);
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}

// Function to create a new account
void create_account(const char *name, float initial_balance) {
    if (num_accounts >= MAX_ACCOUNTS) {
        printf("Sorry, we cannot create more accounts at this time.\n");
        return;
    }

    strcpy(accounts[num_accounts].name, name);
    accounts[num_accounts].balance = initial_balance;
    num_accounts++;
}

// Function to deposit an amount to an account
void deposit(const char *name, float amount) {
    int i;

    for (i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].name, name) == 0) {
            accounts[i].balance += amount;
            break;
        }
    }

    if (i == num_accounts) {
        printf("Account not found.\n");
        return;
    }
}

// Function to withdraw an amount from an account
void withdraw(const char *name, float amount) {
    int i;

    for (i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].name, name) == 0) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
            } else {
                printf("Insufficient balance.\n");
                return;
            }
            break;
        }
    }

    if (i == num_accounts) {
        printf("Account not found.\n");
        return;
    }
}

// Function to print all accounts and their balances
void print_accounts(void) {
    int i;

    printf("Account Name\tBalance\n");
    for (i = 0; i < num_accounts; i++) {
        printf("%s\t%.2f\n", accounts[i].name, accounts[i].balance);
    }
}