//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: accurate
#include <stdio.h> 

int main() 
{ 
    float income, savings, expenses, investment, loan; 

    printf("Enter your monthly income: ");
    scanf("%f", &income);
    
    printf("Enter your monthly savings: ");
    scanf("%f", &savings);

    printf("Enter your monthly expenses: ");
    scanf("%f", &expenses);

    printf("Enter your monthly investments: ");
    scanf("%f", &investment);

    printf("Enter your monthly loan payment: ");
    scanf("%f", &loan);

    float net_income = income - expenses - loan;
    float monthly_savings_rate = (savings / income) * 100;
    float investment_rate = (investment / income) * 100;

    printf("\nYour monthly net income is: $%.2f", net_income);
    printf("\nYour monthly savings rate is: %.2f%%", monthly_savings_rate);
    printf("\nYour monthly investment rate is: %.2f%%", investment_rate);

    if (net_income < 0) {
        printf("\n\nYou have a deficit of $%.2f this month. You need to cut back on your expenses.", net_income * -1);
    } else {
        printf("\n\nYou have a surplus of $%.2f this month.", net_income);

        if (monthly_savings_rate < 20) {
            printf("\n\nYou are not saving enough! You need to save at least 20%% of your income every month.");

            if (investment_rate < 10) {
                printf("\n\nYou are also not investing enough! You need to invest at least 10%% of your income every month.");
            } else {
                printf("\n\nYou are doing a good job with your investments!");
            }
        } else {
            if (investment_rate < 10) {
                printf("\n\nYou are not investing enough! You need to invest at least 10%% of your income every month.");

                if (monthly_savings_rate < 20) {
                    printf("\n\nYou are also not saving enough! You need to save at least 20%% of your income every month.");
                } else {
                    printf("\n\nYou are doing a good job with your savings!");        
                }
            } else {
                printf("\n\nYou are doing a good job with your savings and investments!");
            }
        }
    }

    return 0; 
}