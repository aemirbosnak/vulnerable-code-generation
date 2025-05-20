//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LENGTH 50

typedef struct {
    float amount;
    char description[DESCRIPTION_LENGTH];
} Expense;

Expense* expenses[MAX_EXPENSES];
int expense_count = 0;

void add_expense(float amount, const char* description) {
    if (expense_count >= MAX_EXPENSES) {
        printf("Error: Maximum expense limit reached.\n");
        return;
    }
    Expense* new_expense = (Expense*)malloc(sizeof(Expense));
    if (new_expense == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }
    new_expense->amount = amount;
    strncpy(new_expense->description, description, DESCRIPTION_LENGTH - 1);
    new_expense->description[DESCRIPTION_LENGTH - 1] = '\0'; // Ensure null-termination
    expenses[expense_count++] = new_expense;
    printf("Expense added: %s - $%.2f\n", new_expense->description, new_expense->amount);
}

void view_expenses() {
    if (expense_count == 0) {
        printf("No expenses to display.\n");
        return;
    }
    printf("Expenses:\n");
    for (int i = 0; i < expense_count; i++) {
        printf("%d: %s - $%.2f\n", i + 1, expenses[i]->description, expenses[i]->amount);
    }
}

void delete_expense(int index) {
    if (index < 1 || index > expense_count) {
        printf("Error: Invalid index.\n");
        return;
    }
    index--; // Convert to zero-based index
    free(expenses[index]);
    for (int i = index; i < expense_count - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    expense_count--;
    expenses[expense_count] = NULL; // Nullify the last pointer
    printf("Expense deleted.\n");
}

void free_expenses() {
    for (int i = 0; i < expense_count; i++) {
        free(expenses[i]);
    }
    expense_count = 0;
}

void show_menu() {
    printf("\nExpense Tracker Menu:\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    float amount;
    char description[DESCRIPTION_LENGTH];

    while (1) {
        show_menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Flush invalid input
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter expense amount: $");
                if (scanf("%f", &amount) != 1 || amount < 0) {
                    fprintf(stderr, "Invalid amount.\n");
                    while (getchar() != '\n'); // Flush invalid input
                    continue;
                }
                printf("Enter expense description: ");
                getchar(); // Consume newline
                fgets(description, DESCRIPTION_LENGTH, stdin);
                description[strcspn(description, "\n")] = 0; // Remove newline
                add_expense(amount, description);
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                printf("Enter index of expense to delete: ");
                int index;
                if (scanf("%d", &index) != 1) {
                    fprintf(stderr, "Invalid input.\n");
                    while (getchar() != '\n'); // Flush invalid input
                    continue;
                }
                delete_expense(index);
                break;
            case 4:
                free_expenses();
                printf("Exiting. All expenses cleared.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
                break;
        }
    }
    return 0;
}