//FormAI DATASET v1.0 Category: Banking Record System ; Style: Claude Shannon
/*
 * Banking Record System
 * 
 * This program manages a record of banking activities for multiple accounts.
 * It allows the user to create new accounts, deposit money, withdraw money,
 * and view the account balance and transaction history.
 * 
 * The system uses a structure to store account information, and dynamically
 * allocates memory as needed for new accounts and transaction history.
 * 
 * Developed by: [Your Name]
 * Date: [Current Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define INITIAL_ACCOUNT_CAPACITY 10

// Define a structure to hold account information
typedef struct {
    int account_number;
    char owner_name[MAX_NAME_LENGTH];
    double balance;
    int transaction_count;
    double *transaction_history;
    int transaction_history_capacity;
} Account;

// Function prototypes
void create_account(Account **accounts, int *account_count);
void deposit(Account *account);
void withdraw(Account *account);
void print_balance(Account *account);
void print_history(Account *account);

int main() {
    Account *accounts = malloc(INITIAL_ACCOUNT_CAPACITY * sizeof(Account));
    int account_count = 0;
    char choice;
    
    printf("Welcome to the Banking Record System!\n\n");
    
    do {
        printf("Main Menu:\n");
        printf("1. Create new account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. View balance\n");
        printf("5. View transaction history\n");
        printf("0. Exit program\n");
        printf("\nEnter your choice (0-5): ");
        scanf(" %c", &choice);
        
        switch(choice) {
            case '1':
                create_account(&accounts, &account_count);
                break;
            case '2':
                deposit(accounts);
                break;
            case '3':
                withdraw(accounts);
                break;
            case '4':
                print_balance(accounts);
                break;
            case '5':
                print_history(accounts);
                break;
            case '0':
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
        
        printf("\n");
    } while (choice != '0');
    
    free(accounts);
    return 0;
}

// Function to create a new account and add it to the accounts array
void create_account(Account **accounts, int *account_count) {
    // Check if accounts array needs to be expanded
    if (*account_count >= INITIAL_ACCOUNT_CAPACITY) {
        printf("Expanding account capacity...\n");
        Account *temp = realloc(*accounts, (*account_count + 1) * sizeof(Account));
        if (temp == NULL) {
            printf("Error: memory allocation failed.\n");
            return;
        }
        *accounts = temp;
    }
    
    // Prompt user for account information
    printf("\nCreate New Account:\n");
    printf("Account Number: ");
    scanf("%d", &(*accounts)[*account_count].account_number);
    printf("Owner Name: ");
    scanf("%s", (*accounts)[*account_count].owner_name);
    (*accounts)[*account_count].balance = 0.0;
    (*accounts)[*account_count].transaction_count = 0;
    (*accounts)[*account_count].transaction_history_capacity = 10;
    (*accounts)[*account_count].transaction_history = malloc(10 * sizeof(double));
    
    (*account_count)++;
    
    printf("\nAccount successfully created!\n");
}

// Function to deposit money into an account
void deposit(Account *account) {
    double amount;
    printf("\nEnter deposit amount: ");
    scanf("%lf", &amount);
    
    account->balance += amount;
    if (account->transaction_count >= account->transaction_history_capacity) {
        printf("Expanding transaction history capacity...\n");
        double *temp = realloc(account->transaction_history, (account->transaction_history_capacity + 10) * sizeof(double));
        if (temp == NULL) {
            printf("Error: memory allocation failed.\n");
            return;
        }
        account->transaction_history = temp;
        account->transaction_history_capacity += 10;
    }
    account->transaction_history[account->transaction_count] = amount;
    account->transaction_count++;
    
    printf("\nDeposit successful!\n");
}

// Function to withdraw money from an account
void withdraw(Account *account) {
    double amount;
    printf("\nEnter withdrawal amount: ");
    scanf("%lf", &amount);
    
    if (account->balance >= amount) {
        account->balance -= amount;
        if (account->transaction_count >= account->transaction_history_capacity) {
            printf("Expanding transaction history capacity...\n");
            double *temp = realloc(account->transaction_history, (account->transaction_history_capacity + 10) * sizeof(double));
            if (temp == NULL) {
                printf("Error: memory allocation failed.\n");
                return;
            }
            account->transaction_history = temp;
            account->transaction_history_capacity += 10;
        }
        account->transaction_history[account->transaction_count] = -amount;
        account->transaction_count++;
        printf("\nWithdrawal successful!\n");
    } else {
        printf("\nError: insufficient funds!\n");
    }
}

// Function to print the current balance of an account
void print_balance(Account *account) {
    printf("\nCurrent Balance: $%.2lf\n", account->balance);
}

// Function to print the transaction history of an account
void print_history(Account *account) {
    printf("\nTransaction History:\n");
    for (int i = 0; i < account->transaction_count; i++) {
        if (account->transaction_history[i] > 0) {
            printf("Deposit: $%.2lf\n", account->transaction_history[i]);
        } else {
            printf("Withdrawal: $%.2lf\n", -account->transaction_history[i]);
        }
    }
}