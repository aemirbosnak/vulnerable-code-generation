//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char description[50];
    float amount;
    char date[20];
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
    scanf("%s", expenses[numExpenses].date);

    numExpenses++;
}

void displayExpenses() {
    printf("\nExpenses:\n");
    printf("ID\tDescription\tAmount\tDate\n");

    for (int i = 0; i < numExpenses; i++) {
        printf("%d\t%s\t%.2f\t%s\n", i+1, expenses[i].description, expenses[i].amount, expenses[i].date);
    }
}

void searchExpense() {
    char searchTerm[50];

    printf("Enter search term: ");
    scanf("%s", searchTerm);

    for (int i = 0; i < numExpenses; i++) {
        if (strstr(expenses[i].description, searchTerm)) {
            printf("\nExpense found:\n");
            printf("ID: %d\n", i+1);
            printf("Description: %s\n", expenses[i].description);
            printf("Amount: %.2f\n", expenses[i].amount);
            printf("Date: %s\n", expenses[i].date);
        }
    }
}

void main() {
    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("\nOptions:\n1. Add expense\n2. Display expenses\n3. Search expense\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                displayExpenses();
                break;
            case 3:
                searchExpense();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}