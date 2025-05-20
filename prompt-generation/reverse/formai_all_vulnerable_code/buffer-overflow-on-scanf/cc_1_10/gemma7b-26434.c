//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 10

typedef struct Expense {
    char name[50];
    int amount;
    char category[50];
} Expense;

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;

    printf("Welcome to your peaceful expense tracker!\n");

    // Loop to add expenses
    while (1) {
        printf("Enter the name of the expense: ");
        scanf("%s", expenses[numExpenses].name);

        printf("Enter the amount of the expense: ");
        scanf("%d", &expenses[numExpenses].amount);

        printf("Enter the category of the expense: ");
        scanf("%s", expenses[numExpenses].category);

        numExpenses++;

        // Check if the user wants to add more expenses
        char answer;
        printf("Do you want to add another expense? (Y/N): ");
        scanf("%c", &answer);

        if (answer == 'N') {
            break;
        }
    }

    // Print a summary of expenses
    printf("Here is a summary of your expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("Name: %s, Amount: %d, Category: %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }

    // Calculate total expense
    int totalExpense = 0;
    for (int i = 0; i < numExpenses; i++) {
        totalExpense += expenses[i].amount;
    }

    // Print total expense
    printf("Total expense: %d\n", totalExpense);

    return 0;
}