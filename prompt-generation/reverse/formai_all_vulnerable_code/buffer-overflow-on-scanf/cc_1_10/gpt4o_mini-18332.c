//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define CATEGORY_LENGTH 30
#define DESCRIPTION_LENGTH 50

typedef struct {
    char category[CATEGORY_LENGTH];
    char description[DESCRIPTION_LENGTH];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int expense_count = 0;

void add_expense() {
    if (expense_count >= MAX_EXPENSES) {
        printf("Expense limit reached.\n");
        return;
    }

    Expense new_expense;
    printf("Enter expense category: ");
    scanf("%s", new_expense.category);
    printf("Enter expense description: ");
    scanf("%s", new_expense.description);
    printf("Enter expense amount: ");
    scanf("%f", &new_expense.amount);

    expenses[expense_count++] = new_expense;
    printf("Expense added successfully!\n");
}

void view_expenses() {
    if (expense_count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\n--- Expense Report ---\n");
    for (int i = 0; i < expense_count; i++) {
        printf("Category: %s | Description: %s | Amount: %.2f\n",
               expenses[i].category, expenses[i].description, expenses[i].amount);
    }
    printf("------------------------\n");
}

void save_expenses() {
    FILE *file = fopen("expenses.txt", "w");
    if (!file) {
        printf("Could not open file for saving expenses.\n");
        return;
    }

    for (int i = 0; i < expense_count; i++) {
        fprintf(file, "%s %s %.2f\n", expenses[i].category, expenses[i].description, expenses[i].amount);
    }

    fclose(file);
    printf("Expenses saved to expenses.txt\n");
}

void load_expenses() {
    FILE *file = fopen("expenses.txt", "r");
    if (!file) {
        printf("Could not open file for loading expenses.\n");
        return;
    }

    while (fscanf(file, "%s %s %f", expenses[expense_count].category,
                  expenses[expense_count].description,
                  &expenses[expense_count].amount) != EOF) {
        expense_count++;
    }

    fclose(file);
    printf("Expenses loaded successfully!\n");
}

void display_menu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Save Expenses to File\n");
    printf("4. Load Expenses from File\n");
    printf("5. Exit\n");
    printf("---------------------------\n");
}

int main() {
    int choice;

    load_expenses();

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                save_expenses();
                break;
            case 4:
                load_expenses();
                break;
            case 5:
                printf("Exiting the Expense Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}