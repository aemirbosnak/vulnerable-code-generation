//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define TITLE_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int expense_count = 0;

void add_expense() {
    if (expense_count < MAX_EXPENSES) {
        printf("Enter expense title: ");
        fgets(expenses[expense_count].title, TITLE_LENGTH, stdin);
        expenses[expense_count].title[strcspn(expenses[expense_count].title, "\n")] = '\0'; // Strip newline
        printf("Enter expense amount: ");
        scanf("%f", &expenses[expense_count].amount);
        getchar();  // Clear newline from buffer
        expense_count++;
        printf("Expense added successfully!\n");
    } else {
        printf("Expense limit reached! Can't add more expenses.\n");
    }
}

void view_expenses() {
    if (expense_count == 0) {
        printf("No expenses recorded yet!\n");
        return;
    }
    printf("\nYour expenses:\n");
    for (int i = 0; i < expense_count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, expenses[i].title, expenses[i].amount);
    }
}

void delete_expense() {
    int index;
    view_expenses();
    printf("Enter the number of the expense to delete: ");
    scanf("%d", &index);
    getchar();  // Clear newline from buffer
    if (index > 0 && index <= expense_count) {
        for (int i = index - 1; i < expense_count - 1; i++) {
            expenses[i] = expenses[i + 1]; // Shift expenses left
        }
        expense_count--;
        printf("Expense deleted successfully!\n");
    } else {
        printf("Invalid expense number!\n");
    }
}

void menu() {
    int choice;
    do {
        printf("\n--- Expense Tracker ---\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Delete Expense\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();  // Clear newline from buffer
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
                printf("Thank you for using the Expense Tracker! Come back soon.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}