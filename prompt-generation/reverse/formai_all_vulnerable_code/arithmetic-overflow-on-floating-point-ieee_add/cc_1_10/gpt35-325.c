//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: accurate
#include <stdio.h>

typedef struct {
    float income;
    float housing;
    float transportation;
    float food;
    float health;
    float entertainment;
    float savings;
} Expense;

void getExpenses(Expense* expenses) {
    printf("Enter your monthly income: ");
    scanf("%f", &expenses->income);

    printf("Enter your monthly housing expenses: ");
    scanf("%f", &expenses->housing);

    printf("Enter your monthly transportation expenses: ");
    scanf("%f", &expenses->transportation);

    printf("Enter your monthly food expenses: ");
    scanf("%f", &expenses->food);

    printf("Enter your monthly health expenses: ");
    scanf("%f", &expenses->health);

    printf("Enter your monthly entertainment expenses: ");
    scanf("%f", &expenses->entertainment);

    printf("Enter your monthly savings target: ");
    scanf("%f", &expenses->savings);
}

float getTotalExpenses(Expense* expenses) {
    return expenses->housing + expenses->transportation + expenses->food + expenses->health + expenses->entertainment + expenses->savings;
}

void printReport(Expense* expenses) {
    printf("\n---------- Monthly Expenditure Report ----------\n\n");
    printf("Income: $%.2f\n", expenses->income);
    printf("Housing: $%.2f\n", expenses->housing);
    printf("Transportation: $%.2f\n", expenses->transportation);
    printf("Food: $%.2f\n", expenses->food);
    printf("Health: $%.2f\n", expenses->health);
    printf("Entertainment: $%.2f\n", expenses->entertainment);
    printf("Savings: $%.2f\n\n", expenses->savings);
    printf("Total Monthly Expenses: $%.2f", getTotalExpenses(expenses));
}

int main() {
    Expense expenses;
    getExpenses(&expenses);
    printReport(&expenses);

    return 0;
}