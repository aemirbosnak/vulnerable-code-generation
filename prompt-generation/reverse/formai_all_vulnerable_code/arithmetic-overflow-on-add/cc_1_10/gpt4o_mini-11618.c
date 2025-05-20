//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    float amount;
} Income;

typedef struct {
    char name[NAME_LEN];
    float amount;
} Expense;

typedef struct {
    Income incomes[MAX_ENTRIES];
    Expense expenses[MAX_ENTRIES];
    int income_count;
    int expense_count;
} Budget;

void add_income(Budget *budget) {
    if (budget->income_count >= MAX_ENTRIES) {
        printf("Income entries are full!\n");
        return;
    }
    
    printf("Enter the name of the income source: ");
    scanf("%s", budget->incomes[budget->income_count].name);
    printf("Enter the amount: ");
    scanf("%f", &budget->incomes[budget->income_count].amount);
    
    budget->income_count++;
    printf("Income added successfully!\n");
}

void add_expense(Budget *budget) {
    if (budget->expense_count >= MAX_ENTRIES) {
        printf("Expense entries are full!\n");
        return;
    }

    printf("Enter the name of the expense: ");
    scanf("%s", budget->expenses[budget->expense_count].name);
    printf("Enter the amount: ");
    scanf("%f", &budget->expenses[budget->expense_count].amount);
    
    budget->expense_count++;
    printf("Expense added successfully!\n");
}

void display_budget(Budget *budget) {
    float total_income = 0.0;
    float total_expenses = 0.0;

    printf("\n--- Financial Summary ---\n");
    printf("Incomes:\n");
    for (int i = 0; i < budget->income_count; i++) {
        printf("%s: $%.2f\n", budget->incomes[i].name, budget->incomes[i].amount);
        total_income += budget->incomes[i].amount;
    }

    printf("Total Income: $%.2f\n", total_income);

    printf("\nExpenses:\n");
    for (int i = 0; i < budget->expense_count; i++) {
        printf("%s: $%.2f\n", budget->expenses[i].name, budget->expenses[i].amount);
        total_expenses += budget->expenses[i].amount;
    }

    printf("Total Expenses: $%.2f\n", total_expenses);
    
    float net_savings = total_income - total_expenses;
    printf("Net Savings: $%.2f\n", net_savings);
}

void show_menu() {
    printf("\n--- Personal Finance Planner ---\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. Display Budget\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Budget myBudget;
    myBudget.income_count = 0;
    myBudget.expense_count = 0;

    int choice;
    do {
        show_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_income(&myBudget);
                break;
            case 2:
                add_expense(&myBudget);
                break;
            case 3:
                display_budget(&myBudget);
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