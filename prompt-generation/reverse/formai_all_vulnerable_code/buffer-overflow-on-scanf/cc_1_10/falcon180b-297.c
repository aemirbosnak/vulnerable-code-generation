//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    char category[50];
} Expense;

void addExpense(Expense expenses[], int numExpenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[numExpenses].name);
    printf("Enter expense amount: $");
    scanf("%f", &expenses[numExpenses].amount);
    printf("Enter expense category: ");
    scanf("%s", expenses[numExpenses].category);
    numExpenses++;
}

void displayExpenses(Expense expenses[], int numExpenses) {
    printf("\nExpense Name\tAmount\tCategory\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s\t\t$%.2f\t%s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void sortExpenses(Expense expenses[], int numExpenses) {
    for (int i = 0; i < numExpenses - 1; i++) {
        for (int j = i + 1; j < numExpenses; j++) {
            if (expenses[i].amount > expenses[j].amount) {
                Expense temp = expenses[i];
                expenses[i] = expenses[j];
                expenses[j] = temp;
            }
        }
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;

    while (numExpenses < MAX_EXPENSES) {
        printf("1. Add expense\n2. Display expenses\n3. Sort expenses\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, numExpenses);
                break;
            case 2:
                displayExpenses(expenses, numExpenses);
                break;
            case 3:
                sortExpenses(expenses, numExpenses);
                printf("\nSorted expenses:\n");
                displayExpenses(expenses, numExpenses);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}