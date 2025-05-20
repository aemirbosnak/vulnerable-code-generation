//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main(){

    // Personal Finance Planner
    printf("Welcome to the Personal Finance Planner!\n");

    // Get current savings amount
    float currentSavings;
    printf("Please enter your current savings amount:\n");
    scanf("%f", &currentSavings);

    // Get monthly salary
    float monthlySalary;
    printf("Please enter your monthly salary:\n");
    scanf("%f", &monthlySalary);

    // Get monthly expenses
    float monthlyExpenses;
    printf("Please enter your monthly expenses:\n");
    scanf("%f", &monthlyExpenses);

    // Calculate monthly savings
    float monthlySavings = monthlySalary - monthlyExpenses;

    // Predict future savings amount
    int numMonths = 12;
    float futureSavings = currentSavings + (numMonths * monthlySavings);

    // Display predicted savings amount
    printf("Your predicted savings amount in %d months is: %.2f\n", numMonths, futureSavings);

    // Prompt for investment strategy
    printf("It's important to invest your money to make it grow over time. Please select an investment strategy from the following options:\n");
    printf("1. Conservative\n2. Moderate\n3. Aggressive\n");
    int strategy;
    scanf("%d", &strategy);

    // Calculate investment returns
    float interestRate;
    switch(strategy){
        case 1:
            interestRate = 0.01; // Conservative: 1% interest rate
            break;
        case 2:
            interestRate = 0.03; // Moderate: 3% interest rate
            break;
        case 3:
            interestRate = 0.06; // Aggressive: 6% interest rate
            break;
        default:
            printf("Invalid strategy selected. Please try again.\n");
            return 1;
    }

    float futureValue = futureSavings;
    for(int i=0; i<numMonths; i++){
        futureValue = futureValue + (futureValue * interestRate);
    }

    // Display predicted investment growth
    printf("Your predicted investment growth in %d months with a %s investment strategy is: $%.2f\n", numMonths,(strategy == 1)?"Conservative":(strategy==2)?"Moderate":"Aggressive", futureValue);

    return 0;
}