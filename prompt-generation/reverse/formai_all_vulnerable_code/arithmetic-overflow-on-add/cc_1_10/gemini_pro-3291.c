//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct transaction {
    char *description;
    float amount;
    time_t date;
};

struct account {
    char *name;
    float balance;
    struct transaction *transactions;
    int num_transactions;
};

struct budget {
    char *name;
    float amount;
    float spent;
    struct transaction *transactions;
    int num_transactions;
};

struct user {
    char *name;
    struct account *accounts;
    int num_accounts;
    struct budget *budgets;
    int num_budgets;
};

struct personal_finance_planner {
    struct user *users;
    int num_users;
};

void add_transaction(struct account *account, struct transaction *transaction) {
    account->transactions = realloc(account->transactions, (account->num_transactions + 1) * sizeof(struct transaction));
    account->transactions[account->num_transactions++] = *transaction;
}

void add_budget(struct user *user, struct budget *budget) {
    user->budgets = realloc(user->budgets, (user->num_budgets + 1) * sizeof(struct budget));
    user->budgets[user->num_budgets++] = *budget;
}

void add_account(struct user *user, struct account *account) {
    user->accounts = realloc(user->accounts, (user->num_accounts + 1) * sizeof(struct account));
    user->accounts[user->num_accounts++] = *account;
}

void add_user(struct personal_finance_planner *planner, struct user *user) {
    planner->users = realloc(planner->users, (planner->num_users + 1) * sizeof(struct user));
    planner->users[planner->num_users++] = *user;
}

int main() {
    struct personal_finance_planner planner;

    // Create a new user
    struct user user;
    user.name = "John Doe";

    // Create a new account
    struct account account;
    account.name = "Checking";
    account.balance = 1000.00;

    // Create a new transaction
    struct transaction transaction;
    transaction.description = "Deposit";
    transaction.amount = 500.00;
    transaction.date = time(NULL);

    // Add the transaction to the account
    add_transaction(&account, &transaction);

    // Add the account to the user
    add_account(&user, &account);

    // Add the user to the planner
    add_user(&planner, &user);

    // Print the user's name and account balance
    printf("User: %s\n", user.name);
    printf("Account: %s\n", account.name);
    printf("Balance: %.2f\n", account.balance);

    return 0;
}