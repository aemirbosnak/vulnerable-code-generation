//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: scientific
#include<stdio.h>
#include<stdlib.h>

// Define a struct to store financial information
struct financial_info {
    float monthly_income;
    float monthly_expenses;
    float monthly_savings;
    float investment_return_rate;
    float retirement_goal;
};

// Define a function that calculates total savings at retirement
float calculate_total_savings(float monthly_savings, float investment_return_rate, float retirement_goal) {
    float total_savings = 0;
    int years_to_retirement = 0;
    printf("\nEnter the number of years until retirement:\n");
    scanf("%d", &years_to_retirement);
    for(int i=0; i<years_to_retirement; i++) {
        total_savings += (12 * monthly_savings);
        total_savings *= (1 + (investment_return_rate / 100));
    }
    if(total_savings >= retirement_goal) {
        printf("Congratulations! You have met your retirement goal!\n");
    } else {
        printf("Sorry, you have not met your retirement goal yet.\n");
        printf("Total savings at retirement: $%.2f\n", total_savings);
        printf("Retirement goal: $%.2f\n", retirement_goal);
    }
    return total_savings;
}

int main() {
    // Declare and initialize the struct for financial_info
    struct financial_info finfo = {0};
    
    // Prompt the user to input financial information
    printf("Enter your monthly income:\n");
    scanf("%f", &finfo.monthly_income);
    printf("Enter your monthly expenses:\n");
    scanf("%f", &finfo.monthly_expenses);
    finfo.monthly_savings = finfo.monthly_income - finfo.monthly_expenses;
    printf("Your monthly savings: $%.2f\n",finfo.monthly_savings);
    printf("Enter the expected investment return rate (in percent):\n");
    scanf("%f", &finfo.investment_return_rate);
    printf("Enter your retirement goal:\n");
    scanf("%f", &finfo.retirement_goal);
    
    // Calculate total savings at retirement and display the result
    printf("\nCalculating total savings at retirement...\n");
    float total_savings = calculate_total_savings(finfo.monthly_savings, finfo.investment_return_rate, finfo.retirement_goal);
    printf("Total savings at retirement: $%.2f\n", total_savings);
    
    return 0;
}