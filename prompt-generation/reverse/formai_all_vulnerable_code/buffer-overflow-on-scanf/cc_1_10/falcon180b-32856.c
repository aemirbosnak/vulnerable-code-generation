//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100
#define MAX_CATEGORY_NAME_LENGTH 20
#define MAX_TRANSACTION_NAME_LENGTH 50

typedef struct {
    char name[MAX_CATEGORY_NAME_LENGTH];
    int transactions[MAX_TRANSACTIONS];
} category;

typedef struct {
    char name[MAX_TRANSACTION_NAME_LENGTH];
    int amount;
    int category;
} transaction;

int main() {
    int num_categories, num_transactions;
    category categories[MAX_CATEGORIES];
    transaction transactions[MAX_TRANSACTIONS];

    printf("Enter number of categories: ");
    scanf("%d", &num_categories);

    for (int i = 0; i < num_categories; i++) {
        printf("Enter category name for category %d: ", i+1);
        scanf("%s", categories[i].name);
    }

    printf("Enter number of transactions: ");
    scanf("%d", &num_transactions);

    for (int i = 0; i < num_transactions; i++) {
        printf("Enter transaction name for transaction %d: ", i+1);
        scanf("%s", transactions[i].name);
        printf("Enter amount for transaction %d: ", i+1);
        scanf("%d", &transactions[i].amount);
        printf("Enter category for transaction %d: ", i+1);
        scanf("%d", &transactions[i].category);
    }

    printf("Transactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%s: $%d in %s\n", transactions[i].name, transactions[i].amount, categories[transactions[i].category-1].name);
    }

    return 0;
}