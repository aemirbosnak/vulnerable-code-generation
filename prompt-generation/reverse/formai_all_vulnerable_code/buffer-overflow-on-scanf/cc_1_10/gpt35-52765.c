//FormAI DATASET v1.0 Category: Expense Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char date[11];
    char description[50];
    float amount;
} Expense;

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    char choice;

    while (1) {
        printf("Press 'a' to add an expense or 'q' to quit: ");
        scanf(" %c", &choice);

        if (choice == 'q') {
            break;
        } else if (choice == 'a') {
            Expense e;
            printf("Enter the date (mm/dd/yyyy): ");
            scanf(" %10[^\n]", e.date);
            printf("Enter the description (maximum 50 characters): ");
            scanf(" %50[^\n]", e.description);
            printf("Enter the amount: ");
            scanf(" %f", &e.amount);

            expenses[numExpenses++] = e;
            printf("Expense added successfully!\n");
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    float total = 0;
    printf("\n------------------------------------\n");
    printf("| Date       | Description          | Amount |\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < numExpenses; i++) {
        Expense e = expenses[i];
        printf("| %10s | %-20s | $%.2f |\n", e.date, e.description, e.amount);
        total += e.amount;
    }
    printf("-----------------------------------------\n");
    printf("| Total      |                      | $%.2f |\n", total);
    printf("-----------------------------------------\n");

    return 0;
}