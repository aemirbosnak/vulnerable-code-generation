//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char item_name[MAX_NAME_LENGTH];
    float amount;
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
        printf("Error: Maximum entries reached.\n");
        return;
    }
    Expense new_expense;
    printf("Enter item name: ");
    scanf("%s", new_expense.item_name);
    printf("Enter amount: ");
    scanf("%f", &new_expense.amount);
    
    tracker->entries[tracker->count] = new_expense;
    tracker->count++;
    printf("Expense added successfully!\n");
}

void viewExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    printf("\nYour Expenses:\n");
    printf("---------------------------------------------------\n");
    printf("| %-20s | Amount (USD) |\n", "Item Name");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("| %-20s | %12.2f |\n", tracker->entries[i].item_name, tracker->entries[i].amount);
    }
    printf("---------------------------------------------------\n");
}

void totalExpenses(const ExpenseTracker *tracker) {
    float total = 0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->entries[i].amount;
    }
    printf("Total Expenses: %.2f USD\n", total);
}

void deleteExpense(ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses to delete.\n");
        return;
    }
    int index;
    printf("Enter the index of the expense to delete (0 to %d): ", tracker->count - 1);
    scanf("%d", &index);

    if (index < 0 || index >= tracker->count) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index; i < tracker->count - 1; i++) {
        tracker->entries[i] = tracker->entries[i + 1];
    }
    tracker->count--;
    printf("Expense deleted successfully!\n");
}

void saveToFile(const ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "w");
    if (!file) {
        printf("Error opening file for saving.\n");
        return;
    }

    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s %f\n", tracker->entries[i].item_name, tracker->entries[i].amount);
    }
    fclose(file);
    printf("Expenses saved to expenses.txt successfully!\n");
}

void loadFromFile(ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "r");
    if (!file) {
        printf("No saved expenses found.\n");
        return;
    }

    while (fscanf(file, "%s %f", tracker->entries[tracker->count].item_name, &tracker->entries[tracker->count].amount) != EOF) {
        tracker->count++;
        if (tracker->count >= MAX_ENTRIES) break;
    }
    fclose(file);
    printf("Expenses loaded successfully!\n");
}

void displayMenu() {
    printf("\nExpense Tracker Menu:\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Total Expenses\n");
    printf("4. Delete Expense\n");
    printf("5. Save Expenses to File\n");
    printf("6. Load Expenses from File\n");
    printf("0. Exit\n");
}

int main() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);
    loadFromFile(&tracker);
    int choice;

    do {
        displayMenu();
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
                totalExpenses(&tracker);
                break;
            case 4:
                deleteExpense(&tracker);
                break;
            case 5:
                saveToFile(&tracker);
                break;
            case 6:
                loadFromFile(&tracker);
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}