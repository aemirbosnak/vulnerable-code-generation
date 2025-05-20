//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESC_LENGTH 50

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
    char category[MAX_DESC_LENGTH];
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void initializeTracker(ExpenseTracker* tracker) {
    tracker->count = 0;
}

void addExpense(ExpenseTracker* tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Expense tracker is full!\n");
        return;
    }
    
    Expense newExpense;
    printf("Enter expense description: ");
    scanf(" %[^\n]", newExpense.description);
    
    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);
    
    printf("Enter expense category: ");
    scanf(" %[^\n]", newExpense.category);
    
    tracker->expenses[tracker->count] = newExpense;
    tracker->count++;
    printf("Expense added!\n");
}

void displayExpenses(const ExpenseTracker* tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }

    printf("Your Expenses:\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Description: %s | Amount: %.2f | Category: %s\n", 
                tracker->expenses[i].description, 
                tracker->expenses[i].amount, 
                tracker->expenses[i].category);
    }
    printf("-------------------------------------------------\n");
}

void calculateTotalExpenses(const ExpenseTracker* tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    printf("Total Expenses: %.2f\n", total);
}

void saveExpensesToFile(const ExpenseTracker* tracker) {
    FILE* file = fopen("expenses.txt", "w");
    if (!file) {
        printf("Could not open file for writing.\n");
        return;
    }
    
    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s,%f,%s\n", tracker->expenses[i].description,
                tracker->expenses[i].amount, tracker->expenses[i].category);
    }
    
    fclose(file);
    printf("Expenses saved to expenses.txt\n");
}

void loadExpensesFromFile(ExpenseTracker* tracker) {
    FILE* file = fopen("expenses.txt", "r");
    if (!file) {
        printf("Could not open file for reading.\n");
        return;
    }

    while (!feof(file) && tracker->count < MAX_EXPENSES) {
        Expense loadedExpense;
        fscanf(file, " %49[^,],%f,%49[^\n]\n", loadedExpense.description, 
                &loadedExpense.amount, loadedExpense.category);
        tracker->expenses[tracker->count++] = loadedExpense;
    }

    fclose(file);
    printf("Expenses loaded from expenses.txt\n");
}

int main() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);
    
    int choice;
    do {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Calculate Total Expenses\n");
        printf("4. Save Expenses to File\n");
        printf("5. Load Expenses from File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                displayExpenses(&tracker);
                break;
            case 3:
                calculateTotalExpenses(&tracker);
                break;
            case 4:
                saveExpensesToFile(&tracker);
                break;
            case 5:
                loadExpensesFromFile(&tracker);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}