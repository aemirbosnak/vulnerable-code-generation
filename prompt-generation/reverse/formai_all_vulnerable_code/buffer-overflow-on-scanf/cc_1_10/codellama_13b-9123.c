//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

struct finance_planner {
    float income;
    float expenses[10];
    float savings;
    float debt;
    float emergency_fund;
    float retirement_savings;
};

void get_income(struct finance_planner *fp) {
    printf("Enter your monthly income: ");
    scanf("%f", &fp->income);
}

void get_expenses(struct finance_planner *fp) {
    int i;
    for (i = 0; i < 10; i++) {
        printf("Enter your %dth monthly expense: ", i + 1);
        scanf("%f", &fp->expenses[i]);
    }
}

void get_savings(struct finance_planner *fp) {
    printf("Enter your monthly savings: ");
    scanf("%f", &fp->savings);
}

void get_debt(struct finance_planner *fp) {
    printf("Enter your monthly debt: ");
    scanf("%f", &fp->debt);
}

void get_emergency_fund(struct finance_planner *fp) {
    printf("Enter your monthly emergency fund: ");
    scanf("%f", &fp->emergency_fund);
}

void get_retirement_savings(struct finance_planner *fp) {
    printf("Enter your monthly retirement savings: ");
    scanf("%f", &fp->retirement_savings);
}

void print_finance_planner(struct finance_planner *fp) {
    printf("Income: %.2f\n", fp->income);
    printf("Expenses:\n");
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d: %.2f\n", i + 1, fp->expenses[i]);
    }
    printf("Savings: %.2f\n", fp->savings);
    printf("Debt: %.2f\n", fp->debt);
    printf("Emergency Fund: %.2f\n", fp->emergency_fund);
    printf("Retirement Savings: %.2f\n", fp->retirement_savings);
}

int main() {
    struct finance_planner fp;
    get_income(&fp);
    get_expenses(&fp);
    get_savings(&fp);
    get_debt(&fp);
    get_emergency_fund(&fp);
    get_retirement_savings(&fp);
    print_finance_planner(&fp);
    return 0;
}