//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Grateful Personal Finance Planner!\n\n");

    float income, rent, groceries, utilities, transportation, entertainment, savings;

    printf("Please enter your monthly income: $");
    scanf("%f", &income);

    printf("\nHow much do you spend on rent/mortgage each month? $");
    scanf("%f", &rent);

    printf("\nHow much do you spend on groceries each month? $");
    scanf("%f", &groceries);

    printf("\nHow much do you spend on utilities each month? $");
    scanf("%f", &utilities);

    printf("\nHow much do you spend on transportation each month? $");
    scanf("%f", &transportation);

    printf("\nHow much do you spend on entertainment each month? $");
    scanf("%f", &entertainment);

    savings = income - rent - groceries - utilities - transportation - entertainment;

    printf("\nThank you for entering your expenses! Here is your monthly personal finance breakdown:\n");

    printf("\n=================== EXPENSES ===================\n");
    printf("Rent/Mortgage: $%.2f\n", rent);
    printf("Groceries: $%.2f\n", groceries);
    printf("Utilities: $%.2f\n", utilities);
    printf("Transportation: $%.2f\n", transportation);
    printf("Entertainment: $%.2f\n", entertainment);
    printf("\n");
    printf("==================== SAVINGS ===================\n");
    printf("Monthly Income: $%.2f\n", income);
    printf("Total Expenses: $%.2f\n", rent + groceries + utilities + transportation + entertainment);
    printf("Total Savings: $%.2f\n", savings);

    if (savings > 0)
    {
        printf("\nCongratulations! You have saved $%.2f this month! Keep up the good work!\n", savings);
    }
    else if (savings < 0)
    {
        printf("\nUh oh! Looks like you have spend over your budget. You need to adjust your expenses to save money!\n");
    }
    else
    {
        printf("\nYou have zero savings this month. Better luck next time!\n");
    }

    return 0;
}