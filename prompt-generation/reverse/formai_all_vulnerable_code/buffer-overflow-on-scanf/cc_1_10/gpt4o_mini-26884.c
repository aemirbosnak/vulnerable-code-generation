//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_INCOME 100

typedef struct {
    char category[50];
    float amount;
} Expense;

typedef struct {
    char source[50];
    float amount;
} Income;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    Income incomes[MAX_INCOME];
    int expenseCount;
    int incomeCount;
} FinancialPlan;

void addExpense(FinancialPlan *plan) {
    if (plan->expenseCount >= MAX_EXPENSES) {
        printf("Expense limit reached!\n");
        return;
    }
    Expense newExpense;
    printf("Enter expense category: ");
    scanf("%s", newExpense.category);
    printf("Enter amount for %s: ", newExpense.category);
    scanf("%f", &newExpense.amount);
    plan->expenses[plan->expenseCount++] = newExpense;
    printf("Expense added: %s %0.2f\n", newExpense.category, newExpense.amount);
}

void addIncome(FinancialPlan *plan) {
    if (plan->incomeCount >= MAX_INCOME) {
        printf("Income limit reached!\n");
        return;
    }
    Income newIncome;
    printf("Enter income source: ");
    scanf("%s", newIncome.source);
    printf("Enter amount from %s: ", newIncome.source);
    scanf("%f", &newIncome.amount);
    plan->incomes[plan->incomeCount++] = newIncome;
    printf("Income added: %s %0.2f\n", newIncome.source, newIncome.amount);
}

void viewExpenses(FinancialPlan *plan) {
    printf("\n--- Expenses ---\n");
    for (int i = 0; i < plan->expenseCount; i++) {
        printf("%s: %0.2f\n", plan->expenses[i].category, plan->expenses[i].amount);
    }
}

void viewIncomes(FinancialPlan *plan) {
    printf("\n--- Incomes ---\n");
    for (int i = 0; i < plan->incomeCount; i++) {
        printf("%s: %0.2f\n", plan->incomes[i].source, plan->incomes[i].amount);
    }
}

void calculateBalance(FinancialPlan *plan) {
    float totalIncome = 0, totalExpenses = 0;
    
    for (int i = 0; i < plan->incomeCount; i++) {
        totalIncome += plan->incomes[i].amount;
    }
    
    for (int i = 0; i < plan->expenseCount; i++) {
        totalExpenses += plan->expenses[i].amount;
    }
    
    printf("\nTotal Income: %0.2f\n", totalIncome);
    printf("Total Expenses: %0.2f\n", totalExpenses);
    printf("Balance: %0.2f\n", totalIncome - totalExpenses);
}

void displayMenu() {
    printf("\n=== Personal Finance Planner ===\n");
    printf("1. Add Expense\n");
    printf("2. Add Income\n");
    printf("3. View Expenses\n");
    printf("4. View Incomes\n");
    printf("5. Calculate Balance\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    FinancialPlan plan;
    plan.expenseCount = 0;
    plan.incomeCount = 0;
    int choice;
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addExpense(&plan);
                break;
            case 2:
                addIncome(&plan);
                break;
            case 3:
                viewExpenses(&plan);
                break;
            case 4:
                viewIncomes(&plan);
                break;
            case 5:
                calculateBalance(&plan);
                break;
            case 6:
                printf("Exiting the planner. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 6);
    
    return 0;
}