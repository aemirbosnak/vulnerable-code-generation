//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold an expense record
typedef struct {
    char description[100];
    float amount;
} Expense;

// Structure for the Expense Tracker
typedef struct {
    Expense* expenses;
    int count;
    int capacity;
} ExpenseTracker;

// Function prototypes
void initializeTracker(ExpenseTracker* tracker);
void recordExpense(ExpenseTracker* tracker, const char* description, float amount);
void displayExpenses(const ExpenseTracker* tracker);
void freeTracker(ExpenseTracker* tracker);

int main() {
    printf("Welcome to the Sherlock Holmes Expense Tracker!\n\n");
    
    ExpenseTracker tracker;
    initializeTracker(&tracker);
    
    while (1) {
        printf("1. Record a new expense\n");
        printf("2. Display all expenses\n");
        printf("3. Exit\n");
        printf("Please select an option: ");

        int choice;
        scanf("%d", &choice);
        
        if (choice == 1) {
            char description[100];
            float amount;
            printf("Enter expense description: ");
            getchar(); // clear the newline character
            fgets(description, sizeof(description), stdin);
            description[strcspn(description, "\n")] = 0; // Remove the newline character

            printf("Enter expense amount: ");
            scanf("%f", &amount);

            // Record the expense
            recordExpense(&tracker, description, amount);
            printf("Expense recorded successfully!\n\n");
        } else if (choice == 2) {
            displayExpenses(&tracker);
        } else if (choice == 3) {
            printf("Closing the case of the expenses. Goodbye!\n");
            break;
        } else {
            printf("Invalid option, dear Watson. Please try again.\n\n");
        }
    }

    freeTracker(&tracker);
    return 0;
}

// Initialize the expense tracker
void initializeTracker(ExpenseTracker* tracker) {
    tracker->count = 0;
    tracker->capacity = 10; // Initial capacity
    tracker->expenses = (Expense*)malloc(tracker->capacity * sizeof(Expense));
    if (!tracker->expenses) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
}

// Record a new expense
void recordExpense(ExpenseTracker* tracker, const char* description, float amount) {
    if (tracker->count >= tracker->capacity) {
        tracker->capacity *= 2;
        tracker->expenses = (Expense*)realloc(tracker->expenses, tracker->capacity * sizeof(Expense));
        if (!tracker->expenses) {
            fprintf(stderr, "Re-allocation failed!\n");
            exit(EXIT_FAILURE);
        }
    }
    strcpy(tracker->expenses[tracker->count].description, description);
    tracker->expenses[tracker->count].amount = amount;
    tracker->count++;
}

// Display all recorded expenses
void displayExpenses(const ExpenseTracker* tracker) {
    printf("Expenses recorded in the tracker:\n");
    if (tracker->count == 0) {
        printf("No expenses recorded.\n\n");
        return;
    }
    for (int i = 0; i < tracker->count; i++) {
        printf("Expense %d: %s - $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
    printf("\n");
}

// Free allocated memory in the tracker
void freeTracker(ExpenseTracker* tracker) {
    free(tracker->expenses);
}