//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    double amount;
    char category[NAME_LEN];
    char date[11]; // YYYY-MM-DD
} Entry;

typedef struct {
    Entry entries[MAX_ENTRIES];
    int count;
} FinanceTracker;

void addEntry(FinanceTracker *tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Maximum entry limit reached.\n");
        return;
    }

    Entry newEntry;
    
    printf("Enter Name (Expense/Income): ");
    scanf("%s", newEntry.name);
    
    printf("Enter Amount: ");
    scanf("%lf", &newEntry.amount);
    
    printf("Enter Category: ");
    scanf("%s", newEntry.category);
    
    printf("Enter Date (YYYY-MM-DD): ");
    scanf("%s", newEntry.date);
    
    tracker->entries[tracker->count] = newEntry;
    tracker->count++;
    printf("Entry added successfully.\n");
}

void displayEntries(FinanceTracker *tracker) {
    if (tracker->count == 0) {
        printf("No entries to display.\n");
        return;
    }

    printf("\n--- Finance Entries ---\n");
    for (int i = 0; i < tracker->count; ++i) {
        Entry e = tracker->entries[i];
        printf("Entry %d: Name: %s, Amount: %.2lf, Category: %s, Date: %s\n",
               i + 1, e.name, e.amount, e.category, e.date);
    }
}

void calculateTotal(FinanceTracker *tracker) {
    double totalIncome = 0.0;
    double totalExpense = 0.0;

    for (int i = 0; i < tracker->count; ++i) {
        if (tracker->entries[i].amount > 0)
            totalIncome += tracker->entries[i].amount;
        else
            totalExpense += tracker->entries[i].amount;
    }

    printf("\nTotal Income: %.2lf\n", totalIncome);
    printf("Total Expense: %.2lf\n", totalExpense);
    printf("Net Balance: %.2lf\n", totalIncome + totalExpense);
}

void saveToFile(FinanceTracker *tracker) {
    FILE *file = fopen("finance_data.txt", "w");
    if (!file) {
        printf("Unable to open file for writing.\n");
        return;
    }

    for (int i = 0; i < tracker->count; ++i) {
        Entry e = tracker->entries[i];
        fprintf(file, "%s %.2lf %s %s\n", e.name, e.amount, e.category, e.date);
    }

    fclose(file);
    printf("Data saved to finance_data.txt.\n");
}

void loadFromFile(FinanceTracker *tracker) {
    FILE *file = fopen("finance_data.txt", "r");
    if (!file) {
        printf("No data file found.\n");
        return;
    }

    while (fscanf(file, "%s %lf %s %s", tracker->entries[tracker->count].name,
           &tracker->entries[tracker->count].amount,
           tracker->entries[tracker->count].category,
           tracker->entries[tracker->count].date) != EOF) {
        tracker->count++;
        if (tracker->count >= MAX_ENTRIES) break;
    }

    fclose(file);
    printf("Data loaded successfully. Total entries: %d\n", tracker->count);
}

int main() {
    FinanceTracker tracker = {.count = 0};
    int choice;

    loadFromFile(&tracker);

    do {
        printf("\n--- Personal Finance Planner ---\n");
        printf("1. Add Entry\n");
        printf("2. Display Entries\n");
        printf("3. Calculate Totals\n");
        printf("4. Save Data\n");
        printf("5. Load Data\n");
        printf("0. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(&tracker);
                break;
            case 2:
                displayEntries(&tracker);
                break;
            case 3:
                calculateTotal(&tracker);
                break;
            case 4:
                saveToFile(&tracker);
                break;
            case 5:
                loadFromFile(&tracker);
                break;
            case 0:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}