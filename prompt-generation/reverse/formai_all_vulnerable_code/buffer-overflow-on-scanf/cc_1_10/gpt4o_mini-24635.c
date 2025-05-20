//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
} Entry;

typedef struct {
    Entry income[MAX_ENTRIES];
    Entry expenses[MAX_ENTRIES];
    int incomeCount;
    int expenseCount;
} Finance;

void initializeFinance(Finance *finance) {
    finance->incomeCount = 0;
    finance->expenseCount = 0;
}

void addIncome(Finance *finance) {
    if (finance->incomeCount < MAX_ENTRIES) {
        Entry newEntry;
        printf("Enter income source: ");
        scanf("%s", newEntry.name);
        printf("Enter income amount: ");
        scanf("%f", &newEntry.amount);
        finance->income[finance->incomeCount++] = newEntry;
        printf("Income added successfully!\n");
    } else {
        printf("Income entries are full!\n");
    }
}

void addExpense(Finance *finance) {
    if (finance->expenseCount < MAX_ENTRIES) {
        Entry newEntry;
        printf("Enter expense source: ");
        scanf("%s", newEntry.name);
        printf("Enter expense amount: ");
        scanf("%f", &newEntry.amount);
        finance->expenses[finance->expenseCount++] = newEntry;
        printf("Expense added successfully!\n");
    } else {
        printf("Expense entries are full!\n");
    }
}

void viewSummary(Finance *finance) {
    float totalIncome = 0;
    float totalExpenses = 0;

    printf("\nIncome Summary:\n");
    for (int i = 0; i < finance->incomeCount; i++) {
        printf("%s: $%.2f\n", finance->income[i].name, finance->income[i].amount);
        totalIncome += finance->income[i].amount;
    }

    printf("\nExpense Summary:\n");
    for (int i = 0; i < finance->expenseCount; i++) {
        printf("%s: $%.2f\n", finance->expenses[i].name, finance->expenses[i].amount);
        totalExpenses += finance->expenses[i].amount;
    }

    printf("\nTotal Income: $%.2f\n", totalIncome);
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Remaining Balance: $%.2f\n", totalIncome - totalExpenses);
}

void displayMenu() {
    printf("\n=== SmartSaver Personal Finance Planner ===\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. View Summary\n");
    printf("4. Exit\n");
    printf("===========================================\n");
}

int main() {
    Finance finance;
    initializeFinance(&finance);
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addIncome(&finance);
                break;
            case 2:
                addExpense(&finance);
                break;
            case 3:
                viewSummary(&finance);
                break;
            case 4:
                printf("Thank you for using SmartSaver! Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}