//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 10
#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100

struct account {
    char name[50];
    double balance;
};

struct category {
    char name[50];
    double budget;
};

struct transaction {
    char description[100];
    double amount;
    int category_id;
};

int num_accounts;
int num_categories;
int num_transactions;

struct account accounts[MAX_ACCOUNTS];
struct category categories[MAX_CATEGORIES];
struct transaction transactions[MAX_TRANSACTIONS];

void add_account() {
    printf("Enter account name: ");
    scanf("%s", accounts[num_accounts].name);
    accounts[num_accounts].balance = 0.0;
    num_accounts++;
}

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    printf("Enter category budget: ");
    scanf("%lf", &categories[num_categories].budget);
    num_categories++;
}

void add_transaction() {
    printf("Enter transaction description: ");
    scanf("%s", transactions[num_transactions].description);
    printf("Enter transaction amount: ");
    scanf("%lf", &transactions[num_transactions].amount);
    printf("Enter transaction category ID (0-%d): ", num_categories - 1);
    scanf("%d", &transactions[num_transactions].category_id);
    num_transactions++;
}

void view_accounts() {
    printf("Accounts:\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%s: $%.2lf\n", accounts[i].name, accounts[i].balance);
    }
}

void view_categories() {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s: $%.2lf\n", categories[i].name, categories[i].budget);
    }
}

void view_transactions() {
    printf("Transactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%s - $%.2lf (%s)\n", transactions[i].description, transactions[i].amount, categories[transactions[i].category_id].name);
    }
}

int main() {
    num_accounts = 0;
    num_categories = 0;
    num_transactions = 0;

    add_account();
    add_account();
    add_category();
    add_category();
    add_transaction();
    add_transaction();

    view_accounts();
    view_categories();
    view_transactions();

    return 0;
}