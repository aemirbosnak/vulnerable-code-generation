//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_DESC_LEN 50

typedef struct {
    char description[MAX_DESC_LEN];
    float amount;
} Entry;

typedef struct {
    Entry entries[MAX_ENTRIES];
    int count;
    float totalIncome;
    float totalExpenses;
    float savingsGoal;
    float currentSavings;
} FinancePlanner;

void initializePlanner(FinancePlanner* planner) {
    planner->count = 0;
    planner->totalIncome = 0.0f;
    planner->totalExpenses = 0.0f;
    planner->savingsGoal = 0.0f;
    planner->currentSavings = 0.0f;
}

void addIncome(FinancePlanner* planner, const char* description, float amount) {
    if (planner->count < MAX_ENTRIES) {
        strcpy(planner->entries[planner->count].description, description);
        planner->entries[planner->count].amount = amount;
        planner->totalIncome += amount;
        planner->count++;
    } else {
        printf("Income entries limit reached.\n");
    }
}

void addExpense(FinancePlanner* planner, const char* description, float amount) {
    if (planner->count < MAX_ENTRIES) {
        strcpy(planner->entries[planner->count].description, description);
        planner->entries[planner->count].amount = -amount;
        planner->totalExpenses += amount;
        planner->count++;
    } else {
        printf("Expense entries limit reached.\n");
    }
}

void setSavingsGoal(FinancePlanner* planner, float goal) {
    planner->savingsGoal = goal;
}

void updateCurrentSavings(FinancePlanner* planner, float amount) {
    planner->currentSavings += amount;
}

void displaySummary(const FinancePlanner* planner) {
    printf("\n--- Financial Summary ---\n");
    printf("Total Income: $%.2f\n", planner->totalIncome);
    printf("Total Expenses: $%.2f\n", planner->totalExpenses);
    printf("Savings Goal: $%.2f\n", planner->savingsGoal);
    printf("Current Savings: $%.2f\n", planner->currentSavings);
    printf("Remaining Savings to Goal: $%.2f\n", planner->savingsGoal - planner->currentSavings);
    printf("-------------------------\n\n");
}

void displayEntries(const FinancePlanner* planner) {
    printf("\n--- Entries ---\n");
    for (int i = 0; i < planner->count; i++) {
        printf("%s: $%.2f\n", planner->entries[i].description, planner->entries[i].amount);
    }
    printf("-------------------------\n\n");
}

void saveToFile(const FinancePlanner* planner) {
    FILE* file = fopen("finance_data.txt", "w");
    if (file == NULL) {
        printf("Error saving to file.\n");
        return;
    }

    fprintf(file, "Total Income: $%.2f\n", planner->totalIncome);
    fprintf(file, "Total Expenses: $%.2f\n", planner->totalExpenses);
    fprintf(file, "Savings Goal: $%.2f\n", planner->savingsGoal);
    fprintf(file, "Current Savings: $%.2f\n", planner->currentSavings);
    fprintf(file, "Entries:\n");

    for (int i = 0; i < planner->count; i++) {
        fprintf(file, "%s: $%.2f\n", planner->entries[i].description, planner->entries[i].amount);
    }

    fclose(file);
    printf("Data saved to finance_data.txt\n");
}

int main() {
    FinancePlanner planner;
    initializePlanner(&planner);

    int choice;
    char description[MAX_DESC_LEN];
    float amount;

    do {
        printf("\n--- Personal Finance Planner ---\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Set Savings Goal\n");
        printf("4. Update Current Savings\n");
        printf("5. Display Summary\n");
        printf("6. Display Entries\n");
        printf("7. Save to File\n");
        printf("8. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter income description: ");
                scanf("%s", description);
                printf("Enter income amount: ");
                scanf("%f", &amount);
                addIncome(&planner, description, amount);
                break;
            case 2:
                printf("Enter expense description: ");
                scanf("%s", description);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                addExpense(&planner, description, amount);
                break;
            case 3:
                printf("Enter savings goal: ");
                scanf("%f", &amount);
                setSavingsGoal(&planner, amount);
                break;
            case 4:
                printf("Enter current savings addition: ");
                scanf("%f", &amount);
                updateCurrentSavings(&planner, amount);
                break;
            case 5:
                displaySummary(&planner);
                break;
            case 6:
                displayEntries(&planner);
                break;
            case 7:
                saveToFile(&planner);
                break;
            case 8:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }

    } while (choice != 8);

    return 0;
}