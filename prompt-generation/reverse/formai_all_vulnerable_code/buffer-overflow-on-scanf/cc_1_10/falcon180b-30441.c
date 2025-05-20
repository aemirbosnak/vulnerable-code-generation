//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
} Expense;

void add_expense(Expense *expenses, int count, char *name, float amount) {
    if (count >= MAX_EXPENSES) {
        printf("Error: Maximum expenses reached.\n");
        return;
    }
    strcpy(expenses[count].name, name);
    expenses[count].amount = amount;
    count++;
}

float calculate_total_expenses(Expense *expenses, int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    return total;
}

void print_expenses(Expense *expenses, int count) {
    printf("Expenses:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: $%.2f\n", expenses[i].name, expenses[i].amount);
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    char input[100];

    while (1) {
        printf("Enter expense name: ");
        scanf("%s", input);
        if (strcmp(input, "done") == 0) {
            break;
        }
        printf("Enter expense amount: ");
        scanf("%f", &expenses[count].amount);
        add_expense(expenses, count, input, expenses[count].amount);
        count++;
    }

    float total_expenses = calculate_total_expenses(expenses, count);
    printf("\nTotal expenses: $%.2f\n", total_expenses);
    print_expenses(expenses, count);

    return 0;
}