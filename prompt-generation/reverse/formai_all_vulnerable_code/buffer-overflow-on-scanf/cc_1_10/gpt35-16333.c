//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 50

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char description[50];
    float amount;
    Date date;
} Expense;

// Function to add a new expense
void addExpense(Expense *expenses, int *numExpenses)
{
    // Check whether the array is full
    if (*numExpenses >= MAX_EXPENSES)
    {
        printf("Sorry, you have reached the maximum number of expenses.\n");
        return;
    }

    // Get the expense details from the user
    printf("Enter the expense description: ");
    scanf("%s", expenses[*numExpenses].description);

    printf("Enter the expense amount: ");
    scanf("%f", &expenses[*numExpenses].amount);

    printf("Enter the expense date (DD MM YYYY): ");
    scanf("%d %d %d", &expenses[*numExpenses].date.day, &expenses[*numExpenses].date.month, &expenses[*numExpenses].date.year);

    // Increment the number of expenses
    (*numExpenses)++;

    printf("Expense added successfully.\n");
}

// Function to print the list of expenses
void printExpenses(Expense *expenses, int numExpenses)
{
    // Check whether there are any expenses
    if (numExpenses == 0)
    {
        printf("There are no expenses to display.\n");
        return;
    }

    printf("List of expenses:\n");
    printf("%-20s%-10s%-10s%-10s\n", "Description", "Amount", "Day", "Month", "Year");

    for (int i = 0; i < numExpenses; i++)
    {
        printf("%-20s%-10.2f%-10d%-10d%-10d\n", expenses[i].description, expenses[i].amount, expenses[i].date.day, expenses[i].date.month, expenses[i].date.year);
    }
}

int main()
{
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    int choice;

    printf("Expense Tracker\n");
    printf("================\n\n");

    while (1)
    {
        printf("1. Add expense\n");
        printf("2. Print expenses\n");
        printf("3. Quit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addExpense(expenses, &numExpenses);
                break;

            case 2:
                printExpenses(expenses, numExpenses);
                break;

            case 3:
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a number between 1 and 3.\n");
        }

        printf("\n");
    }

    return 0;
}