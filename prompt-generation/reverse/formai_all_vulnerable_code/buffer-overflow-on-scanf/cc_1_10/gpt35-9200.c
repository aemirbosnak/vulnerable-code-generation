//FormAI DATASET v1.0 Category: Expense Tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constants
#define MAX_EXPENSE_ITEMS 50
#define MAX_ITEM_NAME_LENGTH 50

// define struct for expense item
struct ExpenseItem {
    char name[MAX_ITEM_NAME_LENGTH];
    float cost;
};

// function to add an expense item to the tracker
int addExpenseItem(struct ExpenseItem tracker[], int numItems) {
    // check if tracker is full
    if (numItems == MAX_EXPENSE_ITEMS) {
        printf("Expense tracker is full. Cannot add more items.\n");
        return numItems;
    }
    // get item details from user
    printf("Enter name of item: ");
    scanf("%s", tracker[numItems].name);
    printf("Enter cost of item: ");
    scanf("%f", &tracker[numItems].cost);

    printf("Item %d added successfully!\n", numItems+1);

    // increment number of items in tracker
    numItems++;

    return numItems;
}

// function to print all expense items in the tracker
void printExpenseTracker(struct ExpenseItem tracker[], int numItems) {
    printf("\nExpense Tracker\n");
    printf("----------------\n");
    printf("%-3s%-20s%-10s\n", "No", "Item", "Cost");
    for (int i = 0; i < numItems; i++) {
        printf("%-3d%-20s%-10.2f\n", i+1, tracker[i].name, tracker[i].cost);
    }
    printf("----------------\n");
}

int main() {
    // initialize tracker
    struct ExpenseItem tracker[MAX_EXPENSE_ITEMS];
    int numItems = 0;

    // display welcome message
    printf("Welcome to the Expense Tracker!\n");

    // loop until user chooses to exit
    int choice = 0;
    while (choice != 3) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an expense item\n");
        printf("2. View expense tracker\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                numItems = addExpenseItem(tracker, numItems);
                break;
            case 2:
                printExpenseTracker(tracker, numItems);
                break;
            case 3:
                printf("\nThank you for using the Expense Tracker!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}