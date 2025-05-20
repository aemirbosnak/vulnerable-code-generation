//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void initializeTracker(ExpenseTracker* tracker) {
    tracker->count = 0;
}

void addExpense(ExpenseTracker* tracker, const char* name, float amount) {
    if (tracker->count < MAX_EXPENSES) {
        strncpy(tracker->expenses[tracker->count].name, name, MAX_NAME_LENGTH);
        tracker->expenses[tracker->count].amount = amount;
        tracker->count++;
        printf("Expense added: %s - $%.2f\n", name, amount);
    } else {
        printf("Error: Maximum number of expenses reached.\n");
    }
}

void displayExpenses(ExpenseTracker* tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    
    printf("\nList of Expenses:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d: %s - $%.2f\n", i + 1, tracker->expenses[i].name,
               tracker->expenses[i].amount);
    }
}

float calculateTotal(ExpenseTracker* tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

void saveExpensesToFile(ExpenseTracker* tracker, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file) {
        for (int i = 0; i < tracker->count; i++) {
            fprintf(file, "%s,%.2f\n", tracker->expenses[i].name, 
                    tracker->expenses[i].amount);
        }
        fclose(file);
        printf("Expenses saved to %s\n", filename);
    } else {
        printf("Error: Could not open file %s for writing.\n", filename);
    }
}

void loadExpensesFromFile(ExpenseTracker* tracker, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file) {
        char line[100];
        while (fgets(line, sizeof(line), file) && tracker->count < MAX_EXPENSES) {
            char name[MAX_NAME_LENGTH];
            float amount;
            if (sscanf(line, "%49[^,],%f", name, &amount) == 2) {
                addExpense(tracker, name, amount);
            }
        }
        fclose(file);
        printf("Expenses loaded from %s\n", filename);
    } else {
        printf("Error: Could not open file %s for reading.\n", filename);
    }
}

void displayMenu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. Display Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Save Expenses to File\n");
    printf("5. Load Expenses from File\n");
    printf("6. Exit\n");
    printf("Select an option: ");
}

int main() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);
    int choice;
    char name[MAX_NAME_LENGTH];
    float amount;
    char filename[100];

    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter expense name: ");
                scanf("%s", name);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                addExpense(&tracker, name, amount);
                break;
            case 2:
                displayExpenses(&tracker);
                break;
            case 3:
                printf("Total Expenses: $%.2f\n", calculateTotal(&tracker));
                break;
            case 4:
                printf("Enter filename to save: ");
                scanf("%s", filename);
                saveExpensesToFile(&tracker, filename);
                break;
            case 5:
                printf("Enter filename to load: ");
                scanf("%s", filename);
                loadExpensesFromFile(&tracker, filename);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}