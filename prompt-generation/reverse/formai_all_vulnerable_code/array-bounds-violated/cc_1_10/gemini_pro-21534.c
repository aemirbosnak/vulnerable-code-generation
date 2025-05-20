//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the types of expenses
typedef enum {
    EXPENSE_FOOD,
    EXPENSE_DRINK,
    EXPENSE_ENTERTAINMENT,
    EXPENSE_OTHER
} expense_type;

// Define the structure of an expense
typedef struct {
    expense_type type;
    char *description;
    float amount;
} expense;

// Create an array of expenses
expense expenses[] = {
    {EXPENSE_FOOD, "Dinner at the Olive Garden", 25.00},
    {EXPENSE_DRINK, "Coffee at Starbucks", 3.50},
    {EXPENSE_ENTERTAINMENT, "Movie tickets", 15.00},
    {EXPENSE_OTHER, "Gas for the car", 40.00}
};

// Calculate the total amount of expenses
float total_expenses() {
    float total = 0.0;
    for (int i = 0; i < sizeof(expenses) / sizeof(expense); i++) {
        total += expenses[i].amount;
    }
    return total;
}

// Print the expenses
void print_expenses() {
    for (int i = 0; i < sizeof(expenses) / sizeof(expense); i++) {
        printf("%s: %s - %.2f\n",
            (expenses[i].type == EXPENSE_FOOD) ? "Food" :
            (expenses[i].type == EXPENSE_DRINK) ? "Drink" :
            (expenses[i].type == EXPENSE_ENTERTAINMENT) ? "Entertainment" :
            "Other",
            expenses[i].description,
            expenses[i].amount);
    }
}

// Get the user's input
void get_user_input() {
    char input[100];
    printf("What did you spend money on? ");
    scanf("%s", input);

    // Determine the type of expense
    expense_type type;
    if (strcmp(input, "food") == 0) {
        type = EXPENSE_FOOD;
    } else if (strcmp(input, "drink") == 0) {
        type = EXPENSE_DRINK;
    } else if (strcmp(input, "entertainment") == 0) {
        type = EXPENSE_ENTERTAINMENT;
    } else {
        type = EXPENSE_OTHER;
    }

    // Get the description of the expense
    char description[100];
    printf("What is a description of the expense? ");
    scanf("%s", description);

    // Get the amount of the expense
    float amount;
    printf("How much did you spend? ");
    scanf("%f", &amount);

    // Add the expense to the array
    expense new_expense = {type, description, amount};
    expenses[sizeof(expenses) / sizeof(expense)] = new_expense;
}

// Main function
int main() {
    // Print a welcome message
    printf("Welcome to the Expense Tracker 9000!\n");

    // Get the user's input
    get_user_input();

    // Calculate the total amount of expenses
    float total = total_expenses();

    // Print the expenses
    printf("Here are your expenses:\n");
    print_expenses();

    // Print the total amount of expenses
    printf("Total expenses: %.2f\n", total);

    // Print a goodbye message
    printf("Thanks for using the Expense Tracker 9000! Have a great day!\n");

    return 0;
}