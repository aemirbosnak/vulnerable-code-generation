//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
} Expense;

void add_expense(Expense expenses[], int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Expense limit reached. Cannot add more expenses.\n");
        return;
    }

    Expense new_expense;
    printf("Enter expense name: ");
    scanf("%s", new_expense.name);
    printf("Enter expense amount: ");
    scanf("%f", &new_expense.amount);
    
    expenses[*count] = new_expense;
    (*count)++;
    printf("Expense added successfully!\n");
}

void display_expenses(Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\nRecorded Expenses:\n");
    for (int i = 0; i < count; i++) {
        printf("%d) %s: $%.2f\n", i + 1, expenses[i].name, expenses[i].amount);
    }
}

float calculate_total(Expense expenses[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    return total;
}

void remove_expense(Expense expenses[], int *count, int index) {
    if (index < 0 || index >= *count) {
        printf("Invalid expense index.\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    (*count)--;
    printf("Expense removed successfully!\n");
}

void show_menu() {
    printf("\nExpense Tracker Menu:\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total\n");
    printf("4. Remove Expense\n");
    printf("5. Exit\n");
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int expense_count = 0;
    int choice;
    
    while (1) {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense(expenses, &expense_count);
                break;
            case 2:
                display_expenses(expenses, expense_count);
                break;
            case 3:
                printf("Total Expenses: $%.2f\n", calculate_total(expenses, expense_count));
                break;
            case 4: {
                int index;
                display_expenses(expenses, expense_count);
                printf("Enter the index of the expense to remove: ");
                scanf("%d", &index);
                remove_expense(expenses, &expense_count, index - 1);
                break;
            }
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}