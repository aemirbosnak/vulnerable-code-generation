//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: surprised
#include <stdio.h>

int main() {
    printf("Welcome to your Personal Finance Planner!\n");
    printf("What can I help you with today?\n\n");
    
    // Get user's monthly income
    float monthly_income;
    printf("Please enter your monthly income: $");
    scanf("%f", &monthly_income);
    printf("\n");
    
    // Get user's monthly expenses
    float total_expenses = 0;
    int expense_count = 0;
    char response;
    do {
        float expense;
        printf("Please enter an expense: $");
        scanf("%f", &expense);
        total_expenses += expense;
        expense_count++;
        printf("Do you have another expense? (y/n) ");
        scanf(" %c", &response);
    } while(response == 'y' || response == 'Y');
    printf("\n");
    
    // Calculate user's monthly savings
    float monthly_savings = monthly_income - total_expenses;
    
    // Determine if user is on track for their financial goals
    if(monthly_savings > 0) {
        printf("Great job! You are on track to reach your financial goals.\n");
    } else if(monthly_savings == 0) {
        printf("You are breaking even. Consider finding ways to cut expenses or increase income.\n");
    } else {
        printf("Uh oh! You are spending more than you are earning. It's time to make some changes.\n");
    }
    
    // Provide personalized financial advice based on user's situation
    if(expense_count >= 5 && monthly_savings > 0) {
        printf("You are doing well with your finances, but you may be able to save even more by cutting back on unnecessary expenses.\n");
    } else if(expense_count < 5 && monthly_savings > 0) {
        printf("You are doing well with your finances. Keep up the good work!\n");
    } else if(expense_count >= 5 && monthly_savings == 0) {
        printf("You may need to re-evaluate your expenses and find ways to cut back in order to achieve your financial goals.\n");
    } else if(expense_count < 5 && monthly_savings == 0) {
        printf("You are breaking even, but consider finding ways to increase your income or cut expenses in order to start saving.\n");
    } else if(expense_count >= 5 && monthly_savings < 0) {
        printf("It's time to make some serious changes to your spending habits. Consider finding ways to cut expenses or increase your income.\n");
    } else if(expense_count < 5 && monthly_savings < 0) {
        printf("You are spending more than you are earning. It's time to take a hard look at your expenses and make some changes.\n");
    }
    
    return 0;
}