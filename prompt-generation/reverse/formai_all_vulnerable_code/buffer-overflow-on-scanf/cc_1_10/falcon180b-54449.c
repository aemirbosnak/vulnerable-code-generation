//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUDGET_ITEMS 100
#define MAX_CATEGORY_NAME 50
#define MAX_TRANSACTION_NAME 100

struct budget_item {
    char name[MAX_BUDGET_ITEMS];
    float amount;
};

struct category {
    char name[MAX_CATEGORY_NAME];
    int num_items;
    struct budget_item items[MAX_BUDGET_ITEMS];
};

struct transaction {
    char name[MAX_TRANSACTION_NAME];
    char category_name[MAX_CATEGORY_NAME];
    float amount;
};

int main() {
    int num_categories, num_transactions;
    struct category categories[MAX_CATEGORY_NAME];
    struct transaction transactions[MAX_TRANSACTION_NAME];

    printf("Welcome to the Personal Finance Planner!\n");
    printf("Enter the number of categories you want to create: ");
    scanf("%d", &num_categories);

    for (int i = 0; i < num_categories; i++) {
        printf("\nEnter the name of category %d: ", i + 1);
        scanf("%s", categories[i].name);
        categories[i].num_items = 0;
    }

    printf("\nEnter the number of transactions you want to make: ");
    scanf("%d", &num_transactions);

    for (int i = 0; i < num_transactions; i++) {
        printf("\nEnter the name of transaction %d: ", i + 1);
        scanf("%s", transactions[i].name);
        printf("Enter the category name for transaction %d: ", i + 1);
        scanf("%s", transactions[i].category_name);
        printf("Enter the amount for transaction %d: ", i + 1);
        scanf("%f", &transactions[i].amount);
    }

    for (int i = 0; i < num_categories; i++) {
        printf("\nCategory %s:\n", categories[i].name);
        for (int j = 0; j < categories[i].num_items; j++) {
            printf("\tBudget item %d: %s - $%.2f\n", j + 1, categories[i].items[j].name, categories[i].items[j].amount);
        }
    }

    printf("\nTransactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("\t%s - %s - $%.2f\n", transactions[i].name, transactions[i].category_name, transactions[i].amount);
    }

    return 0;
}