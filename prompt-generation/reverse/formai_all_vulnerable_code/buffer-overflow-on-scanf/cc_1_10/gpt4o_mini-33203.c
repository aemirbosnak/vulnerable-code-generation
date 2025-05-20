//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: peaceful
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

void initializeTracker(ExpenseTracker *tracker) {
    tracker->count = 0;
    printf("✨ Your Expense Tracker has been initialized.\n");
}

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("🌟 You have reached the maximum expense limit. Can't add more expenses!\n");
        return;
    }

    Expense newExpense;
    printf("📝 Enter the name of the expense: ");
    scanf(" %[^\n]%*c", newExpense.name);
    printf("💵 Enter the amount of the expense: ");
    scanf("%f", &newExpense.amount);

    tracker->expenses[tracker->count] = newExpense;
    tracker->count++;

    printf("✅ Expense \"%s\" of amount %.2f has been added.\n", newExpense.name, newExpense.amount);
}

void viewExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("🌼 No expenses recorded yet.\n");
        return;
    }

    printf("\n📊 Here are your recorded expenses:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("🌟 Expense %d: %s - %.2f\n", i + 1, tracker->expenses[i].name, tracker->expenses[i].amount);
    }
}

float calculateTotalExpenses(const ExpenseTracker *tracker) {
    float total = 0.0f;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

void deleteExpense(ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("❌ No expenses to delete.\n");
        return;
    }

    viewExpenses(tracker);
    int index;
    printf("❓ Which expense would you like to delete (1-%d)? ", tracker->count);
    scanf("%d", &index);

    if (index < 1 || index > tracker->count) {
        printf("🚫 Invalid selection. No expenses deleted.\n");
        return;
    }

    // Shift expenses down to delete the selected expense
    for (int i = index - 1; i < tracker->count - 1; i++) {
        tracker->expenses[i] = tracker->expenses[i + 1];
    }
    tracker->count--;

    printf("✅ Expense %d has been deleted.\n", index);
}

void saveExpensesToFile(const ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "w");
    if (!file) {
        printf("❌ Could not open file for writing.\n");
        return;
    }

    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s %.2f\n", tracker->expenses[i].name, tracker->expenses[i].amount);
    }
    fclose(file);
    printf("💾 Your expenses have been saved to 'expenses.txt'.\n");
}

void loadExpensesFromFile(ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "r");
    if (!file) {
        printf("❌ Could not open file to read.\n");
        return;
    }

    while (tracker->count < MAX_EXPENSES && !feof(file)) {
        Expense newExpense;
        fscanf(file, "%s %f\n", newExpense.name, &newExpense.amount);
        tracker->expenses[tracker->count] = newExpense;
        tracker->count++;
    }
    fclose(file);
    printf("📥 Your expenses have been loaded from 'expenses.txt'.\n");
}

void displayMenu() {
    printf("\n🌈 Welcome to the Expense Tracker!\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Calculate Total Expenses\n");
    printf("5. Save Expenses to File\n");
    printf("6. Load Expenses from File\n");
    printf("7. Exit\n");
}

int main() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);

    while (1) {
        displayMenu();
        int choice;
        printf("✨ Please select an option: ");
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
                printf("📈 Total Expenses: %.2f\n", calculateTotalExpenses(&tracker));
                break;
            case 5:
                saveExpensesToFile(&tracker);
                break;
            case 6:
                loadExpensesFromFile(&tracker);
                break;
            case 7:
                printf("🌹 Thank you for using the Expense Tracker! Goodbye!\n");
                exit(0);
            default:
                printf("🚫 Invalid option. Please try again.\n");
        }
    }
    return 0;
}