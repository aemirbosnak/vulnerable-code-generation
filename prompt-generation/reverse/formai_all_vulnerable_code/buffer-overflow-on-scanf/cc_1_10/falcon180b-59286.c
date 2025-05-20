//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100

struct expense {
    char name[50];
    double amount;
    int date;
};

void add_expense(struct expense* expenses, int num_expenses) {
    printf("Enter expense name: ");
    scanf("%s", &expenses[num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%lf", &expenses[num_expenses].amount);
    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%d", &expenses[num_expenses].date);
    num_expenses++;
}

void display_expenses(struct expense* expenses, int num_expenses) {
    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - %.2lf - %d\n", expenses[i].name, expenses[i].amount, expenses[i].date);
    }
}

int main() {
    struct expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    printf("Welcome to the expense tracker!\n");

    while (num_expenses < MAX_EXPENSES) {
        printf("\nEnter 1 to add an expense, 2 to display expenses, or 0 to quit: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense(expenses, num_expenses);
                break;
            case 2:
                display_expenses(expenses, num_expenses);
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}