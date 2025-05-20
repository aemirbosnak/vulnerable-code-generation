//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100

typedef struct {
    char *description;
    float amount;
    char *category;
} expense_t;

int main(int argc, char *argv[]) {
    expense_t expenses[MAX_EXPENSES];
    int num_expenses = 0;
    float total_expenses = 0;

    // Read in the expenses from the user
    printf("Enter your expenses (description, amount, category):\n");
    while (1) {
        char description[100];
        float amount;
        char category[100];

        scanf("%s %f %s", description, &amount, category);

        if (strcmp(description, "EOF") == 0) {
            break;
        }

        // Allocate memory for the description
        expenses[num_expenses].description = malloc(strlen(description) + 1);
        strcpy(expenses[num_expenses].description, description);

        // Store the amount
        expenses[num_expenses].amount = amount;

        // Allocate memory for the category
        expenses[num_expenses].category = malloc(strlen(category) + 1);
        strcpy(expenses[num_expenses].category, category);

        // Increment the number of expenses
        num_expenses++;
    }

    // Calculate the total expenses
    for (int i = 0; i < num_expenses; i++) {
        total_expenses += expenses[i].amount;
    }

    // Print the expenses
    printf("\nYour expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: $%.2f (%s)\n", expenses[i].description, expenses[i].amount, expenses[i].category);
    }

    // Print the total expenses
    printf("\nTotal expenses: $%.2f\n", total_expenses);

    // Free the memory allocated for the expenses
    for (int i = 0; i < num_expenses; i++) {
        free(expenses[i].description);
        free(expenses[i].category);
    }

    return 0;
}