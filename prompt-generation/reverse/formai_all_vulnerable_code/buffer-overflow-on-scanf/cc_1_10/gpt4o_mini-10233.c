//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define DATE_LENGTH 11

typedef struct {
    char name[NAME_LENGTH];
    float amount;
    char date[DATE_LENGTH];
} ExpenseEntry;

typedef struct {
    ExpenseEntry entries[MAX_ENTRIES];
    int totalEntries;
    float totalExpenses;
} FinancePlanner;

void initializePlanner(FinancePlanner *planner) {
    planner->totalEntries = 0;
    planner->totalExpenses = 0.0;
}

void addExpense(FinancePlanner *planner) {
    if (planner->totalEntries >= MAX_ENTRIES) {
        printf("Cannot add more expenses, limit reached!\n");
        return;
    }
    
    ExpenseEntry e;
    printf("Enter expense name: ");
    scanf("%s", e.name);
    printf("Enter amount: ");
    scanf("%f", &e.amount);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", e.date);
    
    planner->entries[planner->totalEntries] = e;
    planner->totalExpenses += e.amount;
    planner->totalEntries++;
    
    printf("Expense added successfully!\n");
}

void viewExpenses(const FinancePlanner *planner) {
    printf("---- Expense Overview ----\n");
    for (int i = 0; i < planner->totalEntries; i++) {
        printf("%s - %.2f on %s\n", planner->entries[i].name, planner->entries[i].amount, planner->entries[i].date);
    }
    printf("Total Expenses: %.2f\n", planner->totalExpenses);
}

void saveExpensesToFile(const FinancePlanner *planner) {
    FILE *file = fopen("expenses.txt", "w");
    if (!file) {
        printf("Error opening file for writing!\n");
        return;
    }
    
    for (int i = 0; i < planner->totalEntries; i++) {
        fprintf(file, "%s,%.2f,%s\n", planner->entries[i].name, planner->entries[i].amount, planner->entries[i].date);
    }
    
    fclose(file);
    printf("Expenses saved to expenses.txt\n");
}

void loadExpensesFromFile(FinancePlanner *planner) {
    FILE *file = fopen("expenses.txt", "r");
    if (!file) {
        printf("No saved expenses found!\n");
        return;
    }
    
    while (fscanf(file, "%[^,],%f,%s\n", planner->entries[planner->totalEntries].name, &planner->entries[planner->totalEntries].amount, planner->entries[planner->totalEntries].date) == 3) {
        planner->totalExpenses += planner->entries[planner->totalEntries].amount;
        planner->totalEntries++;
    }
    
    fclose(file);
    printf("Expenses loaded successfully!\n");
}

void displayMenu() {
    printf("\n--- Personal Finance Planner ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Save Expenses to File\n");
    printf("4. Load Expenses from File\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    FinancePlanner planner;
    initializePlanner(&planner);
    loadExpensesFromFile(&planner);
    
    int choice;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addExpense(&planner);
                break;
            case 2:
                viewExpenses(&planner);
                break;
            case 3:
                saveExpensesToFile(&planner);
                break;
            case 4:
                loadExpensesFromFile(&planner);
                break;
            case 5:
                printf("Exiting the Personal Finance Planner. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}