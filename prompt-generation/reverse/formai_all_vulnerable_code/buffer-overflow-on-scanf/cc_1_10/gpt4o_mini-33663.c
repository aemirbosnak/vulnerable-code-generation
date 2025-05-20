//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float amount;
} Entry;

typedef struct {
    float income;
    Entry expenses[MAX_ENTRIES];
    int expense_count;
    float savings_goal;
    float savings;
} FinancePlanner;

void addIncome(FinancePlanner *planner) {
    printf("Enter your total monthly income: ");
    scanf("%f", &planner->income);
}

void addExpense(FinancePlanner *planner) {
    if (planner->expense_count >= MAX_ENTRIES) {
        printf("Expense limit reached.\n");
        return;
    }
    Entry new_expense;
    printf("Enter expense name: ");
    scanf("%s", new_expense.name);
    printf("Enter expense amount: ");
    scanf("%f", &new_expense.amount);
    planner->expenses[planner->expense_count++] = new_expense;
}

void setSavingsGoal(FinancePlanner *planner) {
    printf("Enter your savings goal: ");
    scanf("%f", &planner->savings_goal);
    planner->savings = 0;
}

void viewFinanceStatus(FinancePlanner *planner) {
    float total_expenses = 0;
    printf("\n--- Financial Status ---\n");
    printf("Total Income: %.2f\n", planner->income);
    
    for (int i = 0; i < planner->expense_count; i++) {
        printf("Expense (%s): %.2f\n", planner->expenses[i].name, planner->expenses[i].amount);
        total_expenses += planner->expenses[i].amount;
    }

    printf("Total Expenses: %.2f\n", total_expenses);
  
    planner->savings = planner->income - total_expenses;
    
    printf("Savings: %.2f\n", planner->savings);
    printf("Savings Goal: %.2f\n", planner->savings_goal);
    
    if (planner->savings >= planner->savings_goal) {
        printf("Congratulations! You have met your savings goal!\n");
    } else {
        printf("You need to save %.2f more to reach your goal.\n",
               planner->savings_goal - planner->savings);
    }
}

void displayMenu() {
    printf("\n--- Personal Finance Planner Menu ---\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. Set Savings Goal\n");
    printf("4. View Financial Status\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    FinancePlanner planner = {0, {{0}}, 0, 0, 0};
    int choice;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addIncome(&planner);
                break;
            case 2:
                addExpense(&planner);
                break;
            case 3:
                setSavingsGoal(&planner);
                break;
            case 4:
                viewFinanceStatus(&planner);
                break;
            case 5:
                printf("Exiting the Personal Finance Planner. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    
    return 0;
}