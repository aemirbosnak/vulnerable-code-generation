//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_CATEGORY_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
    char category[MAX_CATEGORY_LENGTH]; 
} Expense;

typedef struct {
    float totalExpenses;
    int numOfEntries;
    Expense entries[MAX_ENTRIES];
} PersonalFinance;

void addExpense(PersonalFinance *pf) {
    if (pf->numOfEntries >= MAX_ENTRIES) {
        printf("Expense limit reached! Unable to add more entries.\n");
        return;
    }

    Expense newExpense;
    printf("Enter expense description: ");
    getchar(); // Consume the newline character
    fgets(newExpense.description, MAX_DESCRIPTION_LENGTH, stdin);
    newExpense.description[strcspn(newExpense.description, "\n")] = 0; // Remove newline

    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);
    
    printf("Enter expense category: ");
    getchar(); // Consume the newline character
    fgets(newExpense.category, MAX_CATEGORY_LENGTH, stdin);
    newExpense.category[strcspn(newExpense.category, "\n")] = 0; // Remove newline

    pf->entries[pf->numOfEntries] = newExpense;
    pf->totalExpenses += newExpense.amount;
    pf->numOfEntries++;

    printf("Expense added successfully!\n");
}

void viewExpenses(PersonalFinance *pf) {
    printf("\nExpenses Overview:\n");
    printf("%-25s %-10s %-15s\n", "Description", "Amount", "Category");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < pf->numOfEntries; i++) {
        printf("%-25s $%-9.2f %-15s\n", pf->entries[i].description, pf->entries[i].amount, pf->entries[i].category);
    }
    printf("---------------------------------------------------\n");
    printf("Total Expenses: $%.2f\n", pf->totalExpenses);
}

void budgetAnalysis(PersonalFinance *pf) {
    if (pf->numOfEntries == 0) {
        printf("No expenses recorded to analyze.\n");
        return;
    }

    float averageExpense = pf->totalExpenses / pf->numOfEntries;
    printf("\nAverage Expense: $%.2f\n", averageExpense);
    printf("Total Expenses: $%.2f\n", pf->totalExpenses);
}

void clearEntries(PersonalFinance *pf) {
    pf->totalExpenses = 0;
    pf->numOfEntries = 0;
    printf("All entries cleared.\n");
}

int main() {
    PersonalFinance myFinance;
    myFinance.totalExpenses = 0;
    myFinance.numOfEntries = 0;

    int choice;

    do {
        printf("\n--- Personal Finance Planner ---\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Budget Analysis\n");
        printf("4. Clear Entries\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&myFinance);
                break;
            case 2:
                viewExpenses(&myFinance);
                break;
            case 3:
                budgetAnalysis(&myFinance);
                break;
            case 4:
                clearEntries(&myFinance);
                break;
            case 5:
                printf("Exiting. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}