//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    char date[10];
} Expense;

void add_expense(Expense* expenses, int num_expenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense amount: $");
    scanf("%f", &expenses[num_expenses].amount);
    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%s", expenses[num_expenses].date);
    num_expenses++;
}

void display_expenses(Expense* expenses, int num_expenses) {
    printf("\nExpenses:\n");
    printf("--------------------------------------------------\n");
    printf("Name       | Amount    | Date\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%-20s $%-8.2f %s\n", expenses[i].name, expenses[i].amount, expenses[i].date);
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    while (num_expenses < MAX_EXPENSES) {
        printf("\nEnter 1 to add an expense, 2 to display expenses, or 0 to exit:\n");
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
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}