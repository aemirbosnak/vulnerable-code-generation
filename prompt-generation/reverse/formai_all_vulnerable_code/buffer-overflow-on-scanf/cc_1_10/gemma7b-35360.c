//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 10

// Define the structure of an expense
typedef struct Expense {
    char name[20];
    int amount;
    struct Expense* next;
} Expense;

// Create a function to add an expense
void addExpense(Expense* head) {
    // Allocate memory for a new expense
    Expense* newExpense = (Expense*)malloc(sizeof(Expense));

    // Get the name and amount of the expense
    printf("Enter the name of the expense: ");
    scanf("%s", newExpense->name);

    printf("Enter the amount of the expense: ");
    scanf("%d", &newExpense->amount);

    // Add the new expense to the end of the list
    if (head == NULL) {
        head = newExpense;
    } else {
        head->next = newExpense;
    }

    // Print a confirmation message
    printf("Expense added.\n");
}

// Create a function to print all expenses
void printExpenses(Expense* head) {
    // Traverse the list of expenses
    while (head) {
        // Print the name and amount of each expense
        printf("Name: %s, Amount: %d\n", head->name, head->amount);

        // Move to the next expense
        head = head->next;
    }
}

int main() {
    // Create a linked list of expenses
    Expense* head = NULL;

    // Add some expenses
    addExpense(head);
    addExpense(head);
    addExpense(head);

    // Print all expenses
    printExpenses(head);

    return 0;
}