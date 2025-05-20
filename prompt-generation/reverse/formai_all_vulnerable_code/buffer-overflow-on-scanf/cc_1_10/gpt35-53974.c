//FormAI DATASET v1.0 Category: Expense Tracker ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_EXPENSES 100
#define MAX_DESCRIPTION_LENGTH 50

typedef struct {
    char description[MAX_DESCRIPTION_LENGTH];
    double amount;
} Expense;

typedef struct {
    int count;
    Expense expenses[MAX_EXPENSES];
} ExpenseList;

typedef struct {
    char month[10];
    ExpenseList expenses;
} ExpenseTracker;

int main() {

    ExpenseTracker tracker;
    strcpy(tracker.month, "May");
    tracker.expenses.count = 0;

    bool loop = true;
    while (loop) {
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (tracker.expenses.count >= MAX_EXPENSES) {
                    printf("Cannot add more expenses. Maximum limit reached.\n");
                    break;
                }
                Expense expense;
                printf("Enter expense description (max %d characters): ", MAX_DESCRIPTION_LENGTH - 1);
                scanf("%s", expense.description);
                printf("Enter expense amount: ");
                scanf("%lf", &expense.amount);
                tracker.expenses.expenses[tracker.expenses.count] = expense;
                tracker.expenses.count++;
                printf("Expense added successfully.\n");
                break;
            case 2:
                printf("Expenses for %s:\n", tracker.month);
                printf("Description\tAmount\n");
                for (int i = 0; i < tracker.expenses.count; i++) {
                    Expense e = tracker.expenses.expenses[i];
                    printf("%s\t%.2lf\n", e.description, e.amount);
                }
                break;
            case 3:
                printf("Exiting the program.\n");
                loop = false;
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}