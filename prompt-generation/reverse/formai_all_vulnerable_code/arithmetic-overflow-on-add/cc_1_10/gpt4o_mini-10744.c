//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float amount;
} Entry;

typedef struct {
    Entry income[MAX_ITEMS];
    Entry expenses[MAX_ITEMS];
    int income_count;
    int expenses_count;
    float savings_goal;
} FinanceTracker;

void initialize(FinanceTracker *tracker) {
    tracker->income_count = 0;
    tracker->expenses_count = 0;
    tracker->savings_goal = 0.0f;
}

void addIncome(FinanceTracker *tracker) {
    if (tracker->income_count >= MAX_ITEMS) {
        printf("Maximum income entries reached!\n");
        return;
    }
    
    printf("Enter income source: ");
    scanf("%s", tracker->income[tracker->income_count].name);
    printf("Enter income amount: ");
    scanf("%f", &tracker->income[tracker->income_count].amount);
    tracker->income_count++;
    printf("Income added successfully!\n");
}

void addExpense(FinanceTracker *tracker) {
    if (tracker->expenses_count >= MAX_ITEMS) {
        printf("Maximum expense entries reached!\n");
        return;
    }
    
    printf("Enter expense category: ");
    scanf("%s", tracker->expenses[tracker->expenses_count].name);
    printf("Enter expense amount: ");
    scanf("%f", &tracker->expenses[tracker->expenses_count].amount);
    tracker->expenses_count++;
    printf("Expense added successfully!\n");
}

void setSavingsGoal(FinanceTracker *tracker) {
    printf("Enter your savings goal: ");
    scanf("%f", &tracker->savings_goal);
    printf("Savings goal set to: %.2f\n", tracker->savings_goal);
}

void displaySummary(FinanceTracker *tracker) {
    float total_income = 0.0f;
    float total_expenses = 0.0f;

    printf("\n----- Financial Summary -----\n");
    printf("Income:\n");
    for (int i = 0; i < tracker->income_count; i++) {
        printf("%s: %.2f\n", tracker->income[i].name, tracker->income[i].amount);
        total_income += tracker->income[i].amount;
    }

    printf("\nExpenses:\n");
    for (int i = 0; i < tracker->expenses_count; i++) {
        printf("%s: %.2f\n", tracker->expenses[i].name, tracker->expenses[i].amount);
        total_expenses += tracker->expenses[i].amount;
    }

    printf("\nTotal Income: %.2f\n", total_income);
    printf("Total Expenses: %.2f\n", total_expenses);
    printf("Net Income: %.2f\n", total_income - total_expenses);
    printf("Savings Goal: %.2f\n", tracker->savings_goal);
    printf("Remaining to reach goal: %.2f\n", tracker->savings_goal - (total_income - total_expenses));
    printf("----------------------------\n");
}

void displayMenu() {
    printf("\nPersonal Finance Planner\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. Set Savings Goal\n");
    printf("4. Display Summary\n");
    printf("5. Exit\n");
}

int main() {
    FinanceTracker tracker;
    initialize(&tracker);
    
    int choice;
    do {
        displayMenu();
        printf("Choose an option: ");
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
                displaySummary(&tracker);
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}