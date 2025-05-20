//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LENGTH 50

typedef struct {
    char description[DESCRIPTION_LENGTH];
    float amount;
} Expense;

void addExpense(Expense expenses[], int *count);
void viewExpenses(Expense expenses[], int count);
void deleteExpense(Expense expenses[], int *count);
float calculateTotal(Expense expenses[], int count);
void displayMenu();
void clearInputBuffer();

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

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
                printf("Total Expenses: $%.2f\n", calculateTotal(expenses, count));
                break;
            case 5:
                printf("Exiting the Expense Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\n=== Expense Tracker ===\n");
    printf("1. Add Expense\n");
    printf("2. View All Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Calculate Total Expenses\n");
    printf("5. Exit\n");
}

void addExpense(Expense expenses[], int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Expense list is full! Cannot add more expenses.\n");
        return;
    }
    printf("Enter description of the expense: ");
    fgets(expenses[*count].description, DESCRIPTION_LENGTH, stdin);
    expenses[*count].description[strcspn(expenses[*count].description, "\n")] = 0; // Remove newline character

    printf("Enter amount: $");
    scanf("%f", &expenses[*count].amount);
    clearInputBuffer();

    (*count)++;
    printf("Expense added!\n");
}

void viewExpenses(Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }
    printf("\n=== List of Expenses ===\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
    }
}

void deleteExpense(Expense expenses[], int *count) {
    if (*count == 0) {
        printf("No expenses to delete.\n");
        return;
    }
    
    viewExpenses(expenses, *count);
    int index;
    printf("Enter the expense number to delete: ");
    scanf("%d", &index);
    clearInputBuffer();

    if (index < 1 || index > *count) {
        printf("Invalid expense number.\n");
        return;
    }

    for (int i = index - 1; i < *count - 1; i++) {
        expenses[i] = expenses[i + 1]; // Shift expenses to fill the gap
    }
    (*count)--;

    printf("Expense deleted successfully!\n");
}

float calculateTotal(Expense expenses[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    return total;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Clear the buffer
}