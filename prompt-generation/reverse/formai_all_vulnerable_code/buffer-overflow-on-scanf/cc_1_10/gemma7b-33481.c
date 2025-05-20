//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("WELCOME TO THE EXPENSE TRACKER!\n");
    printf("Please enter your name: ");
    char name[20];
    scanf("%s", name);

    printf("Hello, %s, let's track your expenses!\n", name);

    int num_expenses = 0;
    double total_expenses = 0.0;

    // Loop to get the number of expenses
    printf("How many expenses do you have? ");
    int num_expenses_temp;
    scanf("%d", &num_expenses_temp);
    num_expenses = num_expenses_temp;

    // Loop to get the details of each expense
    for (int i = 0; i < num_expenses; i++)
    {
        printf("Enter the name of the expense: ");
        char expense_name[50];
        scanf("%s", expense_name);

        printf("Enter the cost of the expense: ");
        double expense_cost;
        scanf("%lf", &expense_cost);

        // Calculate the total expense
        total_expenses += expense_cost;

        // Display the expense details
        printf("Expense name: %s\n", expense_name);
        printf("Expense cost: %.2lf\n", expense_cost);
    }

    // Display the total expenses
    printf("Total expenses: %.2lf\n", total_expenses);

    // Calculate the average expense
    double average_expense = total_expenses / num_expenses;

    // Display the average expense
    printf("Average expense: %.2lf\n", average_expense);

    // Thank you message
    printf("Thank you for using the expense tracker, %s!\n", name);

    return 0;
}