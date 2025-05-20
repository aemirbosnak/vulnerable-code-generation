//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_CATEGORIES 10

typedef struct {
    char name[30];
    float amount;
} Expense;

typedef struct {
    char name[30];
    float amount;
} Income;

typedef struct {
    Expense expenses[MAX_ENTRIES];
    Income incomes[MAX_ENTRIES];
    int expenseCount;
    int incomeCount;
} FinanceTracker;

void addExpense(FinanceTracker* tracker) {
    if(tracker->expenseCount < MAX_ENTRIES) {
        printf("Enter expense name: ");
        scanf("%s", tracker->expenses[tracker->expenseCount].name);
        printf("Enter expense amount: ");
        scanf("%f", &tracker->expenses[tracker->expenseCount].amount);
        tracker->expenseCount++;
    } else {
        printf("Expense limit reached!\n");
    }
}

void addIncome(FinanceTracker* tracker) {
    if(tracker->incomeCount < MAX_ENTRIES) {
        printf("Enter income source: ");
        scanf("%s", tracker->incomes[tracker->incomeCount].name);
        printf("Enter income amount: ");
        scanf("%f", &tracker->incomes[tracker->incomeCount].amount);
        tracker->incomeCount++;
    } else {
        printf("Income limit reached!\n");
    }
}

void displaySummary(FinanceTracker* tracker) {
    float totalExpenses = 0.0, totalIncome = 0.0;
    printf("\n--- Monthly Financial Summary ---\n");
    printf("Expenses:\n");
    for(int i = 0; i < tracker->expenseCount; i++) {
        printf("%s: $%.2f\n", tracker->expenses[i].name, tracker->expenses[i].amount);
        totalExpenses += tracker->expenses[i].amount;
    }

    printf("Total Expenses: $%.2f\n\n", totalExpenses);

    printf("Income:\n");
    for(int j = 0; j < tracker->incomeCount; j++) {
        printf("%s: $%.2f\n", tracker->incomes[j].name, tracker->incomes[j].amount);
        totalIncome += tracker->incomes[j].amount;
    }

    printf("Total Income: $%.2f\n\n", totalIncome);
    printf("Net Balance: $%.2f\n", totalIncome - totalExpenses);
}

int main() {
    FinanceTracker tracker = { .expenseCount = 0, .incomeCount = 0 };
    int choice;

    do {
        printf("\n--- Personal Finance Planner ---\n");
        printf("1. Add Expense\n");
        printf("2. Add Income\n");
        printf("3. Show Summary\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                addIncome(&tracker);
                break;
            case 3:
                displaySummary(&tracker);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 4);

    return 0;
}