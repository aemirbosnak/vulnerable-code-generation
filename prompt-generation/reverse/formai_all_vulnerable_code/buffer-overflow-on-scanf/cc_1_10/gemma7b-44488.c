//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXPENSES 100

typedef struct Expense
{
    char name[255];
    double amount;
    time_t timestamp;
} Expense;

int main()
{
    time_t t = time(NULL);
    struct Expense expenses[MAX_EXPENSES] = {0};
    int i = 0;
    char input[255];
    double amount;

    printf("Enter 'add' to add an expense, 'list' to see all expenses, or 'quit' to exit: ");
    scanf("%s", input);

    while (strcmp(input, "quit") != 0)
    {
        if (strcmp(input, "add") == 0)
        {
            printf("Enter the name of the expense: ");
            scanf("%s", expenses[i].name);

            printf("Enter the amount of the expense: ");
            scanf("%lf", &expenses[i].amount);

            expenses[i].timestamp = t;
            i++;
        }
        else if (strcmp(input, "list") == 0)
        {
            for (int j = 0; j < i; j++)
            {
                printf("%s - %.2lf - %s\n", expenses[j].name, expenses[j].amount, ctime(&expenses[j].timestamp));
            }
        }
        else if (strcmp(input, "quit") != 0)
        {
            printf("Invalid input.\n");
        }

        printf("Enter 'add' to add an expense, 'list' to see all expenses, or 'quit' to exit: ");
        scanf("%s", input);
    }

    return 0;
}