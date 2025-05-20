//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 50
#define MONTHS_IN_YEAR 12

typedef struct {
    char name[50];
    float amount;
} Expense;

void print_menu() {
    printf("\n1. Add expense\n");
    printf("2. List expenses\n");
    printf("3. Monthly budget\n");
    printf("4. Total expenses\n");
    printf("5. Exit\n");
}

void add_expense(Expense expenses[], float *total, int *num_expenses) {
    char name[50];
    float amount;

    printf("Enter expense name: ");
    scanf("%s", name);

    printf("Enter expense amount: ");
    scanf("%f", &amount);

    if (*num_expenses < MAX_EXPENSES) {
        expenses[*num_expenses].amount = amount;
        strcpy(expenses[*num_expenses].name, name);
        (*num_expenses)++;

        *total += amount;
    } else {
        printf("Maximum number of expenses reached.\n");
    }
}

void list_expenses(Expense expenses[], int num_expenses) {
    int i;

    printf("\nList of expenses:\n");
    for (i = 0; i < num_expenses; i++) {
        printf("%s: %.2f\n", expenses[i].name, expenses[i].amount);
    }
}

void monthly_budget(Expense expenses[], float total, int num_expenses) {
    float monthly_budget = total / MONTHS_IN_YEAR;

    printf("\nMonthly budget: %.2f", monthly_budget);
}

int main() {
    Expense expenses[MAX_EXPENSES];
    float total = 0;
    int num_expenses = 0;

    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense(expenses, &total, &num_expenses);
                break;
            case 2:
                list_expenses(expenses, num_expenses);
                break;
            case 3:
                monthly_budget(expenses, total, num_expenses);
                break;
            case 4:
                printf("\nTotal expenses: %.2f\n", total);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}