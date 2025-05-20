//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LENGTH 50

typedef struct {
    char description[DESCRIPTION_LENGTH];
    float amount;
} Expense;

void addExpense(Expense *expenses, int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Expense list is full. Cannot add more expenses.\n");
        return;
    }

    printf("Enter a description for the expense: ");
    fgets(expenses[*count].description, DESCRIPTION_LENGTH, stdin);
    // Remove newline character from string
    expenses[*count].description[strcspn(expenses[*count].description, "\n")] = 0;

    printf("Enter the amount: ");
    scanf("%f", &expenses[*count].amount);
    getchar(); // To consume the newline character left in stdin buffer

    (*count)++;
    printf("Expense added successfully!\n");
}

void viewExpenses(const Expense *expenses, int count) {
    if (count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\nExpenses List:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s: $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
    }
}

void deleteExpense(Expense *expenses, int *count) {
    if (*count == 0) {
        printf("No expenses to delete.\n");
        return;
    }

    int index;
    printf("Enter the index of the expense to delete (1 to %d): ", *count);
    scanf("%d", &index);
    getchar(); // To consume the newline character left in stdin buffer

    if (index < 1 || index > *count) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index - 1; i < *count - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    
    (*count)--;
    printf("Expense deleted successfully!\n");
}

float calculateTotal(const Expense *expenses, int count) {
    float total = 0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    return total;
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;

    do {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Delete Expense\n");
        printf("4. Calculate Total Expenses\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left in stdin buffer

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
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}