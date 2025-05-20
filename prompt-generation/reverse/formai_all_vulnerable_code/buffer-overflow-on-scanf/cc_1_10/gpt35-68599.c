//FormAI DATASET v1.0 Category: Banking Record System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 1000

// Struct for each account
typedef struct Account {
    char name[50];
    int account_number;
    float balance;
} Account;

// Function declarations
void add_account();
void display_account();
void deposit_money();
void withdraw_money();
void search_account();

// Global variables
Account accounts[MAX_ACCOUNTS];
int num_accounts = 0;

// Main function
int main() {
    int option;

    // Menu loop
    while (1) {
        printf("\n");
        printf("Welcome to the Banking Record System!\n");
        printf("-------------------------------------\n");
        printf("1. Add a new account\n");
        printf("2. Display all accounts\n");
        printf("3. Deposit money\n");
        printf("4. Withdraw money\n");
        printf("5. Search an account\n");
        printf("6. Quit\n");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                add_account();
                break;
            case 2:
                display_account();
                break;
            case 3:
                deposit_money();
                break;
            case 4:
                withdraw_money();
                break;
            case 5:
                search_account();
                break;
            case 6:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid option! Try again.\n");
        }
    }

    return 0;
}

// Function to add a new account
void add_account() {
    Account new_account;

    printf("\nEnter the account details:\n");
    printf("Name: ");
    scanf("%s", new_account.name);
    printf("Account number: ");
    scanf("%d", &new_account.account_number);
    printf("Balance: ");
    scanf("%f", &new_account.balance);

    accounts[num_accounts] = new_account;
    num_accounts++;

    printf("\nAccount added successfully!\n");
}

// Function to display all accounts
void display_account() {
    printf("\nAll accounts:\n");
    printf("--------------\n");

    if (num_accounts == 0) {
        printf("\nNo accounts yet!\n");
        return;
    }

    for (int i = 0; i < num_accounts; i++) {
        Account account = accounts[i];

        printf("\nAccount %d\n", i+1);
        printf("Name: %s\n", account.name);
        printf("Account number: %d\n", account.account_number);
        printf("Balance: $%.2f\n", account.balance);
    }
}

// Function to deposit money
void deposit_money() {
    int account_number, index;
    float amount;

    printf("\nEnter the account number: ");
    scanf("%d", &account_number);

    // Search for the account in the array
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            index = i;
            break;
        }
    }

    printf("Enter the amount to deposit: ");
    scanf("%f", &amount);

    // Update the account balance
    accounts[index].balance += amount;

    printf("\n$%.2f deposited successfully!\n", amount);
    printf("New balance: $%.2f\n", accounts[index].balance);
}

// Function to withdraw money
void withdraw_money() {
    int account_number, index;
    float amount;

    printf("\nEnter the account number: ");
    scanf("%d", &account_number);

    // Search for the account in the array
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            index = i;
            break;
        }
    }

    printf("Enter the amount to withdraw: ");
    scanf("%f", &amount);

    // Check if there is enough balance in the account
    if (amount > accounts[index].balance) {
        printf("\nInsufficient balance! Transaction cancelled.\n");
        return;
    }

    // Update the account balance
    accounts[index].balance -= amount;

    printf("\n$%.2f withdrawn successfully!\n", amount);
    printf("New balance: $%.2f\n", accounts[index].balance);
}

// Function to search for an account by name or account number
void search_account() {
    int option, account_number;
    char name[50];
    int index;

    printf("\nSearch for an account by:\n");
    printf("1. Name\n");
    printf("2. Account number\n");
    printf("\nEnter your option: ");
    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("\nEnter the name: ");
            scanf("%s", name);

            // Search for the account in the array
            for (int i = 0; i < num_accounts; i++) {
                if (strcmp(accounts[i].name, name) == 0) {
                    index = i;
                    break;
                }
            }

            break;
        case 2:
            printf("\nEnter the account number: ");
            scanf("%d", &account_number);

            // Search for the account in the array
            for (int i = 0; i < num_accounts; i++) {
                if (accounts[i].account_number == account_number) {
                    index = i;
                    break;
                }
            }

            break;
        default:
            printf("\nInvalid option! Try again.\n");
            return;
    }

    // Display the account details
    if (index >= 0 && index < num_accounts) {
        Account account = accounts[index];

        printf("\nAccount found!\n");
        printf("Name: %s\n", account.name);
        printf("Account number: %d\n", account.account_number);
        printf("Balance: $%.2f\n", account.balance);
    } else {
        printf("\nAccount not found!\n");
    }
}