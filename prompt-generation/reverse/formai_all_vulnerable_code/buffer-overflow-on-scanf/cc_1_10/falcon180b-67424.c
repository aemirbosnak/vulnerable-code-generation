//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    int category;
} expense;

int main() {
    int num_categories, num_expenses, i, j, choice;
    expense expenses[MAX_EXPENSES];
    char categories[MAX_CATEGORIES][50];
    float total_expenses[MAX_CATEGORIES] = {0};

    printf("Welcome to the Expense Tracker!\n");
    printf("Please enter the number of expense categories: ");
    scanf("%d", &num_categories);

    for (i = 0; i < num_categories; i++) {
        printf("Enter category %d: ", i+1);
        scanf("%s", categories[i]);
    }

    num_expenses = 0;
    while (num_expenses < MAX_EXPENSES) {
        printf("\nEnter an expense (0 to quit):\n");
        printf("Category: ");
        scanf("%d", &expenses[num_expenses].category);

        if (expenses[num_expenses].category == 0) {
            break;
        }

        printf("Name: ");
        scanf("%s", expenses[num_expenses].name);

        printf("Amount: ");
        scanf("%f", &expenses[num_expenses].amount);

        for (i = 0; i < num_categories; i++) {
            if (strcmp(categories[i], expenses[num_expenses].name) == 0) {
                expenses[num_expenses].category = i;
                break;
            }
        }

        total_expenses[expenses[num_expenses].category] += expenses[num_expenses].amount;
        num_expenses++;
    }

    printf("\nExpense Summary:\n");
    for (i = 0; i < num_categories; i++) {
        printf("Category %s: $%.2f\n", categories[i], total_expenses[i]);
    }

    return 0;
}