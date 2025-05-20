//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct Expense {
    char description[50];
    float amount;
    int day;
    int month;
    int year;
};

struct ExpenseList {
    int count;
    struct Expense expenses[MAX_EXPENSES];
};

void addExpense(struct ExpenseList *list, struct Expense expense) {
    if (list->count < MAX_EXPENSES) {
        list->expenses[list->count++] = expense;
        printf("Expense added successfully!\n");
    } else {
        printf("Error: Maximum number of expenses reached.\n");
    }
}

void printExpense(struct Expense expense) {
    printf("%s ($%.2f): %d/%d/%d\n", expense.description, expense.amount, expense.month, expense.day, expense.year);
}

void printExpenses(struct ExpenseList list) {
    printf("Expense List\n");
    printf("============\n");
    for (int i = 0; i < list.count; i++) {
        printExpense(list.expenses[i]);
    }
}

float getTotalExpense(struct ExpenseList list) {
    float total = 0;
    for (int i = 0; i < list.count; i++) {
        total += list.expenses[i].amount;
    }
    return total;
}

void displayMenu() {
    printf("Expense Tracker\n");
    printf("====================\n");
    printf("1. Add expense\n");
    printf("2. Print all expenses\n");
    printf("3. Get total expense\n");
    printf("4. Exit\n");
    printf("====================\n");
}

int main() {
    struct ExpenseList expenses = { 0 };
    int choice = 0;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                struct Expense expense;
                printf("Enter description: ");
                scanf(" %[^\n]s", expense.description);
                printf("Enter amount: $");
                scanf("%f", &expense.amount);
                printf("Enter date (MM/DD/YYYY): ");
                scanf("%d/%d/%d", &expense.month, &expense.day, &expense.year);
                addExpense(&expenses, expense);
                break;
            }
            case 2: {
                printExpenses(expenses);
                break;
            }
            case 3: {
                float total = getTotalExpense(expenses);
                printf("Total expense: $%.2f\n", total);
                break;
            }
            case 4: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
            }
        }
        printf("\n");

    } while (choice != 4);

    return 0;
}