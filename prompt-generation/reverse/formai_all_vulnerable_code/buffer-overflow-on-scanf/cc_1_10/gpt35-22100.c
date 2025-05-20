//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

/* Define Structure for Personal Finance */

struct PersonalFinance {
    float income;
    float expenses;
    float taxes;
    float savings;
    float investment;
};

/* Define Function to calculate Net Income */

float calculateNetIncome(float income, float expenses, float taxes) {
    float netIncome = income - expenses - taxes;
    return netIncome;
}

/* Define Function to calculate Savings */

float calculateSavings(float netIncome) {
    float savings = netIncome * 0.25;
    return savings;
}

/* Define Function to calculate Investment */

float calculateInvestment(float netIncome) {
    float investment = netIncome * 0.15;
    return investment;
}

/* Main Function */

int main() {
    struct PersonalFinance personalFinance;
    
    /* Input User Data */
    
    printf("Enter your monthly Income: ");
    scanf("%f", &personalFinance.income);
    
    printf("Enter your monthly Expenses: ");
    scanf("%f", &personalFinance.expenses);
    
    printf("Enter your monthly Taxes: ");
    scanf("%f", &personalFinance.taxes);
    
    /* Calculate and Output Results */
    
    float netIncome = calculateNetIncome(personalFinance.income, personalFinance.expenses, personalFinance.taxes);
    printf("\nNet Income: $%.2f\n", netIncome);
    
    float savings = calculateSavings(netIncome);
    printf("Savings: $%.2f\n", savings);
    
    float investment = calculateInvestment(netIncome);
    printf("Investment: $%.2f\n", investment);
    
    /* Return Success */
    
    return 0;
}