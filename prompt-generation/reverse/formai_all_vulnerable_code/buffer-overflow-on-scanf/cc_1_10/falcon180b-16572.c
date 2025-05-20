//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100
#define MAX_CATEGORY_NAME_LENGTH 50
#define MAX_TRANSACTION_NAME_LENGTH 100

typedef struct {
    char name[MAX_CATEGORY_NAME_LENGTH];
    float balance;
} Category;

typedef struct {
    char name[MAX_TRANSACTION_NAME_LENGTH];
    float amount;
    int categoryIndex;
} Transaction;

int main() {
    int numCategories, numTransactions;
    Category categories[MAX_CATEGORIES];
    Transaction transactions[MAX_TRANSACTIONS];

    printf("Enter the number of categories: ");
    scanf("%d", &numCategories);

    for (int i = 0; i < numCategories; i++) {
        printf("Enter the name of category %d: ", i + 1);
        scanf("%s", categories[i].name);
        categories[i].balance = 0.0;
    }

    printf("Enter the number of transactions: ");
    scanf("%d", &numTransactions);

    for (int i = 0; i < numTransactions; i++) {
        printf("Enter the name of transaction %d: ", i + 1);
        scanf("%s", transactions[i].name);
        printf("Enter the amount of transaction %d: ", i + 1);
        scanf("%f", &transactions[i].amount);
        printf("Enter the category index of transaction %d: ", i + 1);
        scanf("%d", &transactions[i].categoryIndex);
    }

    for (int i = 0; i < numTransactions; i++) {
        categories[transactions[i].categoryIndex - 1].balance += transactions[i].amount;
    }

    printf("Category balances:\n");
    for (int i = 0; i < numCategories; i++) {
        printf("%s: $%.2f\n", categories[i].name, categories[i].balance);
    }

    return 0;
}