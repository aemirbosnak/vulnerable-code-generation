//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    float amount;
} Expense;

typedef struct {
    char name[50];
    float amount;
} Income;

typedef struct {
    Income incomes[100];
    int incomeCount;
    Expense expenses[100];
    int expenseCount;
} FinancePlan;

void addIncome(FinancePlan *plan) {
    if (plan->incomeCount < 100) {
        printf("Enter income source: ");
        scanf("%s", plan->incomes[plan->incomeCount].name);
        printf("Enter amount: ");
        scanf("%f", &plan->incomes[plan->incomeCount].amount);
        plan->incomeCount++;
        printf("Income added successfully!\n");
    } else {
        printf("Maximum income entries reached!\n");
    }
}

void addExpense(FinancePlan *plan) {
    if (plan->expenseCount < 100) {
        printf("Enter expense name: ");
        scanf("%s", plan->expenses[plan->expenseCount].name);
        printf("Enter amount: ");
        scanf("%f", &plan->expenses[plan->expenseCount].amount);
        plan->expenseCount++;
        printf("Expense added successfully!\n");
    } else {
        printf("Maximum expense entries reached!\n");
    }
}

void displayIncome(FinancePlan *plan) {
    printf("\n--- INCOME REPORT ---\n");
    float totalIncome = 0.0;
    for (int i = 0; i < plan->incomeCount; i++) {
        printf("Source: %s, Amount: %.2f\n", plan->incomes[i].name, plan->incomes[i].amount);
        totalIncome += plan->incomes[i].amount;
    }
    printf("Total Income: %.2f\n", totalIncome);
}

void displayExpenses(FinancePlan *plan) {
    printf("\n--- EXPENSE REPORT ---\n");
    float totalExpenses = 0.0;
    for (int i = 0; i < plan->expenseCount; i++) {
        printf("Expense: %s, Amount: %.2f\n", plan->expenses[i].name, plan->expenses[i].amount);
        totalExpenses += plan->expenses[i].amount;
    }
    printf("Total Expenses: %.2f\n", totalExpenses);
}

void displayBalance(FinancePlan *plan) {
    float totalIncome = 0.0, totalExpenses = 0.0;
    for (int i = 0; i < plan->incomeCount; i++) {
        totalIncome += plan->incomes[i].amount;
    }
    for (int i = 0; i < plan->expenseCount; i++) {
        totalExpenses += plan->expenses[i].amount;
    }
    printf("\n--- BALANCE REPORT ---\n");
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expenses: %.2f\n", totalExpenses);
    printf("Balance: %.2f\n", totalIncome - totalExpenses);
}

void menu() {
    printf("\n=====================\n");
    printf("Personal Finance Planner\n");
    printf("=====================\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. Display Income\n");
    printf("4. Display Expenses\n");
    printf("5. Display Balance\n");
    printf("6. Exit\n");
    printf("=====================\n");
    printf("Choose an option: ");
}

int main() {
    FinancePlan plan = {{}, 0, {}, 0};
    int choice = 0;

    while (choice != 6) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addIncome(&plan);
                break;
            case 2:
                addExpense(&plan);
                break;
            case 3:
                displayIncome(&plan);
                break;
            case 4:
                displayExpenses(&plan);
                break;
            case 5:
                displayBalance(&plan);
                break;
            case 6:
                printf("Exiting the program! Take care of your finances!\n");
                break;
            default:
                printf("Invalid option! Try again!\n");
                break;
        }
    }

    return 0;
}