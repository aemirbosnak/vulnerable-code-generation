//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: curious
// Expense Tracker Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the struct for each expense
struct expense {
    char category[50];
    float amount;
};

// Define the struct for the expense tracker
struct tracker {
    struct expense* expenses;
    int num_expenses;
    float total_amount;
};

// Function to add an expense to the tracker
void add_expense(struct tracker* tracker, char* category, float amount) {
    // Increase the size of the expense array
    tracker->expenses = realloc(tracker->expenses, (tracker->num_expenses + 1) * sizeof(struct expense));
    // Add the new expense to the array
    strcpy(tracker->expenses[tracker->num_expenses].category, category);
    tracker->expenses[tracker->num_expenses].amount = amount;
    // Increment the number of expenses
    tracker->num_expenses++;
    // Update the total amount
    tracker->total_amount += amount;
}

// Function to print the expense tracker
void print_tracker(struct tracker* tracker) {
    // Print the total amount
    printf("Total Amount: $%.2f\n", tracker->total_amount);
    // Print the expenses
    for (int i = 0; i < tracker->num_expenses; i++) {
        printf("Expense %d: %s - $%.2f\n", i + 1, tracker->expenses[i].category, tracker->expenses[i].amount);
    }
}

int main() {
    // Create a new expense tracker
    struct tracker* tracker = malloc(sizeof(struct tracker));
    tracker->expenses = malloc(10 * sizeof(struct expense));
    tracker->num_expenses = 0;
    tracker->total_amount = 0.0f;

    // Add some expenses
    add_expense(tracker, "Groceries", 50.0f);
    add_expense(tracker, "Rent", 1500.0f);
    add_expense(tracker, "Entertainment", 100.0f);
    add_expense(tracker, "Transportation", 20.0f);
    add_expense(tracker, "Gas", 30.0f);

    // Print the tracker
    print_tracker(tracker);

    // Free the memory
    free(tracker->expenses);
    free(tracker);

    return 0;
}