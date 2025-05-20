//FormAI DATASET v1.0 Category: Expense Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100 // maximum number of expenses that can be entered
#define MAX_DESCRIPTION_LENGTH 50 // maximum size of an expense description
#define MAX_CATEGORY_LENGTH 20 // maximum size of an expense category
#define MAX_MONTH_LENGTH 10 // maximum size of a month (e.g. "January")

// structure to hold information about each expense
struct Expense {
    char description[MAX_DESCRIPTION_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int amount;
    char month[MAX_MONTH_LENGTH];
};

// function to display the main menu and obtain user's choice
int displayMenu() {
    int choice;

    printf("\nWelcome to the Expense Tracker!\n");
    printf("1 - Enter a new expense\n");
    printf("2 - View all expenses\n");
    printf("3 - View expenses by category\n");
    printf("4 - View expenses by month\n");
    printf("5 - Quit\n");
    printf("\nEnter your choice (1-5): ");
    scanf("%d", &choice);

    return choice;
}

int main() {
    struct Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    int choice;

    do {
        choice = displayMenu();

        switch (choice) {
            case 1: // add a new expense
                if (numExpenses < MAX_EXPENSES) {
                    printf("\nEnter a description for the expense: ");
                    scanf("%s", expenses[numExpenses].description);

                    printf("Enter a category for the expense: ");
                    scanf("%s", expenses[numExpenses].category);

                    printf("Enter an amount for the expense: ");
                    scanf("%d", &expenses[numExpenses].amount);

                    printf("Enter a month for the expense (e.g. \"January\"): ");
                    scanf("%s", expenses[numExpenses].month);

                    numExpenses++;
                }
                else {
                    printf("\nCannot add any more expenses!\n");
                }
                break;

            case 2: // view all expenses
                if (numExpenses == 0) {
                    printf("\nNo expenses entered!\n");
                }
                else {
                    printf("\nAll expenses:\n");
                    printf("%-20s %-20s %-10s %-10s\n", "Description", "Category", "Amount", "Month");
                    for (int i = 0; i < numExpenses; i++) {
                        printf("%-20s %-20s %-10d %-10s\n", expenses[i].description, expenses[i].category, expenses[i].amount, expenses[i].month);
                    }
                }
                break;

            case 3: // view expenses by category
                if (numExpenses == 0) {
                    printf("\nNo expenses entered!\n");
                }
                else {
                    char category[MAX_CATEGORY_LENGTH];
                    printf("\nEnter a category to view: ");
                    scanf("%s", category);

                    printf("\nExpenses in the category \"%s\":\n", category);
                    printf("%-20s %-10s %-10s\n", "Description", "Amount", "Month");
                    for (int i = 0; i < numExpenses; i++) {
                        if (strcmp(expenses[i].category, category) == 0) {
                            printf("%-20s %-10d %-10s\n", expenses[i].description, expenses[i].amount, expenses[i].month);
                        }
                    }
                }
                break;

            case 4: // view expenses by month
                if (numExpenses == 0) {
                    printf("\nNo expenses entered!\n");
                }
                else {
                    char month[MAX_MONTH_LENGTH];
                    printf("\nEnter a month to view (e.g. \"January\"): ");
                    scanf("%s", month);

                    printf("\nExpenses in %s:\n", month);
                    printf("%-20s %-20s %-10s\n", "Description", "Category", "Amount");
                    for (int i = 0; i < numExpenses; i++) {
                        if (strcmp(expenses[i].month, month) == 0) {
                            printf("%-20s %-20s %-10d\n", expenses[i].description, expenses[i].category, expenses[i].amount);
                        }
                    }
                }
                break;

            case 5: // quit
                printf("\nThank you for using the Expense Tracker!\n");
                break;

            default:
                printf("\nInvalid choice!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}