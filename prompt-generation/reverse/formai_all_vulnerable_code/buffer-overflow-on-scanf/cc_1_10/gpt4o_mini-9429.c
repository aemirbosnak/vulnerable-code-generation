//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_CATEGORY_LENGTH 30
#define MAX_DESC_LENGTH 100

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
    char category[MAX_CATEGORY_LENGTH];
} Expense;

typedef struct {
    float totalExpenses;
    float totalIncome;
    Expense expenses[MAX_ENTRIES];
    int expenseCount;
} FinanceManager;

void initFinanceManager(FinanceManager* manager) {
    manager->totalExpenses = 0;
    manager->totalIncome = 0;
    manager->expenseCount = 0;
}

void addExpense(FinanceManager* manager) {
    if (manager->expenseCount >= MAX_ENTRIES) {
        printf("Expense limit reached!\n");
        return;
    }
    Expense newExpense;
    printf("Enter expense description: ");
    getchar(); // consume newline
    fgets(newExpense.description, MAX_DESC_LENGTH, stdin);
    newExpense.description[strcspn(newExpense.description, "\n")] = 0; // remove newline

    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);

    printf("Enter expense category: ");
    getchar(); // consume newline
    fgets(newExpense.category, MAX_CATEGORY_LENGTH, stdin);
    newExpense.category[strcspn(newExpense.category, "\n")] = 0; // remove newline

    manager->expenses[manager->expenseCount] = newExpense;
    manager->totalExpenses += newExpense.amount;
    manager->expenseCount++;
    printf("Expense added successfully.\n");
}

void addIncome(FinanceManager* manager) {
    float income;
    printf("Enter income amount: ");
    scanf("%f", &income);
    manager->totalIncome += income;
    printf("Income added successfully.\n");
}

void displaySummary(FinanceManager* manager) {
    printf("Financial Summary:\n");
    printf("Total Income: %.2f\n", manager->totalIncome);
    printf("Total Expenses: %.2f\n", manager->totalExpenses);
    printf("Net Savings: %.2f\n", manager->totalIncome - manager->totalExpenses);
    printf("\nExpense Breakdown:\n");

    for (int i = 0; i < manager->expenseCount; i++) {
        printf("Description: %s | Amount: %.2f | Category: %s\n",
            manager->expenses[i].description,
            manager->expenses[i].amount,
            manager->expenses[i].category);
    }
}

int main() {
    FinanceManager manager;
    initFinanceManager(&manager);
    int choice;

    do {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Expense\n");
        printf("2. Add Income\n");
        printf("3. Display Summary\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&manager);
                break;
            case 2:
                addIncome(&manager);
                break;
            case 3:
                displaySummary(&manager);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}