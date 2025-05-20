//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    char category[50];
} Expense;

void addExpense(Expense expenses[], int *numExpenses) {
    printf("Enter expense name: ");
    scanf("%s", (*numExpenses)? expenses[*numExpenses - 1].name : "");
    printf("Enter expense amount: ");
    scanf("%f", (*numExpenses)? &expenses[*numExpenses - 1].amount : &expenses[*numExpenses].amount);
    printf("Enter expense category: ");
    scanf("%s", (*numExpenses)? expenses[*numExpenses - 1].category : &expenses[*numExpenses].category);
    (*numExpenses)++;
}

void displayExpenses(Expense expenses[], int numExpenses) {
    printf("\nExpenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%d. %s - %.2f - %s\n", i + 1, expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;

    addExpense(expenses, &numExpenses);

    while (numExpenses < MAX_EXPENSES) {
        int choice;
        printf("\nDo you want to add another expense? (1=Yes, 0=No): ");
        scanf("%d", &choice);
        if (choice == 1) {
            addExpense(expenses, &numExpenses);
        } else {
            break;
        }
    }

    displayExpenses(expenses, numExpenses);

    return 0;
}