//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_DESC_LENGTH 50

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
} Transaction;

typedef struct {
    Transaction income[MAX_RECORDS];
    Transaction expenses[MAX_RECORDS];
    int income_count;
    int expense_count;
    float savings_goal;
    float current_savings;
} FinancePlanner;

void initializePlanner(FinancePlanner *planner) {
    planner->income_count = 0;
    planner->expense_count = 0;
    planner->savings_goal = 0;
    planner->current_savings = 0;
}

void addIncome(FinancePlanner *planner, const char *description, float amount) {
    if (planner->income_count < MAX_RECORDS) {
        strcpy(planner->income[planner->income_count].description, description);
        planner->income[planner->income_count].amount = amount;
        planner->income_count++;
    } else {
        printf("Income record limit reached!\n");
    }
}

void addExpense(FinancePlanner *planner, const char *description, float amount) {
    if (planner->expense_count < MAX_RECORDS) {
        strcpy(planner->expenses[planner->expense_count].description, description);
        planner->expenses[planner->expense_count].amount = amount;
        planner->expense_count++;
    } else {
        printf("Expense record limit reached!\n");
    }
}

void setSavingsGoal(FinancePlanner *planner, float goal) {
    planner->savings_goal = goal;
}

void makeSaving(FinancePlanner *planner, float amount) {
    planner->current_savings += amount;
}

void viewTransactions(FinancePlanner *planner) {
    printf("\nIncome Transactions:\n");
    for (int i = 0; i < planner->income_count; i++) {
        printf("%s: $%.2f\n", planner->income[i].description, planner->income[i].amount);
    }

    printf("\nExpense Transactions:\n");
    for (int i = 0; i < planner->expense_count; i++) {
        printf("%s: $%.2f\n", planner->expenses[i].description, planner->expenses[i].amount);
    }

    printf("\nCurrent Savings: $%.2f\n", planner->current_savings);
    printf("Savings Goal: $%.2f\n", planner->savings_goal);
}

void calculateBudget(FinancePlanner *planner) {
    float total_income = 0, total_expenses = 0;
    for (int i = 0; i < planner->income_count; i++) {
        total_income += planner->income[i].amount;
    }
    for (int i = 0; i < planner->expense_count; i++) {
        total_expenses += planner->expenses[i].amount;
    }

    float savings = total_income - total_expenses;
    printf("\nTotal Income: $%.2f\n", total_income);
    printf("Total Expenses: $%.2f\n", total_expenses);
    printf("Remaining Budget (Savings): $%.2f\n", savings);
}

void displayMenu() {
    printf("\nPersonal Finance Planner\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. Set Savings Goal\n");
    printf("4. Make Saving\n");
    printf("5. View Transactions\n");
    printf("6. Calculate Budget\n");
    printf("7. Exit\n");
    printf("Select an option: ");
}

int main() {
    FinancePlanner planner;
    initializePlanner(&planner);
    
    int choice;
    char description[MAX_DESC_LENGTH];
    float amount;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter income description: ");
                scanf(" %[^\n]s", description);
                printf("Enter amount: ");
                scanf("%f", &amount);
                addIncome(&planner, description, amount);
                break;
            case 2:
                printf("Enter expense description: ");
                scanf(" %[^\n]s", description);
                printf("Enter amount: ");
                scanf("%f", &amount);
                addExpense(&planner, description, amount);
                break;
            case 3:
                printf("Enter your savings goal: ");
                scanf("%f", &amount);
                setSavingsGoal(&planner, amount);
                break;
            case 4:
                printf("Enter amount to save: ");
                scanf("%f", &amount);
                makeSaving(&planner, amount);
                break;
            case 5:
                viewTransactions(&planner);
                break;
            case 6:
                calculateBudget(&planner);
                break;
            case 7:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}