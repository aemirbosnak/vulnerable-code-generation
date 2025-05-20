//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_ACCOUNTS 10
#define MAX_TRANSACTIONS 100

typedef struct {
    char name[50];
    int id;
} category;

typedef struct {
    char name[50];
    int id;
    int balance;
} account;

typedef struct {
    int id;
    char description[100];
    category category;
    account from_account;
    account to_account;
    float amount;
    int date;
} transaction;

int main() {
    category categories[MAX_CATEGORIES];
    account accounts[MAX_ACCOUNTS];
    transaction transactions[MAX_TRANSACTIONS];
    int num_categories = 0, num_accounts = 0, num_transactions = 0;

    while (num_categories < MAX_CATEGORIES) {
        printf("Enter category name: ");
        scanf("%s", categories[num_categories].name);
        printf("Enter category ID: ");
        scanf("%d", &categories[num_categories].id);
        num_categories++;
    }

    while (num_accounts < MAX_ACCOUNTS) {
        printf("Enter account name: ");
        scanf("%s", accounts[num_accounts].name);
        printf("Enter account ID: ");
        scanf("%d", &accounts[num_accounts].id);
        printf("Enter account balance: ");
        scanf("%d", &accounts[num_accounts].balance);
        num_accounts++;
    }

    while (num_transactions < MAX_TRANSACTIONS) {
        printf("Enter transaction ID: ");
        scanf("%d", &transactions[num_transactions].id);
        printf("Enter transaction description: ");
        scanf("%s", transactions[num_transactions].description);
        printf("Enter transaction category: ");
        scanf("%d", &transactions[num_transactions].category.id);
        printf("Enter transaction from account: ");
        scanf("%d", &transactions[num_transactions].from_account.id);
        printf("Enter transaction to account: ");
        scanf("%d", &transactions[num_transactions].to_account.id);
        printf("Enter transaction amount: ");
        scanf("%f", &transactions[num_transactions].amount);
        printf("Enter transaction date (YYYY-MM-DD): ");
        scanf("%s", transactions[num_transactions].date);
        num_transactions++;
    }

    //TODO: Add code to display and manipulate personal finance data

    return 0;
}