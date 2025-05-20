//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LEN 50
#define DESC_LEN 100

typedef struct {
    char name[NAME_LEN];
    float amount;
    char description[DESC_LEN];
} Entry;

typedef struct {
    Entry entries[MAX_ENTRIES];
    int count;
} FinanceTracker;

void initializeTracker(FinanceTracker *tracker) {
    tracker->count = 0;
}

void addEntry(FinanceTracker *tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    Entry newEntry;
    printf("Enter the name of the entry: ");
    scanf("%s", newEntry.name);
    printf("Enter the amount: ");
    scanf("%f", &newEntry.amount);
    printf("Enter a description: ");
    getchar(); // Consume newline
    fgets(newEntry.description, DESC_LEN, stdin);
    newEntry.description[strcspn(newEntry.description, "\n")] = 0; // Remove newline

    tracker->entries[tracker->count] = newEntry;
    tracker->count++;
    printf("Entry added successfully.\n");
}

void displayEntries(const FinanceTracker *tracker) {
    if (tracker->count == 0) {
        printf("No entries to display.\n");
        return;
    }

    printf("\n--- Financial Entries ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Entry #%d:\n", i + 1);
        printf("Name: %s\n", tracker->entries[i].name);
        printf("Amount: %.2f\n", tracker->entries[i].amount);
        printf("Description: %s\n\n", tracker->entries[i].description);
    }
}

float calculateTotal(const FinanceTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->entries[i].amount;
    }
    return total;
}

void saveEntriesToFile(const FinanceTracker *tracker) {
    FILE *file = fopen("finance_data.txt", "w");
    if (!file) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s\n%f\n%s\n", tracker->entries[i].name,
                tracker->entries[i].amount, tracker->entries[i].description);
    }
    fclose(file);
    printf("Entries saved to finance_data.txt\n");
}

void loadEntriesFromFile(FinanceTracker *tracker) {
    FILE *file = fopen("finance_data.txt", "r");
    if (!file) {
        printf("No saved data found.\n");
        return;
    }

    while (fscanf(file, "%s\n%f\n%[^\n]\n", tracker->entries[tracker->count].name,
                  &tracker->entries[tracker->count].amount,
                  tracker->entries[tracker->count].description) == 3) {
        tracker->count++;
        if (tracker->count >= MAX_ENTRIES) {
            break;
        }
    }
    fclose(file);
    printf("Entries loaded from finance_data.txt\n");
}

int main() {
    FinanceTracker tracker;
    initializeTracker(&tracker);
    
    loadEntriesFromFile(&tracker);
    
    int choice;
    do {
        printf("\n--- Personal Finance Planner ---\n");
        printf("1. Add Entry\n");
        printf("2. Display Entries\n");
        printf("3. Calculate Total Amount\n");
        printf("4. Save Entries to File\n");
        printf("5. Quit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEntry(&tracker);
                break;
            case 2:
                displayEntries(&tracker);
                break;
            case 3:
                printf("Total Amount: %.2f\n", calculateTotal(&tracker));
                break;
            case 4:
                saveEntriesToFile(&tracker);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}