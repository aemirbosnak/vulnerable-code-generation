//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 50
#define MAX_INCOMES 20
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
} Income;

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
} Expense;

void displayMenu() {
    printf("\n=== Personal Finance Planner ===\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. Display Summary\n");
    printf("4. Set Savings Goal\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

void addIncome(Income incomes[], int *incomeCount) {
    if (*incomeCount < MAX_INCOMES) {
        printf("Enter income source: ");
        scanf("%s", incomes[*incomeCount].name);
        printf("Enter income amount: ");
        scanf("%f", &incomes[*incomeCount].amount);
        (*incomeCount)++;
        printf("Income added successfully!\n");
    } else {
        printf("Income list is full! Cannot add more incomes.\n");
    }
}

void addExpense(Expense expenses[], int *expenseCount) {
    if (*expenseCount < MAX_EXPENSES) {
        printf("Enter expense name: ");
        scanf("%s", expenses[*expenseCount].name);
        printf("Enter expense amount: ");
        scanf("%f", &expenses[*expenseCount].amount);
        (*expenseCount)++;
        printf("Expense added successfully!\n");
    } else {
        printf("Expense list is full! Cannot add more expenses.\n");
    }
}

void displaySummary(Income incomes[], int incomeCount, Expense expenses[], int expenseCount, float savingsGoal) {
    float totalIncome = 0, totalExpenses = 0;
    printf("\n=== Financial Summary ===\n");
    printf("Income Sources:\n");
    for (int i = 0; i < incomeCount; i++) {
        printf(" - %s: $%.2f\n", incomes[i].name, incomes[i].amount);
        totalIncome += incomes[i].amount;
    }

    printf("\nExpense List:\n");
    for (int i = 0; i < expenseCount; i++) {
        printf(" - %s: $%.2f\n", expenses[i].name, expenses[i].amount);
        totalExpenses += expenses[i].amount;
    }

    printf("\nTotal Income: $%.2f\n", totalIncome);
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Net Savings: $%.2f\n", totalIncome - totalExpenses);
    printf("Savings Goal: $%.2f\n", savingsGoal);
    
    if (totalIncome - totalExpenses >= savingsGoal) {
        printf("Congratulations! You are on track to meet your savings goal!\n");
    } else {
        printf("You need to save more to reach your goal!\n");
    }
}

int main() {
    Income incomes[MAX_INCOMES];
    Expense expenses[MAX_EXPENSES];
    int incomeCount = 0, expenseCount = 0;
    float savingsGoal = 0;
    int option;

    printf("Welcome to the Personal Finance Planner!\n");
    
    do {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                addIncome(incomes, &incomeCount);
                break;
            case 2:
                addExpense(expenses, &expenseCount);
                break;
            case 3:
                displaySummary(incomes, incomeCount, expenses, expenseCount, savingsGoal);
                break;
            case 4:
                printf("Set your savings goal amount: ");
                scanf("%f", &savingsGoal);
                printf("Savings goal set to $%.2f\n", savingsGoal);
                break;
            case 5:
                printf("Thank you for using the Personal Finance Planner! Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please select again.\n");
        }
    } while (option != 5);

    return 0;
}