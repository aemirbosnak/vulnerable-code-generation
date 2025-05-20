//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: real-life
#include <stdio.h>

float calculate_savings(float income, float expenses) {
    float savings = income - expenses;
    return savings;
}

int main() {

    float income, expenses;
    printf("Enter your monthly income: $");
    scanf("%f", &income);

    printf("Enter your monthly expenses: $");
    scanf("%f", &expenses);

    float savings = calculate_savings(income, expenses);
    printf("Your monthly savings is: $%.2f\n", savings);

    if (savings > 0) {
        printf("Congratulations! You are saving money each month.\n");
    } else if (savings == 0) {
        printf("You are breaking even each month. Consider reducing your expenses.\n");
    } else {
        printf("Uh-oh! You are spending more than your income. Consider reducing your expenses or increasing your income.\n");
    }

    float investment_rate, investment_growth;
    printf("\nEnter the annual rate of return on your investments: ");
    scanf("%f", &investment_rate);

    investment_growth = investment_rate / 100.0;
    
    printf("Enter the amount of money you have invested: $");
    float investment_principal;
    scanf("%f", &investment_principal);

    printf("Enter the number of years you plan to keep this investment: ");
    int investment_years;
    scanf("%d", &investment_years);

    float future_value = investment_principal;

    for (int i = 0; i < investment_years; i++) {
        future_value += future_value * investment_growth;
    }

    printf("After %d years, your investment will be worth: $%.2f\n", investment_years, future_value);

    return 0;

}