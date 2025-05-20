//FormAI DATASET v1.0 Category: Expense Tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100 // Maximum number of expenses that can be stored

struct Expense {
    char name[50];
    double cost;
};

struct Expense expenses[MAX_EXPENSES];
int numExpenses = 0;

void displayMenu();
void addExpense();
void displayExpenses();
void saveExpensesToFile();
void loadExpensesFromFile();

int main() {
    // Load the expenses from file
    loadExpensesFromFile();

    // Display the menu
    displayMenu();

    // Save the expenses to file
    saveExpensesToFile();

    return 0;
}

void displayMenu() {
    int choice;

    printf("--------------------\n");
    printf("   Expense Tracker\n");
    printf("--------------------\n");
    printf("1. Add Expense\n");
    printf("2. Display Expenses\n");
    printf("3. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            addExpense();
            break;
        case 2:
            displayExpenses();
            break;
        case 3:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            displayMenu();
            break;
    }
}

void addExpense() {
    char name[50];
    double cost;
    char confirm;

    printf("Enter the name of the expense: ");
    scanf("%s", name);
    printf("Enter the cost of the expense: $");
    scanf("%lf", &cost);

    printf("Are you sure you want to add this expense? (y/n): ");
    scanf("%s", &confirm);

    if (tolower(confirm) == 'y') {
        struct Expense expense;
        strcpy(expense.name, name);
        expense.cost = cost;

        expenses[numExpenses++] = expense;

        printf("Expense added successfully.\n");
    } else {
        printf("Expense not added.\n");
    }

    displayMenu();
}

void displayExpenses() {
    printf("Expenses:\n");

    if (numExpenses == 0) {
        printf("There are no expenses to display.\n");
    } else {
        double total = 0;
        printf("%-20s %10s\n", "Name", "Cost");
        printf("------------------------------------------\n");
        for (int i = 0; i < numExpenses; i++) {
            struct Expense expense = expenses[i];
            printf("%-20s $%9.2lf\n", expense.name, expense.cost);
            total += expense.cost;
        }
        printf("------------------------------------------\n");
        printf("%-20s $%9.2lf\n", "Total", total);
    }

    displayMenu();
}

void saveExpensesToFile() {
    FILE *fp = fopen("expenses.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(fp, "%d\n", numExpenses);
    for (int i = 0; i < numExpenses; i++) {
        struct Expense expense = expenses[i];
        fprintf(fp, "%s %lf\n", expense.name, expense.cost);
    }

    fclose(fp);
}

void loadExpensesFromFile() {
    FILE *fp = fopen("expenses.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    fscanf(fp, "%d", &numExpenses);
    for (int i = 0; i < numExpenses; i++) {
        struct Expense expense;
        fscanf(fp, "%s %lf", expense.name, &expense.cost);
        expenses[i] = expense;
    }

    fclose(fp);
}