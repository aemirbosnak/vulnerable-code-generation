//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    double amount;
} Transaction;

typedef struct {
    char name[MAX_NAME_LENGTH];
    Transaction transactions[MAX_TRANSACTIONS];
    int numTransactions;
} Category;

void initializeCategory(Category* category) {
    category->numTransactions = 0;
}

void addTransaction(Category* category, Transaction transaction) {
    category->transactions[category->numTransactions] = transaction;
    category->numTransactions++;
}

void printCategory(Category category) {
    printf("Category: %s\n", category.name);
    for (int i = 0; i < category.numTransactions; i++) {
        printf("Transaction %d: %s - $%.2f\n", i + 1, category.transactions[i].name, category.transactions[i].amount);
    }
    printf("\n");
}

int main() {
    Category categories[MAX_CATEGORIES];
    int numCategories = 0;

    initializeCategory(categories);

    while (numCategories < MAX_CATEGORIES) {
        printf("Enter category name (or type 'done' to finish): ");
        scanf("%s", categories[numCategories].name);

        if (strcmp(categories[numCategories].name, "done") == 0) {
            break;
        }

        numCategories++;
    }

    for (int i = 0; i < numCategories; i++) {
        printf("Enter transactions for %s (type 'done' to finish):\n", categories[i].name);

        while (1) {
            Transaction transaction;
            printf("Name: ");
            scanf("%s", transaction.name);

            printf("Amount: ");
            scanf("%lf", &transaction.amount);

            addTransaction(categories + i, transaction);

            char input[MAX_AMOUNT_LENGTH];
            scanf("%s", input);

            if (strcmp(input, "done") == 0) {
                break;
            }
        }
    }

    for (int i = 0; i < numCategories; i++) {
        printCategory(categories[i]);
    }

    return 0;
}