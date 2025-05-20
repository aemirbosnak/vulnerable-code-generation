//FormAI DATASET v1.0 Category: Expense Tracker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 100

// Define the structure for each expense
typedef struct {
    float amount;
    char category[20];
    char description[50];
} expense_t;

// Define the function to add a new expense
void addExpense(expense_t *expenses, int *counter) {
    if (*counter < MAX_EXPENSES) {
        expense_t newExpense;
        printf("Enter the amount: ");
        scanf("%f", &newExpense.amount);
        printf("Enter the category: ");
        scanf("%s", newExpense.category);
        printf("Enter the description: ");
        scanf("%s", newExpense.description);
        expenses[*counter] = newExpense;
        *counter += 1;
        printf("Expense added successfully.\n");
    } else {
        printf("Sorry, you have reached the maximum number of expenses.\n");
    }
}

// Define the function to display all expenses
void displayExpenses(expense_t *expenses, int counter) {
    if (counter == 0) {
        printf("There are no expenses to display.\n");
        return;
    }
    printf("Expense\tCategory\tDescription\n");
    for (int i = 0; i < counter; i++) {
        printf("$%.2f\t%s\t%s\n", expenses[i].amount, expenses[i].category, expenses[i].description);
    }
}

// Define the function to calculate the total expenses
float calculateTotal(expense_t *expenses, int counter) {
    float total = 0;
    for (int i = 0; i < counter; i++) {
        total += expenses[i].amount;
    }
    return total;
}

// Define the main function
int main() {
    expense_t expenses[MAX_EXPENSES];
    int counter = 0;
    int choice;
    do {
        printf("\nExpense Tracker Menu:\n"
               "1. Add new expense\n"
               "2. Display all expenses\n"
               "3. Calculate total expenses\n"
               "4. Exit\n"
               "Enter your choice (1-4): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addExpense(expenses, &counter);
                break;
            case 2:
                displayExpenses(expenses, counter);
                break;
            case 3:
                printf("Total expenses: $%.2f\n", calculateTotal(expenses, counter));
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (1);
    return 0;
}