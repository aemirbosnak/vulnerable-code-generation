//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 1000

typedef struct {
    char description[200];
    float amount;
    int date;
} Expense;

Expense expenses[MAX_EXPENSES];
int numExpenses = 0;

void addExpense() {
    if (numExpenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }

    printf("Enter expense description: ");
    scanf("%s", expenses[numExpenses].description);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[numExpenses].amount);

    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%d", &expenses[numExpenses].date);

    numExpenses++;
}

void viewExpenses() {
    printf("Expense Description | Amount | Date\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s | %.2f | %d\n", expenses[i].description, expenses[i].amount, expenses[i].date);
    }
}

void sortExpenses() {
    for (int i = 0; i < numExpenses - 1; i++) {
        for (int j = i + 1; j < numExpenses; j++) {
            if (expenses[i].date > expenses[j].date) {
                Expense temp = expenses[i];
                expenses[i] = expenses[j];
                expenses[j] = temp;
            }
        }
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");
    printf("1. Add expense\n");
    printf("2. View expenses\n");
    printf("3. Sort expenses by date\n");
    printf("4. Exit\n");

    int choice;
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                sortExpenses();
                viewExpenses();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}