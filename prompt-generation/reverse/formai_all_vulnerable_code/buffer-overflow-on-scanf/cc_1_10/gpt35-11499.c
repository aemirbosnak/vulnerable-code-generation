//FormAI DATASET v1.0 Category: Expense Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 1000  // maximum number of expenses that can be entered

// define a structure to hold the details of an expense
typedef struct {
    char date[11];          // date in the format of "dd/mm/yyyy"
    char description[100];  // brief description of the expense
    double amount;          // amount of the expense
    char category[20];      // category of the expense
} Expense;

Expense expenses[MAX_EXPENSES];  // an array of Expense structures to hold all expenses
int numExpenses = 0;             // the current number of expenses entered

// function prototypes
void printMenu();
void addExpense();
void deleteExpense();
void printExpenses();
void searchExpenses();

int main() {
    int option;
    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &option);
        printf("\n");
        switch (option) {
            case 1:
                addExpense();
                break;
            case 2:
                deleteExpense();
                break;
            case 3:
                printExpenses();
                break;
            case 4:
                searchExpenses();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
        printf("\n");
    } while (option != 5);
    return 0;
}

// function to print the menu
void printMenu() {
    printf("EXPENSE TRACKER\n");
    printf("1. Add expense\n");
    printf("2. Delete expense\n");
    printf("3. View all expenses\n");
    printf("4. Search for an expense\n");
    printf("5. Exit\n");
}

// function to add a new expense
void addExpense() {
    if (numExpenses >= MAX_EXPENSES) {
        printf("Maximum number of expenses exceeded.\n");
        return;
    }
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", expenses[numExpenses].date);
    printf("Enter description: ");
    scanf("%s", expenses[numExpenses].description);
    printf("Enter amount: ");
    scanf("%lf", &expenses[numExpenses].amount);
    printf("Enter category: ");
    scanf("%s", expenses[numExpenses].category);
    numExpenses++;
    printf("Expense added successfully.\n");
}

// function to delete an expense
void deleteExpense() {
    if (numExpenses == 0) {
        printf("There are no expenses to delete.\n");
        return;
    }
    char dateToDelete[11];
    printf("Enter date of expense to delete (dd/mm/yyyy): ");
    scanf("%s", dateToDelete);
    int expenseToDelete = -1;
    for (int i = 0; i < numExpenses; i++) {
        if (strcmp(expenses[i].date, dateToDelete) == 0) {
            expenseToDelete = i;
            break;
        }
    }
    if (expenseToDelete == -1) {
        printf("No expense found with the entered date.\n");
    } else {
        for (int i = expenseToDelete; i < numExpenses - 1; i++) {
            expenses[i] = expenses[i + 1];
        }
        numExpenses--;
        printf("Expense deleted successfully.\n");
    }
}

// function to print all expenses
void printExpenses() {
    if (numExpenses == 0) {
        printf("There are no expenses to view.\n");
        return;
    }
    printf("%-12s%-30s%-12s%-20s\n", "Date", "Description", "Amount", "Category");
    for (int i = 0; i < numExpenses; i++) {
        Expense e = expenses[i];
        printf("%-12s%-30s%-12.2f%-20s\n", e.date, e.description, e.amount, e.category);
    }
}

// function to search for an expense
void searchExpenses() {
    if (numExpenses == 0) {
        printf("There are no expenses to search.\n");
        return;
    }
    char queryCategory[20];
    printf("Enter category to search for: ");
    scanf("%s", queryCategory);
    int numResults = 0;
    double totalAmount = 0;
    printf("%-12s%-30s%-12s%-20s\n", "Date", "Description", "Amount", "Category");
    for (int i = 0; i < numExpenses; i++) {
        Expense e = expenses[i];
        if (strcmp(e.category, queryCategory) == 0) {
            printf("%-12s%-30s%-12.2f%-20s\n", e.date, e.description, e.amount, e.category);
            numResults++;
            totalAmount += e.amount;
        }
    }
    if (numResults == 0) {
        printf("No expenses found with the entered category.\n");
    } else {
        printf("%d expenses found with a total amount of %.2f.\n", numResults, totalAmount);
    }
}