//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    int date;
    int month;
    int year;
} Expense;

void addExpense(Expense expenses[], int *numExpenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[*numExpenses].name);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[*numExpenses].amount);

    printf("Enter expense date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &expenses[*numExpenses].date, &expenses[*numExpenses].month, &expenses[*numExpenses].year);

    (*numExpenses)++;
}

void displayExpenses(Expense expenses[], int numExpenses) {
    printf("\nExpenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s\t%.2f\t%d/%d/%d\n", expenses[i].name, expenses[i].amount, expenses[i].date, expenses[i].month, expenses[i].year);
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;

    printf("Welcome to the Expense Tracker!\n");

    while (numExpenses < MAX_EXPENSES) {
        printf("\n1. Add expense\n2. Display expenses\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                displayExpenses(expenses, numExpenses);
                break;
            case 3:
                printf("Thank you for using the Expense Tracker!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}