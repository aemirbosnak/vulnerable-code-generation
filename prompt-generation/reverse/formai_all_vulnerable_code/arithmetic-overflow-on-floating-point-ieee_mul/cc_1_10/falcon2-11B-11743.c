//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: detailed
#include <stdio.h>

int main()
{
    int income;
    int expenses;
    float total_income;
    float total_expenses;
    float budget;
    float savings;
    int year;
    int month;

    printf("Welcome to your Personal Finance Planner!\n");

    printf("Please enter your total annual income:\n");
    scanf("%d", &income);

    printf("Please enter your total annual expenses:\n");
    scanf("%d", &expenses);

    total_income = income * 12;
    total_expenses = expenses * 12;

    budget = total_income - total_expenses;

    printf("Your annual budget is $%.2f.\n", budget);

    printf("Please enter your desired monthly savings rate (e.g. 10%):\n");
    scanf("%f", &savings);

    savings = savings / 100;

    for(year = 0; year < 5; year++)
    {
        for(month = 0; month < 12; month++)
        {
            savings = savings * 1.05; // 5% increase each month

            savings = savings * budget / 100; // Apply savings rate

            total_income += savings; // Add savings to income

            total_expenses += savings; // Add savings to expenses

            budget -= savings; // Subtract savings from budget
        }

        printf("Year %d complete.\n", year + 1);
    }

    printf("Congratulations! You have saved $%.2f over 5 years.\n", total_income);
    printf("You have a total budget of $%.2f.\n", budget);

    return 0;
}