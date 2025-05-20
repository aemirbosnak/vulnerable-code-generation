//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    int date;
} Expense;

void addExpense(Expense* expenses, int numExpenses, char* name, float amount, int date) {
    if (numExpenses >= MAX_EXPENSES) {
        printf("Sorry, you've reached the maximum number of expenses!\n");
        return;
    }

    strcpy(expenses[numExpenses].name, name);
    expenses[numExpenses].amount = amount;
    expenses[numExpenses].date = date;
    numExpenses++;
}

void printExpenses(Expense* expenses, int numExpenses) {
    printf("Expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s - $%.2f - %d\n", expenses[i].name, expenses[i].amount, expenses[i].date);
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;

    while (1) {
        printf("Enter an expense name: ");
        char name[50];
        scanf("%s", name);

        printf("Enter the amount: ");
        float amount;
        scanf("%f", &amount);

        printf("Enter the date (YYYY-MM-DD): ");
        int date;
        scanf("%d", &date);

        addExpense(expenses, numExpenses, name, amount, date);

        printf("View expenses? (y/n): ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'y' || choice == 'Y') {
            printExpenses(expenses, numExpenses);
        }
    }

    return 0;
}