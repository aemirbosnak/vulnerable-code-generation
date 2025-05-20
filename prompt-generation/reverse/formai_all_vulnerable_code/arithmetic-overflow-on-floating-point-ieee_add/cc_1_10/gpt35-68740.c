//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: energetic
#include <stdio.h>

int main() {

    printf("Welcome to your Personal Finance Planner!\n");
    printf("Please enter your monthly income:\n");

    float income;
    scanf("%f",&income);

    printf("Great! Now, let's move on to your monthly expenses.\n");
    printf("How much do you spend on rent/mortgage?\n");

    float rent;
    scanf("%f",&rent);

    printf("How much do you spend on utilities (electricity, water, gas, internet)?\n");

    float utilities;
    scanf("%f",&utilities);

    printf("What is your monthly transportation cost (fuel, public transport, etc)?\n");

    float transportation;
    scanf("%f",&transportation);

    printf("How much do you spend on groceries and food? \n");

    float groceries;
    scanf("%f",&groceries);

    printf("What is your monthly entertainment budget (restaurants, movies, outings)?\n");

    float entertainment;
    scanf("%f",&entertainment);

    printf("Finally, how much do you put towards savings and investments?\n");

    float savings;
    scanf("%f",&savings);

    float total_expenses = rent + utilities + transportation + groceries + entertainment + savings;
    float remaining_income = income - total_expenses;

    printf("--------------------------------\n");
    printf("Here's a summary of your finances:\n");
    printf("--------------------------------\n");
    printf("Monthly Income: $%.2f\n",income);
    printf("Monthly Expenses: $%.2f\n",total_expenses);
    printf("Remaining Income: $%.2f\n",remaining_income);

    if(remaining_income >= 0) {
        printf("Congratulations! You have a positive cash flow this month. Consider allocating the extra funds towards paying off debt or increasing your savings.\n");
    }
    else if(remaining_income < 0) {
        printf("Uh-oh! You are spending more than you make. It's time to re-assess your budget and see where you can cut back.\n");
    }
    return 0;
}