//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char description[50];
    float amount;
    char date[11]; // format: YYYY-MM-DD
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void initializeTracker(ExpenseTracker *tracker) {
    tracker->count = 0;
}

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Error: Expense limit reached! Cannot add more expenses.\n");
        return;
    }
    
    Expense newExpense;
    
    printf("Enter expense description: ");
    getchar(); // to consume leftover newline
    fgets(newExpense.description, sizeof(newExpense.description), stdin);
    newExpense.description[strcspn(newExpense.description, "\n")] = 0; // remove newline character
    
    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);
    
    printf("Enter date (YYYY-MM-DD): ");
    getchar(); // to consume leftover newline
    fgets(newExpense.date, sizeof(newExpense.date), stdin);
    newExpense.date[strcspn(newExpense.date, "\n")] = 0; // remove newline character
    
    tracker->expenses[tracker->count] = newExpense;
    tracker->count++;
    
    printf("Expense added successfully!\n");
}

void viewExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\n--- Expense Report ---\n");
    float totalAmount = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. [%s] %s: $%.2f\n", i + 1, tracker->expenses[i].date, tracker->expenses[i].description, tracker->expenses[i].amount);
        totalAmount += tracker->expenses[i].amount;
    }
    printf("-----------------------\n");
    printf("Total Expenses: $%.2f\n", totalAmount);
}

void deleteExpense(ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses to delete.\n");
        return;
    }
    
    int index;
    printf("Enter the number of the expense to delete (1-%d): ", tracker->count);
    scanf("%d", &index);
    
    if (index < 1 || index > tracker->count) {
        printf("Invalid expense number.\n");
        return;
    }

    for (int i = index - 1; i < tracker->count - 1; i++) {
        tracker->expenses[i] = tracker->expenses[i + 1];
    }
    
    tracker->count--;
    printf("Expense deleted successfully!\n");
}

void saveExpensesToFile(const ExpenseTracker *tracker, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s,%f,%s\n", tracker->expenses[i].description, tracker->expenses[i].amount, tracker->expenses[i].date);
    }
    
    fclose(file);
    printf("Expenses saved successfully to %s\n", filename);
}

void loadExpensesFromFile(ExpenseTracker *tracker, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file for reading.\n");
        return;
    }

    while (tracker->count < MAX_EXPENSES && !feof(file)) {
        Expense newExpense;
        fscanf(file, "%49[^,],%f,%10s\n", newExpense.description, &newExpense.amount, newExpense.date);
        tracker->expenses[tracker->count++] = newExpense;
    }

    fclose(file);
    printf("Expenses loaded successfully from %s\n", filename);
}

void displayMainMenu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Save Expenses to File\n");
    printf("5. Load Expenses from File\n");
    printf("6. Exit\n");
    printf("-----------------------------\n");
    printf("Choose an option: ");
}

int main() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);
    
    int choice;
    const char *filename = "expenses.txt";
    
    do {
        displayMainMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                viewExpenses(&tracker);
                break;
            case 3:
                deleteExpense(&tracker);
                break;
            case 4:
                saveExpensesToFile(&tracker, filename);
                break;
            case 5:
                loadExpensesFromFile(&tracker, filename);
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 6);
    
    return 0;
}