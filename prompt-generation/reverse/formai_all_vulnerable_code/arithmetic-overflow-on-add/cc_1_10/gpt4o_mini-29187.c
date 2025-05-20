//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float amount;
} Entry;

typedef struct {
    Entry income[MAX_ENTRIES];
    Entry expenses[MAX_ENTRIES];
    int incomeCount;
    int expenseCount;
    float budget;
} Finance;

void initializeFinance(Finance* finance) {
    finance->incomeCount = 0;
    finance->expenseCount = 0;
    finance->budget = 0.0;
}

void addIncome(Finance* finance) {
    if (finance->incomeCount >= MAX_ENTRIES) {
        printf("Income entry limit reached!\n");
        return;
    }
    printf("Enter income source name: ");
    scanf("%s", finance->income[finance->incomeCount].name);
    printf("Enter income amount: ");
    scanf("%f", &finance->income[finance->incomeCount].amount);
    finance->incomeCount++;
    printf("Income added successfully!\n");
}

void addExpense(Finance* finance) {
    if (finance->expenseCount >= MAX_ENTRIES) {
        printf("Expense entry limit reached!\n");
        return;
    }
    printf("Enter expense name: ");
    scanf("%s", finance->expenses[finance->expenseCount].name);
    printf("Enter expense amount: ");
    scanf("%f", &finance->expenses[finance->expenseCount].amount);
    finance->expenseCount++;
    printf("Expense added successfully!\n");
}

void viewTotals(Finance* finance) {
    float totalIncome = 0, totalExpenses = 0;

    for (int i = 0; i < finance->incomeCount; i++) {
        totalIncome += finance->income[i].amount;
    }

    for (int i = 0; i < finance->expenseCount; i++) {
        totalExpenses += finance->expenses[i].amount;
    }

    printf("\nTotal Income: $%.2f\n", totalIncome);
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Net Savings: $%.2f\n", totalIncome - totalExpenses);
}

void setBudget(Finance* finance) {
    printf("Enter your budget: ");
    scanf("%f", &finance->budget);
    printf("Budget set to $%.2f\n", finance->budget);
}

void generateReport(Finance* finance) {
    printf("\n--- Finance Report ---\n");
    printf("Budget: $%.2f\n", finance->budget);
    viewTotals(finance);
    
    printf("\n--- Income ---\n");
    for (int i = 0; i < finance->incomeCount; i++) {
        printf("%s: $%.2f\n", finance->income[i].name, finance->income[i].amount);
    }

    printf("\n--- Expenses ---\n");
    for (int i = 0; i < finance->expenseCount; i++) {
        printf("%s: $%.2f\n", finance->expenses[i].name, finance->expenses[i].amount);
    }
    printf("--- End of Report ---\n");
}

void displayMenu() {
    printf("\n--- Personal Finance Planner Menu ---\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. View Totals\n");
    printf("4. Set Budget\n");
    printf("5. Generate Report\n");
    printf("6. Exit\n");
    printf("Select an option: ");
}

int main() {
    Finance finance;
    initializeFinance(&finance);
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addIncome(&finance);
                break;
            case 2:
                addExpense(&finance);
                break;
            case 3:
                viewTotals(&finance);
                break;
            case 4:
                setBudget(&finance);
                break;
            case 5:
                generateReport(&finance);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}