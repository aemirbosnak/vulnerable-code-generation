//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of an expense
struct Expense {
    char description[50];
    float amount;
    char date[11];
};

// Define the maximum number of expenses
#define MAX_EXPENSES 100

// Get the user's input
void get_input(struct Expense *expenses, int *num_expenses) {
    char input[100];
    int i;

    // Get the number of expenses
    printf("How many expenses do you want to track? ");
    scanf("%d", num_expenses);

    // Get the details of each expense
    for (i = 0; i < *num_expenses; i++) {
        printf("Enter the description of expense %d: ", i + 1);
        scanf(" %[^\n]", input);
        strcpy(expenses[i].description, input);

        printf("Enter the amount of expense %d: ", i + 1);
        scanf(" %f", &expenses[i].amount);

        printf("Enter the date of expense %d (dd/mm/yyyy): ", i + 1);
        scanf(" %[^\n]", input);
        strcpy(expenses[i].date, input);
    }
}

// Print the expenses
void print_expenses(struct Expense *expenses, int num_expenses) {
    int i;

    printf("\nYour expenses are:\n");
    for (i = 0; i < num_expenses; i++) {
        printf("%-50s%-10.2f%-11s\n", expenses[i].description, expenses[i].amount, expenses[i].date);
    }
}

// Calculate the total expenses
float calculate_total_expenses(struct Expense *expenses, int num_expenses) {
    int i;
    float total = 0;

    for (i = 0; i < num_expenses; i++) {
        total += expenses[i].amount;
    }

    return total;
}

// Main function
int main() {
    struct Expense expenses[MAX_EXPENSES];
    int num_expenses;

    get_input(expenses, &num_expenses);
    print_expenses(expenses, num_expenses);

    printf("\nYour total expenses are: %.2f\n", calculate_total_expenses(expenses, num_expenses));

    return 0;
}