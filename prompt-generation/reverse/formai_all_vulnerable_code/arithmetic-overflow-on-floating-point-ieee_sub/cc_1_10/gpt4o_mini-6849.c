//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 30
#define DESCRIPTION_LENGTH 100

typedef struct {
    char name[NAME_LENGTH];
    float income;
    float expenses;
    float savings;
    char description[DESCRIPTION_LENGTH];
} FinanceEntry;

void addEntry(FinanceEntry* entries, int* count) {
    if (*count >= MAX_ENTRIES) {
        printf("Cannot add more entries, limit reached.\n");
        return;
    }

    printf("Enter the name of the entry: ");
    scanf("%s", entries[*count].name);
    printf("Enter your income for this entry: ");
    scanf("%f", &entries[*count].income);
    printf("Enter your expenses for this entry: ");
    scanf("%f", &entries[*count].expenses);
    printf("Enter a description for this entry: ");
    getchar(); // To clear newline
    fgets(entries[*count].description, DESCRIPTION_LENGTH, stdin);
    entries[*count].description[strcspn(entries[*count].description, "\n")] = 0; // Remove newline

    entries[*count].savings = entries[*count].income - entries[*count].expenses;
    (*count)++;
    printf("Entry added successfully!\n");
}

void displayEntries(FinanceEntry* entries, int count) {
    if (count == 0) {
        printf("No entries to display.\n");
        return;
    }

    printf("\n---- Finance Entries ----\n");
    for (int i = 0; i < count; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Name: %s\n", entries[i].name);
        printf("Income: $%.2f\n", entries[i].income);
        printf("Expenses: $%.2f\n", entries[i].expenses);
        printf("Savings: $%.2f\n", entries[i].savings);
        printf("Description: %s\n", entries[i].description);
        printf("-------------------------\n");
    }
}

void totalSummary(FinanceEntry* entries, int count) {
    float totalIncome = 0.0, totalExpenses = 0.0, totalSavings = 0.0;

    for (int i = 0; i < count; i++) {
        totalIncome += entries[i].income;
        totalExpenses += entries[i].expenses;
        totalSavings += entries[i].savings;
    }

    printf("\n--- Total Summary ---\n");
    printf("Total Income: $%.2f\n", totalIncome);
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Total Savings: $%.2f\n", totalSavings);
    printf("---------------------\n");
}

void saveEntries(FinanceEntry* entries, int count) {
    FILE* file = fopen("finance_entries.txt", "w");
    if (file == NULL) {
        printf("Error saving entries to file.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %.2f %.2f %.2f %s\n", 
                entries[i].name, 
                entries[i].income, 
                entries[i].expenses, 
                entries[i].savings, 
                entries[i].description);
    }

    fclose(file);
    printf("Entries saved successfully to 'finance_entries.txt'!\n");
}

int main() {
    FinanceEntry entries[MAX_ENTRIES];
    int count = 0;
    int choice;
    
    while (1) {
        printf("\n--- Personal Finance Planner ---\n");
        printf("1. Add Entry\n");
        printf("2. Display Entries\n");
        printf("3. Total Summary\n");
        printf("4. Save Entries to File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(entries, &count);
                break;
            case 2:
                displayEntries(entries, count);
                break;
            case 3:
                totalSummary(entries, count);
                break;
            case 4:
                saveEntries(entries, count);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }
    }

    return 0;
}