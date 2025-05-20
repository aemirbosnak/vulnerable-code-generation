//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LENGTH 50

typedef struct {
    char description[DESCRIPTION_LENGTH];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int expense_count = 0;

void add_expense();
void view_expenses();
void delete_expense();
void show_menu();

int main() {
    int choice;

    while (1) {
        show_menu();
        printf("Enter your choice (1-4): ");
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
                printf("Exiting Expense Tracker. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again!\n");
                break;
        }
    }
    return 0;
}

void show_menu() {
    printf("\n====== Expense Tracker ======\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Exit\n");
    printf("=============================\n");
}

void add_expense() {
    if (expense_count >= MAX_EXPENSES) {
        printf("Expense list is full! Cannot add more expenses.\n");
        return;
    }
    
    Expense new_expense;
    printf("Enter the description of the expense: ");
    getchar(); // to consume the newline from previous input
    fgets(new_expense.description, DESCRIPTION_LENGTH, stdin);
    new_expense.description[strcspn(new_expense.description, "\n")] = 0;  // Remove newline

    printf("Enter the amount: ");
    scanf("%f", &new_expense.amount);

    expenses[expense_count++] = new_expense;
    printf("Expense added successfully! 🎉\n");
}

void view_expenses() {
    if (expense_count == 0) {
        printf("No expenses recorded yet! 🎈\n");
        return;
    }

    printf("\n=== List of Expenses ===\n");
    for (int i = 0; i < expense_count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
    }
    printf("========================\n");
}

void delete_expense() {
    if (expense_count == 0) {
        printf("No expenses to delete! 📅\n");
        return;
    }

    view_expenses();
    int index;
    printf("Enter the index of the expense to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > expense_count) {
        printf("Invalid index! Please try again! 😢\n");
        return;
    }

    // Shift expenses down to fill the gap
    for (int i = index - 1; i < expense_count - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    expense_count--;
    printf("Expense deleted successfully! 🚀\n");
}