//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: romantic
#include <stdio.h>
#include <string.h>

#define MAX_EXPENSES 10

typedef struct Expense {
    char name[20];
    double amount;
    char category[20];
} Expense;

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;

    // Create a loop to add expenses
    while (1) {
        // Get the expense name, amount, and category
        printf("Enter the expense name: ");
        scanf("%s", expenses[numExpenses].name);

        printf("Enter the expense amount: ");
        scanf("%lf", &expenses[numExpenses].amount);

        printf("Enter the expense category: ");
        scanf("%s", expenses[numExpenses].category);

        // Increment the number of expenses
        numExpenses++;

        // Check if the user wants to add another expense
        char answer;
        printf("Do you want to add another expense? (Y/N): ");
        scanf(" %c", &answer);

        // If the user does not want to add another expense, break out of the loop
        if (answer == 'N' || answer == 'n') {
            break;
        }
    }

    // Print the expenses
    printf("Your expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("Name: %s\n", expenses[i].name);
        printf("Amount: %.2lf\n", expenses[i].amount);
        printf("Category: %s\n", expenses[i].category);
        printf("\n");
    }

    return 0;
}