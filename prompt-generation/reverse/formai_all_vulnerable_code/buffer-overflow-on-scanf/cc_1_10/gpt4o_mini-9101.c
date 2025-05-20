//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    float amount;
    char category[30];
    char date[11]; // Format: YYYY-MM-DD
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Expense limit reached!\n");
        return;
    }
    
    Expense newExpense;

    printf("Enter expense name: ");
    scanf("%s", newExpense.name);
    
    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);

    printf("Enter expense category: ");
    scanf("%s", newExpense.category);

    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%s", newExpense.date);

    tracker->expenses[tracker->count++] = newExpense;
    printf("Expense added successfully.\n");
}

void viewExpenses(ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }

    printf("Expenses:\n");
    printf("%-30s %-10s %-20s %-10s\n", "Name", "Amount", "Category", "Date");
    
    for (int i = 0; i < tracker->count; i++) {
        printf("%-30s %-10.2f %-20s %-10s\n", 
                tracker->expenses[i].name,
                tracker->expenses[i].amount,
                tracker->expenses[i].category,
                tracker->expenses[i].date);
    }
}

void totalExpenses(ExpenseTracker *tracker) {
    float total = 0.0f;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    printf("Total expenses: %.2f\n", total);
}

void filterByCategory(ExpenseTracker *tracker) {
    char category[30];
    printf("Enter category to filter by: ");
    scanf("%s", category);
    
    printf("Filtered Expenses for category '%s':\n", category);
    printf("%-30s %-10s %-20s %-10s\n", "Name", "Amount", "Category", "Date");
    int found = 0;

    for (int i = 0; i < tracker->count; i++) {
        if (strcmp(tracker->expenses[i].category, category) == 0) {
            printf("%-30s %-10.2f %-20s %-10s\n", 
                    tracker->expenses[i].name,
                    tracker->expenses[i].amount,
                    tracker->expenses[i].category,
                    tracker->expenses[i].date);
            found = 1;
        }
    }

    if (!found) {
        printf("No expenses found for category '%s'.\n", category);
    }
}

void futuristicMenu() {
    printf("=========================================\n");
    printf("         Futuristic Expense Tracker      \n");
    printf("=========================================\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Total Expenses\n");
    printf("4. Filter by Category\n");
    printf("5. Exit\n");
    printf("=========================================\n");
}

int main() {
    ExpenseTracker tracker = { .count = 0 };
    int choice;

    while (1) {
        futuristicMenu();
        
        printf("Select an option: ");
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
                filterByCategory(&tracker);
                break;
            case 5:
                printf("Exiting the Future...\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}