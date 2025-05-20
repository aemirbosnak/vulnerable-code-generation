//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct PersonalFinance
{
    char name[MAX];
    int age;
    double income;
    double expenses;
    double savings;
    double investments;
} PersonalFinance;

int main()
{
    PersonalFinance pf[MAX];
    int i = 0;

    // Create an array of PersonalFinance structs
    for (i = 0; i < MAX; i++)
    {
        pf[i].name[0] = '\0';
        pf[i].age = 0;
        pf[i].income = 0.0;
        pf[i].expenses = 0.0;
        pf[i].savings = 0.0;
        pf[i].investments = 0.0;
    }

    // Get the user's name, age, income, expenses, savings, and investments
    printf("Enter your name: ");
    scanf("%s", pf[i].name);

    printf("Enter your age: ");
    scanf("%d", &pf[i].age);

    printf("Enter your income: ");
    scanf("%lf", &pf[i].income);

    printf("Enter your expenses: ");
    scanf("%lf", &pf[i].expenses);

    printf("Enter your savings: ");
    scanf("%lf", &pf[i].savings);

    printf("Enter your investments: ");
    scanf("%lf", &pf[i].investments);

    // Calculate the user's total net worth
    double net_worth = pf[i].savings + pf[i].investments - pf[i].expenses;

    // Print the user's total net worth
    printf("Your total net worth is: $%.2lf", net_worth);

    return 0;
}