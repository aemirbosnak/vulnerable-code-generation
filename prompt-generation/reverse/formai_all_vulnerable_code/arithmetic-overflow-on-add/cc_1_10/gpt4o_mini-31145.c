//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_DESCRIPTION 50

typedef struct {
    char description[MAX_DESCRIPTION];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_ENTRIES];
    int count;
} ExpenseTracker;

void add_expense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }
    
    printf("Enter description of the expense: ");
    scanf(" %[^\n]", tracker->expenses[tracker->count].description);
    printf("Enter amount of the expense: ");
    scanf("%f", &tracker->expenses[tracker->count].amount);

    tracker->count++;
    printf("Expense added successfully!\n");
}

void view_expenses(ExpenseTracker tracker) {
    if (tracker.count == 0) {
        printf("No expenses recorded!\n");
        return;
    }
    
    printf("\nYour Expenses:\n");
    for (int i = 0; i < tracker.count; i++) {
        printf("%d. %s: $%.2f\n", i + 1, tracker.expenses[i].description, tracker.expenses[i].amount);
    }
}

float total_expenses(ExpenseTracker tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker.count; i++) {
        total += tracker.expenses[i].amount;
    }
    return total;
}

void save_expenses(ExpenseTracker tracker) {
    FILE *file = fopen("expenses.txt", "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    for (int i = 0; i < tracker.count; i++) {
        fprintf(file, "%s: %.2f\n", tracker.expenses[i].description, tracker.expenses[i].amount);
    }
    fclose(file);
    printf("Expenses saved to expenses.txt.\n");
}

void load_expenses(ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "r");
    if (file == NULL) {
        printf("No previous expenses found.\n");
        return;
    }

    tracker->count = 0;
    while (fscanf(file, " %[^\n]: %f", tracker->expenses[tracker->count].description, &tracker->expenses[tracker->count].amount) != EOF) {
        tracker->count++;
        if (tracker->count >= MAX_ENTRIES) {
            break;
        }
    }
    fclose(file);
    printf("Expenses loaded successfully!\n");
}

void menu() {
    printf("\n** Personal Finance Planner **\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Total Expenses\n");
    printf("4. Save Expenses\n");
    printf("5. Load Expenses\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    ExpenseTracker tracker;
    tracker.count = 0;

    load_expenses(&tracker);

    int choice;
    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense(&tracker);
                break;
            case 2:
                view_expenses(tracker);
                break;
            case 3:
                printf("Total Expenses: $%.2f\n", total_expenses(tracker));
                break;
            case 4:
                save_expenses(tracker);
                break;
            case 5:
                load_expenses(&tracker);
                break;
            case 6:
                printf("Exiting the Personal Finance Planner. Thank you!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }

    return 0;
}