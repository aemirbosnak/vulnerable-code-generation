//FormAI DATASET v1.0 Category: Expense Tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int expenses[30], totalExpenses = 0, numberOfExpenses = 0, expense = 0;
    char response;

    printf("Welcome to the Cheerful Expense Tracker! Let's get started!\n");

    do {
        printf("\nEnter the expense amount: ");
        scanf("%d", &expense);

        expenses[numberOfExpenses++] = expense;
        totalExpenses += expense;

        printf("Do you want to enter another expense? (y/n): ");
        scanf(" %c", &response);

    } while (response == 'y');

    // Displaying all entered expenses
    printf("\n===== Your Entered Expenses =====\n");

    for (int i = 0; i < numberOfExpenses; i++) {
        printf("Expense %d: $%d\n", i+1, expenses[i]);
    }

    // Displaying total expenses
    printf("\nTotal Expenses: $%d\n", totalExpenses);

    // Calculating and displaying average expense
    float averageExpense = (float) totalExpenses / (float) numberOfExpenses;
    printf("Average Expense: $%.2f\n", averageExpense);

    // Calculating and displaying the highest expense
    int highestExpense = expenses[0];

    for (int i = 1; i < numberOfExpenses; i++) {
        if (expenses[i] > highestExpense) {
            highestExpense = expenses[i];
        }
    }

    printf("Highest Expense: $%d\n", highestExpense);

    // Calculating and displaying the lowest expense
    int lowestExpense = expenses[0];

    for (int i = 1; i < numberOfExpenses; i++) {
        if (expenses[i] < lowestExpense) {
            lowestExpense = expenses[i];
        }
    }

    printf("Lowest Expense: $%d\n", lowestExpense);

    printf("\nThank you for using the Cheerful Expense Tracker! Have a great day!");

    return 0;
}