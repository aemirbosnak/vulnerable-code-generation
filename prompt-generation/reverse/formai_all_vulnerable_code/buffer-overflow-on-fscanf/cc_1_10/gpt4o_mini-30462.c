//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXPENSES 100

typedef struct {
    char description[100];
    float amount;
    char date[11]; // format: YYYY-MM-DD
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void initTracker(ExpenseTracker *tracker) {
    tracker->count = 0;
}

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Expense capacity reached!\n");
        return;
    }

    Expense newExpense;

    printf("Enter description of the expense: ");
    getchar(); // Clear newline left by previous input
    fgets(newExpense.description, sizeof(newExpense.description), stdin);
    newExpense.description[strcspn(newExpense.description, "\n")] = 0; // Remove newline

    printf("Enter amount (in USD): ");
    scanf("%f", &newExpense.amount);

    // Getting current date
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    strftime(newExpense.date, sizeof(newExpense.date), "%Y-%m-%d", tm_info);

    tracker->expenses[tracker->count] = newExpense;
    tracker->count++;

    printf("Expense added successfully!\n");
}

void viewExpenses(ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }

    printf("\n--- Your Expenses ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. [%s] - $%.2f\n", i + 1, tracker->expenses[i].date, tracker->expenses[i].amount);
        printf("   Description: %s\n", tracker->expenses[i].description);
    }
}

void calculateTotal(ExpenseTracker *tracker) {
    float total = 0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    printf("Total Amount Spent: $%.2f\n", total);
}

void saveExpensesToFile(ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "w");
    if (!file) {
        printf("Unable to open file to save expenses.\n");
        return;
    }

    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s,%.2f,%s\n", tracker->expenses[i].description, 
                                      tracker->expenses[i].amount, 
                                      tracker->expenses[i].date);
    }

    fclose(file);
    printf("Expenses saved to 'expenses.txt'.\n");
}

void loadExpensesFromFile(ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "r");
    if (!file) {
        printf("No previous expenses found.\n");
        return;
    }

    while (!feof(file) && tracker->count < MAX_EXPENSES) {
        Expense expense;
        fscanf(file, "%99[^,],%f,%10s\n", expense.description, &expense.amount, expense.date);
        tracker->expenses[tracker->count] = expense;
        tracker->count++;
    }

    fclose(file);
    printf("Previous expenses loaded successfully.\n");
}

void displayMenu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Save Expenses to File\n");
    printf("5. Load Expenses from File\n");
    printf("6. Exit\n");
    printf("Select an option: ");
}

int main() {
    ExpenseTracker tracker;
    initTracker(&tracker);
    loadExpensesFromFile(&tracker);

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
            case 4:
                saveExpensesToFile(&tracker);
                break;
            case 5:
                loadExpensesFromFile(&tracker);
                break;
            case 6:
                printf("Exiting the expense tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

    return 0;
}