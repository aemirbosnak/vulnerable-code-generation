//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    float amount;
} Entry;

typedef struct {
    Entry incomes[MAX_ENTRIES];
    Entry expenses[MAX_ENTRIES];
    int incomeCount;
    int expenseCount;
    float savingsGoal;
    float currentSavings;
} FinancePlanner;

void initializePlanner(FinancePlanner *planner) {
    planner->incomeCount = 0;
    planner->expenseCount = 0;
    planner->savingsGoal = 0.0f;
    planner->currentSavings = 0.0f;
}

void addIncome(FinancePlanner *planner) {
    if (planner->incomeCount < MAX_ENTRIES) {
        printf("Enter income source: ");
        scanf("%s", planner->incomes[planner->incomeCount].name);
        printf("Enter income amount: ");
        scanf("%f", &planner->incomes[planner->incomeCount].amount);
        planner->currentSavings += planner->incomes[planner->incomeCount].amount;
        planner->incomeCount++;
        printf("Income added successfully!\n");
    } else {
        printf("Maximum income entries reached.\n");
    }
}

void addExpense(FinancePlanner *planner) {
    if (planner->expenseCount < MAX_ENTRIES) {
        printf("Enter expense name: ");
        scanf("%s", planner->expenses[planner->expenseCount].name);
        printf("Enter expense amount: ");
        scanf("%f", &planner->expenses[planner->expenseCount].amount);
        planner->currentSavings -= planner->expenses[planner->expenseCount].amount;
        planner->expenseCount++;
        printf("Expense added successfully!\n");
    } else {
        printf("Maximum expense entries reached.\n");
    }
}

void setSavingsGoal(FinancePlanner *planner) {
    printf("Enter your savings goal: ");
    scanf("%f", &planner->savingsGoal);
    printf("Savings goal set to: %.2f\n", planner->savingsGoal);
}

void printSummary(const FinancePlanner *planner) {
    printf("\n--- Financial Summary ---\n");
    printf("Current Savings: %.2f\n", planner->currentSavings);
    printf("Savings Goal: %.2f\n", planner->savingsGoal);
    printf("Incomes:\n");
    for (int i = 0; i < planner->incomeCount; i++) {
        printf("%s - %.2f\n", planner->incomes[i].name, planner->incomes[i].amount);
    }
    printf("Expenses:\n");
    for (int i = 0; i < planner->expenseCount; i++) {
        printf("%s - %.2f\n", planner->expenses[i].name, planner->expenses[i].amount);
    }
}

void runPlanner() {
    FinancePlanner planner;
    initializePlanner(&planner);
    int choice;

    do {
        printf("\n--- Personal Finance Planner ---\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Set Savings Goal\n");
        printf("4. Print Summary\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addIncome(&planner);
                break;
            case 2:
                addExpense(&planner);
                break;
            case 3:
                setSavingsGoal(&planner);
                break;
            case 4:
                printSummary(&planner);
                break;
            case 5:
                printf("Exiting the planner. Have a great day!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    runPlanner();
    return 0;
}