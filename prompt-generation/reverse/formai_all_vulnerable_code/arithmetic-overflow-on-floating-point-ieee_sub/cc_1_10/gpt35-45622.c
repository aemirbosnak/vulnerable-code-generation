//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Dennis Ritchie
#include<stdio.h>

int main(){
    float income, savings, expenses;
    int age, retire_age;
    float inflation_rate, roi, salary_increase_rate;

    printf("Enter your current age: ");
    scanf("%d", &age);

    printf("Enter your retirement age: ");
    scanf("%d", &retire_age);

    printf("Enter your current income: ");
    scanf("%f", &income);

    printf("Enter your current savings: ");
    scanf("%f", &savings);

    printf("Enter your monthly expenses: ");
    scanf("%f", &expenses);

    printf("Enter the expected annual increase in salary: ");
    scanf("%f", &salary_increase_rate);

    printf("Enter the expected inflation rate: ");
    scanf("%f", &inflation_rate);

    printf("Enter the expected rate of return on investment: ");
    scanf("%f", &roi);

    float total_saving = savings;
    float total_expense = 0;
    float future_income = income;

    printf("Year\tAge\tIncome\tExpense\tBalance\n");

    for(int year = age; year <= retire_age; year++){
        float inflation_adjusted_income = future_income * (1 + (salary_increase_rate - inflation_rate) / 100);
        float inflation_adjusted_expense = expenses * (1 + inflation_rate / 100);

        float interest_income = total_saving * roi / 100;
        total_saving += interest_income;

        float total_income = inflation_adjusted_income * 12;
        total_expense += inflation_adjusted_expense * 12;
        float balance = total_saving - total_expense;
        future_income = inflation_adjusted_income;

        printf("%d\t%d\t%.2f\t%.2f\t%.2f\n", year, year-age+1, total_income, total_expense, balance);
    }

    printf("Total Saving: %.2f\n", total_saving);
    printf("Total Expense: %.2f\n", total_expense);

    return 0;
}