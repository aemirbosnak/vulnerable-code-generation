//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESCRIPTION 100

typedef struct {
    float amount;
    char description[MAX_DESCRIPTION];
} Expense;

Expense expenses[MAX_EXPENSES];
int expense_count = 0;

void add_expense() {
    if (expense_count >= MAX_EXPENSES) {
        printf("Expense limit reached. Cannot add more expenses.\n");
        return;
    }
    
    float amount;
    char description[MAX_DESCRIPTION];

    printf("Enter expense amount: ");
    scanf("%f", &amount);
    getchar(); // To consume the newline character left by scanf
    
    printf("Enter expense description: ");
    fgets(description, MAX_DESCRIPTION, stdin);
    description[strcspn(description, "\n")] = 0; // Remove newline character

    expenses[expense_count].amount = amount;
    strcpy(expenses[expense_count].description, description);
    expense_count++;

    printf("Expense added successfully!\n");
}

void view_expenses() {
    if (expense_count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\n--- Expenses List ---\n");
    for (int i = 0; i < expense_count; i++) {
        printf("%d. %s: $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
    }
    printf("----------------------\n");
}

void delete_expense() {
    if (expense_count == 0) {
        printf("No expenses to delete.\n");
        return;
    }

    int index;
    printf("Enter the expense number to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > expense_count) {
        printf("Invalid expense number.\n");
        return;
    }

    for (int i = index - 1; i < expense_count - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    expense_count--;

    printf("Expense deleted successfully!\n");
}

void display_menu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Exit\n");
    printf("----------------------------\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    do {
        display_menu();
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
                printf("Exiting the Expense Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}