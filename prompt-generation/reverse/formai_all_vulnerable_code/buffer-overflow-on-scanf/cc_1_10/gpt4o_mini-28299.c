//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define DESCRIPTION_LEN 50

typedef struct {
    char description[DESCRIPTION_LEN];
    float amount;
    char type; // 'i' for income, 'e' for expense
} Entry;

typedef struct {
    Entry entries[MAX_ENTRIES];
    int count;
} FinanceTracker;

void addEntry(FinanceTracker *tracker, const char *description, float amount, char type) {
    if (tracker->count < MAX_ENTRIES) {
        strncpy(tracker->entries[tracker->count].description, description, DESCRIPTION_LEN);
        tracker->entries[tracker->count].amount = amount;
        tracker->entries[tracker->count].type = type;
        tracker->count++;
        printf("Entry added: %s - %.2f [%c]\n", description, amount, type);
    } else {
        printf("Finance tracker is full, cannot add more entries.\n");
    }
}

void displayEntries(const FinanceTracker *tracker) {
    if(tracker->count == 0){
        printf("No entries to display.\n");
        return;
    }
    
    printf("\n--- Financial Entries ---\n");
    printf("Description\tAmount\tType\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%s\t%.2f\t%c\n", tracker->entries[i].description, tracker->entries[i].amount, tracker->entries[i].type);
    }
    printf("-------------------------\n");
}

float calculateTotalIncome(const FinanceTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        if (tracker->entries[i].type == 'i') {
            total += tracker->entries[i].amount;
        }
    }
    return total;
}

float calculateTotalExpenses(const FinanceTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        if (tracker->entries[i].type == 'e') {
            total += tracker->entries[i].amount;
        }
    }
    return total;
}

void displayBalance(const FinanceTracker *tracker) {
    float totalIncome = calculateTotalIncome(tracker);
    float totalExpenses = calculateTotalExpenses(tracker);
    float balance = totalIncome - totalExpenses;

    printf("\n--- Financial Summary ---\n");
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expenses: %.2f\n", totalExpenses);
    printf("Balance: %.2f\n", balance);
    printf("-------------------------\n");
}

void saveEntriesToFile(const FinanceTracker *tracker, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Unable to open file for saving.\n");
        return;
    }
    
    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s,%.2f,%c\n", tracker->entries[i].description, tracker->entries[i].amount, tracker->entries[i].type);
    }
    fclose(file);
    printf("Entries saved to %s\n", filename);
}

void loadEntriesFromFile(FinanceTracker *tracker, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file for loading.\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) && tracker->count < MAX_ENTRIES) {
        Entry entry;
        sscanf(line, "%49[^,],%f,%c", entry.description, &entry.amount, &entry.type);
        tracker->entries[tracker->count++] = entry;
    }
    fclose(file);
    printf("Entries loaded from %s\n", filename);
}

int main() {
    FinanceTracker tracker;
    tracker.count = 0;

    int choice;
    char description[DESCRIPTION_LEN];
    float amount;
    char type;
    const char *filename = "finance_data.txt";

    printf("Welcome to the Personal Finance Planner!\n");
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Display Entries\n");
        printf("4. Display Balance\n");
        printf("5. Save Entries to File\n");
        printf("6. Load Entries from File\n");
        printf("7. Exit\n");
        printf("Choose an option (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter income description: ");
                scanf(" %[^\n]", description);
                printf("Enter income amount: ");
                scanf("%f", &amount);
                addEntry(&tracker, description, amount, 'i');
                break;
            case 2:
                printf("Enter expense description: ");
                scanf(" %[^\n]", description);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                addEntry(&tracker, description, amount, 'e');
                break;
            case 3:
                displayEntries(&tracker);
                break;
            case 4:
                displayBalance(&tracker);
                break;
            case 5:
                saveEntriesToFile(&tracker, filename);
                break;
            case 6:
                loadEntriesFromFile(&tracker, filename);
                break;
            case 7:
                printf("Exiting the Personal Finance Planner. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}