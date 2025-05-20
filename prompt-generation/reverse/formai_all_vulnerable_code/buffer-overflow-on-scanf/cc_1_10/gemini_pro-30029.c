//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold financial data
typedef struct {
    char name[50];
    double income;
    double expenses;
    double savings;
} budget;

// Function to check if a string is a valid number
int is_number(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

// Function to get a valid double from the user
double get_double(char *prompt) {
    char input[50];
    double value;

    while (1) {
        printf("%s", prompt);
        scanf("%s", input);

        if (is_number(input)) {
            value = atof(input);
            return value;
        } else {
            printf("Invalid input. Please enter a valid number.\n");
        }
    }
}

// Function to create a new budget
budget *create_budget() {
    budget *new_budget = malloc(sizeof(budget));

    printf("Enter your name: ");
    scanf("%s", new_budget->name);

    new_budget->income = get_double("Enter your monthly income: ");
    new_budget->expenses = get_double("Enter your monthly expenses: ");
    new_budget->savings = get_double("Enter your monthly savings goal: ");

    return new_budget;
}

// Function to print a budget
void print_budget(budget *budget) {
    printf("\nName: %s\n", budget->name);
    printf("Income: $%.2f\n", budget->income);
    printf("Expenses: $%.2f\n", budget->expenses);
    printf("Savings: $%.2f\n", budget->savings);
}

// Function to calculate the net worth of a given budget
double calculate_net_worth(budget *budget) {
    return budget->income - budget->expenses + budget->savings;
}

// Main function
int main() {
    budget *my_budget = create_budget();

    printf("\nYour budget:\n");
    print_budget(my_budget);

    printf("\nYour net worth is: $%.2f\n", calculate_net_worth(my_budget));

    return 0;
}