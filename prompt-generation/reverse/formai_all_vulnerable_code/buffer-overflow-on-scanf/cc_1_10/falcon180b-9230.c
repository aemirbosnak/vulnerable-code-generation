//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 10
#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100

typedef struct {
    char name[50];
    int balance;
    int overdraft_limit;
} Account;

typedef struct {
    char name[50];
    int id;
} Category;

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    Category category;
    Date date;
    char description[100];
    int amount;
} Transaction;

int main() {
    int num_accounts, num_categories;
    scanf("%d %d", &num_accounts, &num_categories);

    Account accounts[num_accounts];
    Category categories[num_categories];

    for (int i = 0; i < num_accounts; i++) {
        scanf("%s %d %d", accounts[i].name, &accounts[i].balance, &accounts[i].overdraft_limit);
    }

    for (int i = 0; i < num_categories; i++) {
        scanf("%s %d", categories[i].name, &categories[i].id);
    }

    int num_transactions;
    scanf("%d", &num_transactions);

    Transaction transactions[num_transactions];

    for (int i = 0; i < num_transactions; i++) {
        scanf("%s %d %d %s %d", transactions[i].category.name, &transactions[i].date.year, &transactions[i].date.month, &transactions[i].date.day, &transactions[i].amount);
    }

    // Example usage of the planner
    int total_expenses = 0;
    for (int i = 0; i < num_transactions; i++) {
        total_expenses += transactions[i].amount;
    }

    printf("Total expenses: $%d\n", total_expenses);

    return 0;
}