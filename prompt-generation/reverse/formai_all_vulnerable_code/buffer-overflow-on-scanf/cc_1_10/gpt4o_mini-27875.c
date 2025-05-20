//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESC_LENGTH 100

struct Expense {
    char description[MAX_DESC_LENGTH];
    float amount;
};

struct ExpenseTracker {
    struct Expense expenses[MAX_EXPENSES];
    int count;
};

void initialize_tracker(struct ExpenseTracker *tracker) {
    tracker->count = 0;
}

void add_expense(struct ExpenseTracker *tracker, const char *description, float amount) {
    if (tracker->count < MAX_EXPENSES) {
        strncpy(tracker->expenses[tracker->count].description, description, MAX_DESC_LENGTH);
        tracker->expenses[tracker->count].amount = amount;
        tracker->count++;
    } else {
        printf("Error: Expense tracker is full.\n");
    }
}

void display_expenses(struct ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    printf("\nExpenses Recorded:\n");
    printf("%-30s %10s\n", "Description", "Amount");
    printf("---------------------------------------\n");
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        printf("%-30s $%9.2f\n", tracker->expenses[i].description, tracker->expenses[i].amount);
        total += tracker->expenses[i].amount;
    }
    printf("---------------------------------------\n");
    printf("Total Expenses: $%.2f\n", total);
}

void save_expenses_to_file(struct ExpenseTracker *tracker, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }
    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s,%f\n", tracker->expenses[i].description, tracker->expenses[i].amount);
    }
    fclose(file);
    printf("Expenses saved to %s\n", filename);
}

void load_expenses_from_file(struct ExpenseTracker *tracker, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file for reading.\n");
        return;
    }
    char line[256];
    while (fgets(line, sizeof(line), file) && tracker->count < MAX_EXPENSES) {
        char description[MAX_DESC_LENGTH];
        float amount;
        sscanf(line, "%[^,],%f", description, &amount);
        add_expense(tracker, description, amount);
    }
    fclose(file);
    printf("Expenses loaded from %s\n", filename);
}

int main() {
    struct ExpenseTracker tracker;
    initialize_tracker(&tracker);
    
    int choice;
    char filename[100];

    while (1) {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. Show Expenses\n");
        printf("3. Save Expenses to File\n");
        printf("4. Load Expenses from File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                char description[MAX_DESC_LENGTH];
                float amount;
                printf("Enter description: ");
                getchar(); // Clear newline
                fgets(description, MAX_DESC_LENGTH, stdin);
                description[strcspn(description, "\n")] = 0; // Remove newline
                printf("Enter amount: ");
                scanf("%f", &amount);
                add_expense(&tracker, description, amount);
                break;
            }
            case 2:
                display_expenses(&tracker);
                break;
            case 3:
                printf("Enter file name: ");
                scanf("%s", filename);
                save_expenses_to_file(&tracker, filename);
                break;
            case 4:
                printf("Enter file name: ");
                scanf("%s", filename);
                load_expenses_from_file(&tracker, filename);
                break;
            case 5:
                printf("Exiting the Expense Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}