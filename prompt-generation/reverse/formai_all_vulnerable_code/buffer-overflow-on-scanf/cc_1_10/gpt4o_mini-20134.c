//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    float amount;
} Income;

typedef struct {
    char name[50];
    float amount;
} Expense;

Income incomes[MAX_ENTRIES];
Expense expenses[MAX_ENTRIES];
int incomeCount = 0;
int expenseCount = 0;

void addIncome() {
    if (incomeCount >= MAX_ENTRIES) {
        printf("Income limit reached!\n");
        return;
    }
    printf("Enter income title: ");
    scanf("%s", incomes[incomeCount].name);
    printf("Enter income amount: ");
    scanf("%f", &incomes[incomeCount].amount);
    incomeCount++;
    printf("Income added successfully!\n");
}

void addExpense() {
    if (expenseCount >= MAX_ENTRIES) {
        printf("Expense limit reached!\n");
        return;
    }
    printf("Enter expense title: ");
    scanf("%s", expenses[expenseCount].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[expenseCount].amount);
    expenseCount++;
    printf("Expense added successfully!\n");
}

void viewSummary() {
    float totalIncome = 0, totalExpenses = 0;

    printf("\n=== Financial Summary ===\n");
    
    printf("\n--- Incomes ---\n");
    for (int i = 0; i < incomeCount; i++) {
        printf("%s: $%.2f\n", incomes[i].name, incomes[i].amount);
        totalIncome += incomes[i].amount;
    }

    printf("\n--- Expenses ---\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("%s: $%.2f\n", expenses[i].name, expenses[i].amount);
        totalExpenses += expenses[i].amount;
    }

    printf("\nTotal Income: $%.2f\n", totalIncome);
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Net Savings: $%.2f\n", totalIncome - totalExpenses);
    
    printf("==========================\n");
}

void displayMenu() {
    printf("\n=== Personal Finance Planner ===\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. View Summary\n");
    printf("4. Exit\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addIncome();
            break;
        case 2:
            addExpense();
            break;
        case 3:
            viewSummary();
            break;
        case 4:
            printf("Thank you for using the Personal Finance Planner. Goodbye!\n");
            break;
        default:
            printf("Invalid choice! Please select again.\n");
            break;
        }
    } while (choice != 4);

    return 0;
}