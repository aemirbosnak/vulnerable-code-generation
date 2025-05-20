//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    double amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense(const char *name, double amount) {
    if (num_expenses >= MAX_EXPENSES) {
        fprintf(stderr, "Error: Maximum number of expenses reached.\n");
        return;
    }
    strncpy(expenses[num_expenses].name, name, MAX_NAME_LEN);
    expenses[num_expenses++].amount = amount;
}

void print_expenses() {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: %.2f\n", expenses[i].name, expenses[i].amount);
    }
}

int main() {
    double total_spent = 0;
    char input_name[MAX_NAME_LEN];
    double input_amount;

    while (1) {
        printf("Enter expense name (empty line to quit): ");
        fgets(input_name, sizeof(input_name), stdin);
        input_name[strcspn(input_name, "\n")] = '\0';

        if (strcmp(input_name, "") == 0) {
            break;
        }

        printf("Enter expense amount: ");
        scanf("%lf", &input_amount);

        add_expense(input_name, input_amount);
        total_spent += input_amount;
    }

    printf("Total spent: %.2f\n", total_spent);
    print_expenses();

    return 0;
}