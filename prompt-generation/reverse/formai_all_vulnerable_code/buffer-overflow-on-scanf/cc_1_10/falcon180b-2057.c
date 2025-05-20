//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100
#define MAX_CATEGORY_NAME_LENGTH 20
#define MAX_TRANSACTION_NAME_LENGTH 50

typedef struct {
    char name[MAX_CATEGORY_NAME_LENGTH];
    int id;
} Category;

typedef struct {
    char name[MAX_TRANSACTION_NAME_LENGTH];
    float amount;
    int categoryId;
} Transaction;

int main() {
    int numCategories, numTransactions;
    char input[100];
    Category categories[MAX_CATEGORIES];
    Transaction transactions[MAX_TRANSACTIONS];
    int i, j;

    // Initialize categories
    for (i = 0; i < MAX_CATEGORIES; i++) {
        categories[i].id = -1;
    }

    // Add categories
    printf("Enter the number of categories:\n");
    scanf("%d", &numCategories);
    for (i = 0; i < numCategories; i++) {
        printf("Enter category name (%d):\n", i + 1);
        scanf("%s", input);
        strcpy(categories[i].name, input);
        categories[i].id = i;
    }

    // Initialize transactions
    for (i = 0; i < MAX_TRANSACTIONS; i++) {
        transactions[i].categoryId = -1;
    }

    // Add transactions
    printf("Enter the number of transactions:\n");
    scanf("%d", &numTransactions);
    for (i = 0; i < numTransactions; i++) {
        printf("Enter transaction name (%d):\n", i + 1);
        scanf("%s", input);
        strcpy(transactions[i].name, input);
        printf("Enter category id (%d):\n", i + 1);
        scanf("%d", &transactions[i].categoryId);
        printf("Enter amount:\n");
        scanf("%f", &transactions[i].amount);
    }

    // Print transactions by category
    for (i = 0; i < numCategories; i++) {
        printf("Category: %s\n", categories[i].name);
        for (j = 0; j < numTransactions; j++) {
            if (transactions[j].categoryId == i) {
                printf("Transaction: %s - $%.2f\n", transactions[j].name, transactions[j].amount);
            }
        }
    }

    return 0;
}