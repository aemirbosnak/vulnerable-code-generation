//FormAI DATASET v1.0 Category: Expense Tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>

struct Expense {
    char type[20];
    float amount;
    char date[20];
    char note[50];
};

struct ExpenseTracker {
    struct Expense expense[100];
    int count;
};

void initializeTracker(struct ExpenseTracker *tracker);
void addExpense(struct ExpenseTracker *tracker);
void displayExpenses(struct ExpenseTracker tracker);
void saveExpensesToFile(struct ExpenseTracker tracker);
void loadExpensesFromFile(struct ExpenseTracker *tracker);

int main() {

    struct ExpenseTracker tracker;
    initializeTracker(&tracker);

    int choice;
    do {
        printf("\n\nExpense Tracker Menu\n");
        printf("--------------------\n\n");
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Save expenses to file\n");
        printf("4. Load expenses from file\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addExpense(&tracker); break;
            case 2: displayExpenses(tracker); break;
            case 3: saveExpensesToFile(tracker); break;
            case 4: loadExpensesFromFile(&tracker); break;
            case 5: printf("\nThank you for using the Expense Tracker. Goodbye!\n"); break;
            default: printf("\nInvalid choice. Please try again.\n"); break;
        }
    } while (choice != 5);

    return 0;
}

void initializeTracker(struct ExpenseTracker *tracker) {
    tracker->count = 0;
}

void addExpense(struct ExpenseTracker *tracker) {
    if (tracker->count == 100) {
        printf("\nExpense Tracker is full. Cannot add more expenses.\n");
        return;
    }

    printf("\nEnter expense details:\n");

    printf("Type: ");
    scanf("%s", tracker->expense[tracker->count].type);

    printf("Amount: ");
    scanf("%f", &tracker->expense[tracker->count].amount);

    printf("Date (dd/mm/yyyy): ");
    scanf("%s", tracker->expense[tracker->count].date);

    printf("Note: ");
    scanf("%s", tracker->expense[tracker->count].note);

    tracker->count++;

    printf("\nExpense added successfully.\n");
}

void displayExpenses(struct ExpenseTracker tracker) {
    if (tracker.count == 0) {
        printf("\nNo expenses to display.\n");
        return;
    }

    printf("\nExpense Details\n");
    printf("----------------\n\n");

    for (int i = 0; i < tracker.count; i++) {
        printf("Type: %s\n", tracker.expense[i].type);
        printf("Amount: %.2f\n", tracker.expense[i].amount);
        printf("Date: %s\n", tracker.expense[i].date);
        printf("Note: %s\n\n", tracker.expense[i].note);
    }
}

void saveExpensesToFile(struct ExpenseTracker tracker) {
    if (tracker.count == 0) {
        printf("\nNo expenses to save.\n");
        return;
    }

    FILE *fp = fopen("expenses.txt", "w");

    if (fp == NULL) {
        printf("\nError opening file.\n");
        return;
    }

    for (int i = 0; i < tracker.count; i++) {
        fprintf(fp, "%s %.2f %s %s\n", tracker.expense[i].type, tracker.expense[i].amount,
                                        tracker.expense[i].date, tracker.expense[i].note);
    }

    fclose(fp);

    printf("\nExpenses saved to file successfully.\n");
}

void loadExpensesFromFile(struct ExpenseTracker *tracker) {
    FILE *fp = fopen("expenses.txt", "r");

    if (fp == NULL) {
        printf("\nError opening file.\n");
        return;
    }

    initializeTracker(tracker);

    while (!feof(fp)) {
        fscanf(fp, "%s %f %s %s\n", tracker->expense[tracker->count].type,
                                    &tracker->expense[tracker->count].amount,
                                    tracker->expense[tracker->count].date,
                                    tracker->expense[tracker->count].note);
        tracker->count++;
    }

    fclose(fp);

    printf("\nExpenses loaded from file successfully.\n");
}