//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 50

typedef struct {
    char name[50];
    float amount;
    char category[50];
} expense;

int main() {
    int num_categories = 0, num_expenses = 0;
    char categories[MAX_CATEGORIES][50];
    expense expenses[MAX_EXPENSES];

    printf("Welcome to the Expense Tracker!\n");

    // Add categories
    while(num_categories < MAX_CATEGORIES) {
        printf("Enter a category (or leave blank to finish): ");
        scanf("%s", categories[num_categories]);
        if(strcmp(categories[num_categories], "") == 0) {
            break;
        }
        num_categories++;
    }

    // Add expenses
    while(num_expenses < MAX_EXPENSES) {
        printf("Enter an expense (or leave blank to finish): ");
        scanf("%s %f %s", expenses[num_expenses].name, &expenses[num_expenses].amount, expenses[num_expenses].category);
        if(strcmp(expenses[num_expenses].name, "") == 0) {
            break;
        }
        num_expenses++;
    }

    // Print expenses by category
    printf("\nExpenses by category:\n");
    for(int i = 0; i < num_categories; i++) {
        printf("%s:\n", categories[i]);
        for(int j = 0; j < num_expenses; j++) {
            if(strcmp(expenses[j].category, categories[i]) == 0) {
                printf("%s - $%.2f\n", expenses[j].name, expenses[j].amount);
            }
        }
        printf("\n");
    }

    return 0;
}