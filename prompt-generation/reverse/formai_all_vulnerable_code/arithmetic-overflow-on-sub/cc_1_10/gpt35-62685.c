//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Linus Torvalds
#include <stdio.h>

int main()
{
    int salary, expenses, savings;

    printf("Enter your monthly salary: ");
    scanf("%d", &salary);

    printf("Enter your monthly expenses: ");
    scanf("%d", &expenses);

    savings = salary - expenses;

    if(savings > 0)
    {
        printf("You have extra money to save each month!\n");

        printf("Here are some recommended savings options:\n");

        if(savings >= 500)
        {
            printf("- Open a high-yield savings account.\n");
        }

        if(savings >= 1000)
        {
            printf("- Invest in a low-risk mutual fund.\n");
        }

        if(savings >= 5000)
        {
            printf("- Start a retirement savings account.\n");
        }

        if(savings >= 10000)
        {
            printf("- Consider investing in stocks or other high-risk assets.\n");
        }
    }
    else if(savings == 0)
    {
        printf("You have no extra money to save each month, but you are living within your means.\n");
    }
    else
    {
        printf("You are spending more than you make each month!\n");

        printf("Here are some recommended actions to take:\n");

        if(expenses <= salary * 0.8)
        {
            printf("- Look for ways to reduce your expenses, such as eating out less or downgrading your cable package.\n");
        }

        if(expenses > salary * 0.8)
        {
            printf("- You may need to consider finding ways to increase your income, such as getting a side job or asking for a raise.\n");
        }

        printf("- It's important to create a budget and stick to it to avoid overspending.\n");

        printf("- Consider seeking help from a financial advisor or credit counselor to develop a plan to pay off any debts.\n");
    }

    return 0;
}