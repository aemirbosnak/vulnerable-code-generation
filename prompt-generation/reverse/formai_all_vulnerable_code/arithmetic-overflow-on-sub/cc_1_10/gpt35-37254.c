//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: medieval
#include <stdio.h>

int main()
{
    int gold, expenses;
    float savings = 0;
    char response;

    printf("Welcome to the Medieval Finance Planner!\n");
    printf("Enter your starting gold amount: ");
    scanf("%d", &gold);

    printf("Will you be adding any expenses? (Y/N): ");
    scanf(" %c", &response);

    while (response == 'Y' || response == 'y')
    {
        printf("Enter the amount of the expense: ");
        scanf("%d", &expenses);

        if (expenses > gold)
        {
            printf("You cannot afford this expense.\n");
        }
        else
        {
            gold -= expenses;
            printf("Your remaining gold is now: %d\n", gold);
            savings -= (float)expenses * 0.1;
        }

        printf("Will you be adding any more expenses? (Y/N): ");
        scanf(" %c", &response);
    }

    printf("Your savings: %.2f\n", savings);
    printf("Would you like to deposit any of your remaining gold into savings? (Y/N): ");
    scanf(" %c", &response);

    if (response == 'Y' || response == 'y')
    {
        int deposit;
        printf("Enter the amount you would like to deposit: ");
        scanf("%d", &deposit);
        savings += deposit;
        printf("Your new savings total is: %.2f\n", savings);
    }

    printf("Thank you for using the Medieval Finance Planner!\n");
    return 0;
}