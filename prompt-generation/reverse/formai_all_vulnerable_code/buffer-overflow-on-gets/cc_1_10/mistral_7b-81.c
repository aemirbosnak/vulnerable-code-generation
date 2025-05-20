//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 5

typedef struct Expense {
    char name[50];
    float amount;
} Expense;

int main() {
    Expense expenses[MAX_EXPENSES];
    float total_income = 0.0, total_expenses = 0.0, balance = 0.0;
    int num_expenses = 0;

    printf("\n---------------------------------------\n");
    printf("| Welcome to your Personal Finance Planner |\n");
    printf("---------------------------------------|\n");

    printf("\nEnter your monthly income: $");
    scanf("%f", &total_income);

    printf("\nEnter your expenses (type 'done' when finished):\n");

    while (num_expenses < MAX_EXPENSES && strcmp(gets(expenses[num_expenses].name), "done") != 0) {
        printf("\nName: ");
        scanf("%s", expenses[num_expenses].name);
        printf("Amount: $");
        scanf("%f", &expenses[num_expenses].amount);

        total_expenses += expenses[num_expenses].amount;
        num_expenses++;
    }

    balance = total_income - total_expenses;

    printf("\n---------------------------------------\n");
    printf("| Your monthly income: $%.2f            |\n", total_income);
    printf("---------------------------------------|\n");

    printf("| Your monthly expenses:\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("| %-30s: $%.2f\n", expenses[i].name, expenses[i].amount);
        total_expenses += expenses[i].amount;
    }

    printf("---------------------------------------|\n");
    printf("| Your monthly balance: $%.2f            |\n", balance);
    printf("---------------------------------------|\n");

    return 0;
}