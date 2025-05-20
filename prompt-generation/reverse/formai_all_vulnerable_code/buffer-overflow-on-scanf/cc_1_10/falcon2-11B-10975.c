//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Budget
{
    char name[50];
    float amount;
    char category[50];
};

struct Budget *budgetList = NULL;
int budgetListSize = 0;

void addBudget(char name[], float amount, char category[])
{
    struct Budget *newBudget = (struct Budget *)malloc(sizeof(struct Budget));
    if (newBudget == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(newBudget->name, name);
    newBudget->amount = amount;
    strcpy(newBudget->category, category);
    budgetList = realloc(budgetList, (budgetListSize + 1) * sizeof(struct Budget));
    if (budgetList == NULL)
    {
        printf("Memory reallocation failed\n");
        free(newBudget);
        return;
    }
    budgetList[budgetListSize] = *newBudget;
    budgetListSize++;
}

void printBudgetList()
{
    int i;
    printf("Budget List:\n");
    for (i = 0; i < budgetListSize; i++)
    {
        printf("Name: %s\tAmount: %.2f\tCategory: %s\n", budgetList[i].name, budgetList[i].amount, budgetList[i].category);
    }
}

void main()
{
    char name[50];
    float amount;
    char category[50];
    int choice;

    while (1)
    {
        printf("Enter your choice:\n");
        printf("1. Add a new budget\n");
        printf("2. View all budgets\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter budget name: ");
                fgets(name, sizeof(name), stdin);
                fgets(name, sizeof(name), stdin);
                printf("Enter budget amount: ");
                scanf("%f", &amount);
                printf("Enter budget category: ");
                fgets(category, sizeof(category), stdin);
                fgets(category, sizeof(category), stdin);
                addBudget(name, amount, category);
                break;

            case 2:
                printBudgetList();
                break;

            case 3:
                break;

            default:
                printf("Invalid choice\n");
                break;
        }
    }
}