//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define MAX_DESC_LENGTH 50

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
} Transaction;

typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int count;
} ExpenseTracker;

void initializeTracker(ExpenseTracker *tracker) {
    tracker->count = 0;
}

void addTransaction(ExpenseTracker *tracker, const char *description, float amount) {
    if (tracker->count < MAX_TRANSACTIONS) {
        strncpy(tracker->transactions[tracker->count].description, description, MAX_DESC_LENGTH - 1);
        tracker->transactions[tracker->count].description[MAX_DESC_LENGTH - 1] = '\0'; // Ensure null-termination
        tracker->transactions[tracker->count].amount = amount;
        tracker->count++;
    } else {
        printf("Transaction limit reached!\n");
    }
}

void displayTransactions(const ExpenseTracker *tracker) {
    printf("\n--- Expense Transactions ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d: %s - $%.2f\n", i + 1, tracker->transactions[i].description, tracker->transactions[i].amount);
    }
    printf("--- End Transactions ---\n\n");
}

float calculateTotal(const ExpenseTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->transactions[i].amount;
    }
    return total;
}

void saveToFile(const ExpenseTracker *tracker, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s,%.2f\n", tracker->transactions[i].description, tracker->transactions[i].amount);
    }
    fclose(file);
    printf("Transactions saved to %s\n", filename);
}

void loadFromFile(ExpenseTracker *tracker, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    while (tracker->count < MAX_TRANSACTIONS && !feof(file)) {
        char line[MAX_DESC_LENGTH + 20];
        if (fgets(line, sizeof(line), file) != NULL) {
            char *description = strtok(line, ",");
            char *amount_str = strtok(NULL, ",");
            if (description && amount_str) {
                addTransaction(tracker, description, atof(amount_str));
            }
        }
    }
    fclose(file);
    printf("Transactions loaded from %s\n", filename);
}

void manageExpenses() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);
    char command[20];
    char filename[50];

    while (1) {
        printf("Enter command (add, display, total, save, load, exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char description[MAX_DESC_LENGTH];
            float amount;
            printf("Enter description: ");
            scanf(" %[^\n]", description);
            printf("Enter amount: ");
            scanf("%f", &amount);
            addTransaction(&tracker, description, amount);

        } else if (strcmp(command, "display") == 0) {
            displayTransactions(&tracker);

        } else if (strcmp(command, "total") == 0) {
            printf("Total expenses: $%.2f\n", calculateTotal(&tracker));

        } else if (strcmp(command, "save") == 0) {
            printf("Enter filename: ");
            scanf("%s", filename);
            saveToFile(&tracker, filename);

        } else if (strcmp(command, "load") == 0) {
            printf("Enter filename: ");
            scanf("%s", filename);
            loadFromFile(&tracker, filename);

        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting Expense Tracker.\n");
            break;

        } else {
            printf("Unknown command. Please try again.\n");
        }
    }
}

int main() {
    manageExpenses();
    return 0;
}