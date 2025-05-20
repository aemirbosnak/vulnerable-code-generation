//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_CATEGORY_LENGTH 30
#define MAX_DESCRIPTION_LENGTH 50

typedef struct {
    char category[MAX_CATEGORY_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_ENTRIES];
    int count;
} ExpenseTracker;

void initializeTracker(ExpenseTracker *tracker) {
    tracker->count = 0;
}

void addExpense(ExpenseTracker *tracker, const char *category, const char *description, float amount) {
    if (tracker->count < MAX_ENTRIES) {
        strcpy(tracker->expenses[tracker->count].category, category);
        strcpy(tracker->expenses[tracker->count].description, description);
        tracker->expenses[tracker->count].amount = amount;
        tracker->count++;
        printf("Expense added successfully!\n");
    } else {
        printf("Expense tracker is full!\n");
    }
}

void listExpenses(const ExpenseTracker *tracker) {
    printf("\n--- Expense List ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Category: %s, Description: %s, Amount: %.2f\n",
               tracker->expenses[i].category, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
}

float calculateTotalExpenses(const ExpenseTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

void saveToFile(const ExpenseTracker *tracker, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        for (int i = 0; i < tracker->count; i++) {
            fprintf(file, "%s,%s,%.2f\n",
                    tracker->expenses[i].category,
                    tracker->expenses[i].description,
                    tracker->expenses[i].amount);
        }
        fclose(file);
        printf("Expenses saved to %s successfully!\n", filename);
    } else {
        printf("Error saving expenses to file.\n");
    }
}

void loadFromFile(ExpenseTracker *tracker, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        while (!feof(file) && tracker->count < MAX_ENTRIES) {
            char line[100];
            if (fgets(line, sizeof(line), file)) {
                Expense exp;
                char *token = strtok(line, ",");
                if (token != NULL) strcpy(exp.category, token);
                token = strtok(NULL, ",");
                if (token != NULL) strcpy(exp.description, token);
                token = strtok(NULL, ",");
                if (token != NULL) exp.amount = atof(token);
                tracker->expenses[tracker->count] = exp;
                tracker->count++;
            }
        }
        fclose(file);
        printf("Expenses loaded from %s successfully!\n", filename);
    } else {
        printf("Error loading expenses from file.\n");
    }
}

int main() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);
    
    int choice;
    char category[MAX_CATEGORY_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
    char filename[50] = "expenses.csv";

    do {
        printf("\n--- Expense Tracker Menu ---\n");
        printf("1. Add Expense\n");
        printf("2. List Expenses\n");
        printf("3. Calculate Total Expenses\n");
        printf("4. Save Expenses to File\n");
        printf("5. Load Expenses from File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter category: ");
                scanf(" %29[^\n]", category);
                printf("Enter description: ");
                scanf(" %49[^\n]", description);
                printf("Enter amount: ");
                scanf("%f", &amount);
                addExpense(&tracker, category, description, amount);
                break;
            case 2:
                listExpenses(&tracker);
                break;
            case 3:
                printf("Total Expenses: %.2f\n", calculateTotalExpenses(&tracker));
                break;
            case 4:
                saveToFile(&tracker, filename);
                break;
            case 5:
                loadFromFile(&tracker, filename);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}