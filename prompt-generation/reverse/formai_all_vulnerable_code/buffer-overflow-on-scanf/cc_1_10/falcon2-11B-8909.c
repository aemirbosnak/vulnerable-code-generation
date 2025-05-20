//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    float income;
    float expenses;
    float savings;
} budget;

int main() {
    budget budget1;
    budget budget2;
    budget budget3;

    printf("Enter the name of budget 1: ");
    fgets(budget1.name, sizeof(budget1.name), stdin);
    printf("Enter the income of budget 1: ");
    scanf("%f", &budget1.income);
    printf("Enter the expenses of budget 1: ");
    scanf("%f", &budget1.expenses);
    printf("Enter the savings of budget 1: ");
    scanf("%f", &budget1.savings);

    printf("\n");

    printf("Enter the name of budget 2: ");
    fgets(budget2.name, sizeof(budget2.name), stdin);
    printf("Enter the income of budget 2: ");
    scanf("%f", &budget2.income);
    printf("Enter the expenses of budget 2: ");
    scanf("%f", &budget2.expenses);
    printf("Enter the savings of budget 2: ");
    scanf("%f", &budget2.savings);

    printf("\n");

    printf("Enter the name of budget 3: ");
    fgets(budget3.name, sizeof(budget3.name), stdin);
    printf("Enter the income of budget 3: ");
    scanf("%f", &budget3.income);
    printf("Enter the expenses of budget 3: ");
    scanf("%f", &budget3.expenses);
    printf("Enter the savings of budget 3: ");
    scanf("%f", &budget3.savings);

    printf("\n");

    printf("Budget 1: ");
    printf("Name: %s\n", budget1.name);
    printf("Income: %.2f\n", budget1.income);
    printf("Expenses: %.2f\n", budget1.expenses);
    printf("Savings: %.2f\n", budget1.savings);

    printf("\n");

    printf("Budget 2: ");
    printf("Name: %s\n", budget2.name);
    printf("Income: %.2f\n", budget2.income);
    printf("Expenses: %.2f\n", budget2.expenses);
    printf("Savings: %.2f\n", budget2.savings);

    printf("\n");

    printf("Budget 3: ");
    printf("Name: %s\n", budget3.name);
    printf("Income: %.2f\n", budget3.income);
    printf("Expenses: %.2f\n", budget3.expenses);
    printf("Savings: %.2f\n", budget3.savings);

    printf("\n");

    return 0;
}