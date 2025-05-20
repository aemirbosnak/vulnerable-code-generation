//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORY_LENGTH 30
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char category[MAX_CATEGORY_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void initTracker(ExpenseTracker* tracker) {
    tracker->count = 0;
}

void addExpense(ExpenseTracker* tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Expense tracker is full!\n");
        return;
    }

    Expense newExpense;

    printf("Enter expense category: ");
    scanf("%s", newExpense.category);

    printf("Enter expense description: ");
    scanf(" %[^\n]", newExpense.description); // Read string with spaces

    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);

    tracker->expenses[tracker->count] = newExpense;
    tracker->count++;

    printf("Expense added successfully!\n");
}

void displayExpenses(ExpenseTracker* tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\nRecorded Expenses:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Category: %s, Description: %s, Amount: %.2f\n",
               tracker->expenses[i].category,
               tracker->expenses[i].description,
               tracker->expenses[i].amount);
    }
}

void calculateTotal(ExpenseTracker* tracker) {
    float total = 0.0;

    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }

    printf("Total Expenses: %.2f\n", total);
}

void saveExpensesToFile(ExpenseTracker* tracker, const char* filename) {
    FILE* file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s,%s,%.2f\n",
                tracker->expenses[i].category,
                tracker->expenses[i].description,
                tracker->expenses[i].amount);
    }

    fclose(file);
    printf("Expenses saved to %s successfully!\n", filename);
}

void loadExpensesFromFile(ExpenseTracker* tracker, const char* filename) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    while (fscanf(file, "%[^,],%[^,],%f\n",
                  tracker->expenses[tracker->count].category,
                  tracker->expenses[tracker->count].description,
                  &tracker->expenses[tracker->count].amount) == 3) {
        tracker->count++;

        if (tracker->count >= MAX_EXPENSES) {
            printf("Maximum expense limit reached while loading.\n");
            break;
        }
    }

    fclose(file);
    printf("Expenses loaded from %s successfully!\n", filename);
}

void displayMenu() {
    printf("\nExpense Tracker Menu\n");
    printf("1. Add Expense\n");
    printf("2. Display Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Save Expenses to File\n");
    printf("5. Load Expenses from File\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    ExpenseTracker tracker;
    initTracker(&tracker);

    int choice;
    const char* filename = "expenses.txt";

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                displayExpenses(&tracker);
                break;
            case 3:
                calculateTotal(&tracker);
                break;
            case 4:
                saveExpensesToFile(&tracker, filename);
                break;
            case 5:
                loadExpensesFromFile(&tracker, filename);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}