//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float amount;
    time_t date;
} Expense;

Expense expenses[MAX_ITEMS];
int numExpenses = 0;

void addExpense() {
    printf("Enter expense name: ");
    scanf("%s", expenses[numExpenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[numExpenses].amount);
    time_t now = time(NULL);
    expenses[numExpenses].date = now;
    numExpenses++;
}

void viewExpenses() {
    printf("Expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s: $%.2f on %s\n", expenses[i].name, expenses[i].amount, ctime(&expenses[i].date));
    }
}

void viewExpenseStats() {
    float totalExpenses = 0;
    int numExpensesThisMonth = 0;
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    int month = tm->tm_mon + 1; // Months are 0-indexed in tm struct

    printf("Expense Statistics:\n");
    printf("Total expenses: $%.2f\n", totalExpenses);
    printf("Expenses this month: $%.2f\n", totalExpenses);
    printf("Average expense amount: $%.2f\n", totalExpenses / numExpenses);
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. View expense statistics\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addExpense();
            break;
        case 2:
            viewExpenses();
            break;
        case 3:
            viewExpenseStats();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}