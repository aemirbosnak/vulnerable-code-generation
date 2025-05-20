//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LENGTH 50

typedef struct {
    char description[DESCRIPTION_LENGTH];
    float amount;
    char date[11];  // Format: YYYY-MM-DD
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void add_expense(ExpenseTracker *tracker, const char *description, float amount, const char *date) {
    if (tracker->count < MAX_EXPENSES) {
        strncpy(tracker->expenses[tracker->count].description, description, DESCRIPTION_LENGTH - 1);
        tracker->expenses[tracker->count].description[DESCRIPTION_LENGTH - 1] = '\0';
        tracker->expenses[tracker->count].amount = amount;
        strncpy(tracker->expenses[tracker->count].date, date, 10);
        tracker->expenses[tracker->count].date[10] = '\0';
        tracker->count++;
        printf("Expense added: %s, Amount: %.2f, Date: %s\n", description, amount, date);
    } else {
        printf("Expense limit reached!\n");
    }
}

void display_expenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses logged.\n");
        return;
    }
    printf("\n--- Expenses ---\n");
    for (int i = 0; i < tracker->count; ++i) {
        printf("ID: %d | Description: %s | Amount: %.2f | Date: %s\n",
               i + 1, tracker->expenses[i].description, tracker->expenses[i].amount, tracker->expenses[i].date);
    }
    printf("----------------\n");
}

float calculate_total(const ExpenseTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; ++i) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

void save_to_file(const ExpenseTracker *tracker, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file) {
        for (int i = 0; i < tracker->count; ++i) {
            fprintf(file, "%s,%.2f,%s\n", tracker->expenses[i].description,
                    tracker->expenses[i].amount, tracker->expenses[i].date);
        }
        fclose(file);
        printf("Expenses saved to '%s'.\n", filename);
    } else {
        printf("Error saving to file!\n");
    }
}

void load_from_file(ExpenseTracker *tracker, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        while (tracker->count < MAX_EXPENSES && !feof(file)) {
            char line[100];
            if (fgets(line, sizeof(line), file)) {
                char description[DESCRIPTION_LENGTH];
                float amount;
                char date[11];
                sscanf(line, "%49[^,],%f,%10[^,]", description, &amount, date);
                add_expense(tracker, description, amount, date);
            }
        }
        fclose(file);
        printf("Expenses loaded from '%s'.\n", filename);
    } else {
        printf("Error loading from file!\n");
    }
}

void display_menu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. Display Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Save Expenses to File\n");
    printf("5. Load Expenses from File\n");
    printf("6. Exit\n");
    printf("----------------------------\n");
    printf("Enter your choice: ");
}

int main() {
    ExpenseTracker tracker = {.count = 0};
    int choice;
    char description[DESCRIPTION_LENGTH];
    float amount;
    char date[11];
    const char *filename = "expenses.txt";

    while (1) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter description: ");
                getchar(); // Clear the newline from the input buffer
                fgets(description, DESCRIPTION_LENGTH, stdin);
                description[strcspn(description, "\n")] = 0; // Remove newline
                printf("Enter amount: ");
                scanf("%f", &amount);
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);
                add_expense(&tracker, description, amount, date);
                break;

            case 2:
                display_expenses(&tracker);
                break;

            case 3:
                printf("Total Expenses: %.2f\n", calculate_total(&tracker));
                break;

            case 4:
                save_to_file(&tracker, filename);
                break;

            case 5:
                load_from_file(&tracker, filename);
                break;

            case 6:
                printf("Exiting the Expense Tracker. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}