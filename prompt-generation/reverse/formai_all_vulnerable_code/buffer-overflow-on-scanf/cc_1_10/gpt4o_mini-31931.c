//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_DESC 50

typedef struct {
    char description[MAX_DESC];
    float amount;
    char type; // 'I' for income, 'E' for expense
} Entry;

Entry entries[MAX_ENTRIES];
int entryCount = 0;

void addEntry(const char *description, float amount, char type) {
    if (entryCount >= MAX_ENTRIES) {
        printf("Cannot add more entries. Limit reached.\n");
        return;
    }
    
    strncpy(entries[entryCount].description, description, MAX_DESC);
    entries[entryCount].amount = amount;
    entries[entryCount].type = type;
    entryCount++;
}

void printSummary() {
    float totalIncome = 0;
    float totalExpense = 0;
    
    printf("\nPersonal Finance Summary:\n");
    printf("--------------------------\n");
    for (int i = 0; i < entryCount; i++) {
        if (entries[i].type == 'I') {
            totalIncome += entries[i].amount;
            printf("Income: %s - $%.2f\n", entries[i].description, entries[i].amount);
        } else if (entries[i].type == 'E') {
            totalExpense += entries[i].amount;
            printf("Expense: %s - $%.2f\n", entries[i].description, entries[i].amount);
        }
    }
    
    printf("--------------------------\n");
    printf("Total Income: $%.2f\n", totalIncome);
    printf("Total Expense: $%.2f\n", totalExpense);
    printf("Net Income: $%.2f\n", totalIncome - totalExpense);
}

void printMenu() {
    printf("\nPersonal Finance Planner\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. Print Summary\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    char description[MAX_DESC];
    float amount;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter income description: ");
                scanf(" %[^\n]", description);
                printf("Enter income amount: ");
                scanf("%f", &amount);
                addEntry(description, amount, 'I');
                break;
                
            case 2:
                printf("Enter expense description: ");
                scanf(" %[^\n]", description);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                addEntry(description, amount, 'E');
                break;
                
            case 3:
                printSummary();
                break;

            case 4:
                printf("Exiting the planner. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}