//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
    char type; // 'i' for income, 'e' for expense
} Entry;

void addEntry(Entry *entries, int *entryCount);
void displayEntries(const Entry *entries, int entryCount);
float calculateTotalIncome(const Entry *entries, int entryCount);
float calculateTotalExpenses(const Entry *entries, int entryCount);
void displayReport(const Entry *entries, int entryCount);
void clearBuffer();

int main() {
    Entry entries[MAX_ENTRIES];
    int entryCount = 0;
    int choice;

    do {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Entry\n");
        printf("2. Display Entries\n");
        printf("3. Display Report\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearBuffer(); // Clear the input buffer

        switch (choice) {
            case 1:
                addEntry(entries, &entryCount);
                break;
            case 2:
                displayEntries(entries, entryCount);
                break;
            case 3:
                displayReport(entries, entryCount);
                break;
            case 4:
                printf("Exiting the program. Have a great day!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addEntry(Entry *entries, int *entryCount) {
    if (*entryCount >= MAX_ENTRIES) {
        printf("Maximum entry limit reached!\n");
        return;
    }

    printf("Enter name of the entry (income/expense): ");
    fgets(entries[*entryCount].name, MAX_NAME_LENGTH, stdin);
    entries[*entryCount].name[strcspn(entries[*entryCount].name, "\n")] = '\0'; // Remove newline

    printf("Enter amount: ");
    scanf("%f", &entries[*entryCount].amount);
    clearBuffer(); // Clear the input buffer

    printf("Enter 'i' for Income or 'e' for Expense: ");
    char type;
    scanf("%c", &type);
    clearBuffer(); // Clear the input buffer

    if (type == 'i' || type == 'e') {
        entries[*entryCount].type = type;
        (*entryCount)++;
        printf("Entry added successfully!\n");
    } else {
        printf("Invalid entry type! Please enter 'i' or 'e'.\n");
    }
}

void displayEntries(const Entry *entries, int entryCount) {
    if (entryCount == 0) {
        printf("No entries to display.\n");
        return;
    }

    printf("\nList of Entries:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%d. %s: %.2f (%s)\n", i + 1, entries[i].name, entries[i].amount,
            entries[i].type == 'i' ? "Income" : "Expense");
    }
}

float calculateTotalIncome(const Entry *entries, int entryCount) {
    float total = 0.0;
    for (int i = 0; i < entryCount; i++) {
        if (entries[i].type == 'i') {
            total += entries[i].amount;
        }
    }
    return total;
}

float calculateTotalExpenses(const Entry *entries, int entryCount) {
    float total = 0.0;
    for (int i = 0; i < entryCount; i++) {
        if (entries[i].type == 'e') {
            total += entries[i].amount;
        }
    }
    return total;
}

void displayReport(const Entry *entries, int entryCount) {
    if (entryCount == 0) {
        printf("No entries to report.\n");
        return;
    }

    float totalIncome = calculateTotalIncome(entries, entryCount);
    float totalExpenses = calculateTotalExpenses(entries, entryCount);
    float balance = totalIncome - totalExpenses;

    printf("\nFinancial Report:\n");
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expenses: %.2f\n", totalExpenses);
    printf("Balance: %.2f\n", balance);
}

void clearBuffer() {
    while (getchar() != '\n');
}