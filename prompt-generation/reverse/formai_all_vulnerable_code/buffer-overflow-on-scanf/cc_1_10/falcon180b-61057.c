//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    int category;
} Expense;

int main() {

    int numCategories, numExpenses;
    char categories[MAX_CATEGORIES][50];
    Expense expenses[MAX_EXPENSES];

    printf("How many expense categories do you want to track? ");
    scanf("%d", &numCategories);

    for (int i = 0; i < numCategories; i++) {
        printf("Enter the name of category %d: ", i + 1);
        scanf("%s", categories[i]);
    }

    printf("How many expenses do you want to track? ");
    scanf("%d", &numExpenses);

    for (int i = 0; i < numExpenses; i++) {
        printf("Enter the name of expense %d: ", i + 1);
        scanf("%s", expenses[i].name);
        printf("Enter the amount of expense %d: ", i + 1);
        scanf("%f", &expenses[i].amount);
        printf("Enter the category of expense %d (1-%d): ", i + 1, numCategories - 1);
        scanf("%d", &expenses[i].category);
    }

    printf("Expenses by category:\n");

    for (int i = 0; i < numCategories; i++) {
        printf("%s:\n", categories[i]);
        for (int j = 0; j < numExpenses; j++) {
            if (expenses[j].category == i + 1) {
                printf("- %s: $%.2f\n", expenses[j].name, expenses[j].amount);
            }
        }
    }

    printf("\nTotal expenses by category:\n");

    for (int i = 0; i < numCategories; i++) {
        float total = 0;
        for (int j = 0; j < numExpenses; j++) {
            if (expenses[j].category == i + 1) {
                total += expenses[j].amount;
            }
        }
        printf("%s: $%.2f\n", categories[i], total);
    }

    return 0;
}