//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Expense
{
    char name[50];
    int amount;
    char category[50];
} Expense;

void saveExpenses(Expense expenses[], int size)
{
    FILE *fp = fopen("expenses.txt", "w");
    fprintf(fp, "Total Expenses: %d\n", size);
    for (int i = 0; i < size; i++)
    {
        fprintf(fp, "Name: %s, Amount: %d, Category: %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
    fclose(fp);
}

int main()
{
    Expense expenses[MAX];
    int size = 0;

    while (1)
    {
        printf("Enter expense name: ");
        scanf("%s", expenses[size].name);

        printf("Enter expense amount: ");
        scanf("%d", &expenses[size].amount);

        printf("Enter expense category: ");
        scanf("%s", expenses[size].category);

        size++;

        printf("Do you want to add another expense? (Y/N) ");
        char answer;
        scanf(" %c", &answer);

        if (answer == 'N')
        {
            saveExpenses(expenses, size);
            break;
        }
    }

    return 0;
}