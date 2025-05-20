//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float income, savings, expenses, rent, groceries, utilities, transportation, otherExpenses, totalExpenses;
    int numMonths;

    printf("Welcome to our Personal Finance Planner!\n");

    printf("Please enter your monthly income: ");
    scanf("%f", &income);

    printf("Please enter your monthly savings: ");
    scanf("%f", &savings);

    printf("Please enter your monthly rent/mortgage: ");
    scanf("%f", &rent);

    printf("Please enter your monthly groceries: ");
    scanf("%f", &groceries);

    printf("Please enter your monthly utilities: ");
    scanf("%f", &utilities);

    printf("Please enter your monthly transportation: ");
    scanf("%f", &transportation);

    printf("Please enter your other monthly expenses: ");
    scanf("%f", &otherExpenses);

    totalExpenses = rent + groceries + utilities + transportation + otherExpenses;
    printf("Your total monthly expenses are: %.2f\n", totalExpenses);

    printf("How many months would you like to plan for? ");
    scanf("%d", &numMonths);

    printf("\n");
    printf("Here is your monthly financial plan:\n");
    printf("-------------------------------------\n");

    for(int i=1; i<=numMonths; i++) {
        printf("Month %d:\n", i);
        printf("Income: %.2f\n", income);
        printf("Savings: %.2f\n", savings);
        printf("Expenses: %.2f\n", totalExpenses);
        printf("Remaining Balance: %.2f\n", income - totalExpenses - savings);
        printf("\n");
    }

    printf("Thank you for using our Personal Finance Planner!\n");

    return 0;
}