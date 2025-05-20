//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INCOMES 100
#define MAX_EXPENSES 100
#define MAX_SAVINGS 100

typedef struct {
    float income;
    float expense;
    float savings;
} Finance;

void calculate_finance(Finance* finance) {
    float total_income = 0;
    float total_expense = 0;
    float total_savings = 0;

    for (int i = 0; i < MAX_INCOMES; i++) {
        total_income += finance[i].income;
    }

    for (int i = 0; i < MAX_EXPENSES; i++) {
        total_expense += finance[i].expense;
    }

    for (int i = 0; i < MAX_SAVINGS; i++) {
        total_savings += finance[i].savings;
    }

    finance->income = total_income;
    finance->expense = total_expense;
    finance->savings = total_savings;
}

int main() {
    Finance finance[MAX_INCOMES];
    int n;

    printf("Enter the number of incomes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter income %d: ", i + 1);
        scanf("%f", &finance[i].income);
    }

    printf("Enter the number of expenses: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter expense %d: ", i + 1);
        scanf("%f", &finance[i].expense);
    }

    printf("Enter the number of savings: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter savings %d: ", i + 1);
        scanf("%f", &finance[i].savings);
    }

    calculate_finance(finance);

    printf("Total income: %f\n", finance->income);
    printf("Total expense: %f\n", finance->expense);
    printf("Total savings: %f\n", finance->savings);

    return 0;
}