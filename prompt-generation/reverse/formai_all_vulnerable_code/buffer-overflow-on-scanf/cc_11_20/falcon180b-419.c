//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    int count;
} Category;

typedef struct {
    char description[100];
    double amount;
    int categoryIndex;
} Expense;

int main() {
    int numCategories, numExpenses;
    Category categories[MAX_CATEGORIES];
    Expense expenses[MAX_EXPENSES];
    int i, j, categoryIndex;

    // Initialize categories
    for (i = 0; i < MAX_CATEGORIES; i++) {
        categories[i].name[0] = '\0';
        categories[i].count = 0;
    }

    // Get number of categories
    printf("Enter the number of categories: ");
    scanf("%d", &numCategories);

    // Get category names
    for (i = 0; i < numCategories; i++) {
        printf("Enter category %d name: ", i+1);
        scanf("%s", categories[i].name);
    }

    // Initialize expenses
    for (i = 0; i < MAX_EXPENSES; i++) {
        expenses[i].description[0] = '\0';
        expenses[i].amount = 0.0;
        expenses[i].categoryIndex = -1;
    }

    // Get number of expenses
    printf("Enter the number of expenses: ");
    scanf("%d", &numExpenses);

    // Get expense details
    for (i = 0; i < numExpenses; i++) {
        printf("Enter expense %d description: ", i+1);
        scanf("%s", expenses[i].description);
        printf("Enter expense %d amount: ", i+1);
        scanf("%lf", &expenses[i].amount);

        // Get expense category
        printf("Enter expense %d category: ", i+1);
        scanf("%s", categories[0].name);
        categoryIndex = 0;
        for (j = 1; j < numCategories; j++) {
            if (strcmp(categories[j].name, categories[0].name) == 0) {
                categoryIndex = j;
                break;
            }
        }
        expenses[i].categoryIndex = categoryIndex;
    }

    // Print expense report by category
    for (i = 0; i < numCategories; i++) {
        if (categories[i].count > 0) {
            printf("Category: %s\n", categories[i].name);
            printf("Total Expenses: $%.2f\n\n", expenses[0].amount);
            for (j = 0; j < numExpenses; j++) {
                if (expenses[j].categoryIndex == i) {
                    printf("Expense: %s\n", expenses[j].description);
                    printf("Amount: $%.2f\n", expenses[j].amount);
                }
            }
        }
    }

    return 0;
}