//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

struct budget {
    char name[50];
    double income;
    double expenses;
};

int main() {
    struct budget budget1;
    struct budget budget2;
    struct budget budget3;

    printf("Enter the name of the budget: ");
    scanf("%s", budget1.name);
    printf("Enter the income: ");
    scanf("%lf", &budget1.income);
    printf("Enter the expenses: ");
    scanf("%lf", &budget1.expenses);

    printf("\nBudget 1:\n");
    printf("Name: %s\n", budget1.name);
    printf("Income: %lf\n", budget1.income);
    printf("Expenses: %lf\n", budget1.expenses);

    printf("\nEnter the name of the budget: ");
    scanf("%s", budget2.name);
    printf("Enter the income: ");
    scanf("%lf", &budget2.income);
    printf("Enter the expenses: ");
    scanf("%lf", &budget2.expenses);

    printf("\nBudget 2:\n");
    printf("Name: %s\n", budget2.name);
    printf("Income: %lf\n", budget2.income);
    printf("Expenses: %lf\n", budget2.expenses);

    printf("\nEnter the name of the budget: ");
    scanf("%s", budget3.name);
    printf("Enter the income: ");
    scanf("%lf", &budget3.income);
    printf("Enter the expenses: ");
    scanf("%lf", &budget3.expenses);

    printf("\nBudget 3:\n");
    printf("Name: %s\n", budget3.name);
    printf("Income: %lf\n", budget3.income);
    printf("Expenses: %lf\n", budget3.expenses);

    return 0;
}