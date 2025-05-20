//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: cheerful
#include <stdio.h>

int main() {
    
    printf("Welcome to your Personal Finance Planner! Let's get started.\n\n");
    
    // Get user's name
    char name[20];
    printf("What is your name? ");
    scanf("%s", name);
    
    // Get user's monthly income
    float income;
    printf("What is your monthly income, %s? ", name);
    scanf("%f", &income);
    
    // Get user's monthly expenses
    float expenses;
    printf("What are your monthly expenses, %s? ", name);
    scanf("%f", &expenses);
    
    // Calculate monthly savings
    float savings = income - expenses;
    
    // Output monthly savings
    printf("\nGreat! So, %s, your monthly savings are $%.2f.\n", name, savings);
    
    // Ask user if they have any savings goals
    char response;
    printf("\nDo you have any savings goals, %s? (Y/N) ", name);
    scanf("%s", &response);
    
    // If user has savings goals, get goal amount and calculate how many months it will take to reach it
    if (response == 'Y') {
        float goal;
        printf("How much money would you like to save? ");
        scanf("%f", &goal);
        
        int months = goal / savings;
        printf("\nIf you save $%.2f each month, you will reach your goal in %d months!\n", savings, months);
    }
    
    // If user does not have savings goals, suggest some smart ways to utilize savings
    else {
        printf("\nThat's okay, %s. Here are some smart ways to utilize your monthly savings:\n", name);
        printf("- Contribute to your retirement fund\n");
        printf("- Start an emergency fund\n");
        printf("- Pay off debt\n");
    }
    
    printf("\nThank you for using our Personal Finance Planner. Have a good day, %s!\n", name);
    
    return 0;
}