//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: random
#include <stdio.h>

float monthly_income, rent, utilities, food, transportation, entertainment;
float monthly_savings, monthly_expenses;

int main() {
    
    printf("Welcome to the Personal Finance Planner!\n\n");
    
    // Get input from user
    printf("Enter your monthly income: ");
    scanf("%f", &monthly_income);
    
    printf("Enter your monthly rent/mortgage: ");
    scanf("%f", &rent);
    
    printf("Enter your monthly utilities bill: ");
    scanf("%f", &utilities);
    
    printf("Enter your monthly food expenses: ");
    scanf("%f", &food);
    
    printf("Enter your monthly transportation expenses: ");
    scanf("%f", &transportation);
    
    printf("Enter your monthly entertainment expenses: ");
    scanf("%f", &entertainment);
    
    // Calculate monthly savings and expenses
    monthly_expenses = rent + utilities + food + transportation + entertainment;
    monthly_savings = monthly_income - monthly_expenses;
    
    // Display results to user
    printf("\n\n************ Results ************\n\n");
    printf("Monthly Income:           $ %.2f\n", monthly_income);
    printf("Monthly Rent/Mortgage:    $ %.2f\n", rent);
    printf("Monthly Utilities Bill:   $ %.2f\n", utilities);
    printf("Monthly Food Expenses:    $ %.2f\n", food);
    printf("Monthly Transportation:   $ %.2f\n", transportation);
    printf("Monthly Entertainment:    $ %.2f\n", entertainment);
    printf("---------------------------------\n");
    printf("Monthly Expenses:         $ %.2f\n", monthly_expenses);
    printf("Monthly Savings:          $ %.2f\n", monthly_savings);
    
    // Check if user is saving enough
    if (monthly_savings >= 0.20 * monthly_income) {
        printf("\nYou're doing great! You're saving at least 20 percent of your monthly income.\n");
    } else if (monthly_savings >= 0.10 * monthly_income) {
        printf("\nYou're doing okay. You're saving at least 10 percent of your monthly income.\n");
    } else {
        printf("\nYou need to start saving more. Aim for at least 10 percent of your monthly income.\n");
    }
    
    return 0;
}