//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESCRIPTION 50

typedef struct {
    char description[MAX_DESCRIPTION];
    float amount;
    char date[11]; // Format: YYYY-MM-DD
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void initializeTracker(ExpenseTracker* tracker) {
    tracker->count = 0;
}

void addExpense(ExpenseTracker* tracker, const char* description, float amount, const char* date) {
    if (tracker->count < MAX_EXPENSES) {
        strncpy(tracker->expenses[tracker->count].description, description, MAX_DESCRIPTION);
        tracker->expenses[tracker->count].amount = amount;
        strncpy(tracker->expenses[tracker->count].date, date, 10);
        tracker->count++;
    } else {
        printf("Expense tracker is full! Cannot add more expenses.\n");
    }
}

void displayExpenses(const ExpenseTracker* tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    
    printf("\nExpenses:\n");
    printf("----------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s |\n", "Description", "Amount", "Date");
    printf("----------------------------------------------------\n");
    
    for (int i = 0; i < tracker->count; i++) {
        printf("| %-20s | $%-9.2f | %-10s |\n", 
               tracker->expenses[i].description, 
               tracker->expenses[i].amount, 
               tracker->expenses[i].date);
    }
    
    printf("----------------------------------------------------\n");
}

float calculateTotal(const ExpenseTracker* tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

void saveExpensesToFile(const ExpenseTracker* tracker, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Unable to open file for writing.\n");
        return;
    }
    
    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s,%f,%s\n", 
                tracker->expenses[i].description, 
                tracker->expenses[i].amount, 
                tracker->expenses[i].date);
    }
    
    fclose(file);
    printf("Expenses saved to %s\n", filename);
}

void loadExpensesFromFile(ExpenseTracker* tracker, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("No saved expenses found in %s. Starting fresh.\n", filename);
        return;
    }
    
    while (!feof(file) && tracker->count < MAX_EXPENSES) {
        Expense expense;
        char buffer[100];
        if (fgets(buffer, sizeof(buffer), file)) {
            sscanf(buffer, "%[^,],%f,%s", expense.description, &expense.amount, expense.date);
            addExpense(tracker, expense.description, expense.amount, expense.date);
        }
    }
    
    fclose(file);
    printf("Expenses loaded from %s\n", filename);
}

void menu() {
    printf("\nExpense Tracker Menu:\n");
    printf("1. Add Expense\n");
    printf("2. Display Expenses\n");
    printf("3. Total Expenses\n");
    printf("4. Save Expenses\n");
    printf("5. Load Expenses\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);
    
    int choice;
    char description[MAX_DESCRIPTION];
    float amount;
    char date[11];
    const char* filename = "expenses.txt";
    
    loadExpensesFromFile(&tracker, filename);
    
    while (1) {
        menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter description: ");
                scanf(" %49[^\n]", description); // Read string with spaces
                printf("Enter amount: ");
                scanf("%f", &amount);
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%10s", date);
                addExpense(&tracker, description, amount, date);
                break;
            case 2:
                displayExpenses(&tracker);
                break;
            case 3:
                printf("Total Expenses: $%.2f\n", calculateTotal(&tracker));
                break;
            case 4:
                saveExpensesToFile(&tracker, filename);
                break;
            case 5:
                loadExpensesFromFile(&tracker, filename);
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }
    
    return 0;
}