//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_INCOME_SOURCES 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
} IncomeSource;

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
} Expense;

typedef struct {
    IncomeSource incomes[MAX_INCOME_SOURCES];
    Expense expenses[MAX_EXPENSES];
    int income_count;
    int expense_count;
} FinancialPlan;

void add_income(FinancialPlan *plan, const char *name, float amount) {
    if (plan->income_count >= MAX_INCOME_SOURCES) {
        printf("Maximum income sources reached.\n");
        return;
    }
    strcpy(plan->incomes[plan->income_count].name, name);
    plan->incomes[plan->income_count].amount = amount;
    plan->income_count++;
}

void add_expense(FinancialPlan *plan, const char *name, float amount) {
    if (plan->expense_count >= MAX_EXPENSES) {
        printf("Maximum expenses reached.\n");
        return;
    }
    strcpy(plan->expenses[plan->expense_count].name, name);
    plan->expenses[plan->expense_count].amount = amount;
    plan->expense_count++;
}

void display_financial_plan(const FinancialPlan *plan) {
    float total_income = 0, total_expenses = 0;

    printf("\nIncome Sources:\n");
    for (int i = 0; i < plan->income_count; i++) {
        printf("%s: %.2f\n", plan->incomes[i].name, plan->incomes[i].amount);
        total_income += plan->incomes[i].amount;
    }

    printf("\nExpenses:\n");
    for (int i = 0; i < plan->expense_count; i++) {
        printf("%s: %.2f\n", plan->expenses[i].name, plan->expenses[i].amount);
        total_expenses += plan->expenses[i].amount;
    }

    printf("\nTotal Income: %.2f\n", total_income);
    printf("Total Expenses: %.2f\n", total_expenses);
    printf("Net Savings: %.2f\n", total_income - total_expenses);
}

void save_plan_to_file(const FinancialPlan *plan, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Could not open file %s for writing.\n", filename);
        return;
    }

    fprintf(file, "Income Sources:\n");
    for (int i = 0; i < plan->income_count; i++) {
        fprintf(file, "%s: %.2f\n", plan->incomes[i].name, plan->incomes[i].amount);
    }

    fprintf(file, "\nExpenses:\n");
    for (int i = 0; i < plan->expense_count; i++) {
        fprintf(file, "%s: %.2f\n", plan->expenses[i].name, plan->expenses[i].amount);
    }

    fclose(file);
    printf("Financial plan saved to %s\n", filename);
}

void load_plan_from_file(FinancialPlan *plan, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file %s for reading.\n", filename);
        return;
    }

    plan->income_count = 0;
    plan->expense_count = 0;
    char line[100];
    
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Income Sources", 14) == 0) {
            while (fgets(line, sizeof(line), file) && strcmp(line, "\n") != 0) {
                char name[MAX_NAME_LENGTH];
                float amount;
                sscanf(line, "%[^:]: %f", name, &amount);
                add_income(plan, name, amount);
            }
        }
        if (strncmp(line, "Expenses", 8) == 0) {
            while (fgets(line, sizeof(line), file) && strcmp(line, "\n") != 0) {
                char name[MAX_NAME_LENGTH];
                float amount;
                sscanf(line, "%[^:]: %f", name, &amount);
                add_expense(plan, name, amount);
            }
        }
    }

    fclose(file);
    printf("Financial plan loaded from %s\n", filename);
}

int main() {
    FinancialPlan myFinance = { .income_count = 0, .expense_count = 0 };
    int choice;
    char name[MAX_NAME_LENGTH];
    float amount;

    while (1) {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Display Financial Plan\n");
        printf("4. Save to File\n");
        printf("5. Load from File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter income source name: ");
                scanf("%s", name);
                printf("Enter income amount: ");
                scanf("%f", &amount);
                add_income(&myFinance, name, amount);
                break;
            case 2:
                printf("Enter expense name: ");
                scanf("%s", name);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                add_expense(&myFinance, name, amount);
                break;
            case 3:
                display_financial_plan(&myFinance);
                break;
            case 4: {
                char filename[MAX_NAME_LENGTH];
                printf("Enter filename to save: ");
                scanf("%s", filename);
                save_plan_to_file(&myFinance, filename);
                break;
            }
            case 5: {
                char filename[MAX_NAME_LENGTH];
                printf("Enter filename to load: ");
                scanf("%s", filename);
                load_plan_from_file(&myFinance, filename);
                break;
            }
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}