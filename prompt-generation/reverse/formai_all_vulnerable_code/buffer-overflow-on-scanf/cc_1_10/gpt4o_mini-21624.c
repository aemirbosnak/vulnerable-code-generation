//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
    char category[MAX_NAME_LENGTH];
} Expense;

void addExpense(Expense expenses[], int *count);
void viewExpenses(const Expense expenses[], int count);
void editExpense(Expense expenses[], int count);
void deleteExpense(Expense expenses[], int *count);
void viewTotal(Expense expenses[], int count);
void displayMenu();

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
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
                editExpense(expenses, count);
                break;
            case 4:
                deleteExpense(expenses, &count);
                break;
            case 5:
                viewTotal(expenses, count);
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n=== Expense Tracker ===\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Edit Expense\n");
    printf("4. Delete Expense\n");
    printf("5. View Total Expenses\n");
    printf("6. Exit\n");
}

void addExpense(Expense expenses[], int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Expense limit reached. Please delete an expense before adding a new one.\n");
        return;
    }
    printf("Enter expense name: ");
    scanf("%s", expenses[*count].name);
    printf("Enter amount: ");
    scanf("%f", &expenses[*count].amount);
    printf("Enter category: ");
    scanf("%s", expenses[*count].category);
    (*count)++;
    printf("Expense added successfully!\n");
}

void viewExpenses(const Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    printf("\n=== List of Expenses ===\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - $%.2f (%s)\n", i + 1, expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void editExpense(Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses to edit.\n");
        return;
    }
    int index;
    printf("Enter the expense number to edit (1-%d): ", count);
    scanf("%d", &index);
    index--; // adjust for 0-based index

    if (index < 0 || index >= count) {
        printf("Invalid expense number.\n");
        return;
    }

    printf("Editing expense: %s - $%.2f (%s)\n", expenses[index].name, expenses[index].amount, expenses[index].category);
    printf("Enter new name (current: %s): ", expenses[index].name);
    scanf("%s", expenses[index].name);
    printf("Enter new amount (current: $%.2f): ", expenses[index].amount);
    scanf("%f", &expenses[index].amount);
    printf("Enter new category (current: %s): ", expenses[index].category);
    scanf("%s", expenses[index].category);
    
    printf("Expense updated successfully!\n");
}

void deleteExpense(Expense expenses[], int *count) {
    if (*count == 0) {
        printf("No expenses to delete.\n");
        return;
    }
    int index;
    printf("Enter the expense number to delete (1-%d): ", *count);
    scanf("%d", &index);
    index--; // adjust for 0-based index

    if (index < 0 || index >= *count) {
        printf("Invalid expense number.\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    (*count)--;
    printf("Expense deleted successfully!\n");
}

void viewTotal(Expense expenses[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    printf("Total expenses: $%.2f\n", total);
}