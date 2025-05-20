//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// struct to hold user information and goals
typedef struct {
    char name[30];
    int age;
    float income;
    float expenses;
    float savings_goal;
} user_info;

int main() {
    user_info user;
    float monthly_income, monthly_expenses, monthly_savings;

    // get user information
    printf("Please enter your name: ");
    scanf("%s", user.name);

    printf("Please enter your age: ");
    scanf("%d", &user.age);

    printf("Please enter your monthly income: ");
    scanf("%f", &user.income);

    printf("Please enter your monthly expenses: ");
    scanf("%f", &user.expenses);

    printf("Please enter your desired monthly savings goal: ");
    scanf("%f", &user.savings_goal);

    // display user information
    printf("\n\n");
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Monthly Income: $%.2f\n", user.income);
    printf("Monthly Expenses: $%.2f\n", user.expenses);
    printf("Monthly Savings Goal: $%.2f\n", user.savings_goal);
    printf("\n");

    // calculate monthly income, expenses, and savings
    monthly_income = user.income;
    monthly_expenses = user.expenses;
    monthly_savings = monthly_income - monthly_expenses;

    // display monthly income, expenses, and savings
    printf("Monthly Income: $%.2f\n", monthly_income);
    printf("Monthly Expenses: $%.2f\n", monthly_expenses);
    printf("Monthly Savings: $%.2f\n", monthly_savings);

    // check if user is meeting desired savings goal
    if (monthly_savings >= user.savings_goal) {
        printf("\nCongratulations! You are meeting your monthly savings goal.\n");
    } else {
        printf("\nYou are not currently meeting your monthly savings goal. You need to save $%.2f more per month.\n", user.savings_goal - monthly_savings);
    }

    return 0;
}