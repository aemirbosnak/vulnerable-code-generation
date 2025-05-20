//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

int main(){
    float salary, rent, food, bills, savings, totalSpending;
    int month = 12;

    printf("Welcome to Personal Finance Planner, let's get started!\n\n");

    printf("Enter your monthly salary: ");
    scanf("%f", &salary);

    printf("Enter your monthly rent: ");
    scanf("%f", &rent);

    printf("Enter your monthly food expenses: ");
    scanf("%f", &food);

    printf("Enter your monthly bills (utilities, phone, etc.) expenses: ");
    scanf("%f", &bills);

    printf("Enter your monthly savings: ");
    scanf("%f", &savings);

    totalSpending = rent + food + bills;
    float yearlySpending = totalSpending * month;

    printf("\nYour monthly income: $%.2f\n", salary);
    printf("Your monthly spending (rent, food, bills): $%.2f\n", totalSpending);
    printf("Your monthly savings: $%.2f\n\n", savings);

    printf("Here's a summary of your yearly expenses:\n");
    printf("Rent: $%.2f\n", rent * month);
    printf("Food: $%.2f\n", food * month);
    printf("Bills: $%.2f\n", bills * month);
    printf("Total Spending: $%.2f\n\n", yearlySpending);

    printf("Here's a breakdown of your monthly expenses:\n");
    printf("Rent: $%.2f\n", rent);
    printf("Food: $%.2f\n", food);
    printf("Bills: $%.2f\n", bills);
    printf("Total Spending: $%.2f\n\n", totalSpending);

    float yearlyIncome = salary * month;
    float yearlySavings = savings * month;
    float yearlyNetIncome = yearlyIncome - yearlySpending;

    printf("Here's a summary of your yearly income:\n");
    printf("Salary: $%.2f\n", yearlyIncome);
    printf("Savings: $%.2f\n", yearlySavings);
    printf("Net Income: $%.2f\n\n", yearlyNetIncome);

    if(yearlyNetIncome < 0){
        printf("Uh oh! You're spending more than you're earning.\n");
        printf("You may need to look into ways to cut down your expenses.\n");
    } else {
        printf("Good job! You're spending less than you're earning.\n");
        printf("You're on the right track to achieving your financial goals.\n");
    }

    printf("\nThank you for using Personal Finance Planner!\n\n");

    return 0;
}