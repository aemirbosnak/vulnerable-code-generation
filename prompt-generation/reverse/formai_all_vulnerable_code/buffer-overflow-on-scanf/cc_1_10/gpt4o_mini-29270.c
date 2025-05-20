//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: sophisticated
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
    IncomeSource income[MAX_INCOME_SOURCES];
    Expense expenses[MAX_EXPENSES];
    int incomeCount;
    int expenseCount;
} PersonalFinance;

void addIncome(PersonalFinance *pf) {
    if (pf->incomeCount >= MAX_INCOME_SOURCES) {
        printf("Cannot add more income sources.\n");
        return;
    }
    IncomeSource newIncome;
    printf("Enter income source name: ");
    scanf("%s", newIncome.name);
    printf("Enter amount: ");
    scanf("%f", &newIncome.amount);
    pf->income[pf->incomeCount++] = newIncome;
    printf("Income source added!\n");
}

void addExpense(PersonalFinance *pf) {
    if (pf->expenseCount >= MAX_EXPENSES) {
        printf("Cannot add more expenses.\n");
        return;
    }
    Expense newExpense;
    printf("Enter expense name: ");
    scanf("%s", newExpense.name);
    printf("Enter amount: ");
    scanf("%f", &newExpense.amount);
    pf->expenses[pf->expenseCount++] = newExpense;
    printf("Expense added!\n");
}

void displayFinanceReport(const PersonalFinance *pf) {
    float totalIncome = 0;
    float totalExpenses = 0;

    printf("\n--- Personal Finance Report ---\n");

    printf("Income Sources:\n");
    for (int i = 0; i < pf->incomeCount; i++) {
        printf("%s: $%.2f\n", pf->income[i].name, pf->income[i].amount);
        totalIncome += pf->income[i].amount;
    }

    printf("Total Income: $%.2f\n", totalIncome);

    printf("\nExpenses:\n");
    for (int i = 0; i < pf->expenseCount; i++) {
        printf("%s: $%.2f\n", pf->expenses[i].name, pf->expenses[i].amount);
        totalExpenses += pf->expenses[i].amount;
    }

    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Net Savings: $%.2f\n", totalIncome - totalExpenses);
}

void clearData(PersonalFinance *pf) {
    pf->incomeCount = 0;
    pf->expenseCount = 0;
    printf("All financial data cleared!\n");
}

void showMenu() {
    printf("\n--- Personal Finance Planner ---\n");
    printf("1. Add Income Source\n");
    printf("2. Add Expense\n");
    printf("3. Display Finance Report\n");
    printf("4. Clear All Data\n");
    printf("5. Exit\n");
    printf("-------------------------------\n");
}

int main() {
    PersonalFinance pf = { .incomeCount = 0, .expenseCount = 0 };
    int choice;

    while (1) {
        showMenu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addIncome(&pf);
                break;
            case 2:
                addExpense(&pf);
                break;
            case 3:
                displayFinanceReport(&pf);
                break;
            case 4:
                clearData(&pf);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }

    return 0;
}