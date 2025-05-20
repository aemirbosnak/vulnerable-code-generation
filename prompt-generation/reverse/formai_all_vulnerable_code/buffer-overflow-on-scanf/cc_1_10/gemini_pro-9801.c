//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *description;
    float amount;
} Expense;

int main() {
    // Initialize the list of expenses.
    Expense *expenses = malloc(sizeof(Expense) * 100);
    int num_expenses = 0;

    // Get the user's input.
    printf("Enter your expenses (description and amount):\n");
    while (1) {
        char description[100];
        float amount;
        scanf("%s %f", description, &amount);
        if (strcmp(description, "quit") == 0) {
            break;
        }
        expenses[num_expenses].description = malloc(strlen(description) + 1);
        strcpy(expenses[num_expenses].description, description);
        expenses[num_expenses].amount = amount;
        num_expenses++;
    }

    // Calculate the total amount of expenses.
    float total_amount = 0;
    for (int i = 0; i < num_expenses; i++) {
        total_amount += expenses[i].amount;
    }

    // Print the list of expenses.
    printf("\nYour expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: %f\n", expenses[i].description, expenses[i].amount);
    }

    // Print the total amount of expenses.
    printf("\nTotal amount: %f\n", total_amount);

    // Free the memory allocated for the list of expenses.
    for (int i = 0; i < num_expenses; i++) {
        free(expenses[i].description);
    }
    free(expenses);

    return 0;
}