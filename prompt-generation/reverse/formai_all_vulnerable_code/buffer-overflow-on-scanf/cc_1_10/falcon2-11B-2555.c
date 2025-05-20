//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struct for storing expense data
typedef struct {
    char name[50];
    int amount;
    char category[50];
    int date;
} Expense;

// Function to add a new expense
Expense addExpense(char *name, int amount, char *category, int date) {
    Expense expense;
    snprintf(expense.name, sizeof(expense.name), "%s", name);
    expense.amount = amount;
    snprintf(expense.category, sizeof(expense.category), "%s", category);
    expense.date = date;

    return expense;
}

// Function to print all expenses
void printExpenses(Expense expenses[], int numExpenses) {
    printf("Expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("Name: %s\n", expenses[i].name);
        printf("Amount: %d\n", expenses[i].amount);
        printf("Category: %s\n", expenses[i].category);
        printf("Date: %d\n", expenses[i].date);
        printf("\n");
    }
}

int main() {
    Expense expenses[10]; // Maximum of 10 expenses

    // Add expenses
    char name[50];
    int amount;
    char category[50];
    int date;
    srand(time(NULL));
    int i;
    for (i = 0; i < 10; i++) {
        printf("Enter name: ");
        fgets(name, sizeof(name), stdin);
        printf("Enter amount: ");
        scanf("%d", &amount);
        printf("Enter category: ");
        fgets(category, sizeof(category), stdin);
        printf("Enter date (in format YYYYMMDD): ");
        scanf("%d", &date);
        expenses[i] = addExpense(name, amount, category, date);
    }

    // Print expenses
    printf("Expenses:\n");
    printExpenses(expenses, i);

    return 0;
}