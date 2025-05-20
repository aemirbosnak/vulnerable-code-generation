//FormAI DATASET v1.0 Category: Expense Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Constants
#define MAX_EXPENSES 100
#define MAX_DESCRIPTION_SIZE 50

// Structures
struct Expense {
    int id;
    double amount;
    char description[MAX_DESCRIPTION_SIZE];
};

// Global variables
struct Expense expenses[MAX_EXPENSES];
int expensesCount = 0;

// Functions
void addExpense() {
    struct Expense expense;
    expense.id = expensesCount + 1;
    printf("Enter amount: ");
    scanf("%lf", &expense.amount);
    printf("Enter description: ");
    scanf("%s", expense.description);
    expenses[expensesCount] = expense;
    expensesCount++;
    printf("Expense added successfully!\n");
    printf("\n");
}

void listExpenses() {
    if (expensesCount == 0) {
        printf("No expenses found!\n");
        printf("\n");
        return;
    }

    printf("ID\tAmount\t\tDescription\n");
    printf("--------------------------------------------\n");

    for (int i = 0; i < expensesCount; i++) {
        struct Expense expense = expenses[i];
        printf("%d\t$%.2f\t\t%s\n", expense.id, expense.amount, expense.description);
    }

    printf("\n");
}

void deleteExpense() {
    if (expensesCount == 0) {
        printf("No expenses found!\n");
        printf("\n");
        return;
    }

    int idToDelete;
    printf("Enter ID of expense to delete: ");
    scanf("%d", &idToDelete);

    bool expenseDeleted = false;
    struct Expense newExpenses[MAX_EXPENSES];
    int newExpensesCount = 0;

    for (int i = 0; i < expensesCount; i++) {
        struct Expense expense = expenses[i];

        if (expense.id == idToDelete) {
            expenseDeleted = true;
            continue;
        }

        newExpenses[newExpensesCount] = expense;
        newExpensesCount++;
    }

    if (!expenseDeleted) {
        printf("Expense with ID %d not found!\n", idToDelete);
        printf("\n");
        return;
    }

    memcpy(expenses, newExpenses, sizeof(expenses));
    expensesCount = newExpensesCount;

    printf("Expense deleted successfully!\n");
    printf("\n");
}

void printMenu() {
    printf("Welcome to the Expense Tracker!\n");
    printf("1 - Add expense\n");
    printf("2 - List expenses\n");
    printf("3 - Delete expense\n");
    printf("4 - Exit\n");
    printf("Please enter your choice: ");
}

int main() {
    int choice;

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: addExpense(); break;
            case 2: listExpenses(); break;
            case 3: deleteExpense(); break;
            case 4: break;
            default: printf("Invalid choice! Please try again.\n"); break;
        }

    } while (choice != 4);

    printf("Thank you for using the Expense Tracker!\n");

    return 0;
}