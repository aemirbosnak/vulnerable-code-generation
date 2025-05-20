//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

double add_expense(double cost);
double add_income(double amount);

int main() {
    double expenses = 0;
    double income = 0;
    double net_worth = 0;

    while (1) {
        printf("Enter an expense (or -1 to finish): ");
        int choice;
        scanf("%d", &choice);

        if (choice == -1)
            break;

        double cost;
        scanf("%lf", &cost);

        expenses += add_expense(cost);
    }

    while (1) {
        printf("Enter an income (or -1 to finish): ");
        int choice;
        scanf("%d", &choice);

        if (choice == -1)
            break;

        double amount;
        scanf("%lf", &amount);

        income += add_income(amount);
    }

    net_worth = income - expenses;

    printf("Net Worth: %.2lf\n", net_worth);
    printf("Total Expenses: %.2lf\n", expenses);
    printf("Total Income: %.2lf\n", income);

    return 0;
}

double add_expense(double cost) {
    return cost;
}

double add_income(double amount) {
    return amount;
}