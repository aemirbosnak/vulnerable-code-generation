//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: cheerful
#include <stdio.h>

int main(){
    
    // Welcome Message
    printf("Welcome to Joyful Financial Planner!\n");
    printf("------------------------------------\n");
    printf("\n");
    
    // Declarations
    float monthlyIncome;
    float monthlyExpenses;
    float savingsGoal;
    float currentSavings;
    int monthsToReachGoal;
    
    // User Input
    printf("Let's get started!\n");
    printf("Please enter your monthly income: ");
    scanf("%f", &monthlyIncome);
    printf("\n");
    
    printf("Please enter your monthly expenses: ");
    scanf("%f", &monthlyExpenses);
    printf("\n");
    
    printf("Please enter your savings goal: ");
    scanf("%f", &savingsGoal);
    printf("\n");
    
    printf("Please enter your current savings: ");
    scanf("%f", &currentSavings);
    printf("\n");
    
    // Calculation
    float monthlySavings = monthlyIncome - monthlyExpenses;
    
    if (monthlySavings <= 0) {
        printf("You are currently living beyond your means.");
        return 0;
    }
    
    monthsToReachGoal = (savingsGoal - currentSavings) / monthlySavings;
    
    if (monthsToReachGoal <= 0) {
        printf("Congratulations! You have already reached your savings goal.");
        return 0;
    }
    
    // Results
    printf("If you save $%.2f every month, you can reach your savings goal of $%.2f in %d months.\n", monthlySavings, savingsGoal, monthsToReachGoal);
    printf("\n");
    
    printf("Thank you for using Joyful Financial Planner!\n");
    printf("We hope to see you again soon.\n");
    
    return 0;
}