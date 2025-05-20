//FormAI DATASET v1.0 Category: Expense Tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100 // maximum expenses that can be tracked
#define MAX_DESCRIPTION_SIZE 100 // maximum size of individual expense description
#define MAX_CATEGORY_SIZE 50 // maximum size of individual expense category
#define MAX_DATE_SIZE 20 // maximum size of date string
#define MAX_AMOUNT_SIZE 10 // maximum size of the amount string

// struct to represent an individual expense
typedef struct expense {
    char description[MAX_DESCRIPTION_SIZE];
    char category[MAX_CATEGORY_SIZE];
    char date[MAX_DATE_SIZE];
    double amount;
} Expense;

// function to prompt the user for an expense and store it in the expenses array
void addExpense(Expense expenses[], int *numExpenses) {
    Expense e;
    printf("Enter expense description: ");
    scanf("%s", e.description);
    printf("Enter expense category: ");
    scanf("%s", e.category);
    printf("Enter expense date (MM/DD/YYYY): ");
    scanf("%s", e.date);
    printf("Enter expense amount: ");
    scanf("%lf", &e.amount);
    expenses[*numExpenses] = e;
    (*numExpenses)++;
}

// function to print all expenses in the expenses array
void printExpenses(Expense expenses[], int numExpenses) {
    printf("%-15s %-15s %-15s %-10s\n", "Description", "Category", "Date", "Amount");
    for (int i = 0; i < numExpenses; i++) {
        printf("%-15s %-15s %-15s $%-10.2lf\n", expenses[i].description, expenses[i].category, expenses[i].date, expenses[i].amount);
    }
}

// function to calculate the total amount spent on a given category
double getTotalByCategory(Expense expenses[], int numExpenses, char category[]) {
    double total = 0;
    for (int i = 0; i < numExpenses; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            total += expenses[i].amount;
        }
    }
    return total;
}

int main() {
    Expense expenses[MAX_EXPENSES]; // array to store all expenses
    int numExpenses = 0; // count of number of expenses tracked
    int choice; // user's menu choice
    char category[MAX_CATEGORY_SIZE]; // category input for total spending calculation

    do {
        printf("\n1. Add expense\n");
        printf("2. Print all expenses\n");
        printf("3. Get total spent by category\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                printExpenses(expenses, numExpenses);
                break;
            case 3:
                printf("Enter category to get total for: ");
                scanf("%s", category);
                printf("Total spent on %s: $%.2lf\n", category, getTotalByCategory(expenses, numExpenses, category));
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}