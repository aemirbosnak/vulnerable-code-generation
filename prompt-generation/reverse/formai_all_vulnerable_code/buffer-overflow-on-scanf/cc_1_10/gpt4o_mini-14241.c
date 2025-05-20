//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_INCOMES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
} Income;

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
} Expense;

typedef struct {
    Income incomes[MAX_INCOMES];
    Expense expenses[MAX_EXPENSES];
    int income_count;
    int expense_count;
} FinanceTracker;

void add_income(FinanceTracker *tracker) {
    if (tracker->income_count < MAX_INCOMES) {
        Income new_income;
        printf("Enter income source: ");
        scanf("%s", new_income.name);
        printf("Enter income amount: ");
        scanf("%f", &new_income.amount);
        tracker->incomes[tracker->income_count] = new_income;
        tracker->income_count++;
        printf("Income added successfully!\n");
    } else {
        printf("Maximum income entries reached!\n");
    }
}

void add_expense(FinanceTracker *tracker) {
    if (tracker->expense_count < MAX_EXPENSES) {
        Expense new_expense;
        printf("Enter expense name: ");
        scanf("%s", new_expense.name);
        printf("Enter expense amount: ");
        scanf("%f", &new_expense.amount);
        tracker->expenses[tracker->expense_count] = new_expense;
        tracker->expense_count++;
        printf("Expense added successfully!\n");
    } else {
        printf("Maximum expense entries reached!\n");
    }
}

void display_summary(FinanceTracker *tracker) {
    float total_income = 0.0;
    float total_expense = 0.0;

    printf("\n--- Income Summary ---\n");
    for (int i = 0; i < tracker->income_count; i++) {
        printf("%s: $%.2f\n", tracker->incomes[i].name, tracker->incomes[i].amount);
        total_income += tracker->incomes[i].amount;
    }
    printf("Total Income: $%.2f\n", total_income);

    printf("\n--- Expense Summary ---\n");
    for (int i = 0; i < tracker->expense_count; i++) {
        printf("%s: $%.2f\n", tracker->expenses[i].name, tracker->expenses[i].amount);
        total_expense += tracker->expenses[i].amount;
    }
    printf("Total Expense: $%.2f\n", total_expense);

    printf("\n--- Net Balance ---\n");
    printf("Net Balance: $%.2f\n", total_income - total_expense);
}

void user_interface(FinanceTracker *tracker) {
    int choice;
    do {
        printf("\n--- Personal Finance Planner ---\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Display Summary\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_income(tracker);
                break;
            case 2:
                add_expense(tracker);
                break;
            case 3:
                display_summary(tracker);
                break;
            case 4:
                printf("Exiting the planner. Happy budgeting!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    FinanceTracker tracker;
    tracker.income_count = 0;
    tracker.expense_count = 0;

    user_interface(&tracker);
    return 0;
}