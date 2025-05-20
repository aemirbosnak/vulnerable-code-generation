//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Declare structures for transactions and accounts
typedef struct {
    char* description;
    float amount;
    char* category;
    char* date;
} Transaction;

typedef struct {
    char* name;
    float balance;
    Transaction* transactions;
    int num_transactions;
} Account;

// Declare functions
void print_welcome();
void create_account(Account** accounts, int* num_accounts);
void add_transaction(Account* account, Transaction* transaction);
void print_account(Account* account);
void print_all_accounts(Account* accounts, int num_accounts);
void free_accounts(Account* accounts, int num_accounts);

// Main function
int main() {
    // Print welcome message
    print_welcome();

    // Create an array of accounts
    Account* accounts = NULL;
    int num_accounts = 0;

    // Allow the user to create multiple accounts
    int choice;
    do {
        printf("Would you like to create an account? (1 for yes, 0 for no): ");
        scanf("%d", &choice);

        if (choice) {
            create_account(&accounts, &num_accounts);
        }
    } while (choice);

    // Allow the user to add transactions to each account
    for (int i = 0; i < num_accounts; i++) {
        Account* account = &accounts[i];

        printf("Enter transactions for account %s:\n", account->name);

        int num_transactions;
        printf("How many transactions would you like to add? ");
        scanf("%d", &num_transactions);

        for (int j = 0; j < num_transactions; j++) {
            Transaction* transaction = malloc(sizeof(Transaction));

            printf("Enter transaction description: ");
            scanf(" %[^\n]s", transaction->description);

            printf("Enter transaction amount: ");
            scanf("%f", &transaction->amount);

            printf("Enter transaction category: ");
            scanf(" %[^\n]s", transaction->category);

            printf("Enter transaction date: ");
            scanf(" %[^\n]s", transaction->date);

            add_transaction(account, transaction);
        }
    }

    // Print all accounts and their transactions
    print_all_accounts(accounts, num_accounts);

    // Free the memory allocated for the accounts and transactions
    free_accounts(accounts, num_accounts);

    return 0;
}

// Function to print welcome message
void print_welcome() {
    printf("Welcome to the Personal Finance Planner!\n");
}

// Function to create an account
void create_account(Account** accounts, int* num_accounts) {
    // Get the account name from the user
    char* name = malloc(sizeof(char) * 256);
    printf("Enter account name: ");
    scanf(" %[^\n]s", name);

    // Get the initial balance from the user
    float balance;
    printf("Enter initial balance: ");
    scanf("%f", &balance);

    // Allocate memory for the new account
    Account* account = malloc(sizeof(Account));
    account->name = name;
    account->balance = balance;
    account->transactions = NULL;
    account->num_transactions = 0;

    // Add the new account to the array of accounts
    *accounts = realloc(*accounts, (*num_accounts + 1) * sizeof(Account));
    (*accounts)[*num_accounts] = *account;
    (*num_accounts)++;
}

// Function to add a transaction to an account
void add_transaction(Account* account, Transaction* transaction) {
    // Allocate memory for the new transaction
    account->transactions = realloc(account->transactions, (account->num_transactions + 1) * sizeof(Transaction));
    account->transactions[account->num_transactions] = *transaction;
    account->num_transactions++;
}

// Function to print an account
void print_account(Account* account) {
    printf("Account: %s\n", account->name);
    printf("Balance: %.2f\n", account->balance);

    printf("Transactions:\n");
    for (int i = 0; i < account->num_transactions; i++) {
        Transaction* transaction = &account->transactions[i];
        printf("  - %s: %.2f (%s) [%s]\n", transaction->description, transaction->amount, transaction->category, transaction->date);
    }
}

// Function to print all accounts
void print_all_accounts(Account* accounts, int num_accounts) {
    for (int i = 0; i < num_accounts; i++) {
        print_account(&accounts[i]);
        printf("\n");
    }
}

// Function to free the memory allocated for the accounts and transactions
void free_accounts(Account* accounts, int num_accounts) {
    for (int i = 0; i < num_accounts; i++) {
        Account* account = &accounts[i];

        // Free the memory allocated for the account name
        free(account->name);

        // Free the memory allocated for the transactions
        for (int j = 0; j < account->num_transactions; j++) {
            Transaction* transaction = &account->transactions[j];

            // Free the memory allocated for the transaction description, category, and date
            free(transaction->description);
            free(transaction->category);
            free(transaction->date);
        }

        // Free the memory allocated for the transactions array
        free(account->transactions);
    }

    // Free the memory allocated for the accounts array
    free(accounts);
}