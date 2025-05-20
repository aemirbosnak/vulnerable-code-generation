//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    int date;
} Expense;

void addExpense(Expense expenses[], int *numExpenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[*numExpenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*numExpenses].amount);
    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%d", &expenses[*numExpenses].date);
    (*numExpenses)++;
}

void displayExpenses(Expense expenses[], int numExpenses) {
    printf("\nExpense Report\n");
    printf("--------------------\n");
    printf("Date\tExpense Name\tAmount\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%d\t%s\t%.2f\n", expenses[i].date, expenses[i].name, expenses[i].amount);
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;

    printf("Welcome to Expense Tracker!\n");
    printf("------------------------------------\n");

    while (1) {
        printf("\n1. Add expense\n2. Display expenses\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numExpenses >= MAX_EXPENSES) {
                    printf("Maximum number of expenses reached.\n");
                } else {
                    addExpense(expenses, &numExpenses);
                }
                break;
            case 2:
                displayExpenses(expenses, numExpenses);
                break;
            case 3:
                printf("Thank you for using Expense Tracker!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}