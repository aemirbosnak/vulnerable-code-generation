//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: cheerful
#include <stdio.h>

int main() {
    printf("Welcome to the Personal Finance Planner!\n");

    float income;
    float expenses;

    printf("Enter your monthly income: ");
    scanf("%f", &income);

    printf("Enter your monthly expenses: ");
    scanf("%f", &expenses);

    float savings = income - expenses;
    float percent_savings = (savings / income) * 100;

    printf("Your monthly savings is $%.2f\n", savings);
    printf("This is %.2f%% of your monthly income\n", percent_savings);

    if (percent_savings >= 20) {
        printf("Great job! You're saving more than 20%% of your income!\n");
    } else {
        printf("Let's try to increase your savings to 20%% of your income!\n");
        float new_savings = income * 0.2;
        float diff_savings = new_savings - savings;
        printf("To reach your goal, you need to increase your savings by $%.2f\n", diff_savings);
    }

    printf("Would you like to see projected savings with an annual interest rate?\n");
    char response;
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y') {
        float interest_rate;
        printf("Enter the annual interest rate (e.g. 5.0 for 5%% interest): ");
        scanf("%f", &interest_rate);

        float monthly_interest_rate = interest_rate / 12;
        float years = 5;
        float balance = savings;
        for (int i = 0; i < years * 12; i++) {
            balance *= 1 + (monthly_interest_rate / 100);
            balance += savings;
        }
        printf("With an annual interest rate of %.2f%% for %0.f years,\n", interest_rate, years);
        printf("your projected savings would be $%.2f\n", balance);
    }

    printf("Thank you for using the Personal Finance Planner!\n");
    return 0;
}