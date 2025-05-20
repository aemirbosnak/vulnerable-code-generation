//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct {
    char description[50];
    float amount;
    char category[20];
    char date[20];
} Expense;

// Declare the array of expenses
Expense expenses[MAX_EXPENSES];

// Declare the number of expenses
int num_expenses = 0;

// Get user input for an expense
void get_expense(Expense *expense) {
    printf("Enter the expense description: ");
    scanf("%s", expense->description);

    printf("Enter the expense amount: ");
    scanf("%f", &expense->amount);

    printf("Enter the expense category: ");
    scanf("%s", expense->category);

    printf("Enter the expense date (dd/mm/yyyy): ");
    scanf("%s", expense->date);
}

// Print an expense
void print_expense(const Expense *expense) {
    printf("Description: %s\n", expense->description);
    printf("Amount: %.2f\n", expense->amount);
    printf("Category: %s\n", expense->category);
    printf("Date: %s\n\n", expense->date);
}

// Add an expense to the array of expenses
void add_expense(const Expense *expense) {
    if (num_expenses < MAX_EXPENSES) {
        expenses[num_expenses++] = *expense;
    } else {
        printf("Error: Maximum number of expenses reached.\n");
    }
}

// Print all expenses
void print_all_expenses() {
    for (int i = 0; i < num_expenses; i++) {
        print_expense(&expenses[i]);
    }
}

// Get the total amount of expenses
float get_total_amount() {
    float total = 0;
    for (int i = 0; i < num_expenses; i++) {
        total += expenses[i].amount;
    }
    return total;
}

// Get the average amount of expenses
float get_average_amount() {
    if (num_expenses == 0) {
        return 0;
    } else {
        return get_total_amount() / num_expenses;
    }
}

// Get the maximum amount of expenses
float get_max_amount() {
    float max = 0;
    for (int i = 0; i < num_expenses; i++) {
        if (expenses[i].amount > max) {
            max = expenses[i].amount;
        }
    }
    return max;
}

// Get the minimum amount of expenses
float get_min_amount() {
    float min = get_max_amount();
    for (int i = 0; i < num_expenses; i++) {
        if (expenses[i].amount < min) {
            min = expenses[i].amount;
        }
    }
    return min;
}

// Get the total amount of expenses in a given category
float get_total_amount_by_category(const char *category) {
    float total = 0;
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            total += expenses[i].amount;
        }
    }
    return total;
}

// Get the average amount of expenses in a given category
float get_average_amount_by_category(const char *category) {
    float total = get_total_amount_by_category(category);
    int count = 0;
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            count++;
        }
    }
    if (count == 0) {
        return 0;
    } else {
        return total / count;
    }
}

// Get the maximum amount of expenses in a given category
float get_max_amount_by_category(const char *category) {
    float max = 0;
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].category, category) == 0 && expenses[i].amount > max) {
            max = expenses[i].amount;
        }
    }
    return max;
}

// Get the minimum amount of expenses in a given category
float get_min_amount_by_category(const char *category) {
    float min = get_max_amount_by_category(category);
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].category, category) == 0 && expenses[i].amount < min) {
            min = expenses[i].amount;
        }
    }
    return min;
}

// Main function
int main() {
    // Get user input for the number of expenses
    int num_expenses_input;
    printf("Enter the number of expenses: ");
    scanf("%d", &num_expenses_input);

    // Get user input for each expense
    for (int i = 0; i < num_expenses_input; i++) {
        Expense expense;
        get_expense(&expense);
        add_expense(&expense);
    }

    // Print all expenses
    printf("\nAll expenses:\n");
    print_all_expenses();

    // Get the total amount of expenses
    float total_amount = get_total_amount();
    printf("\nTotal amount: %.2f\n", total_amount);

    // Get the average amount of expenses
    float average_amount = get_average_amount();
    printf("Average amount: %.2f\n", average_amount);

    // Get the maximum amount of expenses
    float max_amount = get_max_amount();
    printf("Maximum amount: %.2f\n", max_amount);

    // Get the minimum amount of expenses
    float min_amount = get_min_amount();
    printf("Minimum amount: %.2f\n", min_amount);

    // Get the total amount of expenses in a given category
    char category_input[20];
    printf("\nEnter the category to get the total amount for: ");
    scanf("%s", category_input);
    float total_amount_by_category = get_total_amount_by_category(category_input);
    printf("Total amount in %s category: %.2f\n", category_input, total_amount_by_category);

    // Get the average amount of expenses in a given category
    float average_amount_by_category = get_average_amount_by_category(category_input);
    printf("Average amount in %s category: %.2f\n", category_input, average_amount_by_category);

    // Get the maximum amount of expenses in a given category
    float max_amount_by_category = get_max_amount_by_category(category_input);
    printf("Maximum amount in %s category: %.2f\n", category_input, max_amount_by_category);

    // Get the minimum amount of expenses in a given category
    float min_amount_by_category = get_min_amount_by_category(category_input);
    printf("Minimum amount in %s category: %.2f\n", category_input, min_amount_by_category);

    return 0;
}