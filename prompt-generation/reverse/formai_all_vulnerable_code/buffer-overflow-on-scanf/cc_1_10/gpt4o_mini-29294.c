//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 30
#define TYPE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    double amount;
    char type[TYPE_LENGTH]; // Income or Expense
} Entry;

Entry entries[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Maximum number of entries reached.\n");
        return;
    }
    
    Entry newEntry;
    printf("Enter name of entry: ");
    scanf("%s", newEntry.name);
    printf("Enter amount: ");
    scanf("%lf", &newEntry.amount);
    printf("Enter type (Income/Expense): ");
    scanf("%s", newEntry.type);
    
    entries[entryCount++] = newEntry;
    printf("Entry added successfully!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("\n--- Financial Entries ---\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%d. %s: %.2f (%s)\n", i + 1, entries[i].name, entries[i].amount, entries[i].type);
    }
    printf("\n");
}

void calculateBalance() {
    double income = 0.0;
    double expenses = 0.0;

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(entries[i].type, "Income") == 0) {
            income += entries[i].amount;
        } else if (strcmp(entries[i].type, "Expense") == 0) {
            expenses += entries[i].amount;
        }
    }

    printf("Total Income: %.2f\n", income);
    printf("Total Expenses: %.2f\n", expenses);
    printf("Net Balance: %.2f\n", income - expenses);
}

void deleteEntry() {
    if (entryCount == 0) {
        printf("No entries found to delete.\n");
        return;
    }

    int entryNum;
    viewEntries();
    
    printf("Enter the entry number to delete: ");
    scanf("%d", &entryNum);

    if (entryNum < 1 || entryNum > entryCount) {
        printf("Invalid entry number.\n");
        return;
    }

    for (int i = entryNum - 1; i < entryCount - 1; i++) {
        entries[i] = entries[i + 1];
    }
    entryCount--;
    printf("Entry deleted successfully!\n");
}

void displayMenu() {
    printf("\n--- Personal Finance Planner ---\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Calculate Balance\n");
    printf("4. Delete Entry\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                calculateBalance();
                break;
            case 4:
                deleteEntry();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}