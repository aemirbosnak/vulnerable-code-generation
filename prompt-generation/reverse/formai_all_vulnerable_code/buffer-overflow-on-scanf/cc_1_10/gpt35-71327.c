//FormAI DATASET v1.0 Category: Expense Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESCRIPTION 50

typedef struct {
    char description[MAX_DESCRIPTION];
    float amount;
} Expense;

void print_report(Expense expenses[], int size, float total_spent) {
    printf("---------- EXPENSE TRACKER REPORT ----------\n");
    printf("Description\t\tAmount\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%-20s\t$%.2f\n", expenses[i].description, expenses[i].amount);
    }
    printf("--------------------------------------------\n");
    printf("Total spent:\t\t$%.2f\n", total_spent);
    printf("--------------------------------------------\n");
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int num_expenses = 0;
    float total_spent = 0.0;

    while (1) {
        char input[100];
        printf("Enter expense description (or 'q' to quit): ");
        scanf("%s", input);

        if (strcmp(input, "q") == 0 || num_expenses >= MAX_EXPENSES) {
            // User entered 'q' or reached max expenses
            break;
        }

        Expense expense;
        strncpy(expense.description, input, MAX_DESCRIPTION);

        printf("Enter expense amount: ");
        scanf("%f", &expense.amount);

        expenses[num_expenses] = expense;
        num_expenses++;
        total_spent += expense.amount;
    }

    print_report(expenses, num_expenses, total_spent);

    return 0;
}