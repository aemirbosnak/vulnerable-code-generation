//FormAI DATASET v1.0 Category: Expense Tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct expense {
    char date[11]; // format: yyyy-mm-dd
    char description[50];
    double amount;
} Expense;

Expense expenses[100]; // max 100 expense entries
int numExpenses = 0;

void addExpense() {
    if (numExpenses >= 100) {
        printf("Cannot add more expenses. Maximum limit reached.\n");
        return;
    }

    Expense e;

    printf("Enter the date (in yyyy-mm-dd format): ");
    scanf("%s", e.date);

    printf("Enter a description: ");
    fflush(stdin); // clear input buffer
    fgets(e.description, 50, stdin);
    e.description[strcspn(e.description, "\n")] = '\0'; // remove trailing newline character

    printf("Enter the amount: ");
    scanf("%lf", &e.amount);

    expenses[numExpenses++] = e;

    printf("Expense added successfully!\n");
}

void listExpenses() {
    if (numExpenses == 0) {
        printf("There are no expenses.\n");
        return;
    }

    printf("%-12s %-50s %s\n", "Date", "Description", "Amount");
    for (int i = 0; i < numExpenses; i++) {
        printf("%-12s %-50s $ %.2lf\n", expenses[i].date, expenses[i].description, expenses[i].amount);
    }
}

void totalExpenses() {
    double total = 0;
    for (int i = 0; i < numExpenses; i++) {
        total += expenses[i].amount;
    }

    printf("Total expenses: $ %.2lf\n", total);
}

int main() {
    int choice;
    do {
        printf("\nExpense Tracker\n");
        printf("===============\n");
        printf("1. Add expense\n");
        printf("2. List expenses\n");
        printf("3. Total expenses\n");
        printf("4. Exit\n");

        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                listExpenses();
                break;
            case 3:
                totalExpenses();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}