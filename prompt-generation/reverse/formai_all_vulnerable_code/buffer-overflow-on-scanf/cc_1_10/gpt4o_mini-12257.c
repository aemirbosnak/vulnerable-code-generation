//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float amount;
    char type[10]; // "income" or "expense"
} Entry;

Entry entries[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Maximum number of entries reached.\n");
        return;
    }
    Entry newEntry;
    printf("Enter a name for the entry: ");
    scanf(" %[^\n]", newEntry.name);
    printf("Enter the amount: ");
    scanf("%f", &newEntry.amount);
    printf("Is this an income or expense? (type 'income' or 'expense'): ");
    scanf("%s", newEntry.type);
    
    entries[entryCount++] = newEntry;
    printf("Entry added successfully!\n");
}

void displayEntries() {
    printf("\n--- Personal Finance Entries ---\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%d. %s - %s: %.2f\n", 
               i + 1, entries[i].name, entries[i].type, entries[i].amount);
    }
}

float calculateTotal(const char* type) {
    float total = 0.0;
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(entries[i].type, type) == 0) {
            total += entries[i].amount;
        }
    }
    return total;
}

void displaySummary() {
    float totalIncome = calculateTotal("income");
    float totalExpense = calculateTotal("expense");
    float balance = totalIncome - totalExpense;

    printf("\n--- Financial Summary ---\n");
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expense: %.2f\n", totalExpense);
    printf("Net Balance: %.2f\n", balance);
}

void deleteEntry() {
    int index;
    displayEntries();
    printf("Enter the number of the entry you want to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > entryCount) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index - 1; i < entryCount - 1; i++) {
        entries[i] = entries[i + 1];
    }
   
    entryCount--;
    printf("Entry deleted successfully!\n");
}

void saveToFile() {
    FILE *file = fopen("financial_data.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s|%.2f|%s\n", entries[i].name, entries[i].amount, entries[i].type);
    }
    fclose(file);
    printf("Data saved to financial_data.txt successfully!\n");
}

void loadFromFile() {
    FILE *file = fopen("financial_data.txt", "r");
    if (file == NULL) {
        printf("No existing data file found. Starting fresh!\n");
        return;
    }
    
    while (fscanf(file, " %49[^|]|%f|%9s", entries[entryCount].name, &entries[entryCount].amount, entries[entryCount].type) == 3) {
        entryCount++;
        if (entryCount >= MAX_ENTRIES) break; // Avoid overflow
    }
    fclose(file);
    printf("Data loaded successfully! %d entries found.\n", entryCount);
}

void showMenu() {
    printf("\n--- Personal Finance Planner Menu ---\n");
    printf("1. Add Entry\n");
    printf("2. Display Entries\n");
    printf("3. Display Summary\n");
    printf("4. Delete Entry\n");
    printf("5. Save to File\n");
    printf("6. Load from File\n");
    printf("7. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    loadFromFile();
    
    do {
        showMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addEntry(); break;
            case 2: displayEntries(); break;
            case 3: displaySummary(); break;
            case 4: deleteEntry(); break;
            case 5: saveToFile(); break;
            case 6: loadFromFile(); break;
            case 7: printf("Exiting the program. Goodbye!\n"); break;
            default: printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 7);

    return 0;
}