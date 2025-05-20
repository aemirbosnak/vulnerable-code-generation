//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 100

typedef struct {
    char description[50];
    float amount;
} Expense;

typedef struct {
    char description[50];
    float amount;
} Income;

typedef struct {
    Expense expenses[MAX_ENTRIES];
    Income incomes[MAX_ENTRIES];
    int expense_count;
    int income_count;
    float total_income;
    float total_expenses;
} Budget;

void initializeBudget(Budget *budget) {
    budget->expense_count = 0;
    budget->income_count = 0;
    budget->total_income = 0.0;
    budget->total_expenses = 0.0;
}

void addExpense(Budget *budget) {
    if (budget->expense_count >= MAX_ENTRIES) {
        printf("Expense list is full!\n");
        return;
    }

    Expense newExpense;
    printf("Enter expense description: ");
    scanf("%s", newExpense.description);
    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);

    budget->expenses[budget->expense_count++] = newExpense;
    budget->total_expenses += newExpense.amount;
    printf("Expense added successfully!\n");
}

void addIncome(Budget *budget) {
    if (budget->income_count >= MAX_ENTRIES) {
        printf("Income list is full!\n");
        return;
    }

    Income newIncome;
    printf("Enter income description: ");
    scanf("%s", newIncome.description);
    printf("Enter income amount: ");
    scanf("%f", &newIncome.amount);

    budget->incomes[budget->income_count++] = newIncome;
    budget->total_income += newIncome.amount;
    printf("Income added successfully!\n");
}

void displayBudget(const Budget *budget) {
    printf("\n--- Budget Summary ---\n");
    printf("Total Income: $%.2f\n", budget->total_income);
    printf("Total Expenses: $%.2f\n", budget->total_expenses);
    printf("Balance: $%.2f\n", budget->total_income - budget->total_expenses);
    printf("\n--- Income Items ---\n");
    for (int i = 0; i < budget->income_count; i++) {
        printf("%s: $%.2f\n", budget->incomes[i].description, budget->incomes[i].amount);
    }
    printf("\n--- Expense Items ---\n");
    for (int i = 0; i < budget->expense_count; i++) {
        printf("%s: $%.2f\n", budget->expenses[i].description, budget->expenses[i].amount);
    }
    printf("----------------------\n");
}

void saveBudgetToFile(const Budget *budget) {
    FILE *file = fopen("budget.txt", "w");
    if (!file) {
        printf("Unable to open file for writing.\n");
        return;
    }

    fprintf(file, "Total Income: $%.2f\n", budget->total_income);
    fprintf(file, "Total Expenses: $%.2f\n", budget->total_expenses);
    fprintf(file, "Balance: $%.2f\n", budget->total_income - budget->total_expenses);
    fprintf(file, "--- Income Items ---\n");
    for (int i = 0; i < budget->income_count; i++) {
        fprintf(file, "%s: $%.2f\n", budget->incomes[i].description, budget->incomes[i].amount);
    }
    fprintf(file, "--- Expense Items ---\n");
    for (int i = 0; i < budget->expense_count; i++) {
        fprintf(file, "%s: $%.2f\n", budget->expenses[i].description, budget->expenses[i].amount);
    }
    fclose(file);
    printf("Budget saved to budget.txt successfully!\n");
}

int main() {
    Budget budget;
    initializeBudget(&budget);
    
    int choice;
    do {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Display Budget\n");
        printf("4. Save Budget to File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addIncome(&budget);
                break;
            case 2:
                addExpense(&budget);
                break;
            case 3:
                displayBudget(&budget);
                break;
            case 4:
                saveBudgetToFile(&budget);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}