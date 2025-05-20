//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESC_LEN 50

typedef struct {
    char description[MAX_DESC_LEN];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

// Function declarations
void addExpense(ExpenseTracker *tracker);
void viewExpenses(const ExpenseTracker *tracker);
void romanceAndBalance(const ExpenseTracker *tracker);
float calculateTotal(const ExpenseTracker *tracker);

int main() {
    ExpenseTracker tracker = {{0}, 0};
    int choice;

    // A love story begins...
    while (1) {
        printf("\n--- Expense Tracker: A Love Story ---\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Check Total Expenses\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                viewExpenses(&tracker);
                break;
            case 3:
                romanceAndBalance(&tracker);
                break;
            case 4:
                printf("Thank you for sharing your love story with me. Farewell!\n");
                return 0;
            default:
                printf("Ah, the path is unclear. Please choose a valid option.\n");
        }
    }
}

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Love can be overwhelming; no more expenses can be added!\n");
        return;
    }

    printf("Enter a sweet description of your expense (up to %d characters): ", MAX_DESC_LEN - 1);
    scanf(" %[^\n]", tracker->expenses[tracker->count].description);
    printf("Whisper the amount spent: ");
    scanf("%f", &tracker->expenses[tracker->count].amount);

    printf("Your expense, a testament to love's journey, has been noted.\n");
    tracker->count++;
}

void viewExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("Ah, the heart is empty; no expenses to share.\n");
        return;
    }

    printf("\nYour romantic journey of expenses:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s | Amount: $%.2f\n",
               i + 1,
               tracker->expenses[i].description,
               tracker->expenses[i].amount);
    }
}

void romanceAndBalance(const ExpenseTracker *tracker) {
    float total = calculateTotal(tracker);
    printf("The total amount spent in this beautiful adventure of love is: $%.2f\n", total);
}

float calculateTotal(const ExpenseTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}