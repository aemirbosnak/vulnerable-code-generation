//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {

    double salary, rent, bills, groceries, transportation, entertainment, savings;

    printf("Welcome to the Personal Finance Planner!\n\n");

    printf("Please input your monthly salary: ");
    scanf("%lf", &salary);
    
    printf("\nGreat! Now let's start budgeting.\n\n");

    printf("How much is your monthly rent/mortgage? ");
    scanf("%lf", &rent);

    printf("How much are your monthly bills? ");
    scanf("%lf", &bills);

    printf("How much do you spend on groceries each month? ");
    scanf("%lf", &groceries);

    printf("How much do you spend on transportation (e.g. gas, public transit) each month? ");
    scanf("%lf", &transportation);

    printf("How much do you spend on entertainment (e.g. dining out, movies, streaming services) each month? ");
    scanf("%lf", &entertainment);

    printf("\nThank you for your input! Here's a breakdown of your monthly expenses:\n");

    double total_expenses = rent + bills + groceries + transportation + entertainment;

    printf("\nRent/mortgage: $%.2lf\n", rent);
    printf("Bills: $%.2lf\n", bills);
    printf("Groceries: $%.2lf\n", groceries);
    printf("Transportation: $%.2lf\n", transportation);
    printf("Entertainment: $%.2lf\n", entertainment);
    printf("---------------------\n");
    printf("Total expenses: $%.2lf\n\n", total_expenses);

    double remaining_money = salary - total_expenses;

    if (remaining_money > 0) {
        printf("Congrats, you have $%.2lf remaining in your budget!\n", remaining_money);

        printf("How much of this remaining money would you like to allocate towards savings? ");
        scanf("%lf", &savings);

        printf("\nGreat! Here's your final monthly budget plan:\n");

        double remaining_money_after_savings = remaining_money - savings;

        printf("\nIncome: $%.2lf\n", salary);
        printf("Expenses:\n");
        printf("    Rent/mortgage: $%.2lf\n", rent);
        printf("    Bills: $%.2lf\n", bills);
        printf("    Groceries: $%.2lf\n", groceries);
        printf("    Transportation: $%.2lf\n", transportation);
        printf("    Entertainment: $%.2lf\n", entertainment);
        printf("    Savings: $%.2lf\n", savings);
        printf("---------------------\n");
        printf("Total expenses: $%.2lf\n", total_expenses);
        printf("Remaining money: $%.2lf\n\n", remaining_money_after_savings);
    } else {
        printf("Uh-oh, it looks like you're over-budget! You need to cut back on expenses.\n");
    }

    return 0;
}