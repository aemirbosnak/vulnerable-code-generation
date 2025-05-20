//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: minimalist
#include <stdio.h>

// Function to calculate the total savings
float calculateSavings(float income, float expenses)
{
    return income - expenses;
}

int main()
{
    float income, expenses;

    // Getting user input for income and expenses
    printf("Enter your income: ");
    scanf("%f", &income);

    printf("Enter your expenses: ");
    scanf("%f", &expenses);

    // Calculating savings
    float savings = calculateSavings(income, expenses);

    // Checking if the user is saving or overspending
    if (savings < 0)
    {
        printf("Oops! You are overspending. You need to cut down on your expenses.\n");
    }
    else if (savings == 0)
    {
        printf("You are breaking even. You need to start saving more.\n");
    }
    else
    {
        printf("Great! You are saving money. Here are some tips to further increase your savings:\n");

        // Suggesting some tips to increase savings
        if (savings < income/2)
        {
            printf("- Try to cut down on eating out. Cook more meals at home.\n");
        }
        if (savings < income/4)
        {
            printf("- Try to negotiate your rent or mortgage.\n");
        }
        if (savings < income/8)
        {
            printf("- Consider getting a side job or freelance work.\n");
        }
    }

    return 0; // End of program
}