//FormAI DATASET v1.0 Category: Expense Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char date[11];
    float amount;
    char category[20];
} Expense;

typedef struct {
    Expense *expenses;
    int size;
    int capacity;
} Tracker;

void addExpense(Tracker *tracker, Expense expense) {
    if (tracker->size == tracker->capacity) {
        tracker->capacity *= 2;
        tracker->expenses = realloc(tracker->expenses, tracker->capacity * sizeof(Expense));
    }

    tracker->expenses[tracker->size] = expense;
    tracker->size++;
}

void printExpense(Expense expense) {
    printf("%s: $%.2f (%s)\n", expense.date, expense.amount, expense.category);
}

void printAllExpenses(Tracker tracker) {
    printf("All expenses:\n");
    for (int i = 0; i < tracker.size; i++) {
        printExpense(tracker.expenses[i]);
    }
}

float getTotalExpense(Tracker tracker) {
    float total = 0;
    for (int i = 0; i < tracker.size; i++) {
        total += tracker.expenses[i].amount;
    }
    return total;
}

int main() {
    Tracker tracker;
    tracker.size = 0;
    tracker.capacity = 10;
    tracker.expenses = malloc(tracker.capacity * sizeof(Expense));

    printf("Welcome to Expense Tracker!\n\n");

    while (1) {
        printf("1. Add expense\n2. Show all expenses\n3. Show total expense\n4. Exit\n\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nEnter expense details:\n");

            Expense expense;
            printf("Date (YYYY/MM/DD): ");
            scanf("%s", expense.date);
            printf("Amount: ");
            scanf("%f", &expense.amount);
            printf("Category: ");
            scanf("%s", expense.category);

            addExpense(&tracker, expense);

            printf("\nExpense added successfully!\n\n");
        }
        else if (choice == 2) {
            printf("\n");
            printAllExpenses(tracker);
            printf("\n");
        }
        else if (choice == 3) {
            printf("Total expense: $%.2f\n\n", getTotalExpense(tracker));
        }
        else if (choice == 4) {
            printf("Thank you for using Expense Tracker!\n");
            break;
        }
        else {
            printf("\nInvalid choice. Try again.\n\n");
        }
    }

    free(tracker.expenses);

    return 0;
}