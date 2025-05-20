//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LENGTH 50

typedef struct {
    char description[DESCRIPTION_LENGTH];
    float amount;
    char date[11]; // Format: YYYY-MM-DD
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void add_expense(ExpenseTracker *tracker);
void view_expenses(const ExpenseTracker *tracker);
void total_expense(const ExpenseTracker *tracker);
void display_menu();
void clear_buffer();

int main() {
    ExpenseTracker tracker = { .count = 0 };
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_buffer(); // Clear the input buffer to avoid anomalies

        switch (choice) {
            case 1:
                add_expense(&tracker);
                break;
            case 2:
                view_expenses(&tracker);
                break;
            case 3:
                total_expense(&tracker);
                break;
            case 4:
                printf("Exiting Expense Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void add_expense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Expense Tracker is full. Cannot add more expenses.\n");
        return;
    }
    
    Expense new_expense;
    printf("Enter description of the expense: ");
    fgets(new_expense.description, DESCRIPTION_LENGTH, stdin);
    new_expense.description[strcspn(new_expense.description, "\n")] = 0; // Remove newline character

    printf("Enter amount: ");
    scanf("%f", &new_expense.amount);
    clear_buffer(); // Clear buffer to avoid anomalies

    printf("Enter date (YYYY-MM-DD): ");
    fgets(new_expense.date, 11, stdin);
    new_expense.date[strcspn(new_expense.date, "\n")] = 0; // Remove newline character

    tracker->expenses[tracker->count] = new_expense;
    tracker->count++;
    printf("Expense added successfully!\n");
}

void view_expenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }

    printf("\n---- List of Expenses ----\n");
    for (int i = 0; i < tracker->count; ++i) {
        printf("Expense %d: Description: %s, Amount: %.2f, Date: %s\n",
               i + 1, tracker->expenses[i].description,
               tracker->expenses[i].amount,
               tracker->expenses[i].date);
    }
    printf("--------------------------\n");
}

void total_expense(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded to calculate total.\n");
        return;
    }

    float total = 0.0;
    for (int i = 0; i < tracker->count; ++i) {
        total += tracker->expenses[i].amount;
    }
    printf("Total expenses recorded: %.2f\n", total);
}

void display_menu() {
    printf("\n---- Expense Tracker Menu ----\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Total Expenses\n");
    printf("4. Exit\n");
    printf("-------------------------------\n");
}

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}