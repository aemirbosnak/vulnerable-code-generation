//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    float salary, rent, groceries, utilities, transport, other_expenses, savings;
    char option;
    
    // Prompt user for input
    printf("Personal Finance Planning Tool\n\n");
    printf("Please enter your monthly salary: $");
    scanf("%f", &salary);
    
    printf("\nPlease enter your monthly expenses:\n");
    printf("Rent: $");
    scanf("%f", &rent);
    
    printf("Groceries: $");
    scanf("%f", &groceries);
    
    printf("Utilities: $");
    scanf("%f", &utilities);
    
    printf("Transport: $");
    scanf("%f", &transport);
    
    printf("Other expenses: $");
    scanf("%f", &other_expenses);
    
    // Calculate and display results
    savings = salary - rent - groceries - utilities - transport - other_expenses;
    
    printf("\nYour monthly savings are: $%.2f\n", savings);
    
    // Ask user if they want to save more
    printf("\nDo you want to save more money? (Y/N)");
    scanf(" %c", &option);
    
    if (option == 'Y' || option == 'y') {
        float additional_savings;
        printf("\nHow much more money do you want to save each month? $");
        scanf("%f", &additional_savings);
        savings += additional_savings;
        printf("\nYour new monthly savings are: $%.2f\n", savings);
    }
    
    // Personal finance advice based on savings
    if (savings < 0) {
        printf("\nYou are overspending, consider reducing your expenses or increasing your income.\n");
    }
    else if (savings < 500) {
        printf("\nYou are saving some money, but consider trying to save more.\n");
    }
    else if (savings < 1000) {
        printf("\nYou are doing a good job saving money, keep it up!\n");
    }
    else {
        printf("\nYou are a great saver, keep investing your money wisely.\n");
    }
    
    return 0;
}