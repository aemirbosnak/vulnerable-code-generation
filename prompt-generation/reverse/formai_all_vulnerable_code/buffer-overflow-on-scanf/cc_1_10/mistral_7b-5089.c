//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    char date[11];
} Expense;

void print_menu() {
    printf("\n--- Sweetheart Expense Tracker ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Total Expenses\n");
    printf("5. Exit\n");
}

void add_expense(Expense expenses[MAX_EXPENSES], int *num_expenses) {
    Expense new_expense;

    if (*num_expenses >= MAX_EXPENSES) {
        printf("Dear, we have reached the maximum number of expenses.\n");
        return;
    }

    printf("Enter expense name: ");
    scanf("%s", new_expense.name);

    printf("Enter expense amount: ");
    scanf("%f", &new_expense.amount);

    printf("Enter expense date (MM/DD/YYYY): ");
    scanf("%s", new_expense.date);

    expenses[*num_expenses] = new_expense;
    (*num_expenses)++;
}

void view_expenses(Expense expenses[MAX_EXPENSES], int num_expenses) {
    int i;

    printf("\nExpenses:\n");
    printf("-------------------------------------\n");

    for (i = 0; i < num_expenses; i++) {
        printf("| %-45s | %10.2f | %-11s |\n", expenses[i].name, expenses[i].amount, expenses[i].date);
    }

    printf("-------------------------------------\n");
}

void delete_expense(Expense expenses[MAX_EXPENSES], int *num_expenses, int index) {
    int i;

    if (index < 0 || index >= *num_expenses) {
        printf("Dear, that expense index is out of bounds.\n");
        return;
    }

    for (i = index; i < *num_expenses - 1; i++) {
        expenses[i] = expenses[i + 1];
    }

    (*num_expenses)--;
}

float total_expenses(Expense expenses[MAX_EXPENSES], int num_expenses) {
    int i;
    float total = 0;

    for (i = 0; i < num_expenses; i++) {
        total += expenses[i].amount;
    }

    return total;
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int num_expenses = 0;
    int choice;
    int index;
    float total;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense(expenses, &num_expenses);
                break;
            case 2:
                view_expenses(expenses, num_expenses);
                break;
            case 3:
                printf("Enter expense index to delete: ");
                scanf("%d", &index);
                delete_expense(expenses, &num_expenses, index);
                break;
            case 4:
                total = total_expenses(expenses, num_expenses);
                printf("Total expenses: %.2f\n", total);
                break;
            case 5:
                printf("Goodbye, my love.\n");
                exit(0);
            default:
                printf("Invalid choice, sweetheart.\n");
        }
    }

    return 0;
}