//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LENGTH 50

typedef struct {
    char description[DESCRIPTION_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void initializeTracker(ExpenseTracker *tracker) {
    tracker->count = 0;
}

void addExpense(ExpenseTracker *tracker, const char *description, float amount) {
    if (tracker->count < MAX_EXPENSES) {
        strncpy(tracker->expenses[tracker->count].description, description, DESCRIPTION_LENGTH);
        tracker->expenses[tracker->count].amount = amount;
        tracker->count++;
        printf("Expense added: %s - $%.2f\n", description, amount);
    } else {
        printf("Expense limit reached. Cannot add more expenses.\n");
    }
}

void viewExpenses(const ExpenseTracker *tracker) {
    printf("\n--- Expense List ---\n");
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
    } else {
        for (int i = 0; i < tracker->count; i++) {
            printf("%d. %s - $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
        }
    }
    printf("---------------------\n");
}

float calculateTotalExpenses(const ExpenseTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

void deleteExpense(ExpenseTracker *tracker, int index) {
    if (index < 0 || index >= tracker->count) {
        printf("Invalid index. Expense not deleted.\n");
        return;
    }
    
    for (int i = index; i < tracker->count - 1; i++) {
        tracker->expenses[i] = tracker->expenses[i + 1];
    }
    tracker->count--;
    printf("Expense at index %d deleted.\n", index + 1);
}

void saveExpensesToFile(const ExpenseTracker *tracker, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for saving.\n");
        return;
    }
    
    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s,%.2f\n", tracker->expenses[i].description, tracker->expenses[i].amount);
    }
    fclose(file);
    printf("Expenses saved to %s.\n", filename);
}

void loadExpensesFromFile(ExpenseTracker *tracker, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for loading.\n");
        return;
    }
    
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file) != NULL && tracker->count < MAX_EXPENSES) {
        char description[DESCRIPTION_LENGTH];
        float amount;
        sscanf(buffer, "%[^,],%f", description, &amount);
        addExpense(tracker, description, amount);
    }
    fclose(file);
    printf("Expenses loaded from %s.\n", filename);
}

void showMenu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Calculate Total Expenses\n");
    printf("5. Save Expenses to File\n");
    printf("6. Load Expenses from File\n");
    printf("0. Exit\n");
    printf("-----------------------------\n");
}

int main() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);

    int choice;
    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume newline character after scanf

        switch (choice) {
            case 1: {
                char description[DESCRIPTION_LENGTH];
                float amount;
                printf("Enter expense description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = 0; // Remove newline character

                printf("Enter expense amount: ");
                scanf("%f", &amount);
                addExpense(&tracker, description, amount);
                break;
            }
            case 2:
                viewExpenses(&tracker);
                break;
            case 3: {
                int index;
                printf("Enter the index of the expense to delete: ");
                scanf("%d", &index);
                deleteExpense(&tracker, index - 1); // Adjust for zero-based index
                break;
            }
            case 4: {
                float total = calculateTotalExpenses(&tracker);
                printf("Total Expenses: $%.2f\n", total);
                break;
            }
            case 5: {
                char filename[100];
                printf("Enter filename to save expenses: ");
                scanf("%s", filename);
                saveExpensesToFile(&tracker, filename);
                break;
            }
            case 6: {
                char filename[100];
                printf("Enter filename to load expenses: ");
                scanf("%s", filename);
                loadExpensesFromFile(&tracker, filename);
                break;
            }
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}