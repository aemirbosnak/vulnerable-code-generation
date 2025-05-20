//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Personal Finance Planner!\n\n");

    // Getting user input for monthly salary and expenses
    float monthlySalary, rent, utilities, groceries, transportation, otherExpenses;
    printf("Please enter your monthly salary: ");
    scanf("%f", &monthlySalary);

    printf("Please enter your monthly rent amount: ");
    scanf("%f", &rent);

    printf("Please enter your monthly utilities amount: ");
    scanf("%f", &utilities);

    printf("Please enter your monthly groceries amount: ");
    scanf("%f", &groceries);

    printf("Please enter your monthly transportation amount: ");
    scanf("%f", &transportation);

    printf("Please enter any other monthly expenses: ");
    scanf("%f", &otherExpenses);

    printf("\n");

    // Calculating total monthly expenses and savings
    float totalExpenses = rent + utilities + groceries + transportation + otherExpenses;
    float savings = monthlySalary - totalExpenses;

    // Checking if user is saving enough or spending too much
    if(savings > 0)
    {
        printf("Congratulations! You are saving %.2f USD every month.\n", savings);
    }
    else if(savings == 0)
    {
        printf("You are breaking even every month. Consider saving some money for emergencies.\n");
    }
    else
    {
        printf("Uh oh, looks like you are spending more than you earn!\n");
        printf("You are overspending by %.2f USD every month. Please consider reducing your expenses.\n", savings*-1);
    }

    printf("\n");

    // Suggesting ways to save money
    if(totalExpenses > monthlySalary/2)
    {
        printf("You are spending way too much on expenses! Here are some tips to save money:\n\n");
        
        // Housing expenses suggestions
        if(rent > monthlySalary/4)
        {
            printf("- Consider getting a roommate to split rent costs.\n");
        }
        
        if(utilities > monthlySalary/10)
        {
            printf("- Try to limit your energy usage by turning off lights when not in use or investing in energy-efficient appliances.\n");
        }

        // Food expenses suggestions
        if(groceries > monthlySalary/10)
        {
            printf("- Try cutting down on eating out and cook meals at home. Buying from bulk stores or shopping for deals can also save money.\n");
        }

        // Transportation expenses suggestions
        if(transportation > monthlySalary/10)
        {
            printf("- Take public transportation instead of owning a car, if feasible.\n");
            printf("- Carpool to work or school with friends or coworkers to save on gas.\n");
        }

        // Other expenses suggestions
        if(otherExpenses > monthlySalary/5)
        {
            printf("- If possible, try to pick up a side hustle or part-time job to increase your income.\n");
            printf("- Cut down on miscellaneous expenses such as subscriptions, online shopping, and impulse purchases.\n");
        }
    }
    else if(totalExpenses > monthlySalary/4)
    {
        printf("Your expenses are quite high. Here are some tips to save money:\n\n");

        // Housing expenses suggestions
        if(rent > monthlySalary/7)
        {
            printf("- Consider getting a roommate to split rent costs.\n");
        }

        // Food expenses suggestions
        if(groceries > monthlySalary/15)
        {
            printf("- Try cutting down on eating out and cook meals at home. Buying from bulk stores or shopping for deals can also save money.\n");
        }

        // Transportation expenses suggestions
        if(transportation > monthlySalary/15)
        {
            printf("- Take public transportation instead of owning a car, if feasible.\n");
        }
        
        // Other expenses suggestions
        if(otherExpenses > monthlySalary/7.5)
        {
            printf("- Cut down on miscellaneous expenses such as subscriptions, online shopping, and impulse purchases.\n");
        }
    }
    else
    {
        printf("Your expenses are well within your monthly salary. Keep up the great work!\n");
    }

    printf("\nThank you for using Personal Finance Planner. Have a great day!");

    return 0;
}