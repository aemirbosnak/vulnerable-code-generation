//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for an expense
typedef struct {
    char* description;
    double amount;
    char* category;
} Expense;

// Function to add an expense
void add_expense(Expense* expenses, int* num_expenses, char* desc, double amt, char* cat) {
    // Allocate memory for the new expense
    Expense* new_expense = (Expense*)malloc(sizeof(Expense));

    // Copy the description, amount, and category into the new expense
    new_expense->description = strdup(desc);
    new_expense->amount = amt;
    new_expense->category = strdup(cat);

    // Add the new expense to the array
    expenses[*num_expenses] = *new_expense;
    (*num_expenses)++;
}

// Function to print the expenses
void print_expenses(Expense* expenses, int num_expenses) {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("Description: %s\n", expenses[i].description);
        printf("Amount: $%.2f\n", expenses[i].amount);
        printf("Category: %s\n\n", expenses[i].category);
    }
}

// Function to calculate the total amount spent in a category
double calculate_total_spent(Expense* expenses, int num_expenses, char* category) {
    double total = 0.0;
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            total += expenses[i].amount;
        }
    }
    return total;
}

// Function to calculate the average amount spent in a category
double calculate_average_spent(Expense* expenses, int num_expenses, char* category) {
    double total = 0.0;
    int count = 0;
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            total += expenses[i].amount;
            count++;
        }
    }
    return total / count;
}

int main() {
    // Initialize the array of expenses
    Expense* expenses = NULL;
    int num_expenses = 0;

    // Add some sample expenses
    add_expense(&expenses, &num_expenses, "Coffee", 3.50, "Food");
    add_expense(&expenses, &num_expenses, "Rent", 1000.00, "Housing");
    add_expense(&expenses, &num_expenses, "Books", 50.00, "Education");

    // Print the expenses
    print_expenses(expenses, num_expenses);

    // Calculate the total amount spent on food
    double total_food_spent = calculate_total_spent(expenses, num_expenses, "Food");
    printf("Total amount spent on food: $%.2f\n", total_food_spent);

    // Calculate the average amount spent on education
    double avg_education_spent = calculate_average_spent(expenses, num_expenses, "Education");
    printf("Average amount spent on education: $%.2f\n", avg_education_spent);

    // Free the memory allocated for the expenses
    for (int i = 0; i < num_expenses; i++) {
        free(expenses[i].description);
        free(expenses[i].category);
    }
    free(expenses);

    return 0;
}