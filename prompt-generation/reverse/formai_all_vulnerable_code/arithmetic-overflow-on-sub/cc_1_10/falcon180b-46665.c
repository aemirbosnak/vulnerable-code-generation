//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ACCOUNTS 10
#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100

typedef struct {
    char name[50];
    double balance;
} Account;

typedef struct {
    char name[50];
    double budget;
} Category;

typedef struct {
    time_t date;
    char description[100];
    Account* from_account;
    Account* to_account;
    Category* category;
    double amount;
} Transaction;

int main() {
    srand(time(NULL));

    int num_accounts = rand() % MAX_ACCOUNTS + 1;
    int num_categories = rand() % MAX_CATEGORIES + 1;

    Account accounts[MAX_ACCOUNTS];
    Category categories[MAX_CATEGORIES];

    for (int i = 0; i < num_accounts; i++) {
        accounts[i].balance = rand() % 1000;
        sprintf(accounts[i].name, "Account %d", i + 1);
    }

    for (int i = 0; i < num_categories; i++) {
        categories[i].budget = rand() % 1000;
        sprintf(categories[i].name, "Category %d", i + 1);
    }

    int num_transactions = rand() % MAX_TRANSACTIONS + 1;

    Transaction transactions[MAX_TRANSACTIONS];

    for (int i = 0; i < num_transactions; i++) {
        transactions[i].date = time(NULL) - i * 86400;
        sprintf(transactions[i].description, "Transaction %d", i + 1);

        int from_account_index = rand() % num_accounts;
        int to_account_index = rand() % num_accounts;

        if (from_account_index == to_account_index) {
            transactions[i].from_account = &accounts[from_account_index];
            transactions[i].to_account = NULL;
        } else {
            transactions[i].from_account = &accounts[from_account_index];
            transactions[i].to_account = &accounts[to_account_index];
        }

        int category_index = rand() % num_categories;
        transactions[i].category = &categories[category_index];

        transactions[i].amount = rand() % 1000;
    }

    return 0;
}