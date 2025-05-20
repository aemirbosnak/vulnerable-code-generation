//FormAI DATASET v1.0 Category: Banking Record System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts that can be stored in the record system
#define MAX_ACCOUNTS 50

// Define the account structure
typedef struct Account {
    char name[100];
    int account_number;
    int balance;
} Account;

// Declare the account record system array
Account record_system[MAX_ACCOUNTS];

// Define the function to add an account to the record system
void add_account() {
    char name[100];
    int account_number, balance;
    
    // Prompt the user for account information
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter account number: ");
    scanf("%d", &account_number);
    printf("Enter balance: ");
    scanf("%d", &balance);
    
    // Create a new account and add it to the array
    Account new_account;
    strcpy(new_account.name, name);
    new_account.account_number = account_number;
    new_account.balance = balance;
    
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        if (record_system[i].account_number == 0) {
            record_system[i] = new_account;
            printf("Account added successfully.\n");
            return;
        }
    }
    
    // If the record system is full, notify the user
    printf("Sorry, the record system is full.\n");
}

// Define the function to search for an account by account number
void search_by_account_number() {
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    
    // Search for the account and display its information
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        if (record_system[i].account_number == account_number) {
            printf("Account found:\n");
            printf("Name: %s\n", record_system[i].name);
            printf("Account number: %d\n", record_system[i].account_number);
            printf("Balance: %d\n", record_system[i].balance);
            return;
        }
    }
    
    // If the account number is not found, notify the user
    printf("Sorry, account not found.\n");
}

// Define the function to deposit funds into an account
void deposit_funds() {
    int account_number, amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    printf("Enter amount to deposit: ");
    scanf("%d", &amount);
    
    // Search for the account and increase its balance by the deposit amount
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        if (record_system[i].account_number == account_number) {
            record_system[i].balance += amount;
            printf("Deposit completed successfully.\n");
            printf("New balance: %d\n", record_system[i].balance);
            return;
        }
    }
    
    // If the account number is not found, notify the user
    printf("Sorry, account not found.\n");
}

// Define the function to withdraw funds from an account
void withdraw_funds() {
    int account_number, amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    printf("Enter amount to withdraw: ");
    scanf("%d", &amount);
    
    // Search for the account and decrease its balance by the withdrawal amount
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        if (record_system[i].account_number == account_number) {
            if (record_system[i].balance >= amount) {
                record_system[i].balance -= amount;
                printf("Withdrawal completed successfully.\n");
                printf("New balance: %d\n", record_system[i].balance);
            } else {
                printf("Sorry, not enough funds to withdraw.\n");
            }
            return;
        }
    }
    
    // If the account number is not found, notify the user
    printf("Sorry, account not found.\n");
}

// Define the main function
int main() {
    int choice;
    
    // Display the menu and prompt the user for a choice
    do {
        printf("Banking Record System\n");
        printf("1. Add account\n");
        printf("2. Search by account number\n");
        printf("3. Deposit funds\n");
        printf("4. Withdraw funds\n");
        printf("5. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                add_account();
                break;
            case 2:
                search_by_account_number();
                break;
            case 3:
                deposit_funds();
                break;
            case 4:
                withdraw_funds();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}