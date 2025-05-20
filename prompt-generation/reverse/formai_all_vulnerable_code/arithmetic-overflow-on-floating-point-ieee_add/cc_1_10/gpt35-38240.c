//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

int main(){
    float monthly_income, expenses, savings;
    printf("Welcome to Personal Finance Planner!\n");
    printf("Please enter your monthly income: $");
    scanf("%f", &monthly_income);
    printf("Please enter your monthly expenses: $");
    scanf("%f", &expenses);
    savings = monthly_income - expenses;
    printf("Your monthly savings: $%.2f\n", savings);
    if (savings > 0){
        printf("Congratulations! You have some money left over each month!\n");
        printf("Let's see what you can do with that money:\n");
        printf("1. Save for a rainy day\n");
        printf("2. Invest in a high-interest savings account\n");
        printf("3. Pay off high-interest debt\n");
        printf("4. Invest in stocks or mutual funds\n");
        printf("Please enter your choice (1-4): ");
        int choice;
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Great choice! It's important to have a safety net in case of unexpected expenses.\n");
                printf("How much would you like to save each month? $");
                float savings_choice;
                scanf("%f", &savings_choice);
                savings += savings_choice;
                printf("Your new monthly savings: $%.2f\n", savings);
                break;
            case 2:
                printf("Good idea! Look for a savings account with a high interest rate to get the most out of your savings.\n");
                printf("How much would you like to invest each month? $");
                float investment_choice;
                scanf("%f", &investment_choice);
                savings += investment_choice;
                printf("Your new monthly savings: $%.2f\n", savings);
                break;
            case 3:
                printf("Smart move! High-interest debts, such as credit card debt, can really hold you back.\n");
                printf("How much would you like to pay towards your debt each month? $");
                float debt_choice;
                scanf("%f", &debt_choice);
                expenses -= debt_choice;
                printf("Your new monthly expenses: $%.2f\n", expenses);
                savings = monthly_income - expenses;
                printf("Your new monthly savings: $%.2f\n", savings);
                break;
            case 4:
                printf("Investing in stocks or mutual funds is a great way to grow your wealth over time.\n");
                printf("How much would you like to invest each month? $");
                float investment_choice_2;
                scanf("%f", &investment_choice_2);
                savings += investment_choice_2;
                printf("Your new monthly savings: $%.2f\n", savings);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } else if (savings < 0){
        printf("Uh oh. It looks like you're spending more than you're making. Let's see how we can fix that.\n");
        printf("1. Review your expenses\n");
        printf("2. Find ways to increase your income\n");
        printf("Please enter your choice (1 or 2): ");
        int choice_2;
        scanf("%d", &choice_2);
        switch(choice_2){
            case 1:
                printf("Great idea! It's always good to review your expenses and see where you can cut back.\n");
                printf("Enter the amount you would like to cut back on your monthly expenses: $");
                float cutback;
                scanf("%f", &cutback);
                expenses -= cutback;
                printf("Your new monthly expenses: $%.2f\n", expenses);
                savings = monthly_income - expenses;
                printf("Your new monthly savings: $%.2f\n", savings);
                break;
            case 2:
                printf("Good thinking! Let's see how you can increase your income.\n");
                printf("Enter the amount you would like to increase your monthly income: $");
                float income_increase;
                scanf("%f", &income_increase);
                monthly_income += income_increase;
                printf("Your new monthly income: $%.2f\n", monthly_income);
                savings = monthly_income - expenses;
                printf("Your new monthly savings: $%.2f\n", savings);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } else {
        printf("You're breaking even! That's a good thing, but don't forget to plan for unexpected expenses.\n");
    }
    printf("Thank you for using Personal Finance Planner. Good luck with your finances!");
    return 0;
}