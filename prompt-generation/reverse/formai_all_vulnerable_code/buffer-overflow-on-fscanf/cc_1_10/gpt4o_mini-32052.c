//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: Ada Lovelace
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

void addExpense(ExpenseTracker* tracker, const char* description, float amount) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Error: Cannot add more expenses. Limit reached.\n");
        return;
    }

    strcpy(tracker->expenses[tracker->count].description, description);
    tracker->expenses[tracker->count].amount = amount;
    tracker->count++;
    printf("Expense added: %s, $%.2f\n", description, amount);
}

void showExpenses(const ExpenseTracker* tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\nExpense List:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s: $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
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
        printf("Error: Could not open file for writing.\n");
        return;
    }

    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s,$%.2f\n", tracker->expenses[i].description, tracker->expenses[i].amount);
    }

    fclose(file);
    printf("Expenses saved to %s\n", filename);
}

void loadExpensesFromFile(ExpenseTracker* tracker, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file for reading.\n");
        return;
    }

    while (tracker->count < MAX_EXPENSES && !feof(file)) {
        char description[DESCRIPTION_LENGTH];
        float amount;
        if (fscanf(file, "%49[^,],%f\n", description, &amount) == 2) {
            addExpense(tracker, description, amount);
        }
    }

    fclose(file);
    printf("Expenses loaded from %s\n", filename);
}

int main() {
    ExpenseTracker tracker = {0};
    int choice;

    while (1) {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. Show All Expenses\n");
        printf("3. Calculate Total Expenses\n");
        printf("4. Save Expenses to File\n");
        printf("5. Load Expenses from File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char description[DESCRIPTION_LENGTH];
                float amount;

                printf("Enter the description of the expense: ");
                getchar();  // Consume newline left by previous input
                fgets(description, DESCRIPTION_LENGTH, stdin);
                description[strcspn(description, "\n")] = 0;  // Remove newline

                printf("Enter the amount: ");
                scanf("%f", &amount);
                addExpense(&tracker, description, amount);
                break;
            }
            case 2:
                showExpenses(&tracker);
                break;
            case 3: {
                float total = calculateTotal(&tracker);
                printf("Total Expenses: $%.2f\n", total);
                break;
            }
            case 4: {
                char filename[100];
                printf("Enter the filename to save expenses: ");
                getchar();  // Consume newline left by previous input
                fgets(filename, 100, stdin);
                filename[strcspn(filename, "\n")] = 0;  // Remove newline

                saveExpensesToFile(&tracker, filename);
                break;
            }
            case 5: {
                char filename[100];
                printf("Enter the filename to load expenses: ");
                getchar();  // Consume newline left by previous input
                fgets(filename, 100, stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline

                loadExpensesFromFile(&tracker, filename);
                break;
            }
            case 6:
                printf("Exiting the Expense Tracker. Farewell!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}