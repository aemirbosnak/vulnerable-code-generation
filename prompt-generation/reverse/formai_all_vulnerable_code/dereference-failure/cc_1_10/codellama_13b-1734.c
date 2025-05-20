//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 32
#define MAX_ACCOUNT_LEN 10
#define MAX_BALANCE_LEN 10

// Structure to hold bank account information
struct account {
    char name[MAX_NAME_LEN];
    char account_number[MAX_ACCOUNT_LEN];
    float balance;
};

// Structure to hold user information
struct user {
    char name[MAX_NAME_LEN];
    char password[MAX_NAME_LEN];
    struct account* accounts;
    int num_accounts;
};

// Function to create a new user
struct user* create_user(char* name, char* password) {
    struct user* user = malloc(sizeof(struct user));
    strcpy(user->name, name);
    strcpy(user->password, password);
    user->accounts = NULL;
    user->num_accounts = 0;
    return user;
}

// Function to create a new account
struct account* create_account(char* name, char* account_number, float balance) {
    struct account* account = malloc(sizeof(struct account));
    strcpy(account->name, name);
    strcpy(account->account_number, account_number);
    account->balance = balance;
    return account;
}

// Function to add an account to a user
void add_account(struct user* user, struct account* account) {
    user->accounts = realloc(user->accounts, (user->num_accounts + 1) * sizeof(struct account));
    user->accounts[user->num_accounts] = *account;
    user->num_accounts++;
}

// Function to delete an account from a user
void delete_account(struct user* user, int index) {
    for (int i = index; i < user->num_accounts - 1; i++) {
        user->accounts[i] = user->accounts[i + 1];
    }
    user->num_accounts--;
}

// Function to display all accounts for a user
void display_accounts(struct user* user) {
    printf("Name: %s\n", user->name);
    printf("Accounts:\n");
    for (int i = 0; i < user->num_accounts; i++) {
        printf("Account %d: %s, %s, $%.2f\n", i + 1, user->accounts[i].name, user->accounts[i].account_number, user->accounts[i].balance);
    }
}

// Function to update the balance of an account
void update_balance(struct account* account, float amount) {
    account->balance += amount;
}

int main() {
    // Create a new user
    struct user* user1 = create_user("John Doe", "password123");

    // Create two new accounts
    struct account* account1 = create_account("Checking", "1234567890", 1000.00);
    struct account* account2 = create_account("Savings", "9876543210", 5000.00);

    // Add the accounts to the user
    add_account(user1, account1);
    add_account(user1, account2);

    // Display the accounts for the user
    display_accounts(user1);

    // Update the balance of one of the accounts
    update_balance(account1, 500.00);

    // Display the updated accounts for the user
    display_accounts(user1);

    // Delete one of the accounts
    delete_account(user1, 0);

    // Display the updated accounts for the user
    display_accounts(user1);

    // Free the memory for the user and accounts
    free(user1);
    free(account1);
    free(account2);

    return 0;
}