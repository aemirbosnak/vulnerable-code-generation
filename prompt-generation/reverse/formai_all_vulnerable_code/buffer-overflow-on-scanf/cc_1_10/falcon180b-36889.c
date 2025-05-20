//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 50
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    double amount;
    char category[MAX_CATEGORIES][MAX_NAME_LENGTH];
} Expense;

int main() {
    int numCategories, numExpenses;
    char input[100];
    Expense expenses[MAX_EXPENSES];

    printf("Welcome to the Expense Tracker!\n");

    // Get number of categories
    printf("How many categories do you want to track? ");
    scanf("%d", &numCategories);

    // Get category names
    for (int i = 0; i < numCategories; i++) {
        printf("Enter category %d: ", i + 1);
        scanf("%s", expenses[i].category[i]);
    }

    // Get number of expenses
    printf("How many expenses do you want to enter? ");
    scanf("%d", &numExpenses);

    // Get expense details
    for (int i = 0; i < numExpenses; i++) {
        printf("Enter expense %d details:\n", i + 1);
        printf("Name: ");
        scanf("%s", expenses[i].name);
        printf("Amount: ");
        scanf("%lf", &expenses[i].amount);
        printf("Category: ");
        scanf("%s", expenses[i].category[i]);
    }

    // Print expense summary
    printf("\nExpense Summary:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("Name: %s\n", expenses[i].name);
        printf("Amount: $%.2f\n", expenses[i].amount);
        printf("Category: %s\n\n", expenses[i].category[i]);
    }

    return 0;
}