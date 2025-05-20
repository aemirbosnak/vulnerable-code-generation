//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
} Expense;

void addExpense(Expense* expenses, int* numExpenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[*numExpenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*numExpenses].amount);
    (*numExpenses)++;
}

void displayExpenses(Expense* expenses, int numExpenses) {
    printf("\nExpenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s: $%.2f\n", expenses[i].name, expenses[i].amount);
    }
}

void calculateTotalExpenses(Expense* expenses, int numExpenses) {
    float totalExpenses = 0.0;
    for (int i = 0; i < numExpenses; i++) {
        totalExpenses += expenses[i].amount;
    }
    printf("\nTotal expenses: $%.2f\n", totalExpenses);
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    char choice;

    do {
        printf("\nExpense Tracker\n");
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Calculate total expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            addExpense(expenses, &numExpenses);
            break;
        case '2':
            displayExpenses(expenses, numExpenses);
            break;
        case '3':
            calculateTotalExpenses(expenses, numExpenses);
            break;
        case '4':
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= '4');

    return 0;
}