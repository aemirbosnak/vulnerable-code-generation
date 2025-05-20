//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESCRIPTION_LENGTH 50
#define MAX_EXPENSES 100

typedef struct {
    char description[MAX_DESCRIPTION_LENGTH]; 
    float amount; 
    char date[11]; // Format: YYYY-MM-DD
} Expense;

typedef struct {
    Expense *expenses; 
    int count;      
} ExpenseTracker;

void initializeTracker(ExpenseTracker *tracker) {
    tracker->expenses = malloc(MAX_EXPENSES * sizeof(Expense));
    tracker->count = 0;
}

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Cannot add more expenses. Maximum limit reached.\n");
        return;
    }
    
    printf("Enter expense description: ");
    scanf(" %[^\n]", tracker->expenses[tracker->count].description);
    printf("Enter expense amount: ");
    scanf("%f", &tracker->expenses[tracker->count].amount);
    printf("Enter date (YYYY-MM-DD): ");
    scanf(" %10s", tracker->expenses[tracker->count].date);
    
    tracker->count++;
    printf("Expense added successfully!\n");
}

void displayExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    
    printf("\n--- Expense List ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Description: %s\nAmount: %.2f\nDate: %s\n\n", 
                tracker->expenses[i].description, 
                tracker->expenses[i].amount, 
                tracker->expenses[i].date);
    }
}

void saveExpensesToFile(const ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "a");
    
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s,%f,%s\n", 
                tracker->expenses[i].description, 
                tracker->expenses[i].amount, 
                tracker->expenses[i].date);
    }
    
    fclose(file);
    printf("Expenses saved to expenses.txt successfully!\n");
}

void loadExpensesFromFile(ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "r");
    
    if (file == NULL) {
        printf("No expense file found. Starting fresh!\n");
        return;
    }
    
    while (fscanf(file, " %49[^,],%f,%10s\n", 
                  tracker->expenses[tracker->count].description, 
                  &tracker->expenses[tracker->count].amount, 
                  tracker->expenses[tracker->count].date) == 3) {
        tracker->count++;
        if (tracker->count >= MAX_EXPENSES) {
            printf("Maximum expense limit reached while loading. Some expenses may not be loaded.\n");
            break;
        }
    }
    
    fclose(file);
    printf("Expenses loaded from expenses.txt successfully!\n");
}

void freeTracker(ExpenseTracker *tracker) {
    free(tracker->expenses);
}

int main() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);
    loadExpensesFromFile(&tracker);
    
    int choice;
    do {
        printf("\n--- Expense Tracker Menu ---\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Save Expenses to File\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                displayExpenses(&tracker);
                break;
            case 3:
                saveExpensesToFile(&tracker);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (choice != 4);
    
    freeTracker(&tracker);
    return 0;
}