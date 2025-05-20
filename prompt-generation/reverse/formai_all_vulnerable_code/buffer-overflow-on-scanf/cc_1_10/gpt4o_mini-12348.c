//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESC_LENGTH 50

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
} Expense;

void showMenu();
void addExpense(Expense expenses[], int *count);
void viewExpenses(const Expense expenses[], int count);
void deleteExpense(Expense expenses[], int *count);
void shapeShift();

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;

    do {
        shapeShift();
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                viewExpenses(expenses, count);
                break;
            case 3:
                deleteExpense(expenses, &count);
                break;
            case 4:
                printf("Thank you for using the Expense Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void showMenu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Exit\n");
}

void addExpense(Expense expenses[], int *count) {
    if (*count < MAX_EXPENSES) {
        printf("Enter description of the expense: ");
        scanf(" %[^\n]", expenses[*count].description);
        printf("Enter amount: ");
        scanf("%f", &expenses[*count].amount);
        (*count)++;
        printf("Expense added successfully!\n");
    } else {
        printf("Maximum limit of expenses reached!\n");
    }
}

void viewExpenses(const Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    printf("\n--- List of Expenses ---\n");
    for (int i = 0; i < count; i++) {
        printf("Expense %d: %s - $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
    }
}

void deleteExpense(Expense expenses[], int *count) {
    if (*count == 0) {
        printf("No expenses to delete.\n");
        return;
    }
    int index;
    printf("Enter the expense number to delete (1 to %d): ", *count);
    scanf("%d", &index);
    if (index < 1 || index > *count) {
        printf("Invalid expense number!\n");
        return;
    }
    for (int i = index - 1; i < *count - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    (*count)--;
    printf("Expense deleted successfully!\n");
}

void shapeShift() {
    // This function creates a visual effect based on imaginary shapes
    // or a simple animated banner for user interaction.
    printf("\n===============================\n");
    printf("     Welcome to the Expense     \n");
    printf("          Tracker!              \n");
    printf("===============================\n");
    printf("▶ Creative shape-shifting icon ◀\n");
    printf("*******************************\n");
}