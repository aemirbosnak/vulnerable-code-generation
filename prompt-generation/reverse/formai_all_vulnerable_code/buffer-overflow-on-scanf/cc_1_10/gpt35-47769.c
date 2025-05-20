//FormAI DATASET v1.0 Category: Expense Tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
    char item[20];
    float amount;
} Expense;

typedef struct {
    Expense expense[MAX];
    float total;
    int count;
} ExpenseTracker;

void addExpense(ExpenseTracker *, char[], float);
void printExpenses(ExpenseTracker *);
void calculateTotal(ExpenseTracker *);

int main() {
    char item[20];
    float amount;
    ExpenseTracker tracker;
    tracker.total = 0;
    tracker.count = 0;
    printf("Expense Tracker\n\n");
    while(1) {
        printf("Enter item name or 'q' to quit: ");
        fgets(item, sizeof(item), stdin);
        if(item[0] == 'q' && strlen(item) == 2) {
            break;
        }
        printf("Enter item amount: $");
        scanf("%f", &amount);
        getchar();
        addExpense(&tracker, item, amount);
    }
    printExpenses(&tracker);
    calculateTotal(&tracker);
    printf("Total spendings: $%.2f\n", tracker.total);
    return 0;
}

void addExpense(ExpenseTracker *tracker, char item[], float amount) {
    if(tracker->count == MAX) {
        printf("No more items can be added.\n");
    }
    else {
        strncpy(tracker->expense[tracker->count].item, item, sizeof(tracker->expense[tracker->count].item) - 1);
        tracker->expense[tracker->count].amount = amount;
        tracker->count++;
    }
}

void printExpenses(ExpenseTracker *tracker) {
    printf("\nExpense list:\n");
    for(int i = 0; i < tracker->count; i++) {
        printf("%s\t\t$%.2f\n", tracker->expense[i].item, tracker->expense[i].amount);
    }
}

void calculateTotal(ExpenseTracker *tracker) {
    for(int i = 0; i < tracker->count; i++) {
        tracker->total += tracker->expense[i].amount;
    }
}