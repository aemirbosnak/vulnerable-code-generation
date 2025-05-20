//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_DESC_LENGTH 100

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
    time_t date;
} Expense;

typedef struct {
    Expense entries[MAX_ENTRIES];
    int count;
} ExpenseTracker;

void addExpense(ExpenseTracker *tracker, const char *description, float amount) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Expense limit reached. Cannot add more expenses.\n");
        return;
    }
    strncpy(tracker->entries[tracker->count].description, description, MAX_DESC_LENGTH);
    tracker->entries[tracker->count].amount = amount;
    tracker->entries[tracker->count].date = time(NULL);
    tracker->count++;
    printf("Expense added successfully.\n");
}

void viewExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    printf("\n--- Expense List ---\n");
    for (int i = 0; i < tracker->count; i++) {
        struct tm *tm_info = localtime(&tracker->entries[i].date);
        char date_buf[26];
        strftime(date_buf, sizeof(date_buf), "%Y-%m-%d %H:%M:%S", tm_info);
        printf("%d. %s | Amount: %.2f | Date: %s\n", i + 1,
               tracker->entries[i].description,
               tracker->entries[i].amount,
               date_buf);
    }
}

float calculateTotal(const ExpenseTracker *tracker) {
    float total = 0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->entries[i].amount;
    }
    return total;
}

void deleteExpense(ExpenseTracker *tracker, int index) {
    if (index < 1 || index > tracker->count) {
        printf("Invalid index.\n");
        return;
    }
    for (int i = index - 1; i < tracker->count - 1; i++) {
        tracker->entries[i] = tracker->entries[i + 1];
    }
    tracker->count--;
    printf("Expense deleted successfully.\n");
}

void displayMenu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Delete Expense\n");
    printf("5. Exit\n");
}

int main() {
    ExpenseTracker tracker = { .count = 0 };
    int choice;
    char description[MAX_DESC_LENGTH];
    float amount;
    int index;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter expense description: ");
                getchar(); // to consume newline left by scanf
                fgets(description, MAX_DESC_LENGTH, stdin);
                description[strcspn(description, "\n")] = '\0'; // remove trailing newline

                printf("Enter amount: ");
                scanf("%f", &amount);
                addExpense(&tracker, description, amount);
                break;

            case 2:
                viewExpenses(&tracker);
                break;

            case 3:
                printf("Total Expenses: %.2f\n", calculateTotal(&tracker));
                break;

            case 4:
                printf("Enter the index of the expense to delete: ");
                scanf("%d", &index);
                deleteExpense(&tracker, index);
                break;

            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}