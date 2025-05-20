//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define DESCRIPTION_LENGTH 50

typedef struct {
    char description[DESCRIPTION_LENGTH];
    float amount;
    char category[DESCRIPTION_LENGTH];
} Expense;

typedef struct {
    Expense entries[MAX_ENTRIES];
    int count;
} ExpenseTracker;

void initializeTracker(ExpenseTracker *tracker) {
    tracker->count = 0;
}

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Expense tracker is full. Cannot add more expenses.\n");
        return;
    }
    
    Expense newExpense;
    
    printf("Enter expense description: ");
    getchar(); // Clear input buffer
    fgets(newExpense.description, DESCRIPTION_LENGTH, stdin);
    newExpense.description[strcspn(newExpense.description, "\n")] = 0; // Remove newline
    
    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);
    
    printf("Enter expense category: ");
    getchar(); // Clear input buffer
    fgets(newExpense.category, DESCRIPTION_LENGTH, stdin);
    newExpense.category[strcspn(newExpense.category, "\n")] = 0; // Remove newline
    
    tracker->entries[tracker->count] = newExpense;
    tracker->count++;
    printf("Expense added successfully!\n");
}

void viewExpenses(const ExpenseTracker *tracker) {
    printf("\n--- Expense List ---\n");
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    for (int i = 0; i < tracker->count; i++) {
        printf("Expense %d: %s - %.2f | Category: %s\n", 
               i + 1, tracker->entries[i].description, 
               tracker->entries[i].amount, 
               tracker->entries[i].category);
    }
}

float calculateTotalExpenses(const ExpenseTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->entries[i].amount;
    }
    return total;
}

void saveToFile(const ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s|%.2f|%s\n", 
                tracker->entries[i].description,
                tracker->entries[i].amount,
                tracker->entries[i].category);
    }

    fclose(file);
    printf("Expenses saved to expenses.txt\n");
}

void loadFromFile(ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "r");
    if (!file) {
        printf("No previous expenses found or error accessing file.\n");
        return;
    }

    while (tracker->count < MAX_ENTRIES && !feof(file)) {
        Expense newExpense;
        fscanf(file, "%49[^|]|%f|%49[^\n]\n", 
               newExpense.description, 
               &newExpense.amount, 
               newExpense.category);
        tracker->entries[tracker->count] = newExpense;
        tracker->count++;
    }

    fclose(file);
    printf("Expenses loaded successfully!\n");
}

void displayMenu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Save Expenses to File\n");
    printf("5. Load Expenses from File\n");
    printf("6. Exit\n");
}

int main() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);
    loadFromFile(&tracker);

    int choice;
    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                viewExpenses(&tracker);
                break;
            case 3: {
                float total = calculateTotalExpenses(&tracker);
                printf("Total Expenses: %.2f\n", total);
                break;
            }
            case 4:
                saveToFile(&tracker);
                break;
            case 5:
                loadFromFile(&tracker);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}