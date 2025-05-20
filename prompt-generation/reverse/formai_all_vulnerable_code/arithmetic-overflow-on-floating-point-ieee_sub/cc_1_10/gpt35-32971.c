//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Cryptic Personal Finance Planner

    float income_today, income_tomorrow, expenses_today, expenses_tomorrow, balance_current, balance_next;
    char report[1000];

    // Get inputs from user
    printf("Please enter your income for today: ");
    scanf("%f", &income_today);

    printf("Please enter your income for tomorrow: ");
    scanf("%f", &income_tomorrow);

    printf("Please enter your expenses for today: ");
    scanf("%f", &expenses_today);

    printf("Please enter your expenses for tomorrow: ");
    scanf("%f", &expenses_tomorrow);

    // Calculate balances
    balance_current = income_today - expenses_today;
    balance_next = income_tomorrow - expenses_tomorrow;

    // Generate report
    sprintf(report, "Current Balance: %0.2f\nNext Balance: %0.2f\n\n", balance_current, balance_next);

    // Output report
    printf("\n\n\n");

    for (int i = 0; i < 1000; i++)
    {
        if (report[i] == '\n')
        {
            sleep(2);
            printf("%c", report[i]);
        }
        else if (report[i] == '\0')
        {
            break;
        }
        else
        {
            printf("%c", report[i]);
        }
    }

    return 0;
}