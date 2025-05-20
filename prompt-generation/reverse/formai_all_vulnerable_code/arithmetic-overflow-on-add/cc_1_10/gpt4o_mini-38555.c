//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char description[50];
    double amount;
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
        printf("Enter income description: ");
        scanf("%s", finance->income[finance->incomeCount].description);
        printf("Enter income amount: ");
        scanf("%lf", &finance->income[finance->incomeCount].amount);
        finance->incomeCount++;
        printf("Income added successfully!\n");
    } else {
        printf("Income entries full!\n");
    }
}

void addExpense(Finance *finance) {
    if (finance->expenseCount < MAX_ENTRIES) {
        printf("Enter expense description: ");
        scanf("%s", finance->expenses[finance->expenseCount].description);
        printf("Enter expense amount: ");
        scanf("%lf", &finance->expenses[finance->expenseCount].amount);
        finance->expenseCount++;
        printf("Expense added successfully!\n");
    } else {
        printf("Expense entries full!\n");
    }
}

void displaySummary(const Finance *finance) {
    double totalIncome = 0;
    double totalExpense = 0;

    printf("\n--- Income Summary ---\n");
    for (int i = 0; i < finance->incomeCount; i++) {
        printf("%s: %.2f\n", finance->income[i].description, finance->income[i].amount);
        totalIncome += finance->income[i].amount;
    }

    printf("\n--- Expense Summary ---\n");
    for (int i = 0; i < finance->expenseCount; i++) {
        printf("%s: %.2f\n", finance->expenses[i].description, finance->expenses[i].amount);
        totalExpense += finance->expenses[i].amount;
    }

    printf("\nTotal Income: %.2f\n", totalIncome);
    printf("Total Expenses: %.2f\n", totalExpense);
    printf("Net Savings: %.2f\n", totalIncome - totalExpense);
}

void displayMenu() {
    printf("\n--- Personal Finance Planner ---\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. Display Summary\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    Finance finance;
    initializeFinance(&finance);

    int choice;
    do {
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
                displaySummary(&finance);
                break;
            case 4:
                printf("Thank you for using the Personal Finance Planner!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 4);

    return 0;
}