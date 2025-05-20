//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_SIZE 50

typedef struct {
    char name[NAME_SIZE];
    float amount;
    char description[NAME_SIZE];
} Expense;

typedef struct {
    Expense entries[MAX_ENTRIES];
    int count;
} ExpenseTracker;

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Verily, thou hast reached the maximum of %d entries!\n", MAX_ENTRIES);
        return;
    }

    Expense newExpense;

    printf("Enter the name of the expense (e.g. 'Dagger'): ");
    scanf(" %[^\n]%*c", newExpense.name);
    
    printf("Enter the amount of coin spent (in gold ducats): ");
    scanf("%f", &newExpense.amount);
    
    printf("Enter a brief description of the expense: ");
    scanf(" %[^\n]%*c", newExpense.description);

    tracker->entries[tracker->count] = newExpense;
    tracker->count++;

    printf("Huzzah! Expense has been added!\n");
}

void viewExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("Alas! No expenses recorded!\n");
        return;
    }

    printf("\nList of Recorded Expenses:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Entry %d: \n", i + 1);
        printf("\tName: %s\n", tracker->entries[i].name);
        printf("\tAmount: %.2f gold ducats\n", tracker->entries[i].amount);
        printf("\tDescription: %s\n", tracker->entries[i].description);
        printf("-----------------------\n");
    }
}

void calculateTotalExpenses(const ExpenseTracker *tracker) {
    float total = 0.0;

    for (int i = 0; i < tracker->count; i++) {
        total += tracker->entries[i].amount;
    }

    printf("Total expenses recorded: %.2f gold ducats\n", total);
}

void displayMenu() {
    printf("\n===== Expense Tracker of the Realm =====\n");
    printf("1. Add a New Expense\n");
    printf("2. View All Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Exit\n");
    printf("=========================================\n");
    printf("Please choose thine option: ");
}

int main() {
    ExpenseTracker tracker;
    tracker.count = 0;
    int choice;

    while (1) {
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
                calculateTotalExpenses(&tracker);
                break;
            case 4:
                printf("Fare thee well! May thy purse be ever full!\n");
                exit(0);
            default:
                printf("Nay! That is not a valid option! Please choose again.\n");
        }
    }

    return 0;
}