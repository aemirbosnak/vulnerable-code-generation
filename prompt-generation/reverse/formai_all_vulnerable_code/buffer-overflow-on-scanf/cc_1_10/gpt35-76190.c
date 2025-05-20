//FormAI DATASET v1.0 Category: Expense Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expenses {
    char name[50];
    float amount;
    char category[20];
};

int main()
{
    struct Expenses expenses[50];
    int expense_count = 0;
    float total_expenses = 0;

    while (1) {
        printf("Enter expense name (or 'q' to quit): ");
        scanf("%s", expenses[expense_count].name);

        if (strcmp(expenses[expense_count].name, "q") == 0) {
            break;
        }

        printf("Enter expense amount: ");
        scanf("%f", &expenses[expense_count].amount);
        total_expenses += expenses[expense_count].amount;

        printf("Enter expense category: ");
        scanf("%s", expenses[expense_count].category);

        expense_count++;
    }

    printf("\nExpenses by category:\n");

    float total_food = 0, total_entertainment = 0, total_transportation = 0, total_other = 0;

    for (int i = 0; i < expense_count; i++) {
        if (strcmp(expenses[i].category, "food") == 0) {
            total_food += expenses[i].amount;
        } else if (strcmp(expenses[i].category, "entertainment") == 0) {
            total_entertainment += expenses[i].amount;
        } else if (strcmp(expenses[i].category, "transportation") == 0) {
            total_transportation += expenses[i].amount;
        } else {
            total_other += expenses[i].amount;
        }
    }

    printf("Food: %.2f\n", total_food);
    printf("Entertainment: %.2f\n", total_entertainment);
    printf("Transportation: %.2f\n", total_transportation);
    printf("Other: %.2f\n", total_other);

    printf("\nTotal expenses: %.2f\n", total_expenses);

    return 0;
}