//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_SIZE 30

typedef struct {
    char name[NAME_SIZE];
    float amount;
} Entry;

typedef struct {
    Entry income[MAX_ENTRIES];
    Entry expense[MAX_ENTRIES];
    int incomeCount;
    int expenseCount;
} FinanceManager;

void addIncome(FinanceManager *fm) {
    if (fm->incomeCount < MAX_ENTRIES) {
        printf("Enter income source: ");
        scanf("%s", fm->income[fm->incomeCount].name);
        printf("Enter amount: ");
        scanf("%f", &fm->income[fm->incomeCount].amount);
        fm->incomeCount++;
        printf("Income entry added!\n");
    } else {
        printf("Income entries are full!\n");
    }
}

void addExpense(FinanceManager *fm) {
    if (fm->expenseCount < MAX_ENTRIES) {
        printf("Enter expense name: ");
        scanf("%s", fm->expense[fm->expenseCount].name);
        printf("Enter amount: ");
        scanf("%f", &fm->expense[fm->expenseCount].amount);
        fm->expenseCount++;
        printf("Expense entry added!\n");
    } else {
        printf("Expense entries are full!\n");
    }
}

void viewEntries(FinanceManager *fm) {
    printf("\n--- Current Finances ---\n");
    
    printf("\nIncome Entries:\n");
    for (int i = 0; i < fm->incomeCount; i++) {
        printf("%s: $%.2f\n", fm->income[i].name, fm->income[i].amount);
    }
    
    printf("\nExpense Entries:\n");
    for (int i = 0; i < fm->expenseCount; i++) {
        printf("%s: $%.2f\n", fm->expense[i].name, fm->expense[i].amount);
    }
    
    float totalIncome = 0, totalExpense = 0;
    for (int i = 0; i < fm->incomeCount; i++) totalIncome += fm->income[i].amount;
    for (int i = 0; i < fm->expenseCount; i++) totalExpense += fm->expense[i].amount;
    
    printf("\nTotal Income: $%.2f\n", totalIncome);
    printf("Total Expenses: $%.2f\n", totalExpense);
    printf("Net Savings: $%.2f\n", totalIncome - totalExpense);
}

void clearEntries(FinanceManager *fm) {
    fm->incomeCount = 0;
    fm->expenseCount = 0;
    printf("All entries cleared!\n");
}

int main() {
    FinanceManager fm;
    fm.incomeCount = 0;
    fm.expenseCount = 0;
    int choice;
    
    do {
        printf("\n--- Personal Finance Planner Menu ---\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Entries\n");
        printf("4. Clear Entries\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addIncome(&fm);
                break;
            case 2:
                addExpense(&fm);
                break;
            case 3:
                viewEntries(&fm);
                break;
            case 4:
                clearEntries(&fm);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}