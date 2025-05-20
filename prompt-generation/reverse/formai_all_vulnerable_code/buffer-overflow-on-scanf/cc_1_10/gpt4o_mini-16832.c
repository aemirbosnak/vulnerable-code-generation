//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESCRIPTION 50

typedef struct {
    char description[MAX_DESCRIPTION];
    double amount;
} Expense;

void addExpense(Expense *expenses, int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Cannot add more expenses, limit reached.\n");
        return;
    }
    
    printf("Enter description of the expense: ");
    scanf(" %[^\n]", expenses[*count].description); // To read string with spaces
    printf("Enter amount: ");
    scanf("%lf", &expenses[*count].amount);
    
    (*count)++;
    printf("Expense added successfully.\n");
}

void deleteExpense(Expense *expenses, int *count) {
    if (*count == 0) {
        printf("No expenses to delete.\n");
        return;
    }

    int index;
    printf("Enter the index of the expense to delete (0 to %d): ", *count - 1);
    scanf("%d", &index);

    if (index < 0 || index >= *count) {
        printf("Invalid index. No expense deleted.\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    (*count)--;
    printf("Expense deleted successfully.\n");
}

void viewExpenses(Expense *expenses, int count) {
    if (count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\nExpenses List:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s - $%.2f\n", i, expenses[i].description, expenses[i].amount);
    }
    printf("\n");
}

void calculateTotal(Expense *expenses, int count) {
    double total = 0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    printf("Total Expenses: $%.2f\n", total);
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;

    while (1) {
        printf("Expense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. Delete Expense\n");
        printf("3. View Expenses\n");
        printf("4. Calculate Total\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                deleteExpense(expenses, &count);
                break;
            case 3:
                viewExpenses(expenses, count);
                break;
            case 4:
                calculateTotal(expenses, count);
                break;
            case 5:
                printf("Exiting Expense Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}