//FormAI DATASET v1.0 Category: Expense Tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME 50

// Structure to hold expense items
typedef struct {
    char name[MAX_NAME];
    float amount;
} ExpenseItem;

// Function to display menu options
void displayMenu() {
    printf("\nExpense Tracker Menu\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Exit\n");
}

// Function to add an expense item to the array
void addExpense(ExpenseItem *expenses, int *count) {
    char name[MAX_NAME];
    float amount;

    // Get expense name
    printf("Enter expense name: ");
    scanf("%s", name);

    // Get expense amount
    printf("Enter expense amount: ");
    scanf("%f", &amount);

    // Create new expense item and add to array
    ExpenseItem item;
    strcpy(item.name, name);
    item.amount = amount;

    expenses[*count] = item;
    (*count)++;
}

// Function to display all expense items in the array
void viewExpenses(ExpenseItem *expenses, int count) {
    printf("\nExpense List\n");
    printf("Name\tAmount\n");
    printf("------------------\n");

    // Loop through array and display each expense item
    int i;
    for (i = 0; i < count; i++) {
        printf("%s\t%.2f\n", expenses[i].name, expenses[i].amount);
    }
}

int main() {
    // Initialize variables
    ExpenseItem expenses[MAX_ITEMS];
    int count = 0;
    int choice = 0;

    // Loop until user chooses to exit
    while (choice != 3) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                viewExpenses(expenses, count);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}