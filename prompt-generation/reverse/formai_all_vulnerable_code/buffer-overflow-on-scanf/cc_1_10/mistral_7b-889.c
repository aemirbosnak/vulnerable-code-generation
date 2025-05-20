//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Define some cryptic structures and functions

typedef struct {
    char name[50];
    float amount;
    int id;
} Expense;

typedef struct {
    Expense expenses[100];
    int count;
} ExpenseTracker;

void pushExpense(ExpenseTracker *tracker, const char *name, float amount);
void printExpenses(const ExpenseTracker *tracker);
void clearTracker(ExpenseTracker *tracker);

void pushExpense(ExpenseTracker *tracker, const char *name, float amount) {
    if (tracker->count == 100) {
        printf("Tracker is full.\n");
        return;
    }

    strcpy(tracker->expenses[tracker->count].name, name);
    tracker->expenses[tracker->count].amount = amount;
    tracker->expenses[tracker->count].id = tracker->count;
    tracker->count++;
}

void printExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("Expenses:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("ID: %d, Name: %s, Amount: %.2f\n", tracker->expenses[i].id, tracker->expenses[i].name, tracker->expenses[i].amount);
    }
}

void clearTracker(ExpenseTracker *tracker) {
    tracker->count = 0;
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    ExpenseTracker tracker = {0};

    char name[50];
    float amount;
    int choice;

    while (1) {
        printf("\n1. Record Expense\n2. Print Expenses\n3. Clear Tracker\n4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter expense name: ");
                scanf("%s", name);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                pushExpense(&tracker, name, amount);
                break;
            case 2:
                printExpenses(&tracker);
                break;
            case 3:
                clearTracker(&tracker);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}