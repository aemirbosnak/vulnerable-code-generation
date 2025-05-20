//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

void track_expenses(int num_expenses);

int main()
{
    int num_expenses = 0;
    char ch;

    printf("Enter 'add' to add an expense or 'quit' to quit: ");
    scanf("%c", &ch);

    while (ch != 'quit')
    {
        if (ch == 'add')
        {
            track_expenses(++num_expenses);
        }
        else
        {
            printf("Invalid input. Please try again: ");
        }

        printf("Enter 'add' to add an expense or 'quit' to quit: ");
        scanf("%c", &ch);
    }

    printf("Total expenses: $%d\n", num_expenses);

    return 0;
}

void track_expenses(int num_expenses)
{
    int expense_amount;
    char expense_description[20];

    printf("Enter the expense amount: ");
    scanf("%d", &expense_amount);

    printf("Enter the expense description: ");
    scanf("%s", expense_description);

    // Store the expense data in an array or other data structure
    // ...

    // Increment the total number of expenses
    num_expenses++;
}