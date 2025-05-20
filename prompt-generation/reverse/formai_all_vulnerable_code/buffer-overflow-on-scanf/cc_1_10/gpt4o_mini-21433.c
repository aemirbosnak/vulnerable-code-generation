//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    double amount;
    char category[MAX_NAME_LENGTH]; // e.g., "Expense", "Income"
} Entry;

typedef struct {
    Entry entries[MAX_ENTRIES];
    int count;
} FinanceTracker;

void addEntry(FinanceTracker *tracker, char *name, double amount, char *category) {
    if (tracker->count < MAX_ENTRIES) {
        strncpy(tracker->entries[tracker->count].name, name, MAX_NAME_LENGTH);
        tracker->entries[tracker->count].amount = amount;
        strncpy(tracker->entries[tracker->count].category, category, MAX_NAME_LENGTH);
        tracker->count++;
    } else {
        printf("Entry limit reached. Cannot add more entries.\n");
    }
}

void displayEntries(const FinanceTracker *tracker) {
    printf("\nFinance Entries:\n");
    printf("------------------------------------------------\n");
    printf("| %-30s | %-8s | %-10s |\n", "Name", "Amount", "Category");
    printf("------------------------------------------------\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("| %-30s | %-8.2f | %-10s |\n", 
               tracker->entries[i].name, 
               tracker->entries[i].amount, 
               tracker->entries[i].category);
    }
    printf("------------------------------------------------\n");
}

void calculateBalance(const FinanceTracker *tracker) {
    double totalIncome = 0.0;
    double totalExpense = 0.0;
    
    for (int i = 0; i < tracker->count; i++) {
        if (strcmp(tracker->entries[i].category, "Income") == 0) {
            totalIncome += tracker->entries[i].amount;
        } else if (strcmp(tracker->entries[i].category, "Expense") == 0) {
            totalExpense += tracker->entries[i].amount;
        }
    }
    
    double balance = totalIncome - totalExpense;
    printf("\nTotal Income: %.2f\n", totalIncome);
    printf("Total Expense: %.2f\n", totalExpense);
    printf("Your Balance: %.2f\n", balance);
}

void showMenu() {
    printf("\nPersonal Finance Planner Menu:\n");
    printf("1. Add Entry\n");
    printf("2. Display Entries\n");
    printf("3. Calculate Balance\n");
    printf("4. Exit\n");
}

int main() {
    FinanceTracker tracker = { .count = 0 };
    int choice;
    
    do {
        showMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // to consume newline after entering the choice
        switch (choice) {
            case 1: {
                char name[MAX_NAME_LENGTH];
                double amount;
                char category[MAX_NAME_LENGTH];

                printf("Enter entry name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character

                printf("Enter amount: ");
                scanf("%lf", &amount);
                getchar(); // consume newline

                printf("Enter category (Income/Expense): ");
                fgets(category, MAX_NAME_LENGTH, stdin);
                category[strcspn(category, "\n")] = 0; // Remove newline character

                addEntry(&tracker, name, amount, category);
                printf("Entry added successfully!\n");
                break;
            }
            case 2:
                displayEntries(&tracker);
                break;
            case 3:
                calculateBalance(&tracker);
                break;
            case 4:
                printf("Exiting the Personal Finance Planner. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}