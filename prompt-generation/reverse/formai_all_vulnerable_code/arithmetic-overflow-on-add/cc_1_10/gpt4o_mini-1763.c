//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define STRING_SIZE 50

typedef struct {
    char name[STRING_SIZE];
    float amount;
} Entry;

typedef struct {
    Entry income[MAX_ENTRIES];
    Entry expenses[MAX_ENTRIES];
    int income_count;
    int expense_count;
    float savings_goal;
} FinanceTracker;

void initializeFinanceTracker(FinanceTracker *tracker) {
    tracker->income_count = 0;
    tracker->expense_count = 0;
    tracker->savings_goal = 0.0;
}

void addIncome(FinanceTracker *tracker) {
    if (tracker->income_count < MAX_ENTRIES) {
        printf("Enter income source: ");
        scanf("%s", tracker->income[tracker->income_count].name);
        printf("Enter income amount: ");
        scanf("%f", &tracker->income[tracker->income_count].amount);
        tracker->income_count++;
    } else {
        printf("Income entries limit reached!\n");
    }
}

void addExpense(FinanceTracker *tracker) {
    if (tracker->expense_count < MAX_ENTRIES) {
        printf("Enter expense source: ");
        scanf("%s", tracker->expenses[tracker->expense_count].name);
        printf("Enter expense amount: ");
        scanf("%f", &tracker->expenses[tracker->expense_count].amount);
        tracker->expense_count++;
    } else {
        printf("Expense entries limit reached!\n");
    }
}

void setSavingsGoal(FinanceTracker *tracker) {
    printf("Enter your savings goal: ");
    scanf("%f", &tracker->savings_goal);
}

void viewSummary(FinanceTracker *tracker) {
    float total_income = 0.0;
    float total_expenses = 0.0;

    printf("\nIncome Summary:\n");
    for (int i = 0; i < tracker->income_count; i++) {
        printf("%s: %.2f\n", tracker->income[i].name, tracker->income[i].amount);
        total_income += tracker->income[i].amount;
    }

    printf("\nExpense Summary:\n");
    for (int i = 0; i < tracker->expense_count; i++) {
        printf("%s: %.2f\n", tracker->expenses[i].name, tracker->expenses[i].amount);
        total_expenses += tracker->expenses[i].amount;
    }

    printf("\nTotal Income: %.2f\n", total_income);
    printf("Total Expenses: %.2f\n", total_expenses);
    printf("Net Savings: %.2f\n", total_income - total_expenses);
    printf("Savings Goal: %.2f\n", tracker->savings_goal);
}

void menu() {
    printf("\nPersonal Finance Planner Menu:\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. Set Savings Goal\n");
    printf("4. View Summary\n");
    printf("5. Exit\n");
}

int main() {
    FinanceTracker tracker;
    initializeFinanceTracker(&tracker);
    int choice;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addIncome(&tracker);
                break;
            case 2:
                addExpense(&tracker);
                break;
            case 3:
                setSavingsGoal(&tracker);
                break;
            case 4:
                viewSummary(&tracker);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}