//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Transaction {
    char description[100];
    double amount;
    int category;
};

struct Category {
    char name[50];
    double budget;
    double spent;
};

int main() {
    int num_categories, num_transactions;
    struct Category categories[10];
    struct Transaction transactions[100];

    printf("Enter the number of categories: ");
    scanf("%d", &num_categories);

    for (int i = 0; i < num_categories; i++) {
        printf("Enter the name of category %d: ", i+1);
        scanf("%s", categories[i].name);
        printf("Enter the budget for category %s: ", categories[i].name);
        scanf("%lf", &categories[i].budget);
        categories[i].spent = 0;
    }

    printf("Enter the number of transactions: ");
    scanf("%d", &num_transactions);

    for (int i = 0; i < num_transactions; i++) {
        printf("Enter the description of transaction %d: ", i+1);
        scanf("%s", transactions[i].description);
        printf("Enter the amount of transaction %s: ", transactions[i].description);
        scanf("%lf", &transactions[i].amount);
        printf("Enter the category of transaction %s (1-%d): ", transactions[i].description, num_categories);
        scanf("%d", &transactions[i].category);
    }

    for (int i = 0; i < num_categories; i++) {
        printf("Category %s:\n", categories[i].name);
        printf("Budget: $%.2lf\n", categories[i].budget);
        printf("Spent: $%.2lf\n\n", categories[i].spent);
    }

    return 0;
}