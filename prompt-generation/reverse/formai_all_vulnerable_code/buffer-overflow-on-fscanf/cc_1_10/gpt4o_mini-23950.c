//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LENGTH 100

typedef struct {
    char description[DESCRIPTION_LENGTH];
    float amount;
    char category[DESCRIPTION_LENGTH];
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
        printf("Error: Can't add more expenses. Limit reached!\n");
        return;
    }

    Expense newExpense;
    printf("Enter the description of the expense: ");
    scanf(" %[^\n]%*c", newExpense.description);
    printf("Enter the amount: ");
    scanf("%f", &newExpense.amount);
    printf("Enter the category of the expense: ");
    scanf(" %[^\n]%*c", newExpense.category);

    tracker->expenses[tracker->count] = newExpense;
    tracker->count++;
    printf("Expense added successfully!\n");
}

void viewExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\nExpenses Recorded:\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Description: %s\n", tracker->expenses[i].description);
        printf("Amount: %.2f\n", tracker->expenses[i].amount);
        printf("Category: %s\n", tracker->expenses[i].category);
        printf("--------------------------------------------------\n");
    }
}

void calculateTotalExpenses(const ExpenseTracker *tracker) {
    float total = 0.0f;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    printf("Total Expenses: %.2f\n", total);
}

void saveExpensesToFile(const ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "Description: %s\n", tracker->expenses[i].description);
        fprintf(file, "Amount: %.2f\n", tracker->expenses[i].amount);
        fprintf(file, "Category: %s\n", tracker->expenses[i].category);
        fprintf(file, "----------------------------------------------\n");
    }

    fclose(file);
    printf("Expenses saved to expenses.txt successfully!\n");
}

void loadExpensesFromFile(ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "r");
    if (file == NULL) {
        printf("No existing expense file found.\n");
        return;
    }

    while (fscanf(file, " Description: %[^\n]\n Amount: %f\n Category: %[^\n]\n",
                  tracker->expenses[tracker->count].description,
                  &tracker->expenses[tracker->count].amount,
                  tracker->expenses[tracker->count].category) != EOF) {
        tracker->count++;
        if (tracker->count >= MAX_EXPENSES) {
            printf("Reached maximum expenses limit while loading...\n");
            break;
        }
    }

    fclose(file);
    printf("Expenses loaded successfully!\n");
}

int main() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);
    loadExpensesFromFile(&tracker);

    int choice;
    do {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
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
                viewExpenses(&tracker);
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