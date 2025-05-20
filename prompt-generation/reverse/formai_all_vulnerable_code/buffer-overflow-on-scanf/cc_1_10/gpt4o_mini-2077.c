//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_DESCRIPTION_LENGTH 50
#define COMMAND_LENGTH 10

typedef struct {
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense entries[MAX_ENTRIES];
    int count;
} ExpenseTracker;

void addExpense(ExpenseTracker *tracker, const char *description, float amount) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("The wasteland has no more room for expenses.\n");
        return;
    }
    strncpy(tracker->entries[tracker->count].description, description, MAX_DESCRIPTION_LENGTH);
    tracker->entries[tracker->count].amount = amount;
    tracker->count++;
    printf("Added expense: %s - %.2f scraps\n", description, amount);
}

void listExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded in the desolate realm...\n");
        return;
    }

    printf("Expenses recorded in the wasteland:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s - %.2f scraps\n", i + 1, tracker->entries[i].description, tracker->entries[i].amount);
    }
}

float calculateTotal(const ExpenseTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->entries[i].amount;
    }
    return total;
}

void clearExpenses(ExpenseTracker *tracker) {
    tracker->count = 0;
    printf("Cleared all expenses from the wasteland...\n");
}

void displayCommands() {
    printf("Commands:\n");
    printf("  add <description> <amount> - Add an expense\n");
    printf("  list - List all expenses\n");
    printf("  total - Show total expenses\n");
    printf("  clear - Remove all expenses\n");
    printf("  exit - Leave the wasteland\n");
}

int main() {
    ExpenseTracker tracker = { .count = 0 };
    char command[COMMAND_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;

    printf("Welcome to the Wasteland Expense Tracker!\n");
    printf("Life is tough out here. Keep track of your resources wisely...\n");

    while (1) {
        printf(">> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter description: ");
            getchar(); // to consume newline
            fgets(description, MAX_DESCRIPTION_LENGTH, stdin);
            description[strcspn(description, "\n")] = 0; // remove newline character

            printf("Enter amount (in scraps): ");
            scanf("%f", &amount);

            addExpense(&tracker, description, amount);
        } else if (strcmp(command, "list") == 0) {
            listExpenses(&tracker);
        } else if (strcmp(command, "total") == 0) {
            printf("Total expenses: %.2f scraps\n", calculateTotal(&tracker));
        } else if (strcmp(command, "clear") == 0) {
            clearExpenses(&tracker);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the wasteland. Stay safe out there...\n");
            break;
        } else {
            printf("Unknown command. Please try again...\n");
        }
        
        displayCommands();
    }

    return 0;
}