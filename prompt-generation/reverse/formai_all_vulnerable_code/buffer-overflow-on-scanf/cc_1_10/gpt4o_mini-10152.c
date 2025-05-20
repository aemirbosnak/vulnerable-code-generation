//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_DESC_LENGTH 50

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
    char date[11]; // Format: YYYY-MM-DD
} Expense;

typedef struct {
    Expense entries[MAX_ENTRIES];
    int count;
} ExpenseTracker;

void initializeTracker(ExpenseTracker* tracker) {
    tracker->count = 0;
}

void addExpense(ExpenseTracker* tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Expense tracker is full. Cannot add more entries.\n");
        return;
    }
    
    Expense newExpense;

    printf("Enter expense description: ");
    getchar(); // clear the newline character from previous input
    fgets(newExpense.description, MAX_DESC_LENGTH, stdin);
    newExpense.description[strcspn(newExpense.description, "\n")] = 0; // remove newline

    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);
    
    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%s", newExpense.date);

    tracker->entries[tracker->count] = newExpense;
    tracker->count++;
    
    printf("Expense added successfully!\n");
}

void viewExpenses(const ExpenseTracker* tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    
    printf("\n--- Expenses ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Description: %s\n", tracker->entries[i].description);
        printf("Amount: %.2f\n", tracker->entries[i].amount);
        printf("Date: %s\n\n", tracker->entries[i].date);
    }
}

void calculateTotal(const ExpenseTracker* tracker) {
    float total = 0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->entries[i].amount;
    }
    printf("Total Expenses: %.2f\n", total);
}

void saveToFile(const ExpenseTracker* tracker, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }

    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s,%.2f,%s\n", tracker->entries[i].description, tracker->entries[i].amount, tracker->entries[i].date);
    }

    fclose(file);
    printf("Expenses saved to %s\n", filename);
}

void loadFromFile(ExpenseTracker* tracker, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file for reading");
        return;
    }

    while (tracker->count < MAX_ENTRIES && !feof(file)) {
        Expense tempExpense;
        fscanf(file, "%49[^,],%f,%10s\n", tempExpense.description, &tempExpense.amount, tempExpense.date);
        tracker->entries[tracker->count++] = tempExpense;
    }
    fclose(file);
    printf("Expenses loaded from %s\n", filename);
}

void displayMenu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total\n");
    printf("4. Save to File\n");
    printf("5. Load from File\n");
    printf("6. Exit\n");
    printf("Select an option: ");
}

int main() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                viewExpenses(&tracker);
                break;
            case 3:
                calculateTotal(&tracker);
                break;
            case 4: {
                char filename[50];
                printf("Enter filename to save expenses: ");
                scanf("%s", filename);
                saveToFile(&tracker, filename);
                break;
            }
            case 5: {
                char filename[50];
                printf("Enter filename to load expenses: ");
                scanf("%s", filename);
                loadFromFile(&tracker, filename);
                break;
            }
            case 6:
                printf("Exiting the Expense Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}