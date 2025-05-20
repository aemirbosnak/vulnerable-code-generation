//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Declare variables
    char name[20];
    int age;
    float salary;
    char expense[100];
    int expense_num = 0;
    float total_expense = 0.0;

    // Get user input
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your salary: ");
    scanf("%f", &salary);

    // Loop to get user's expenses
    while (1)
    {
        printf("Enter an expense: ");
        scanf("%s", expense);

        // Check if the user wants to continue
        char continue_exp = 'n';
        printf("Do you want to continue entering expenses? (Y/N) ");
        scanf("%c", &continue_exp);

        // If the user wants to continue, add the expense to the list
        if (continue_exp == 'Y')
        {
            expense_num++;
            total_expense += atof(expense);
        }
        else
        {
            break;
        }
    }

    // Calculate the total expense
    total_expense = total_expense / 100.0 * salary;

    // Print the results
    printf("Hello, %s. You are %d years old and earn %.2f.", name, age, salary);
    printf("\nYour total expense is $%.2f, which is %.2f% of your salary.", total_expense, total_expense / salary * 100);

    return 0;
}