//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUDGET_ENTRIES 100
#define MAX_NAME_LENGTH 50

// Structures to hold budget entries
typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
} BudgetEntry;

typedef struct {
    BudgetEntry entries[MAX_BUDGET_ENTRIES];
    int count;
} Budget;

// Function declarations
void displayMenu();
void addExpense(Budget *budget);
void viewExpenses(Budget *budget);
void saveBudget(Budget *budget, const char *filename);
void loadBudget(Budget *budget, const char *filename);
void analyzeSpending(Budget *budget);

int main() {
    Budget budget = { .count = 0 };
    int choice;
    const char *filename = "budget.dat";

    // Load existing budget data
    loadBudget(&budget, filename);

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&budget);
                break;
            case 2:
                viewExpenses(&budget);
                break;
            case 3:
                analyzeSpending(&budget);
                break;
            case 4:
                saveBudget(&budget, filename);
                printf("Budget data saved successfully.\n");
                break;
            case 5:
                printf("Exiting the Personal Finance Planner...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void displayMenu() {
    printf("\nPersonal Finance Planner - Futuristic Edition\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Analyze Spending\n");
    printf("4. Save Budget\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void addExpense(Budget *budget) {
    if (budget->count >= MAX_BUDGET_ENTRIES) {
        printf("Budget limit reached! Cannot add more entries.\n");
        return;
    }

    BudgetEntry entry;
    printf("Enter the name of the expense: ");
    scanf("%s", entry.name);
    printf("Enter the amount: ");
    scanf("%f", &entry.amount);

    budget->entries[budget->count++] = entry;
    printf("Expense added successfully.\n");
}

void viewExpenses(Budget *budget) {
    if (budget->count == 0) {
        printf("No expenses to display.\n");
        return;
    }

    printf("\n--- Expenses ---\n");
    for (int i = 0; i < budget->count; i++) {
        printf("Expense %d: %s - $%.2f\n", i + 1, budget->entries[i].name, budget->entries[i].amount);
    }
    printf("-----------------\n");
}

void saveBudget(Budget *budget, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error saving budget data.\n");
        return;
    }
    fwrite(budget, sizeof(Budget), 1, file);
    fclose(file);
}

void loadBudget(Budget *budget, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file) {
        fread(budget, sizeof(Budget), 1, file);
        fclose(file);
    } else {
        printf("No previous budget data found. Starting fresh.\n");
    }
}

void analyzeSpending(Budget *budget) {
    if (budget->count == 0) {
        printf("No expenses recorded for analysis.\n");
        return;
    }

    float total = 0.0;
    for (int i = 0; i < budget->count; i++) {
        total += budget->entries[i].amount;
    }
    printf("Total spending: $%.2f\n", total);
    
    // Identify most expensive item
    float maxExpense = 0.0;
    char maxExpenseName[MAX_NAME_LENGTH] = "";
    
    for (int i = 0; i < budget->count; i++) {
        if (budget->entries[i].amount > maxExpense) {
            maxExpense = budget->entries[i].amount;
            strcpy(maxExpenseName, budget->entries[i].name);
        }
    }
    
    printf("Most expensive item: %s - $%.2f\n", maxExpenseName, maxExpense);
}