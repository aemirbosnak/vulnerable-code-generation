//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: excited
// Personal Finance Planner

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Budget {
    float income;
    float expenses[10];
    float savings[10];
};

void welcome() {
    printf("Welcome to the Personal Finance Planner!\n");
}

void get_income(struct Budget *budget) {
    printf("Enter your monthly income: ");
    scanf("%f", &budget->income);
}

void get_expenses(struct Budget *budget) {
    printf("Enter your monthly expenses: ");
    for (int i = 0; i < 10; i++) {
        scanf("%f", &budget->expenses[i]);
    }
}

void get_savings(struct Budget *budget) {
    printf("Enter your monthly savings: ");
    for (int i = 0; i < 10; i++) {
        scanf("%f", &budget->savings[i]);
    }
}

void calculate_savings(struct Budget *budget) {
    float total_expenses = 0;
    for (int i = 0; i < 10; i++) {
        total_expenses += budget->expenses[i];
    }
    budget->savings[11] = budget->income - total_expenses;
}

void display_budget(struct Budget *budget) {
    printf("Income: %f\n", budget->income);
    printf("Expenses:");
    for (int i = 0; i < 10; i++) {
        printf(" %f", budget->expenses[i]);
    }
    printf("\nSavings:");
    for (int i = 0; i < 10; i++) {
        printf(" %f", budget->savings[i]);
    }
    printf("\nTotal Savings: %f\n", budget->savings[11]);
}

int main() {
    struct Budget budget;
    welcome();
    get_income(&budget);
    get_expenses(&budget);
    get_savings(&budget);
    calculate_savings(&budget);
    display_budget(&budget);
    return 0;
}