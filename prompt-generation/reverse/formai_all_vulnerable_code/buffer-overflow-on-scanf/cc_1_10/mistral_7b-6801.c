//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define EXPENSE_NAME_LENGTH 50
#define EXPENSE_AMOUNT_PRECISION 2

typedef struct {
    char name[EXPENSE_NAME_LENGTH];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int current_expense_index = 0;

void print_menu() {
    printf("****************************************\n");
    printf("* Welcome to Gratitude Expense Tracker! *\n");
    printf("****************************************\n");
    printf("* 1. Add Expense                       *\n");
    printf("* 2. List Expenses                     *\n");
    printf("* 3. Total Expenses                    *\n");
    printf("* 4. Average Expense                   *\n");
    printf("* 5. Quit                             *\n");
    printf("****************************************\n");
}

void add_expense() {
    if (current_expense_index >= MAX_EXPENSES) {
        printf("Expense Tracker is full.\n");
        return;
    }

    printf("Enter expense name: ");
    scanf("%s", expenses[current_expense_index].name);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[current_expense_index].amount);

    current_expense_index++;

    printf("Expense added successfully.\n");
}

void list_expenses() {
    if (current_expense_index == 0) {
        printf("No expenses found.\n");
        return;
    }

    printf("Expenses:\n");
    for (int i = 0; i < current_expense_index; i++) {
        printf("%d. %s: %.2f\n", i + 1, expenses[i].name, expenses[i].amount);
    }
}

void total_expenses() {
    float total = 0;

    for (int i = 0; i < current_expense_index; i++) {
        total += expenses[i].amount;
    }

    printf("Total expenses: %.2f\n", total);
}

void average_expense() {
    if (current_expense_index == 0) {
        printf("No expenses found to calculate average.\n");
        return;
    }

    float total = 0;

    for (int i = 0; i < current_expense_index; i++) {
        total += expenses[i].amount;
    }

    float average = total / current_expense_index;

    printf("Average expense: %.2f\n", average);
}

int main() {
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                list_expenses();
                break;
            case 3:
                total_expenses();
                break;
            case 4:
                average_expense();
                break;
            case 5:
                printf("Thank you for using Gratitude Expense Tracker.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}