//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_INCOME 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
} Income;

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
} Expense;

typedef struct {
    Income incomes[MAX_INCOME];
    int income_count;
    Expense expenses[MAX_EXPENSES];
    int expense_count;
} PersonalFinance;

void addIncome(PersonalFinance *pf);
void addExpense(PersonalFinance *pf);
void viewFinances(const PersonalFinance *pf);
void displaySummary(const PersonalFinance *pf);
void clearScreen();

int main() {
    PersonalFinance pf = { .income_count = 0, .expense_count = 0 };
    int choice;

    do {
        clearScreen();
        printf("=== Personal Finance Planner ===\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Finances\n");
        printf("4. Summary\n");
        printf("5. Exit\n");
        printf("===============================\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addIncome(&pf);
                break;
            case 2:
                addExpense(&pf);
                break;
            case 3:
                viewFinances(&pf);
                break;
            case 4:
                displaySummary(&pf);
                break;
            case 5:
                printf("Exiting the planner. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void clearScreen() {
    // ANSI escape codes to clear the console
    printf("\033[H\033[J");
}

void addIncome(PersonalFinance *pf) {
    if (pf->income_count < MAX_INCOME) {
        printf("Enter Income Name: ");
        scanf("%s", pf->incomes[pf->income_count].name);
        printf("Enter Income Amount: ");
        scanf("%f", &pf->incomes[pf->income_count].amount);
        pf->income_count++;
        printf("Income added successfully!\n");
    } else {
        printf("Income limit reached, cannot add more.\n");
    }
    getchar(); // To consume newline character from previous input
    printf("Press Enter to continue...");
    getchar(); // Wait for user input
}

void addExpense(PersonalFinance *pf) {
    if (pf->expense_count < MAX_EXPENSES) {
        printf("Enter Expense Name: ");
        scanf("%s", pf->expenses[pf->expense_count].name);
        printf("Enter Expense Amount: ");
        scanf("%f", &pf->expenses[pf->expense_count].amount);
        pf->expense_count++;
        printf("Expense added successfully!\n");
    } else {
        printf("Expense limit reached, cannot add more.\n");
    }
    getchar(); // To consume newline character from previous input
    printf("Press Enter to continue...");
    getchar(); // Wait for user input
}

void viewFinances(const PersonalFinance *pf) {
    printf("=== View Finances ===\n");
    
    printf("\nIncomes:\n");
    for (int i = 0; i < pf->income_count; i++) {
        printf("%s: %.2f\n", pf->incomes[i].name, pf->incomes[i].amount);
    }

    printf("\nExpenses:\n");
    for (int i = 0; i < pf->expense_count; i++) {
        printf("%s: %.2f\n", pf->expenses[i].name, pf->expenses[i].amount);
    }

    printf("Press Enter to continue...");
    getchar(); // Wait for user input
    getchar(); // To consume newline character from previous input
}

void displaySummary(const PersonalFinance *pf) {
    float total_income = 0, total_expenses = 0;

    for (int i = 0; i < pf->income_count; i++) {
        total_income += pf->incomes[i].amount;
    }
    
    for (int i = 0; i < pf->expense_count; i++) {
        total_expenses += pf->expenses[i].amount;
    }

    float balance = total_income - total_expenses;

    printf("=== Financial Summary ===\n");
    printf("Total Income: %.2f\n", total_income);
    printf("Total Expenses: %.2f\n", total_expenses);
    printf("Balance: %.2f\n", balance);
    if (balance < 0) {
        printf("You are in debt! Consider reviewing your expenses.\n");
    } else if (balance > 0) {
        printf("Great job! You have a positive balance.\n");
    } else {
        printf("You break even. Consider adjusting your budget.\n");
    }

    printf("Press Enter to continue...");
    getchar(); // Wait for user input
    getchar(); // To consume newline character from previous input
}