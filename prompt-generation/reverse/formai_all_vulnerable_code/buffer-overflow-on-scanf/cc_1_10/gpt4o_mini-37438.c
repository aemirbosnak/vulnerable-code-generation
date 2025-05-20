//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUDGET_ITEMS 100
#define MAX_EXPENSE_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
} BudgetItem;

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
} ExpenseItem;

typedef struct {
    BudgetItem budgets[MAX_BUDGET_ITEMS];
    int budgetCount;
    ExpenseItem expenses[MAX_EXPENSE_ITEMS];
    int expenseCount;
} FinancePlanner;

void addBudgetItem(FinancePlanner *planner) {
    if (planner->budgetCount < MAX_BUDGET_ITEMS) {
        BudgetItem item;
        printf("Enter budget item name: ");
        scanf("%s", item.name);
        printf("Enter budget amount: ");
        scanf("%f", &item.amount);
        planner->budgets[planner->budgetCount++] = item;
        printf("Budget item added!\n");
    } else {
        printf("Maximum budget items reached!\n");
    }
}

void addExpenseItem(FinancePlanner *planner) {
    if (planner->expenseCount < MAX_EXPENSE_ITEMS) {
        ExpenseItem item;
        printf("Enter expense item name: ");
        scanf("%s", item.name);
        printf("Enter expense amount: ");
        scanf("%f", &item.amount);
        planner->expenses[planner->expenseCount++] = item;
        printf("Expense item added!\n");
    } else {
        printf("Maximum expense items reached!\n");
    }
}

void viewBudgets(FinancePlanner *planner) {
    printf("\n=== Your Budgets ===\n");
    for (int i = 0; i < planner->budgetCount; i++) {
        printf("%s: $%.2f\n", planner->budgets[i].name, planner->budgets[i].amount);
    }
}

void viewExpenses(FinancePlanner *planner) {
    printf("\n=== Your Expenses ===\n");
    for (int i = 0; i < planner->expenseCount; i++) {
        printf("%s: $%.2f\n", planner->expenses[i].name, planner->expenses[i].amount);
    }
}

void calculateRemainingBudget(FinancePlanner *planner) {
    float totalBudget = 0, totalExpenses = 0;

    for (int i = 0; i < planner->budgetCount; i++) {
        totalBudget += planner->budgets[i].amount;
    }

    for (int i = 0; i < planner->expenseCount; i++) {
        totalExpenses += planner->expenses[i].amount;
    }

    float remaining = totalBudget - totalExpenses;
    printf("\nYour remaining budget is: $%.2f\n", remaining);
}

void displayMenu() {
    printf("\n=== Personal Finance Planner ===\n");
    printf("1. Add Budget Item\n");
    printf("2. Add Expense Item\n");
    printf("3. View Budgets\n");
    printf("4. View Expenses\n");
    printf("5. Calculate Remaining Budget\n");
    printf("6. Exit\n");
    printf("===============================\n");
}

int main() {
    FinancePlanner planner;
    planner.budgetCount = 0;
    planner.expenseCount = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBudgetItem(&planner);
                break;
            case 2:
                addExpenseItem(&planner);
                break;
            case 3:
                viewBudgets(&planner);
                break;
            case 4:
                viewExpenses(&planner);
                break;
            case 5:
                calculateRemainingBudget(&planner);
                break;
            case 6:
                printf("Thank you for using the Personal Finance Planner!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
    return 0;
}