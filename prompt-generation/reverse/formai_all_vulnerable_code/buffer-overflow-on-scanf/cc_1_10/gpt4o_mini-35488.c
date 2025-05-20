//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_DESC_LENGTH 50

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
} Entry;

typedef struct {
    Entry income[MAX_ENTRIES];
    Entry expenses[MAX_ENTRIES];
    int income_count;
    int expense_count;
} FinancePlanner;

void initializePlanner(FinancePlanner *planner) {
    planner->income_count = 0;
    planner->expense_count = 0;
}

void addIncome(FinancePlanner *planner) {
    if (planner->income_count >= MAX_ENTRIES) {
        printf("Income entries limit reached.\n");
        return;
    }
    
    Entry new_income;
    printf("Enter income description: ");
    scanf(" %[^\n]", new_income.description);
    printf("Enter income amount: ");
    scanf("%f", &new_income.amount);
    
    planner->income[planner->income_count] = new_income;
    planner->income_count++;
    printf("Income added successfully!\n");
}

void addExpense(FinancePlanner *planner) {
    if (planner->expense_count >= MAX_ENTRIES) {
        printf("Expense entries limit reached.\n");
        return;
    }
    
    Entry new_expense;
    printf("Enter expense description: ");
    scanf(" %[^\n]", new_expense.description);
    printf("Enter expense amount: ");
    scanf("%f", &new_expense.amount);
    
    planner->expenses[planner->expense_count] = new_expense;
    planner->expense_count++;
    printf("Expense added successfully!\n");
}

void viewStatus(FinancePlanner *planner) {
    float total_income = 0.0;
    float total_expense = 0.0;

    printf("Income Summary:\n");
    for (int i = 0; i < planner->income_count; i++) {
        printf("Description: %s, Amount: %.2f\n", planner->income[i].description, planner->income[i].amount);
        total_income += planner->income[i].amount;
    }
    
    printf("\nExpense Summary:\n");
    for (int i = 0; i < planner->expense_count; i++) {
        printf("Description: %s, Amount: %.2f\n", planner->expenses[i].description, planner->expenses[i].amount);
        total_expense += planner->expenses[i].amount;
    }

    printf("\nTotal Income: %.2f\n", total_income);
    printf("Total Expense: %.2f\n", total_expense);
    printf("Net Savings: %.2f\n", total_income - total_expense);
}

void displayMenu() {
    printf("\nPersonal Finance Planner\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. View Financial Status\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    FinancePlanner planner;
    initializePlanner(&planner);
    
    int choice;
    do {
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
                viewStatus(&planner);
                break;
            case 4:
                printf("Exiting the planner. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}