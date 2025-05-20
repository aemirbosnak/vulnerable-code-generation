//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define MAX_CATEGORIES 20

typedef struct {
    char description[50];
    float amount;
    char category[20];
} transaction;

typedef struct {
    char name[20];
    float budget;
    float actual;
} category;

int main() {
    // Declare variables
    int num_transactions = 0;
    int num_categories = 0;
    transaction transactions[MAX_TRANSACTIONS];
    category categories[MAX_CATEGORIES];
    char input[50];

    // Get user input
    printf("Enter the number of transactions: ");
    scanf("%d", &num_transactions);
    for (int i = 0; i < num_transactions; i++) {
        printf("Enter the description of transaction %d: ", i + 1);
        scanf(" %[^\n]s", transactions[i].description);
        printf("Enter the amount of transaction %d: ", i + 1);
        scanf("%f", &transactions[i].amount);
        printf("Enter the category of transaction %d: ", i + 1);
        scanf(" %[^\n]s", transactions[i].category);
    }
    printf("Enter the number of categories: ");
    scanf("%d", &num_categories);
    for (int i = 0; i < num_categories; i++) {
        printf("Enter the name of category %d: ", i + 1);
        scanf(" %[^\n]s", categories[i].name);
        printf("Enter the budget for category %d: ", i + 1);
        scanf("%f", &categories[i].budget);
    }

    // Calculate actual expenses for each category
    for (int i = 0; i < num_transactions; i++) {
        for (int j = 0; j < num_categories; j++) {
            if (strcmp(transactions[i].category, categories[j].name) == 0) {
                categories[j].actual += transactions[i].amount;
            }
        }
    }

    // Print report
    printf("\nPersonal Finance Planner\n");
    printf("------------------------\n");
    printf("Transactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf(" - %s: $%.2f (%s)\n", transactions[i].description, transactions[i].amount, transactions[i].category);
    }
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf(" - %s: $%.2f (actual) / $%.2f (budget)\n", categories[i].name, categories[i].actual, categories[i].budget);
    }

    return 0;
}