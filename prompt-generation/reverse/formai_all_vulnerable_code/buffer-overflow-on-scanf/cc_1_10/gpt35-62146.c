//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Define a struct for storing finance data
struct finance_data {
    float income;
    float expenses;
    float savings;
    float debt;
};

// Function to calculate finance data based on user input
void calculate_finances(struct finance_data *data) {
    printf("Enter your income: ");
    scanf("%f", &data->income);
    printf("Enter your monthly expenses: ");
    scanf("%f", &data->expenses);
    printf("Enter your monthly savings: ");
    scanf("%f", &data->savings);
    printf("Enter your total debt: ");
    scanf("%f", &data->debt);

    // Calculate debt-to-income ratio
    float dti_ratio = data->debt / data->income * 100;
    printf("\nYour debt-to-income ratio is %.2f%%\n", dti_ratio);

    // Check if user has savings or if they are in debt
    if (data->savings > 0) {
        printf("\nYou have some savings, keep that up! ");
    } else {
        printf("\nYou do not have any savings, consider setting up an emergency fund. ");
    }
    if (data->debt > 0) {
        printf("You are in debt, focus on paying that off as soon as possible.\n");
    } else {
        printf("You do not have any debt, keep it up!\n");
    }

    // Calculate monthly budget
    float budget = data->income - data->expenses;
    printf("\nYour monthly budget is $%.2f\n", budget);

    // Check if user's budget is positive or negative
    if (budget > 0) {
        printf("You have a positive monthly budget, that's great!\n");
    } else if (budget == 0) {
        printf("You have a zero monthly budget, be careful with your expenses.\n");
    } else {
        printf("You have a negative monthly budget, consider reducing your expenses or finding ways to increase your income.\n");
    }
}

int main() {
    // Display post-apocalyptic message
    printf("Welcome to the Personal Finance Planner.\n");
    printf("In this post-apocalyptic world, money is more valuable than ever. ");
    printf("But don't forget, your survival is also at stake.\n\n");

    // Create a pointer to store finance data
    struct finance_data *data = malloc(sizeof(struct finance_data));
    if (data == NULL) {
        printf("Error: Unable to allocate memory. Exiting program.\n");
        exit(1);
    }

    // Call function to calculate finance data
    calculate_finances(data);

    // Free memory and exit program
    free(data);
    return 0;
}