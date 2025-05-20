//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    char category[50];
} Expense;

void addExpense(Expense* expenses, int* numExpenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[*numExpenses].name);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[*numExpenses].amount);

    printf("Enter expense category: ");
    scanf("%s", expenses[*numExpenses].category);

    (*numExpenses)++;
}

void printExpenses(Expense* expenses, int numExpenses) {
    printf("\nExpenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s - %.2f - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;

    printf("Welcome to the Expense Tracker!\n");

    while (numExpenses < MAX_EXPENSES) {
        printf("\nEnter 1 to add an expense or 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            addExpense(expenses, &numExpenses);
        } else if (choice!= 0) {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("\nYour expenses:\n");
    printExpenses(expenses, numExpenses);

    return 0;
}