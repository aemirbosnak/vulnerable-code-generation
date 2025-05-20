//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUDGET_ITEMS 20
#define MAX_ACCOUNT_NAME_LENGTH 50
#define MAX_TRANSACTION_NAME_LENGTH 100

typedef struct {
    char name[MAX_ACCOUNT_NAME_LENGTH];
    double balance;
} Account;

typedef struct {
    char name[MAX_TRANSACTION_NAME_LENGTH];
    double amount;
    Account* from_account;
    Account* to_account;
} Transaction;

typedef struct {
    char name[MAX_BUDGET_ITEMS];
    double amount;
} BudgetItem;

Account* create_account(char* name, double initial_balance) {
    Account* account = (Account*)malloc(sizeof(Account));
    strcpy(account->name, name);
    account->balance = initial_balance;
    return account;
}

Transaction* create_transaction(char* name, double amount, Account* from_account, Account* to_account) {
    Transaction* transaction = (Transaction*)malloc(sizeof(Transaction));
    strcpy(transaction->name, name);
    transaction->amount = amount;
    transaction->from_account = from_account;
    transaction->to_account = to_account;
    return transaction;
}

BudgetItem* create_budget_item(char* name, double amount) {
    BudgetItem* budget_item = (BudgetItem*)malloc(sizeof(BudgetItem));
    strcpy(budget_item->name, name);
    budget_item->amount = amount;
    return budget_item;
}

void print_account(Account* account) {
    printf("Name: %s\n", account->name);
    printf("Balance: %.2f\n", account->balance);
}

void print_transaction(Transaction* transaction) {
    printf("Name: %s\n", transaction->name);
    printf("Amount: %.2f\n", transaction->amount);
    printf("From account: %s\n", transaction->from_account->name);
    printf("To account: %s\n", transaction->to_account->name);
}

void print_budget_item(BudgetItem* budget_item) {
    printf("Name: %s\n", budget_item->name);
    printf("Amount: %.2f\n", budget_item->amount);
}

int main() {
    Account* checking_account = create_account("Checking", 1000.00);
    Account* savings_account = create_account("Savings", 500.00);

    Transaction* rent_payment = create_transaction("Rent Payment", 800.00, checking_account, savings_account);
    Transaction* grocery_shopping = create_transaction("Grocery Shopping", 150.00, checking_account, NULL);

    BudgetItem* rent = create_budget_item("Rent", 800.00);
    BudgetItem* groceries = create_budget_item("Groceries", 200.00);

    print_account(checking_account);
    print_account(savings_account);

    print_transaction(rent_payment);
    print_transaction(grocery_shopping);

    print_budget_item(rent);
    print_budget_item(groceries);

    return 0;
}