//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 30

typedef struct {
    char description[NAME_LENGTH];
    float amount;
} Entry;

typedef struct {
    Entry income[MAX_ENTRIES];
    Entry expenses[MAX_ENTRIES];
    int income_count;
    int expense_count;
} FinancePlanner;

void addIncome(FinancePlanner *planner) {
    if (planner->income_count >= MAX_ENTRIES) {
        printf("Income entries are full! Please delete an entry.\n");
        return;
    }
    
    printf("Enter income description: ");
    scanf(" %[^\n]s", planner->income[planner->income_count].description);
    printf("Enter income amount: ");
    scanf("%f", &planner->income[planner->income_count].amount);
    
    planner->income_count++;
    printf("Income added successfully!\n");
}

void addExpense(FinancePlanner *planner) {
    if (planner->expense_count >= MAX_ENTRIES) {
        printf("Expense entries are full! Please delete an entry.\n");
        return;
    }
    
    printf("Enter expense description: ");
    scanf(" %[^\n]s", planner->expenses[planner->expense_count].description);
    printf("Enter expense amount: ");
    scanf("%f", &planner->expenses[planner->expense_count].amount);
    
    planner->expense_count++;
    printf("Expense added successfully!\n");
}

void viewIncome(FinancePlanner *planner) {
    printf("\n----- Income Entries -----\n");
    for (int i = 0; i < planner->income_count; i++) {
        printf("%d. %s: $%.2f\n", i + 1, planner->income[i].description, planner->income[i].amount);
    }
}

void viewExpenses(FinancePlanner *planner) {
    printf("\n----- Expense Entries -----\n");
    for (int i = 0; i < planner->expense_count; i++) {
        printf("%d. %s: $%.2f\n", i + 1, planner->expenses[i].description, planner->expenses[i].amount);
    }
}

void viewSummary(FinancePlanner *planner) {
    float total_income = 0;
    float total_expense = 0;

    for (int i = 0; i < planner->income_count; i++) {
        total_income += planner->income[i].amount;
    }

    for (int i = 0; i < planner->expense_count; i++) {
        total_expense += planner->expenses[i].amount;
    }

    printf("\n----- Financial Summary -----\n");
    printf("Total Income: $%.2f\n", total_income);
    printf("Total Expenses: $%.2f\n", total_expense);
    printf("Net Savings: $%.2f\n", total_income - total_expense);
}

void menu() {
    printf("\n--- Personal Finance Planner ---\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. View Income\n");
    printf("4. View Expenses\n");
    printf("5. View Summary\n");
    printf("6. Exit\n");
}

int main() {
    FinancePlanner planner;
    planner.income_count = 0;
    planner.expense_count = 0;

    int choice;
    do {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addIncome(&planner);
                break;
            case 2:
                addExpense(&planner);
                break;
            case 3:
                viewIncome(&planner);
                break;
            case 4:
                viewExpenses(&planner);
                break;
            case 5:
                viewSummary(&planner);
                break;
            case 6:
                printf("Exiting. Have a great day!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}