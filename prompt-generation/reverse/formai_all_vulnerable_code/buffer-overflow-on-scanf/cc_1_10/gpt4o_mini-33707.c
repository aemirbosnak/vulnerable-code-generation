//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LEN 50

typedef struct {
    char category[MAX_LEN];
    float amount;
} Expense;

typedef struct {
    float budget;
    Expense expenses[MAX_ENTRIES];
    int expenseCount;
} FinancePlanner;

void displayMenu() {
    printf("\n=====================\n");
    printf("   Personal Finance Planner   \n");
    printf("=====================\n");
    printf("1. Set Budget\n");
    printf("2. Add Expense\n");
    printf("3. View Expenses\n");
    printf("4. View Budget Summary\n");
    printf("5. Exit\n");
    printf("=====================\n");
}

void setBudget(FinancePlanner *planner) {
    printf("Enter your budget: $");
    scanf("%f", &planner->budget);
    planner->expenseCount = 0; // Reset expenses whenever a new budget is set
    printf("Budget set to $%.2f\n", planner->budget);
}

void addExpense(FinancePlanner *planner) {
    if (planner->expenseCount >= MAX_ENTRIES) {
        printf("Expense limit reached! Cannot add more expenses.\n");
        return;
    }

    Expense newExpense;
    printf("Enter expense category: ");
    scanf("%s", newExpense.category);
    printf("Enter expense amount: $");
    scanf("%f", &newExpense.amount);

    planner->expenses[planner->expenseCount] = newExpense;
    planner->expenseCount++;
    printf("Expense added: %s - $%.2f\n", newExpense.category, newExpense.amount);
}

void viewExpenses(FinancePlanner *planner) {
    printf("\n--- Expense List ---\n");
    if (planner->expenseCount == 0) {
        printf("No expenses recorded yet!\n");
        return;
    }
    for (int i = 0; i < planner->expenseCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, planner->expenses[i].category, planner->expenses[i].amount);
    }
}

void viewBudgetSummary(FinancePlanner *planner) {
    float totalExpenses = 0.0;
    for (int i = 0; i < planner->expenseCount; i++) {
        totalExpenses += planner->expenses[i].amount;
    }
    printf("\n--- Budget Summary ---\n");
    printf("Budget: $%.2f\n", planner->budget);
    printf("Total Expenses: $%.2f\n", totalExpenses);
    float remaining = planner->budget - totalExpenses;
    if (remaining < 0) {
        printf("You are over budget by: $%.2f\n", -remaining);
    } else {
        printf("Remaining budget: $%.2f\n", remaining);
    }
}

int main() {
    FinancePlanner planner;
    planner.budget = 0.0;
    planner.expenseCount = 0;

    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                setBudget(&planner);
                break;
            case 2:
                addExpense(&planner);
                break;
            case 3:
                viewExpenses(&planner);
                break;
            case 4:
                viewBudgetSummary(&planner);
                break;
            case 5:
                printf("Exiting the Personal Finance Planner. Have a great day!\n");
                exit(0);
            default:
                printf("Please choose a valid option!\n");
        }
    }

    return 0;
}