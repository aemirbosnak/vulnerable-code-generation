//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
} Entry;

typedef struct {
    Entry income[MAX_ENTRIES];
    Entry expenses[MAX_ENTRIES];
    int incomeCount;
    int expenseCount;
} FinanceTracker;

void addIncome(FinanceTracker *tracker) {
    if (tracker->incomeCount >= MAX_ENTRIES) {
        printf("Maximum income entries reached!\n");
        return;
    }
    printf("Enter the income source (e.g., salary): ");
    scanf("%s", tracker->income[tracker->incomeCount].name);
    printf("Enter the amount: ");
    scanf("%f", &tracker->income[tracker->incomeCount].amount);
    tracker->incomeCount++;
    printf("Income added successfully!\n");
}

void addExpense(FinanceTracker *tracker) {
    if (tracker->expenseCount >= MAX_ENTRIES) {
        printf("Maximum expense entries reached!\n");
        return;
    }
    printf("Enter the expense category (e.g., rent): ");
    scanf("%s", tracker->expenses[tracker->expenseCount].name);
    printf("Enter the amount: ");
    scanf("%f", &tracker->expenses[tracker->expenseCount].amount);
    tracker->expenseCount++;
    printf("Expense added successfully!\n");
}

void viewFinances(FinanceTracker tracker) {
    float totalIncome = 0.0;
    float totalExpenses = 0.0;

    printf("\nINCOME:\n");
    for (int i = 0; i < tracker.incomeCount; i++) {
        printf("%s: $%.2f\n", tracker.income[i].name, tracker.income[i].amount);
        totalIncome += tracker.income[i].amount;
    }

    printf("\nEXPENSES:\n");
    for (int i = 0; i < tracker.expenseCount; i++) {
        printf("%s: $%.2f\n", tracker.expenses[i].name, tracker.expenses[i].amount);
        totalExpenses += tracker.expenses[i].amount;
    }

    printf("\nTotal Income: $%.2f\n", totalIncome);
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Net Savings: $%.2f\n", totalIncome - totalExpenses);
}

void budgetHelp() {
    printf("Welcome to Budgeting Help!\n");
    printf("1. Track your incomes and expenses to allocate your budget efficiently.\n");
    printf("2. Identify areas to cut expenses - every dollar saved counts!\n");
    printf("3. Set savings goals and stay motivated.\n");
    printf("4. Regularly review your finances to make informed decisions!\n");
}

void displayMenu() {
    printf("\n====== Personal Finance Planner ======\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. View Finances\n");
    printf("4. Budget Help\n");
    printf("5. Exit\n");
    printf("========================================\n");
}

int main() {
    FinanceTracker tracker = {0};
    int choice;

    do {
        displayMenu();
        printf("Please select an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                addIncome(&tracker);
                break;
            case 2: 
                addExpense(&tracker);
                break;
            case 3: 
                viewFinances(tracker);
                break;
            case 4:
                budgetHelp();
                break;
            case 5: 
                printf("Thank you for using the Personal Finance Planner! Keep saving!\n");
                break;
            default: 
                printf("Invalid option! Please choose again.\n");
        }
    } while (choice != 5);

    return 0;
}