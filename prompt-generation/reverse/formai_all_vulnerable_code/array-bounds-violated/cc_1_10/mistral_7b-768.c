//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100

typedef struct {
    char description[50];
    float amount;
    int date;
} Expense;

Expense expenses[MAX_EXPENSES];
int current_expense = 0;

void print_menu() {
    printf("\nExpense Tracker Menu:\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Quit\n");
}

void add_expense() {
    if (current_expense >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }

    printf("Enter expense description: ");
    fgets(expenses[current_expense].description, sizeof(expenses[current_expense].description), stdin);
    expenses[current_expense].description[strlen(expenses[current_expense].description) - 1] = '\0'; // remove newline character

    printf("Enter expense amount: ");
    scanf("%f", &expenses[current_expense].amount);

    printf("Enter expense date (YYYYMMDD): ");
    scanf("%d", &expenses[current_expense].date);

    current_expense++;
}

void view_expenses() {
    if (current_expense == 0) {
        printf("No expenses found.\n");
        return;
    }

    printf("\nExpenses:\n");
    for (int i = 0; i < current_expense; i++) {
        printf("Description: %s\n", expenses[i].description);
        printf("Amount: %.2f\n", expenses[i].amount);
        printf("Date: %d\n", expenses[i].date);
        printf("------------------\n");
    }
}

void delete_expense() {
    if (current_expense == 0) {
        printf("Error: No expenses found.\n");
        return;
    }

    int index;
    printf("Enter expense index to delete: ");
    scanf("%d", &index);

    if (index >= 0 && index < current_expense) {
        current_expense--;
        memmove(&expenses[index], &expenses[index + 1], (current_expense - index) * sizeof(Expense));
    } else {
        printf("Error: Invalid expense index.\n");
    }
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
                view_expenses();
                break;
            case 3:
                delete_expense();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}