//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 100

typedef struct {
    char description[50];
    float amount;
} Entry;

typedef struct {
    Entry income[MAX_ENTRIES];
    Entry expenses[MAX_ENTRIES];
    int income_count;
    int expenses_count;
} Finance;

void addIncome(Finance *finance) {
    if (finance->income_count >= MAX_ENTRIES) {
        printf("Maximum income entries reached.\n");
        return;
    }
    printf("Enter income description: ");
    scanf("%s", finance->income[finance->income_count].description);
    printf("Enter income amount: ");
    scanf("%f", &finance->income[finance->income_count].amount);
    finance->income_count++;
}

void addExpense(Finance *finance) {
    if (finance->expenses_count >= MAX_ENTRIES) {
        printf("Maximum expense entries reached.\n");
        return;
    }
    printf("Enter expense description: ");
    scanf("%s", finance->expenses[finance->expenses_count].description);
    printf("Enter expense amount: ");
    scanf("%f", &finance->expenses[finance->expenses_count].amount);
    finance->expenses_count++;
}

void showReport(Finance *finance) {
    float total_income = 0, total_expenses = 0;

    printf("\n=== Financial Report ===\n");

    printf("Income:\n");
    for (int i = 0; i < finance->income_count; i++) {
        printf("%s: $%.2f\n", finance->income[i].description, finance->income[i].amount);
        total_income += finance->income[i].amount;
    }

    printf("\nExpenses:\n");
    for (int i = 0; i < finance->expenses_count; i++) {
        printf("%s: $%.2f\n", finance->expenses[i].description, finance->expenses[i].amount);
        total_expenses += finance->expenses[i].amount;
    }

    printf("\nTotal Income: $%.2f\n", total_income);
    printf("Total Expenses: $%.2f\n", total_expenses);
    printf("Net Savings: $%.2f\n", total_income - total_expenses);
}

int main() {
    Finance personalFinance = {0};
    int choice;

    while (1) {
        printf("\n=== Personal Finance Planner ===\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Show Report\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addIncome(&personalFinance);
                break;
            case 2:
                addExpense(&personalFinance);
                break;
            case 3:
                showReport(&personalFinance);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}