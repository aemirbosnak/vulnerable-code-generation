//FormAI DATASET v1.0 Category: Expense Tracker ; Style: irregular
/* Hey! This is a funky expense tracker program */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char item[50];
    float amount;
    char category[20];
} expense;

int main()
{
    int num_expenses;
    printf("Welcome to the one-of-a-kind expense tracker!\n");
    printf("How many expenses do you have?\n");
    scanf("%d", &num_expenses);

    expense expenses[num_expenses];

    for(int i = 0; i < num_expenses; i++)
    {
        printf("\nExpense %d:\n", i+1);
        printf("What did you buy?\n");
        scanf(" %[^\n]", expenses[i].item);
        printf("How much did it cost?\n");
        scanf("%f", &expenses[i].amount);
        printf("What category does this expense belong to?\n");
        scanf(" %[^\n]", expenses[i].category);
    }

    printf("\n\nGreat, here is your expense summary:\n\n");

    float total_expenses = 0.0;
    char* category_list[10];
    int num_categories = 0;

    for(int i = 0; i < num_expenses; i++)
    {
        if(!strstr(category_list, expenses[i].category))
        {
            category_list[num_categories] = expenses[i].category;
            num_categories++;
        }

        printf("You spent $%.2f on %s which belongs to the category %s.\n", expenses[i].amount, expenses[i].item, expenses[i].category);
        
        total_expenses += expenses[i].amount;
    }

    printf("\n\nYour total expenses for this period are $%.2f\n", total_expenses);

    printf("You spent money in the following categories:\n");
    for(int i = 0; i < num_categories; i++)
    {
        printf("- %s\n", category_list[i]);
    }

    return 0;
}