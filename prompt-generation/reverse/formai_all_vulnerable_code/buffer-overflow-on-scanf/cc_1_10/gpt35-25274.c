//FormAI DATASET v1.0 Category: Expense Tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float amount;
} Expense;

typedef struct {
    Expense *expenses;
    int numExpenses;
} ExpenseTracker;

void addExpense(ExpenseTracker *tracker, char name[], float amount) {
    tracker->numExpenses++;
    tracker->expenses = realloc(tracker->expenses, tracker->numExpenses * sizeof(Expense));
    strcpy(tracker->expenses[tracker->numExpenses-1].name, name);
    tracker->expenses[tracker->numExpenses-1].amount = amount;
}

void viewExpenses(ExpenseTracker tracker) {
    printf("%-20s %s\n", "Expense", "Amount");
    for (int i = 0; i < tracker.numExpenses; i++) {
        printf("%-20s $%.2f\n", tracker.expenses[i].name, tracker.expenses[i].amount);
    }
}

int main() {
    int numPlayers;
    printf("Enter number of players: ");
    scanf("%d", &numPlayers);

    ExpenseTracker *trackers = malloc(numPlayers * sizeof(ExpenseTracker));
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter player %d's name: ", i+1);
        char name[50];
        scanf("%s", name);
        trackers[i].expenses = NULL;
        trackers[i].numExpenses = 0;
    }

    int currentPlayer = 0;
    int done = 0;
    while (!done) {
        printf("Player %d's turn:\n", currentPlayer+1);
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. End turn\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter expense name: ");
                char name[50];
                scanf("%s", name);
                printf("Enter expense amount: ");
                float amount;
                scanf("%f", &amount);
                addExpense(&trackers[currentPlayer], name, amount);
                break;
            case 2:
                viewExpenses(trackers[currentPlayer]);
                break;
            case 3:
                currentPlayer = (currentPlayer + 1) % numPlayers;
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }

        done = 1;
        for (int i = 0; i < numPlayers; i++) {
            if (trackers[i].numExpenses == 0 || (i != currentPlayer && trackers[i].numExpenses != trackers[currentPlayer].numExpenses)) {
                done = 0;
                break;
            }
        }
    }

    printf("Expenses:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d:\n", i+1);
        viewExpenses(trackers[i]);
        printf("\n");
        free(trackers[i].expenses);
    }
    free(trackers);
    
    return 0;
}