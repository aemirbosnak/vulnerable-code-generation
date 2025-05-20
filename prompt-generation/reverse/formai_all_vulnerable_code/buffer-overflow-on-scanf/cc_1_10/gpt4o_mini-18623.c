//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_INCOME 100
#define MAX_CATEGORY 50
#define MAX_NAME 100

typedef struct {
    char name[MAX_NAME];
    float amount;
} Income;

typedef struct {
    char category[MAX_CATEGORY];
    float amount;
} Expense;

typedef struct {
    Income incomes[MAX_INCOME];
    int income_count;
    Expense expenses[MAX_EXPENSES];
    int expense_count;
} FinancePlanner;

void add_income(FinancePlanner *planner) {
    if (planner->income_count >= MAX_INCOME) {
        printf("Income limit reached. Cannot add more.\n");
        return;
    }
    
    printf("Enter income source: ");
    scanf("%s", planner->incomes[planner->income_count].name);
    
    printf("Enter amount: ");
    scanf("%f", &planner->incomes[planner->income_count].amount);
    
    planner->income_count++;
}

void add_expense(FinancePlanner *planner) {
    if (planner->expense_count >= MAX_EXPENSES) {
        printf("Expense limit reached. Cannot add more.\n");
        return;
    }
    
    printf("Enter expense category: ");
    scanf("%s", planner->expenses[planner->expense_count].category);
    
    printf("Enter amount: ");
    scanf("%f", &planner->expenses[planner->expense_count].amount);

    planner->expense_count++;
}

void view_summary(FinancePlanner *planner) {
    float total_income = 0.0;
    float total_expense = 0.0;

    printf("\n--- Income Summary ---\n");
    for (int i = 0; i < planner->income_count; i++) {
        printf("Source: %s, Amount: %.2f\n", planner->incomes[i].name, planner->incomes[i].amount);
        total_income += planner->incomes[i].amount;
    }

    printf("\n--- Expense Summary ---\n");
    for (int i = 0; i < planner->expense_count; i++) {
        printf("Category: %s, Amount: %.2f\n", planner->expenses[i].category, planner->expenses[i].amount);
        total_expense += planner->expenses[i].amount;
    }

    printf("\nTotal Income: %.2f\n", total_income);
    printf("Total Expense: %.2f\n", total_expense);
    printf("Net Savings: %.2f\n", total_income - total_expense);
}

void view_monthly_report(FinancePlanner *planner) {
    char month_name[20];
    int month, year;

    printf("Enter month (1-12): ");
    scanf("%d", &month);
    printf("Enter year (YYYY): ");
    scanf("%d", &year);
    
    printf("\n--- Monthly Report for %d/%d ---\n", month, year);
    view_summary(planner);
}

void save_data(FinancePlanner *planner) {
    FILE *file = fopen("finance_planner.dat", "wb");
    if (!file) {
        printf("Error saving data!\n");
        return;
    }

    fwrite(planner, sizeof(FinancePlanner), 1, file);
    fclose(file);
    printf("Data saved successfully.\n");
}

void load_data(FinancePlanner *planner) {
    FILE *file = fopen("finance_planner.dat", "rb");
    if (!file) {
        printf("No saved data found. Starting fresh.\n");
        return;
    }

    fread(planner, sizeof(FinancePlanner), 1, file);
    fclose(file);
    printf("Data loaded successfully.\n");
}

void display_menu() {
    printf("\n--- Personal Finance Planner ---\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. View Summary\n");
    printf("4. View Monthly Report\n");
    printf("5. Save Data\n");
    printf("6. Load Data\n");
    printf("7. Exit\n");
}

int main() {
    FinancePlanner planner;
    planner.income_count = 0;
    planner.expense_count = 0;
    
    load_data(&planner);

    int choice;
    do {
        display_menu();
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_income(&planner);
                break;
            case 2:
                add_expense(&planner);
                break;
            case 3:
                view_summary(&planner);
                break;
            case 4:
                view_monthly_report(&planner);
                break;
            case 5:
                save_data(&planner);
                break;
            case 6:
                load_data(&planner);
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid selection. Please try again.\n");
                break;
        }
    } while(choice != 7);

    return 0;
}