//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    double amount;
} Expense;

void addExpense(Expense* expenses, int* numExpenses) {
    printf("Enter the name of the expense: ");
    scanf("%s", expenses[*numExpenses].name);

    printf("Enter the category of the expense: ");
    scanf("%s", expenses[*numExpenses].category);

    printf("Enter the amount of the expense: ");
    scanf("%lf", &expenses[*numExpenses].amount);

    (*numExpenses)++;
}

void displayExpenses(Expense* expenses, int numExpenses) {
    printf("Expense Name\tExpense Category\tExpense Amount\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%-50s\t%-50s\t%.2lf\n", expenses[i].name, expenses[i].category, expenses[i].amount);
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;

    while (numExpenses < MAX_EXPENSES) {
        addExpense(expenses, &numExpenses);
        printf("Do you want to add another expense? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    displayExpenses(expenses, numExpenses);

    return 0;
}