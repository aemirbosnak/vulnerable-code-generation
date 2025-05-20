//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100
#define MAX_CATEGORY_LENGTH 20
#define MAX_TRANSACTION_LENGTH 80

typedef struct {
    char name[MAX_CATEGORY_LENGTH];
    int id;
    double balance;
} Category;

typedef struct {
    int category_id;
    char description[MAX_TRANSACTION_LENGTH];
    double amount;
    char date[20];
} Transaction;

int main() {
    int num_categories, num_transactions;
    Category categories[MAX_CATEGORIES];
    Transaction transactions[MAX_TRANSACTIONS];

    printf("Enter number of categories: ");
    scanf("%d", &num_categories);

    for (int i = 0; i < num_categories; i++) {
        printf("Enter category name: ");
        scanf("%s", categories[i].name);
        printf("Enter category ID: ");
        scanf("%d", &categories[i].id);
        categories[i].balance = 0;
    }

    printf("Enter number of transactions: ");
    scanf("%d", &num_transactions);

    for (int i = 0; i < num_transactions; i++) {
        printf("Enter transaction category ID: ");
        scanf("%d", &transactions[i].category_id);
        printf("Enter transaction description: ");
        scanf("%s", transactions[i].description);
        printf("Enter transaction amount: ");
        scanf("%lf", &transactions[i].amount);
        printf("Enter transaction date (YYYY-MM-DD): ");
        scanf("%s", transactions[i].date);
    }

    return 0;
}