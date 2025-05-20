//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_STRING_LENGTH 100

typedef struct {
    char description[MAX_STRING_LENGTH];
    float amount;
    char category[MAX_STRING_LENGTH];
} BudgetEntry;

typedef struct {
    BudgetEntry entries[MAX_ENTRIES];
    int count;
} Budget;

void initializeBudget(Budget* budget) {
    budget->count = 0;
}

void addEntry(Budget* budget) {
    if (budget->count >= MAX_ENTRIES) {
        printf("Maximum number of entries reached.\n");
        return;
    }
    
    BudgetEntry entry;
    printf("Enter description: ");
    getchar(); // Clear newline character
    fgets(entry.description, MAX_STRING_LENGTH, stdin);
    entry.description[strcspn(entry.description, "\n")] = 0; // Remove newline
    
    printf("Enter amount: ");
    scanf("%f", &entry.amount);
    
    printf("Enter category: ");
    getchar(); // Clear newline character
    fgets(entry.category, MAX_STRING_LENGTH, stdin);
    entry.category[strcspn(entry.category, "\n")] = 0; // Remove newline

    budget->entries[budget->count] = entry;
    budget->count++;
    printf("Entry added successfully!\n");
}

void viewEntries(const Budget* budget) {
    printf("\n--- Budget Entries ---\n");
    for (int i = 0; i < budget->count; i++) {
        printf("Entry %d:\n", i + 1);
        printf("  Description: %s\n", budget->entries[i].description);
        printf("  Amount: %.2f\n", budget->entries[i].amount);
        printf("  Category: %s\n", budget->entries[i].category);
        printf("----------------------\n");
    }
}

void viewSummary(const Budget* budget) {
    float totalIncome = 0;
    float totalExpenses = 0;

    for (int i = 0; i < budget->count; i++) {
        if (budget->entries[i].amount > 0) {
            totalIncome += budget->entries[i].amount;
        } else {
            totalExpenses += -budget->entries[i].amount; // Convert to positive for expenses
        }
    }

    printf("\n--- Financial Summary ---\n");
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expenses: %.2f\n", totalExpenses);
    printf("Net Savings: %.2f\n", totalIncome - totalExpenses);
    printf("-------------------------\n");
}

void saveBudgetToFile(const Budget* budget, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for saving.\n");
        return;
    }
    
    for (int i = 0; i < budget->count; i++) {
        fprintf(file, "%s,%.2f,%s\n", budget->entries[i].description,
                budget->entries[i].amount, budget->entries[i].category);
    }
    fclose(file);
    printf("Budget saved to %s successfully!\n", filename);
}

void loadBudgetFromFile(Budget* budget, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file for loading.\n");
        return;
    }
    
    while (!feof(file) && budget->count < MAX_ENTRIES) {
        BudgetEntry entry;
        fscanf(file, "%99[^,],%f,%99[^\n]\n", entry.description, &entry.amount, entry.category);
        budget->entries[budget->count++] = entry;
    }
    fclose(file);
    printf("Budget loaded from %s successfully!\n", filename);
}

int main() {
    Budget myBudget;
    initializeBudget(&myBudget);
    int choice;
    
    do {
        printf("\n--- Personal Finance Planner ---\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. View Summary\n");
        printf("4. Save Budget to File\n");
        printf("5. Load Budget from File\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEntry(&myBudget);
                break;
            case 2:
                viewEntries(&myBudget);
                break;
            case 3:
                viewSummary(&myBudget);
                break;
            case 4: {
                char filename[MAX_STRING_LENGTH];
                printf("Enter filename to save: ");
                getchar(); // Clear the newline character
                fgets(filename, MAX_STRING_LENGTH, stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline
                saveBudgetToFile(&myBudget, filename);
                break;
            }
            case 5: {
                char filename[MAX_STRING_LENGTH];
                printf("Enter filename to load: ");
                getchar(); // Clear the newline character
                fgets(filename, MAX_STRING_LENGTH, stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline
                loadBudgetFromFile(&myBudget, filename);
                break;
            }
            case 6:
                printf("Exiting. Thank you for using the Personal Finance Planner!\n");
                break;
            default:
                printf("Invalid option. Please choose again.\n");
        }
    } while (choice != 6);

    return 0;
}