//FormAI DATASET v1.0 Category: Expense Tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[11];
    char description[1024];
    float amount;
} ExpenseEntry;

int numEntries = 0;
ExpenseEntry expenseEntries[MAX_ENTRIES];

void addEntry() {
    ExpenseEntry newEntry;
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", newEntry.date);
    printf("Enter description: ");
    scanf("%s", newEntry.description);
    printf("Enter amount: ");
    scanf("%f", &newEntry.amount);
    expenseEntries[numEntries] = newEntry;
    numEntries++;
    printf("New expense entry added!\n");
}

void printEntries() {
    if(numEntries == 0) {
        printf("No expense entries yet.\n");
        return;
    }
    printf("%d expense entries:\n", numEntries);
    for(int i = 0; i < numEntries; i++) {
        ExpenseEntry currentEntry = expenseEntries[i];
        printf("%s - %s - %.2f\n", currentEntry.date, currentEntry.description, currentEntry.amount);
    }
}

void saveToFile() {
    char filename[1024];
    printf("Enter filename to save to: ");
    scanf("%s", filename);
    FILE *fp = fopen(filename, "w");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for(int i = 0; i < numEntries; i++) {
        ExpenseEntry currentEntry = expenseEntries[i];
        fprintf(fp, "%s,%s,%.2f\n", currentEntry.date, currentEntry.description, currentEntry.amount);
    }
    fclose(fp);
    printf("Expense entries saved to file.\n");
}

void loadFromFile() {
    char filename[1024];
    printf("Enter filename to load from: ");
    scanf("%s", filename);
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    numEntries = 0;
    char line[2048];
    while(fgets(line, sizeof(line), fp)) {
        char *token;
        token = strtok(line, ",");
        ExpenseEntry newEntry;
        strcpy(newEntry.date, token);
        token = strtok(NULL, ",");
        strcpy(newEntry.description, token);
        token = strtok(NULL, ",");
        newEntry.amount = atof(token);
        expenseEntries[numEntries] = newEntry;
        numEntries++;
    }
    fclose(fp);
    printf("Expense entries loaded from file.\n");
}

int main() {
    printf("Welcome to My Expense Tracker!\n");
    int choice = -1;
    while(choice != 0) {
        printf("\nMenu:\n");
        printf("1. Add expense entry\n");
        printf("2. View all expense entries\n");
        printf("3. Save expense entries to file\n");
        printf("4. Load expense entries from file\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addEntry(); break;
            case 2: printEntries(); break;
            case 3: saveToFile(); break;
            case 4: loadFromFile(); break;
            case 0: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n"); break;
        }
    }

    return 0;
}