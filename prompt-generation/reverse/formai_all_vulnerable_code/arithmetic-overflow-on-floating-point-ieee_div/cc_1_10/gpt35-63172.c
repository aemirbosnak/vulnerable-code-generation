//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main () {
    //Introduction and User Input
    
    printf("*** Welcome to the Happy Personal Finance Planner ***\n\n");
    printf("Please enter your monthly income: ");
    float income;
    scanf("%f", &income);
    printf("\n");

    //Fixed Expenses

    printf("*** Fixed Expenses ***\n\n");
    printf("Please enter your rent/mortgage: ");
    float rent;
    scanf("%f", &rent);
    printf("Please enter your car payment: ");
    float carPayment;
    scanf("%f", &carPayment);
    printf("Please enter your utility bills: ");
    float utilities;
    scanf("%f", &utilities);
    printf("\n");
    
    //Discretionary Spending
    
    printf("*** Discretionary Spending ***\n\n");
    printf("Please enter your monthly food budget: ");
    float food;
    scanf("%f", &food);
    printf("Please enter your entertainment budget: ");
    float entertainment;
    scanf("%f", &entertainment);
    printf("Please enter your shopping budget: ");
    float shopping;
    scanf("%f", &shopping);
    printf("\n");

    //Calculations and Results

    float fixedTotal = rent + carPayment + utilities;
    float discretionaryTotal = food + entertainment + shopping;
    float savings = income - fixedTotal - discretionaryTotal;
    float savingsPercentage = (savings / income) * 100;

    printf("*** Results ***\n\n");
    printf("Your monthly fixed expenses total is: $%.2f\n", fixedTotal);
    printf("Your monthly discretionary spending total is: $%.2f\n", discretionaryTotal);
    printf("Your monthly savings is: $%.2f\n", savings);

    if (savingsPercentage >= 30) {
        printf("Congratulations! You are saving at least 30%% of your income. Keep it up! :)\n");
    } else if (savingsPercentage >= 20 && savingsPercentage < 30) {
        printf("Great job! You are saving at least 20%% of your income. You can do even better! :D\n");
    } else if (savingsPercentage >= 10 && savingsPercentage < 20) {
        printf("Not bad! You are saving at least 10%% of your income. Keep working on it! :)\n");
    } else {
        printf("Oops! You are only saving less than 10%% of your income. Let's work on improving that! :/\n");
    }

    return 0;
}