//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    double amount;
    char description[MAX_DESCRIPTION_LENGTH];
} Expense;

typedef struct {
    char name[MAX_NAME_LENGTH];
    double amount;
    char description[MAX_DESCRIPTION_LENGTH];
} Income;

typedef struct {
    Expense expenses[MAX_ENTRIES];
    Income incomes[MAX_ENTRIES];
    int expense_count;
    int income_count;
} PersonalFinance;

void add_income(PersonalFinance *pf) {
    if (pf->income_count >= MAX_ENTRIES) {
        printf("Income entry limit reached!\n");
        return;
    }
    Income new_income;
    printf("Enter income source name: ");
    scanf("%s", new_income.name);
    printf("Enter income amount: ");
    scanf("%lf", &new_income.amount);
    printf("Enter income description: ");
    getchar(); // To clear the newline after previous input
    fgets(new_income.description, MAX_DESCRIPTION_LENGTH, stdin);
    new_income.description[strcspn(new_income.description, "\n")] = 0; // Remove newline
    pf->incomes[pf->income_count++] = new_income;
    printf("Income added successfully!\n");
}

void add_expense(PersonalFinance *pf) {
    if (pf->expense_count >= MAX_ENTRIES) {
        printf("Expense entry limit reached!\n");
        return;
    }
    Expense new_expense;
    printf("Enter expense name: ");
    scanf("%s", new_expense.name);
    printf("Enter expense amount: ");
    scanf("%lf", &new_expense.amount);
    printf("Enter expense description: ");
    getchar(); // To clear the newline after previous input
    fgets(new_expense.description, MAX_DESCRIPTION_LENGTH, stdin);
    new_expense.description[strcspn(new_expense.description, "\n")] = 0; // Remove newline
    pf->expenses[pf->expense_count++] = new_expense;
    printf("Expense added successfully!\n");
}

void view_summary(PersonalFinance *pf) {
    double total_income = 0.0;
    double total_expense = 0.0;

    printf("\nIncome Summary:\n");
    for (int i = 0; i < pf->income_count; i++) {
        printf("Source: %s, Amount: %.2f, Description: %s\n", pf->incomes[i].name, pf->incomes[i].amount, pf->incomes[i].description);
        total_income += pf->incomes[i].amount;
    }

    printf("\nExpense Summary:\n");
    for (int i = 0; i < pf->expense_count; i++) {
        printf("Name: %s, Amount: %.2f, Description: %s\n", pf->expenses[i].name, pf->expenses[i].amount, pf->expenses[i].description);
        total_expense += pf->expenses[i].amount;
    }

    printf("\nTotal Income: %.2f\n", total_income);
    printf("Total Expense: %.2f\n", total_expense);
    printf("Net Savings: %.2f\n", total_income - total_expense);
}

void display_menu() {
    printf("\nPersonal Finance Planner Menu:\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. View Summary\n");
    printf("4. Exit\n");
}

int main() {
    PersonalFinance pf;
    pf.income_count = 0;
    pf.expense_count = 0;

    int choice;
    do {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_income(&pf);
                break;
            case 2:
                add_expense(&pf);
                break;
            case 3:
                view_summary(&pf);
                break;
            case 4:
                printf("Exiting... Stay Financially Savvy!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}