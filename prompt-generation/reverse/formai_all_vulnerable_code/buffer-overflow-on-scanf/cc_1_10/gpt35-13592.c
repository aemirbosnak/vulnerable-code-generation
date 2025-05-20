//FormAI DATASET v1.0 Category: Expense Tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 1000

typedef struct Expense {
    int day;
    int month;
    int year;
    char description[50];
    double cost;
} Expense;

int numExpenses = 0;
Expense expenses[MAX_EXPENSES];

void addExpense() {
    // Get input from the user
    int day, month, year;
    char description[50];
    double cost;

    printf("Enter the date of the expense (dd mm yyyy): ");
    scanf("%d %d %d", &day, &month, &year);

    printf("Enter a brief description of the expense: ");
    scanf("%s", description);

    printf("Enter the cost of the expense: ");
    scanf("%lf", &cost);

    // Create the new expense
    Expense newExpense;
    newExpense.day = day;
    newExpense.month = month;
    newExpense.year = year;
    strcpy(newExpense.description, description);
    newExpense.cost = cost;

    // Add it to the list
    expenses[numExpenses++] = newExpense;
    printf("Expense added successfully!\n");
}

void viewExpensesByMonth() {
    // Get input from the user (month and year)
    int month, year;

    printf("Enter the month and year of the expenses you wish to view (mm yyyy): ");
    scanf("%d %d", &month, &year);

    // Display all expenses in the given month and year
    double totalCost = 0;
    printf("Here are the expenses for %02d/%04d:\n", month, year);
    for (int i = 0; i < numExpenses; i++) {
        Expense expense = expenses[i];
        if (expense.month == month && expense.year == year) {
            printf("%02d/%02d/%04d - %-30s - $%.2lf\n", expense.day, expense.month, expense.year, expense.description, expense.cost);
            totalCost += expense.cost;
        }
    }
    printf("Total expenses: $%.2lf\n", totalCost);
}

void viewExpensesByDescription() {
    // Get input from the user (description keyword)
    char keyword[50];

    printf("Enter a keyword to search for in the expense descriptions: ");
    scanf("%s", keyword);

    // Display all expenses that contain the keyword in the description
    double totalCost = 0;
    printf("Here are the expenses that match your search:\n");
    for (int i = 0; i < numExpenses; i++) {
        Expense expense = expenses[i];
        if (strstr(expense.description, keyword) != NULL) {
            printf("%02d/%02d/%04d - %-30s - $%.2lf\n", expense.day, expense.month, expense.year, expense.description, expense.cost);
            totalCost += expense.cost;
        }
    }
    printf("Total expenses: $%.2lf\n", totalCost);
}

int main() {
    int choice;
    do {
        printf("Expense Tracker\n");
        printf("1. Add an expense\n");
        printf("2. View expenses by month and year\n");
        printf("3. View expenses by description\n");
        printf("4. Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpensesByMonth();
                break;
            case 3:
                viewExpensesByDescription();
                break;
            case 4:
                printf("Thank you for using Expense Tracker!\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    } while (choice != 4);

    return 0;
}