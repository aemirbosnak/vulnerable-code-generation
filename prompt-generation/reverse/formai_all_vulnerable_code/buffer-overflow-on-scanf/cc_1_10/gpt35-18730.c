//FormAI DATASET v1.0 Category: Banking Record System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define some constants for our banking system
#define MAX_ACCOUNTS 10
#define NAME_LENGTH 30

// Define our account struct, which holds all of the relevant information for a single account
typedef struct Account {
    int account_number;
    char name[NAME_LENGTH];
    float balance;
} Account;

// Define our global array of accounts
Account accounts[MAX_ACCOUNTS];

// Define our global account counter variable
int num_accounts = 0;

// Define our helper function for finding an account in the array by its account number
int find_account(int account_number) {
    int i;
    for (i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            return i;
        }
    }
    return -1;
}

int main() {
    // Define our user input variables
    int choice, account_number, index;
    char name[NAME_LENGTH];
    float amount;
    
    // Define our welcome message
    printf("Welcome to the Silliest Banking System Ever!\n");
    
    // Start our main loop
    while (1) {
        // Print out our menu of options
        printf("\nPlease choose from the following options:\n");
        printf("1. Create a new account\n");
        printf("2. Deposit money into an account\n");
        printf("3. Withdraw money from an account\n");
        printf("4. Check the balance of an account\n");
        printf("5. Print out all accounts in the system\n");
        printf("6. Quit the program\n");
        
        // Get the user's choice
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        // Take action based on the user's choice
        switch (choice) {
            case 1:
                // Create a new account and add it to the array
                printf("\nEnter the account number: ");
                scanf("%d", &account_number);
                
                // Make sure the account number is unique
                index = find_account(account_number);
                if (index != -1) {
                    printf("\nThat account number is already in use!\n");
                    break;
                }
                
                // Get the rest of the account information from the user and create the new account
                printf("\nEnter the account holder's name: ");
                scanf("%s", name);
                
                printf("\nEnter the initial balance: ");
                scanf("%f", &amount);
                
                accounts[num_accounts].account_number = account_number;
                strcpy(accounts[num_accounts].name, name);
                accounts[num_accounts].balance = amount;
                num_accounts++;
                
                // Let the user know they've successfully created an account
                printf("\nAccount created successfully!\n");
                break;
            case 2:
                // Deposit money into an account
                printf("\nEnter the account number: ");
                scanf("%d", &account_number);
                
                // Find the account in the array
                index = find_account(account_number);
                if (index == -1) {
                    printf("\nThat account does not exist!\n");
                    break;
                }
                
                // Get the amount to deposit from the user and add it to the account balance
                printf("\nEnter the amount to deposit: ");
                scanf("%f", &amount);
                
                accounts[index].balance += amount;
                
                // Let the user know the deposit was successful
                printf("\nDeposit successful! New balance: $%.2f\n", accounts[index].balance);
                break;
            case 3:
                // Withdraw money from an account
                printf("\nEnter the account number: ");
                scanf("%d", &account_number);
                
                // Find the account in the array
                index = find_account(account_number);
                if (index == -1) {
                    printf("\nThat account does not exist!\n");
                    break;
                }
                
                // Get the amount to withdraw from the user and subtract it from the account balance
                printf("\nEnter the amount to withdraw: ");
                scanf("%f", &amount);
                
                if (amount > accounts[index].balance) {
                    printf("\nYou do not have enough funds in your account!\n");
                    break;
                }
                
                accounts[index].balance -= amount;
                
                // Let the user know the withdrawal was successful
                printf("\nWithdrawal successful! New balance: $%.2f\n", accounts[index].balance);
                break;
            case 4:
                // Check the balance of an account
                printf("\nEnter the account number: ");
                scanf("%d", &account_number);
                
                // Find the account in the array
                index = find_account(account_number);
                if (index == -1) {
                    printf("\nThat account does not exist!\n");
                    break;
                }
                
                // Print out the current balance of the account
                printf("\nCurrent balance: $%.2f\n", accounts[index].balance);
                break;
            case 5:
                // Print out all accounts in the system
                printf("\nAll accounts in the system:\n");
                for (int i = 0; i < num_accounts; i++) {
                    printf("Account #%d - Holder: %s, Balance: $%.2f\n",
                           accounts[i].account_number, accounts[i].name, accounts[i].balance);
                }
                break;
            case 6:
                // Quit the program
                printf("\nThank you for using the Silliest Banking System Ever!\n");
                exit(0);
            default:
                // The user entered an invalid choice
                printf("\nThat is not a valid choice!\n");
                break;
        }
    }
    
    return 0;
}