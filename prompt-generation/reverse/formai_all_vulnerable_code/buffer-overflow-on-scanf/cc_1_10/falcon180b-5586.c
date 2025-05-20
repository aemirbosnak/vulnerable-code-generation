//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_INCOME_SOURCES 10

// Structure for an expense
typedef struct {
    char name[50];
    float amount;
    int month;
} expense;

// Structure for an income source
typedef struct {
    char name[50];
    float amount;
    int month;
} income;

int main() {
    int num_expenses, num_income_sources, i, j;
    expense expenses[MAX_EXPENSES];
    income incomes[MAX_INCOME_SOURCES];

    // Get the number of expenses and income sources from the user
    printf("Enter the number of expenses: ");
    scanf("%d", &num_expenses);
    printf("Enter the number of income sources: ");
    scanf("%d", &num_income_sources);

    // Get the details of each expense from the user
    for(i=0; i<num_expenses; i++) {
        printf("Enter the details of expense %d:\n", i+1);
        printf("Name: ");
        scanf("%s", expenses[i].name);
        printf("Amount: ");
        scanf("%f", &expenses[i].amount);
        printf("Month: ");
        scanf("%d", &expenses[i].month);
    }

    // Get the details of each income source from the user
    for(i=0; i<num_income_sources; i++) {
        printf("Enter the details of income source %d:\n", i+1);
        printf("Name: ");
        scanf("%s", incomes[i].name);
        printf("Amount: ");
        scanf("%f", &incomes[i].amount);
        printf("Month: ");
        scanf("%d", &incomes[i].month);
    }

    // Calculate the total income and expenses for each month
    for(i=0; i<12; i++) {
        float total_income = 0.0, total_expenses = 0.0;
        for(j=0; j<num_income_sources; j++) {
            if(incomes[j].month == i+1) {
                total_income += incomes[j].amount;
            }
        }
        for(j=0; j<num_expenses; j++) {
            if(expenses[j].month == i+1) {
                total_expenses += expenses[j].amount;
            }
        }
        printf("For month %d, total income is %.2f and total expenses are %.2f\n", i+1, total_income, total_expenses);
    }

    return 0;
}