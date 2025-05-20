//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_DESC_LENGTH 50

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
} Entry;

typedef struct {
    Entry income[MAX_ENTRIES];
    Entry expenses[MAX_ENTRIES];
    int incomeCount;
    int expenseCount;
} FinanceTracker;

void addIncome(FinanceTracker *tracker) {
    if (tracker->incomeCount >= MAX_ENTRIES) {
        printf("Income entries full!\n");
        return;
    }
    Entry newIncome;
    printf("Enter income description: ");
    scanf(" %[^\n]", newIncome.description);
    printf("Enter income amount: ");
    scanf("%f", &newIncome.amount);
    
    tracker->income[tracker->incomeCount] = newIncome;
    tracker->incomeCount++;
    printf("Income added successfully!\n");
}

void addExpense(FinanceTracker *tracker) {
    if (tracker->expenseCount >= MAX_ENTRIES) {
        printf("Expense entries full!\n");
        return;
    }
    Entry newExpense;
    printf("Enter expense description: ");
    scanf(" %[^\n]", newExpense.description);
    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);
    
    tracker->expenses[tracker->expenseCount] = newExpense;
    tracker->expenseCount++;
    printf("Expense added successfully!\n");
}

void viewReport(FinanceTracker *tracker) {
    float totalIncome = 0, totalExpenses = 0;
    
    printf("\n--- Income Report ---\n");
    for (int i = 0; i < tracker->incomeCount; i++) {
        printf("%s: $%.2f\n", tracker->income[i].description, tracker->income[i].amount);
        totalIncome += tracker->income[i].amount;
    }
    printf("Total Income: $%.2f\n", totalIncome);
    
    printf("\n--- Expense Report ---\n");
    for (int i = 0; i < tracker->expenseCount; i++) {
        printf("%s: $%.2f\n", tracker->expenses[i].description, tracker->expenses[i].amount);
        totalExpenses += tracker->expenses[i].amount;
    }
    printf("Total Expenses: $%.2f\n", totalExpenses);
    
    printf("\n--- Financial Summary ---\n");
    printf("Net Amount: $%.2f\n", totalIncome - totalExpenses);
}

void saveData(FinanceTracker *tracker) {
    FILE *file = fopen("finance_data.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    fprintf(file, "%d\n", tracker->incomeCount);
    for (int i = 0; i < tracker->incomeCount; i++) {
        fprintf(file, "%s,%.2f\n", tracker->income[i].description, tracker->income[i].amount);
    }

    fprintf(file, "%d\n", tracker->expenseCount);
    for (int i = 0; i < tracker->expenseCount; i++) {
        fprintf(file, "%s,%.2f\n", tracker->expenses[i].description, tracker->expenses[i].amount);
    }
    
    fclose(file);
    printf("Data saved successfully!\n");
}

void loadData(FinanceTracker *tracker) {
    FILE *file = fopen("finance_data.txt", "r");
    if (file == NULL) {
        printf("No existing data found.\n");
        return;
    }

    fscanf(file, "%d", &tracker->incomeCount);
    for (int i = 0; i < tracker->incomeCount; i++) {
        fscanf(file, " %[^\n],%f", tracker->income[i].description, &tracker->income[i].amount);
    }

    fscanf(file, "%d", &tracker->expenseCount);
    for (int i = 0; i < tracker->expenseCount; i++) {
        fscanf(file, " %[^\n],%f", tracker->expenses[i].description, &tracker->expenses[i].amount);
    }
    
    fclose(file);
    printf("Data loaded successfully!\n");
}

int main() {
    FinanceTracker tracker = {0};
    int choice;

    loadData(&tracker);

    do {
        printf("\n--- Personal Finance Planner ---\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Report\n");
        printf("4. Save Data\n");
        printf("5. Load Data\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addIncome(&tracker);
                break;
            case 2:
                addExpense(&tracker);
                break;
            case 3:
                viewReport(&tracker);
                break;
            case 4:
                saveData(&tracker);
                break;
            case 5:
                loadData(&tracker);
                break;
            case 6:
                printf("Exiting program. Bye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}