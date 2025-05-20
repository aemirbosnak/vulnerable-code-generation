//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORY_NAME 50

typedef struct {
    char category[MAX_CATEGORY_NAME];
    float amount;
} Expense;

typedef struct {
    float income;
    Expense expenses[MAX_EXPENSES];
    int expense_count;
    float savings_goal;
} FinancialPlan;

void initializePlan(FinancialPlan *plan) {
    plan->income = 0.0;
    plan->expense_count = 0;
    plan->savings_goal = 0.0;
}

void addIncome(FinancialPlan *plan) {
    printf("Enter your total income: ");
    scanf("%f", &plan->income);
}

void addExpense(FinancialPlan *plan) {
    if (plan->expense_count >= MAX_EXPENSES) {
        printf("Expense limit reached!\n");
        return;
    }
    printf("Enter expense category: ");
    scanf("%s", plan->expenses[plan->expense_count].category);
    printf("Enter expense amount: ");
    scanf("%f", &plan->expenses[plan->expense_count].amount);
    plan->expense_count++;
}

void setSavingsGoal(FinancialPlan *plan) {
    printf("Enter your savings goal: ");
    scanf("%f", &plan->savings_goal);
}

float calculateTotalExpenses(FinancialPlan *plan) {
    float total = 0.0;
    for (int i = 0; i < plan->expense_count; i++) {
        total += plan->expenses[i].amount;
    }
    return total;
}

void generateReport(FinancialPlan *plan) {
    printf("\n--- Financial Summary Report ---\n");
    printf("Total Income: %.2f\n", plan->income);
    printf("Total Expenses: %.2f\n", calculateTotalExpenses(plan));
    printf("Savings Goal: %.2f\n", plan->savings_goal);
    printf("Current Balance: %.2f\n", plan->income - calculateTotalExpenses(plan));
    printf("---------------------------------\n");
    printf("Expense Breakdown:\n");
    
    for (int i = 0; i < plan->expense_count; i++) {
        printf("%s: %.2f\n", plan->expenses[i].category, plan->expenses[i].amount);
    }
    
    printf("---------------------------------\n");
    
    float total = calculateTotalExpenses(plan);
    if (plan->income - total >= plan->savings_goal) {
        printf("You are on track to meet your savings goal!\n");
    } else {
        printf("You are NOT on track to meet your savings goal.\n");
    }
}

int main() {
    FinancialPlan myPlan;
    int choice;

    initializePlan(&myPlan);

    do {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Set Savings Goal\n");
        printf("4. Generate Report\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addIncome(&myPlan);
                break;
            case 2:
                addExpense(&myPlan);
                break;
            case 3:
                setSavingsGoal(&myPlan);
                break;
            case 4:
                generateReport(&myPlan);
                break;
            case 5:
                printf("Exiting the planner. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}