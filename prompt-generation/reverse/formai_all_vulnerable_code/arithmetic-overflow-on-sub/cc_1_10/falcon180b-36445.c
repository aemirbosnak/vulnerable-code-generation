//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100

// Function to check if input is a valid integer
int is_integer(char *input) {
    while (*input!= '\0') {
        if (!isdigit(*input)) {
            return 0;
        }
        input++;
    }
    return 1;
}

int main() {
    // Initialize variables
    char input_buffer[MAX_LINE_LENGTH];
    char *input_ptr;
    int budget;
    int income;
    int expenses;

    // Prompt user for budget
    printf("Please enter your monthly budget: ");
    fgets(input_buffer, MAX_LINE_LENGTH, stdin);
    budget = atoi(input_buffer);

    // Prompt user for income
    printf("Please enter your monthly income: ");
    fgets(input_buffer, MAX_LINE_LENGTH, stdin);
    income = atoi(input_buffer);

    // Prompt user for expenses
    printf("Please enter your monthly expenses (separated by spaces): ");
    fgets(input_buffer, MAX_LINE_LENGTH, stdin);

    // Parse expenses
    input_ptr = input_buffer;
    while (*input_ptr!= '\0') {
        // Skip leading spaces
        while (isspace(*input_ptr)) {
            input_ptr++;
        }

        // Check if input is a valid integer
        if (is_integer(input_ptr)) {
            expenses += atoi(input_ptr);
            input_ptr += strlen(input_ptr);
        } else {
            // Invalid input, exit program
            printf("Invalid input: %s\n", input_ptr);
            exit(1);
        }

        // Skip trailing spaces
        while (isspace(*input_ptr)) {
            input_ptr++;
        }
    }

    // Calculate remaining budget
    int remaining_budget = budget - expenses;

    // Print summary
    printf("Monthly budget: $%d\n", budget);
    printf("Monthly income: $%d\n", income);
    printf("Monthly expenses: $%d\n", expenses);
    printf("Remaining budget: $%d\n", remaining_budget);

    return 0;
}