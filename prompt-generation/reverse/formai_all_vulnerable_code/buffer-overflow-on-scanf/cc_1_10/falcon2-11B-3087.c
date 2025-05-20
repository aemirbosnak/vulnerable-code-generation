//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: expert-level
#include <stdio.h>

#define MAX_EXPENSES 100

typedef struct {
    int amount;
    char category[20];
    char date[20];
} Expense;

void addExpense(Expense expenses[MAX_EXPENSES], int size) {
    int amount;
    printf("Enter the amount: ");
    scanf("%d", &amount);

    char category[20];
    printf("Enter the category: ");
    scanf(" %s", category);

    char date[20];
    printf("Enter the date (YYYY-MM-DD): ");
    scanf(" %s", date);

    Expense newExpense = { amount, category, date };

    if (size < MAX_EXPENSES) {
        expenses[size] = newExpense;
        size++;
    }
}

void displayExpenses(Expense expenses[MAX_EXPENSES], int size) {
    printf("Expenses:\n");
    for (int i = 0; i < size; i++) {
        printf("Amount: %d\nCategory: %s\nDate: %s\n", expenses[i].amount, expenses[i].category, expenses[i].date);
    }
}

int calculateTotalExpenses(Expense expenses[MAX_EXPENSES], int size) {
    int totalExpenses = 0;

    for (int i = 0; i < size; i++) {
        totalExpenses += expenses[i].amount;
    }

    return totalExpenses;
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int size = 0;

    addExpense(expenses, size);
    displayExpenses(expenses, size);
    printf("Total expenses: %d\n", calculateTotalExpenses(expenses, size));

    return 0;
}