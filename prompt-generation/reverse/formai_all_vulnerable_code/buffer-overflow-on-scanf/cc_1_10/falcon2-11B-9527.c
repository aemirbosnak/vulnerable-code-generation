//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int months = 0;
int income = 0;
int expenses = 0;
int savings = 0;
int net_income = 0;

// Function to calculate net income
void calculate_net_income() {
    net_income = income - expenses + savings;
    printf("Net income for month %d: $%.2f\n", months, net_income);
}

// Function to enter income, expenses, and savings
void enter_data() {
    printf("Enter your income for this month: ");
    scanf("%d", &income);

    printf("Enter your expenses for this month: ");
    scanf("%d", &expenses);

    printf("Enter your savings for this month: ");
    scanf("%d", &savings);
}

// Function to display menu
void display_menu() {
    printf("1. Enter income, expenses, and savings\n");
    printf("2. Calculate net income\n");
    printf("3. Display net income for each month\n");
    printf("4. Quit\n");
}

// Main function
int main() {
    srand(time(NULL)); // Seed random number generator
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enter_data();
                break;
            case 2:
                calculate_net_income();
                break;
            case 3:
                printf("Net income for each month:\n");
                for (int i = 0; i < months; i++) {
                    printf("Month %d: $%.2f\n", i, net_income);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}