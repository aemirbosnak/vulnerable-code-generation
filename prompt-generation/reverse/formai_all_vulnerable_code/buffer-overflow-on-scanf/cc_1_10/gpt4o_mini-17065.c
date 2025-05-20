//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORY 30
#define DATE_SIZE 11

typedef struct {
    char date[DATE_SIZE];
    char category[MAX_CATEGORY];
    double amount;
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
        printf("Expense limit reached. Cannot add more expenses.\n");
        return;
    }

    Expense newExpense;
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", newExpense.date);
    printf("Enter category: ");
    scanf("%s", newExpense.category);
    printf("Enter amount: ");
    scanf("%lf", &newExpense.amount);

    tracker->expenses[tracker->count] = newExpense;
    tracker->count++;
    printf("Expense added successfully!\n");
}

void listExpenses(const ExpenseTracker* tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded yet!\n");
        return;
    }

    printf("\nExpenses List:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s | %s | %.2lf\n", i + 1, tracker->expenses[i].date, 
               tracker->expenses[i].category, tracker->expenses[i].amount);
    }
    printf("\n");
}

void calculateTotal(const ExpenseTracker* tracker) {
    double total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    printf("Total expenses: %.2lf\n", total);
}

void findExpensesByCategory(const ExpenseTracker* tracker) {
    char category[MAX_CATEGORY];
    printf("Enter category to search: ");
    scanf("%s", category);
    
    int found = 0;
    printf("\nExpenses in '%s' category:\n", category);
    for (int i = 0; i < tracker->count; i++) {
        if (strcmp(tracker->expenses[i].category, category) == 0) {
            printf("%s | %.2lf\n", tracker->expenses[i].date, tracker->expenses[i].amount);
            found = 1;
        }
    }
    if (!found) {
        printf("No expenses found for this category.\n");
    }
}

void saveExpensesToFile(const ExpenseTracker* tracker) {
    FILE* file = fopen("expenses.txt", "w");
    if (!file) {
        printf("Error opening the file!\n");
        return;
    }

    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s,%s,%.2lf\n", tracker->expenses[i].date,
                tracker->expenses[i].category, tracker->expenses[i].amount);
    }
    fclose(file);
    printf("Expenses saved to 'expenses.txt'\n");
}

void loadExpensesFromFile(ExpenseTracker* tracker) {
    FILE* file = fopen("expenses.txt", "r");
    if (!file) {
        printf("No saved expenses to load.\n");
        return;
    }

    while (!feof(file) && tracker->count < MAX_EXPENSES) {
        Expense exp;
        fscanf(file, "%[^,],%[^,],%lf\n", exp.date, exp.category, &exp.amount);
        tracker->expenses[tracker->count] = exp;
        tracker->count++;
    }
    fclose(file);
    printf("Expenses loaded from 'expenses.txt'\n");
}

void displayMenu() {
    printf("\n=== Expense Tracker Menu ===\n");
    printf("1. Add Expense\n");
    printf("2. List Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Find Expenses by Category\n");
    printf("5. Save Expenses to File\n");
    printf("6. Load Expenses from File\n");
    printf("7. Exit\n");
    printf("============================\n");
}

int main() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);

    loadExpensesFromFile(&tracker);

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
                listExpenses(&tracker);
                break;
            case 3:
                calculateTotal(&tracker);
                break;
            case 4:
                findExpensesByCategory(&tracker);
                break;
            case 5:
                saveExpensesToFile(&tracker);
                break;
            case 6:
                loadExpensesFromFile(&tracker);
                break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}