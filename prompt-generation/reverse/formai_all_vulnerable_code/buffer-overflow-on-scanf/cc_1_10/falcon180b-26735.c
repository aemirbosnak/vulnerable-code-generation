//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_DESC_LEN 100
#define MAX_AMOUNT 1000.00

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    double amount;
} Item;

int main() {
    int num_items;
    Item items[MAX_ITEMS];
    double total_income = 0.00;
    double total_expenses = 0.00;

    // Get number of items from user
    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    // Get item details from user
    printf("Enter item details:\n");
    for (int i = 0; i < num_items; i++) {
        printf("Item %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", items[i].name);
        printf("Description: ");
        scanf("%s", items[i].description);
        printf("Amount: ");
        scanf("%lf", &items[i].amount);

        // Check if amount is income or expense
        if (items[i].amount > 0.00) {
            total_income += items[i].amount;
        } else {
            total_expenses += items[i].amount;
        }
    }

    // Print summary
    printf("\nSummary:\n");
    printf("Total Income: $%.2f\n", total_income);
    printf("Total Expenses: $%.2f\n", total_expenses);

    // Print item details
    printf("\nItem Details:\n");
    for (int i = 0; i < num_items; i++) {
        printf("Item %d:\n", i + 1);
        printf("Name: %s\n", items[i].name);
        printf("Description: %s\n", items[i].description);
        printf("Amount: $%.2f\n\n", items[i].amount);
    }

    return 0;
}