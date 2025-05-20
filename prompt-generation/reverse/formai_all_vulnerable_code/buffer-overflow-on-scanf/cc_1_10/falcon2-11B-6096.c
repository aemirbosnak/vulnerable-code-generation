//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: systematic
#include <stdio.h>

// Function prototypes
void display_menu();
void display_savings();
void display_expenses();
void display_income();

int main() {
    char option;

    // Display the menu
    display_menu();

    // Loop until the user wants to exit
    while(1) {
        printf("\nEnter your choice: ");
        scanf("%c", &option);

        // Handle different options
        switch(option) {
            case '1':
                display_savings();
                break;
            case '2':
                display_expenses();
                break;
            case '3':
                display_income();
                break;
            case '4':
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid option.\n");
        }
    }

    return 0;
}

// Function to display the savings
void display_savings() {
    float savings = 10000;

    printf("\nSavings: %0.2f\n", savings);
}

// Function to display the expenses
void display_expenses() {
    float expenses = 5000;

    printf("\nExpenses: %0.2f\n", expenses);
}

// Function to display the income
void display_income() {
    float income = 20000;

    printf("\nIncome: %0.2f\n", income);
}

// Function to display the menu
void display_menu() {
    printf("\n1. Display savings\n");
    printf("2. Display expenses\n");
    printf("3. Display income\n");
    printf("4. Exit\n");
}