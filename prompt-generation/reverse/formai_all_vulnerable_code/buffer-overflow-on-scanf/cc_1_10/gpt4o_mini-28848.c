//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_DESC_LEN 50

typedef struct {
    char description[MAX_DESC_LEN];
    float amount;
    int isIncome; // 1 for income, 0 for expense
} Entry;

Entry entries[MAX_ENTRIES];
int entryCount = 0;

void addEntry(float amount, const char *description, int isIncome) {
    if (entryCount < MAX_ENTRIES) {
        entries[entryCount].amount = amount;
        strncpy(entries[entryCount].description, description, MAX_DESC_LEN);
        entries[entryCount].isIncome = isIncome;
        entryCount++;
    } else {
        printf("Max entries limit reached. Cannot add more entries.\n");
    }
}

void displayEntries() {
    printf("\n--- Financial Entries ---\n");
    for (int i = 0; i < entryCount; i++) {
        const char *type = entries[i].isIncome ? "Income" : "Expense";
        printf("%s: %s - $%.2f\n", type, entries[i].description, entries[i].amount);
    }
    printf("-------------------------\n");
}

float calculateTotalIncome() {
    float total = 0.0;
    for (int i = 0; i < entryCount; i++) {
        if (entries[i].isIncome) {
            total += entries[i].amount;
        }
    }
    return total;
}

float calculateTotalExpenses() {
    float total = 0.0;
    for (int i = 0; i < entryCount; i++) {
        if (!entries[i].isIncome) {
            total += entries[i].amount;
        }
    }
    return total;
}

void displaySummary() {
    float totalIncome = calculateTotalIncome();
    float totalExpenses = calculateTotalExpenses();
    float balance = totalIncome - totalExpenses;
    
    printf("\n--- Financial Summary ---\n");
    printf("Total Income: $%.2f\n", totalIncome);
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Balance: $%.2f\n", balance);
    printf("-------------------------\n");
}

void clearEntries() {
    entryCount = 0;
    printf("All entries have been cleared.\n");
}

int main() {
    int choice;
    float amount;
    char description[MAX_DESC_LEN];
    
    do {
        printf("\n--- Personal Finance Planner ---\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Display Entries\n");
        printf("4. Display Summary\n");
        printf("5. Clear All Entries\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter income amount: ");
                scanf("%f", &amount);
                printf("Enter income description: ");
                getchar(); // to consume the newline character
                fgets(description, MAX_DESC_LEN, stdin);
                description[strcspn(description, "\n")] = 0; // remove newline
                addEntry(amount, description, 1);
                break;
            case 2:
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                printf("Enter expense description: ");
                getchar();
                fgets(description, MAX_DESC_LEN, stdin);
                description[strcspn(description, "\n")] = 0; // remove newline
                addEntry(amount, description, 0);
                break;
            case 3:
                displayEntries();
                break;
            case 4:
                displaySummary();
                break;
            case 5:
                clearEntries();
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}