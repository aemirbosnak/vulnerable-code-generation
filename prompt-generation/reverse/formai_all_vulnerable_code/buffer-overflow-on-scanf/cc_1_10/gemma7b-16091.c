//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    char name[20];
    int age;
    float salary;
    float total_expenses = 0;
    float current_expense = 0;
    int num_expenses = 0;

    // Get the user's name, age, and salary
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your salary: ");
    scanf("%f", &salary);

    // Calculate the user's total expenses
    while (1)
    {
        // Get the user's current expense
        printf("Enter your current expense: ");
        scanf("%f", &current_expense);

        // Check if the user wants to continue entering expenses
        printf("Do you want to continue entering expenses? (Y/N) ");
        char answer;
        scanf("%c", &answer);

        // If the user wants to continue, add the current expense to the total expenses
        if (answer == 'Y')
        {
            total_expenses += current_expense;
            num_expenses++;
        }
        // Otherwise, break out of the loop
        else
        {
            break;
        }
    }

    // Calculate the user's total savings
    float total_savings = salary - total_expenses;

    // Print the user's information
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Salary: %.2f\n", salary);
    printf("Total Expenses: %.2f\n", total_expenses);
    printf("Total Savings: %.2f\n", total_savings);
    printf("Number of Expenses: %d\n", num_expenses);

    return 0;
}