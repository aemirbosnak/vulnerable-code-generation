//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_EXPENSES 100
#define MAX_INCOME 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    float amount;
} Income;

typedef struct {
    char name[MAX_NAME_LEN];
    float amount;
} Expense;

typedef struct {
    Income incomes[MAX_INCOME];
    Expense expenses[MAX_EXPENSES];
    int incomeCount;
    int expenseCount;
} PersonalFinance;

void addIncome(PersonalFinance* pf, const char* name, float amount) {
    if (pf->incomeCount < MAX_INCOME) {
        snprintf(pf->incomes[pf->incomeCount].name, MAX_NAME_LEN, "%s", name);
        pf->incomes[pf->incomeCount].amount = amount;
        pf->incomeCount++;
        printf("Income added: %s - $%.2f\n", name, amount);
    } else {
        printf("Income limit reached. Cannot add more incomes.\n");
    }
}

void addExpense(PersonalFinance* pf, const char* name, float amount) {
    if (pf->expenseCount < MAX_EXPENSES) {
        snprintf(pf->expenses[pf->expenseCount].name, MAX_NAME_LEN, "%s", name);
        pf->expenses[pf->expenseCount].amount = amount;
        pf->expenseCount++;
        printf("Expense added: %s - $%.2f\n", name, amount);
    } else {
        printf("Expense limit reached. Cannot add more expenses.\n");
    }
}

float calculateTotalIncome(PersonalFinance* pf) {
    float total = 0.0;
    for (int i = 0; i < pf->incomeCount; i++) {
        total += pf->incomes[i].amount;
    }
    return total;
}

float calculateTotalExpenses(PersonalFinance* pf) {
    float total = 0.0;
    for (int i = 0; i < pf->expenseCount; i++) {
        total += pf->expenses[i].amount;
    }
    return total;
}

void displaySummary(PersonalFinance* pf) {
    printf("\n--- Financial Summary ---\n");
    printf("Total Income: $%.2f\n", calculateTotalIncome(pf));
    printf("Total Expenses: $%.2f\n", calculateTotalExpenses(pf));
    printf("Net Income: $%.2f\n", calculateTotalIncome(pf) - calculateTotalExpenses(pf));
}

void displayIncomes(PersonalFinance* pf) {
    printf("\n--- Incomes ---\n");
    for (int i = 0; i < pf->incomeCount; i++) {
        printf("%s: $%.2f\n", pf->incomes[i].name, pf->incomes[i].amount);
    }
}

void displayExpenses(PersonalFinance* pf) {
    printf("\n--- Expenses ---\n");
    for (int i = 0; i < pf->expenseCount; i++) {
        printf("%s: $%.2f\n", pf->expenses[i].name, pf->expenses[i].amount);
    }
}

void clearData(PersonalFinance* pf) {
    pf->incomeCount = 0;
    pf->expenseCount = 0;
    printf("All data has been cleared.\n");
}

int main() {
    PersonalFinance pf;
    pf.incomeCount = 0;
    pf.expenseCount = 0;

    int choice;
    do {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Display Summary\n");
        printf("4. Display Incomes\n");
        printf("5. Display Expenses\n");
        printf("6. Clear Data\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        char name[MAX_NAME_LEN];
        float amount;

        switch (choice) {
            case 1:
                printf("Enter Income Source: ");
                scanf("%s", name);
                printf("Enter Income Amount: ");
                scanf("%f", &amount);
                addIncome(&pf, name, amount);
                break;
            case 2:
                printf("Enter Expense Name: ");
                scanf("%s", name);
                printf("Enter Expense Amount: ");
                scanf("%f", &amount);
                addExpense(&pf, name, amount);
                break;
            case 3:
                displaySummary(&pf);
                break;
            case 4:
                displayIncomes(&pf);
                break;
            case 5:
                displayExpenses(&pf);
                break;
            case 6:
                clearData(&pf);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}