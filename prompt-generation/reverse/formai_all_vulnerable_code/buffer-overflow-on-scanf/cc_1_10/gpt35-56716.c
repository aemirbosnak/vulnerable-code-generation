//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: statistical
#include <stdio.h>
#define MAX 100

int main()
{
    int n;  
    float sum = 0, average;  
    float expenses[MAX];  
    float income, balance;
    int i;
    
    printf("Welcome to the Personal Finance Planner\n");

    // Collect user input for expenses
    printf("Enter the number of expenses for the month: ");
    scanf("%d", &n);

    printf("Enter your expenses for the month:\n");
    for (i = 0; i < n; i++)
    {
        printf("Expense %d: $", i + 1);
        scanf("%f", &expenses[i]);
        sum += expenses[i];
    }

    // Calculate the average expense
    average = sum / n;

    // Print the total expenses and average expense to the user
    printf("Your total expenses for the month are: $%.2f\n", sum);
    printf("Your average expense for the month is: $%.2f\n", average);

    // Collect user input for income
    printf("Enter your total monthly income: $");
    scanf("%f", &income);

    // Calculate the balance
    balance = income - sum;

    // Print the balance to the user
    printf("Your monthly balance is: $%.2f\n", balance);

    // Determine whether the user has a positive or negative balance
    if (balance > 0)
    {
        printf("Congratulations! You have a positive balance this month!\n");
    } 
    else if (balance < 0) 
    {
        printf("Sorry, you have a negative balance this month. Have you considered cutting back on expenses?\n");
    } 
    else 
    {
        printf("Your income and expenses for the month are the same. It's always good to break even!\n");
    }
    
    return 0;
}