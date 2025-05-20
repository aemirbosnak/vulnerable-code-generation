//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Struct to hold financial information for the user
typedef struct {
    double monthly_income;
    double rent;
    double utilities;
    double groceries;
    double entertainment;
    double transportation;
    double insurance;
    double savings;
    double investments;
    double tax_rate;
} finances;

// Function to calculate the total budget
double calculate_total_budget(finances *f) {
    return f->monthly_income - f->rent - f->utilities - f->groceries - f->entertainment 
           - f->transportation - f->insurance - f->savings - f->investments 
           - (f->monthly_income * f->tax_rate);
}

// Function to display user's current financial status
void display_financial_status(finances *f) {
    double total_budget = calculate_total_budget(f);
    printf("Your current financial status:\n\n");
    printf("Monthly Income: $%.2f\n", f->monthly_income);
    printf("Monthly Expenses:\n");
    printf("    Rent: $%.2f\n", f->rent);
    printf("    Utilities: $%.2f\n", f->utilities);
    printf("    Groceries: $%.2f\n", f->groceries);
    printf("    Entertainment: $%.2f\n", f->entertainment);
    printf("    Transportation: $%.2f\n", f->transportation);
    printf("    Insurance: $%.2f\n", f->insurance);
    printf("Savings: $%.2f\n", f->savings);
    printf("Investments: $%.2f\n", f->investments);
    printf("Tax Rate: %.2f%%\n", f->tax_rate * 100);
    printf("Total Budget: $%.2f\n", total_budget);
}

// Function to prompt user for financial information
void prompt_for_financial_info(finances *f) {
    printf("Monthly Income: $");
    scanf("%lf", &f->monthly_income);
    printf("Rent: $");
    scanf("%lf", &f->rent);
    printf("Utilities: $");
    scanf("%lf", &f->utilities);
    printf("Groceries: $");
    scanf("%lf", &f->groceries);
    printf("Entertainment: $");
    scanf("%lf", &f->entertainment);
    printf("Transportation: $");
    scanf("%lf", &f->transportation);
    printf("Insurance: $");
    scanf("%lf", &f->insurance);
    printf("Savings: $");
    scanf("%lf", &f->savings);
    printf("Investments: $");
    scanf("%lf", &f->investments);
    printf("Tax Rate: ");
    scanf("%lf", &f->tax_rate);
}

// Function to randomly generate a financial status for demonstration purposes
void generate_random_financial_status(finances *f) {
    srand(time(NULL));
    f->monthly_income = (rand() % 10000) + 1000;
    f->rent = (rand() % 2000) + 500;
    f->utilities = (rand() % 1000) + 200;
    f->groceries = (rand() % 500) + 100;
    f->entertainment = (rand() % 500) + 50;
    f->transportation = (rand() % 1000) + 200;
    f->insurance = (rand() % 200) + 50;
    f->savings = (rand() % 500) + 50;
    f->investments = (rand() % 1000);
    f->tax_rate = ((rand() % 10) + 10) / 100.0;
}

// Main program loop
int main() {
    int choice;
    bool running = true;
    finances *f = (finances*)malloc(sizeof(finances));

    printf("Welcome to the Personal Finance Planner!\n\n");

    // Prompt user for financial information or generate random data
    printf("Would you like to input your financial information or generate it randomly?\n");
    printf("Enter 1 for Input, 2 for Random: ");
    scanf("%d", &choice);
    if (choice == 1) {
        prompt_for_financial_info(f);
    } else {
        printf("\nGenerating random financial status...\n");
        generate_random_financial_status(f);
    }

    // Loop through menu options until user chooses to exit
    while (running) {
        printf("\nPlease choose an option below:\n\n");
        printf("1. Display current financial status\n");
        printf("2. Change financial Information\n");
        printf("3. Exit\n\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_financial_status(f);
                break;

            case 2:
                prompt_for_financial_info(f);
                break;

            case 3:
                printf("\nExiting Personal Finance Planner... Goodbye!\n");
                running = false;
                break;

            default:
                printf("\nInvalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}