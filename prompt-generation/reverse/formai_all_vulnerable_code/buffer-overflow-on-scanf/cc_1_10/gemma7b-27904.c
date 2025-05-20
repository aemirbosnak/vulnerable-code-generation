//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: retro
#include <stdio.h>
#include <string.h>

#define MAX_EXPENSE_ITEMS 10

typedef struct ExpenseItem
{
    char name[50];
    int amount;
    char category[50];
} ExpenseItem;

int main()
{
    ExpenseItem items[MAX_EXPENSE_ITEMS];
    int numItems = 0;
    char input[20];

    printf("Welcome to the Retro Expense Tracker!\n");
    printf("--------------------\n");

    // Loop until the user enters 'q'
    while (1)
    {
        printf("Enter the name of the expense: ");
        scanf("%s", items[numItems].name);

        printf("Enter the amount of the expense: ");
        scanf("%d", &items[numItems].amount);

        printf("Enter the category of the expense: ");
        scanf("%s", items[numItems].category);

        numItems++;

        printf("Do you want to enter another expense? (y/n): ");
        scanf("%s", input);

        if (strcmp(input, "n") == 0)
        {
            break;
        }
    }

    // Print the expenses
    printf("Here is a list of your expenses:\n");
    for (int i = 0; i < numItems; i++)
    {
        printf("%s - %d - %s\n", items[i].name, items[i].amount, items[i].category);
    }

    return 0;
}