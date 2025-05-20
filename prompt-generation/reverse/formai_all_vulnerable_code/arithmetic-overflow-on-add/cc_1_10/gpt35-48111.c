//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int income, rent, utilities, food, transportation, entertainment, other, total_expenses, savings;
    
    printf("Welcome to Personal Finance Planner!\n\n");
    
    printf("Enter your monthly income: $");
    scanf("%d", &income);
    
    printf("Enter your monthly rent payment: $");
    scanf("%d", &rent);
    
    printf("Enter your monthly utilities expenses: $");
    scanf("%d", &utilities);
    
    printf("Enter your monthly food expenses: $");
    scanf("%d", &food);
    
    printf("Enter your monthly transportation expenses: $");
    scanf("%d", &transportation);
    
    printf("Enter your monthly entertainment expenses: $");
    scanf("%d", &entertainment);
    
    printf("Enter any other monthly expenses: $");
    scanf("%d", &other);
    
    // Calculate total expenses and savings
    total_expenses = rent + utilities + food + transportation + entertainment + other;
    savings = income - total_expenses;
    
    // Display results
    printf("\nYour monthly expenses are: $%d\n", total_expenses);
    printf("Your total income is: $%d\n", income);
    printf("Your savings for the month are: $%d\n", savings);
    
    // Determine if user is overspending and give financial advice
    if (savings < 0) {
        printf("\nYou are spending more than you make. Consider reducing your expenses or finding ways to increase your income.\n");
    } else if (savings == 0) {
        printf("\nYou are breaking even. Consider finding ways to reduce your expenses or increase your income.\n");
    } else {
        printf("\nYou are saving money! Consider putting some of your savings towards long-term financial goals.\n");
    }
    
    return 0;
}