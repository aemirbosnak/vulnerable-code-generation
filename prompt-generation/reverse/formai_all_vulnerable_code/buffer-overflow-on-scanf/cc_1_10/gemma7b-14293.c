//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 10

// Define the expense structure
typedef struct Expense {
    char name[50];
    int amount;
    struct Expense* next;
} Expense;

// Function to insert an expense
void insertExpense(Expense** head) {
    // Allocate memory for the new expense
    Expense* newExpense = malloc(sizeof(Expense));

    // Get the expense name and amount
    printf("Enter expense name: ");
    scanf("%s", newExpense->name);

    printf("Enter expense amount: ");
    scanf("%d", &newExpense->amount);

    // Insert the new expense into the list
    if (*head == NULL) {
        *head = newExpense;
    } else {
        (*head)->next = newExpense;
    }

    // Print the success message
    printf("Expense inserted successfully!\n");
}

// Function to print all expenses
void printExpenses(Expense* head) {
    // Iterate over the expenses and print them
    while (head) {
        printf("Name: %s, Amount: %d\n", head->name, head->amount);
        head = head->next;
    }
}

int main() {
    // Create an empty expense list
    Expense* head = NULL;

    // Insert some expenses
    insertExpense(&head);
    insertExpense(&head);
    insertExpense(&head);

    // Print the expenses
    printExpenses(head);

    return 0;
}