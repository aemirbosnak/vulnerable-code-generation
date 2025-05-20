//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_MONTHS 12

void print_menu();
float enter_income();
float enter_expense();
float enter_savings();
void calculate_budget(float income, float expenses, float savings);
float calculate_total(float *values, int num_values);

int main() {
    float income, expenses, savings;
    float expenses_per_month[MAX_MONTHS];
    int num_months = 0;

    int choice = -1;
    while (choice != 4) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                income = enter_income();
                break;
            case 2:
                expenses_per_month[num_months] = enter_expense();
                num_months++;
                break;
            case 3:
                savings = enter_savings();
                break;
            case 4:
                printf("Exiting Program\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    }

    expenses = calculate_total(expenses_per_month, num_months);
    calculate_budget(income, expenses, savings);

    return 0;
}

void print_menu() {
    printf("\nC Personal Finance Planner\n");
    printf("=========================\n");
    printf("1. Enter Income\n");
    printf("2. Enter Monthly Expenses\n");
    printf("3. Enter Monthly Savings\n");
    printf("4. Quit\n");
    printf("\nEnter Choice: ");
}

float enter_income() {
    float income;
    printf("\nEnter Income: ");
    scanf("%f", &income);
    return income;
}

float enter_expense() {
    float expense;
    printf("\nEnter Monthly Expense: ");
    scanf("%f", &expense);
    return expense;
}

float enter_savings() {
    float savings;
    printf("\nEnter Savings: ");
    scanf("%f", &savings);
    return savings;
}

void calculate_budget(float income, float expenses, float savings) {
    float total_expense = expenses * MAX_MONTHS;
    float net_income = income - total_expense - savings;
    
    printf("\nBudget Breakdown\n");
    printf("================\n");
    printf("Monthly Income: $%.2f\n", income);
    printf("Monthly Expenses: $%.2f\n", expenses);
    printf("Total Savings: $%.2f\n", savings);
    printf("Total Expenses for the Year: $%.2f\n", total_expense);
    printf("Net Income for the Year: $%.2f\n", net_income);
}

float calculate_total(float *values, int num_values) {
    float total = 0.0;

    for (int i = 0; i < num_values; i++) {
        total += values[i];
    }

    return total;
}