//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the structure for an expense
typedef struct Expense {
    char category[50];
    float amount;
    struct Expense *next;
} Expense;

// Initialize an empty linked list
Expense *expenses = NULL;

// Function to add an expense to the list
void add_expense(char *category, float amount) {
    Expense *new_expense = (Expense *) malloc(sizeof(Expense));
    strcpy(new_expense->category, category);
    new_expense->amount = amount;
    new_expense->next = expenses;
    expenses = new_expense;
}

// Function to display all expenses
void display_expenses() {
    Expense *current = expenses;
    printf("\nCurrent Expenses:\n");
    printf("%-50s %10s\n", "Category", "Amount");
    while (current != NULL) {
        printf("%-50s %10.2f\n", current->category, current->amount);
        current = current->next;
    }
}

// Function to calculate total expenses
float total_expenses() {
    Expense *current = expenses;
    float total = 0;
    while (current != NULL) {
        total += current->amount;
        current = current->next;
    }
    return total;
}

// Function to remove an expense by category
void remove_expense(char *category) {
    Expense *previous = NULL;
    Expense *current = expenses;

    // Search for the expense to be removed
    while (current != NULL && strcmp(current->category, category) != 0) {
        previous = current;
        current = current->next;
    }

    // If the expense was not found, return
    if (current == NULL) {
        printf("Error: Expense not found.\n");
        return;
    }

    // Remove the expense from the list
    if (previous == NULL) {
        expenses = current->next;
    } else {
        previous->next = current->next;
    }

    // Free the memory for the removed expense
    free(current);
}

// Main function
int main() {
    char category[50];
    float amount;
    int choice;

    // Menu for the expense tracker
    do {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Total Expenses\n");
        printf("4. Remove Expense\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch statement to perform the chosen action
        switch (choice) {
            case 1:
                printf("Enter expense category: ");
                scanf("%s", category);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                add_expense(category, amount);
                break;
            case 2:
                display_expenses();
                break;
            case 3:
                printf("Total Expenses: %.2f\n", total_expenses());
                break;
            case 4:
                printf("Enter expense category to remove: ");
                scanf("%s", category);
                remove_expense(category);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}