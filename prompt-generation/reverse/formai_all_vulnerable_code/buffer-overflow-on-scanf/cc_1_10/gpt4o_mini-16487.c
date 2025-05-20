//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LENGTH 50

typedef struct {
    char description[DESCRIPTION_LENGTH];
    float amount;
} Expense;

void addExpense(Expense expenses[], int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Expense list is full!\n");
        return;
    }

    printf("Enter description of the expense: ");
    scanf(" %[^\n]", expenses[*count].description); // reads string with spaces
    printf("Enter amount of the expense: ");
    scanf("%f", &expenses[*count].amount);

    (*count)++;
    printf("Expense added successfully!\n");
}

void viewExpenses(const Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses logged yet!\n");
        return;
    }

    printf("\nYour Expenses List:\n");
    printf("--------------------------------------------------\n");
    printf("%-20s %-10s\n", "Description", "Amount");
    printf("--------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-20s $%-9.2f\n", expenses[i].description, expenses[i].amount);
    }
    
    printf("--------------------------------------------------\n");
}

float calculateTotal(const Expense expenses[], int count) {
    float total = 0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    return total;
}

void deleteExpense(Expense expenses[], int *count) {
    if (*count == 0) {
        printf("No expenses to delete!\n");
        return;
    }

    int index;
    printf("Enter the index of the expense to delete (0 to %d): ", *count - 1);
    scanf("%d", &index);

    if (index < 0 || index >= *count) {
        printf("Invalid index! No expense deleted.\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        expenses[i] = expenses[i + 1];   // Shift expenses left
    }

    (*count)--;
    printf("Expense deleted successfully!\n");
}

void clearAllExpenses(Expense expenses[], int *count) {
    *count = 0;
    printf("All expenses cleared successfully!\n");
}

void showMenu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Total Expenses\n");
    printf("4. Delete an Expense\n");
    printf("5. Clear All Expenses\n");
    printf("6. Exit\n");
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;

    while (1) {
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
                printf("Total Expenses: $%.2f\n", calculateTotal(expenses, count));
                break;
            case 4:
                deleteExpense(expenses, &count);
                break;
            case 5:
                clearAllExpenses(expenses, &count);
                break;
            case 6:
                printf("Exiting the program. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
    
    return 0;
}