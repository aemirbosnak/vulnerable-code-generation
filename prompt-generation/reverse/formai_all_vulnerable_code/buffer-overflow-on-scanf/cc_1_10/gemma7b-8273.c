//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct PersonalFinance
{
    char name[MAX];
    int income;
    int expenses;
    int savings;
} PersonalFinance;

int main()
{
    PersonalFinance pf[MAX];

    // Initialize the array of PersonalFinance structures
    for (int i = 0; i < MAX; i++)
    {
        pf[i].name[0] = '\0';
        pf[i].income = 0;
        pf[i].expenses = 0;
        pf[i].savings = 0;
    }

    // Get the number of PersonalFinance structures to manage
    int num = 0;

    // Loop over the array and get the information for each PersonalFinance structure
    while (1)
    {
        printf("Enter the name of the PersonalFinance structure: ");
        scanf("%s", pf[num].name);

        printf("Enter the income of the PersonalFinance structure: ");
        scanf("%d", &pf[num].income);

        printf("Enter the expenses of the PersonalFinance structure: ");
        scanf("%d", &pf[num].expenses);

        printf("Enter the savings of the PersonalFinance structure: ");
        scanf("%d", &pf[num].savings);

        // Increment the number of PersonalFinance structures
        num++;

        // Check if the user wants to continue
        printf("Do you want to enter another PersonalFinance structure? (Y/N) ");
        char answer;
        scanf(" %c", &answer);

        if (answer == 'N')
        {
            break;
        }
    }

    // Calculate the total income, expenses, and savings
    int total_income = 0;
    int total_expenses = 0;
    int total_savings = 0;
    for (int i = 0; i < num; i++)
    {
        total_income += pf[i].income;
        total_expenses += pf[i].expenses;
        total_savings += pf[i].savings;
    }

    // Print the total income, expenses, and savings
    printf("Total income: $%d\n", total_income);
    printf("Total expenses: $%d\n", total_expenses);
    printf("Total savings: $%d\n", total_savings);

    return 0;
}