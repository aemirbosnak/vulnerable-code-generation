//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CREDITS 10

int main()
{
    int credits = MAX_CREDITS;
    char credit_card_number[20];
    char pin_number[10];
    int i, j;

    system("clear");

    // Paranoid credit card number validation
    printf("Enter your credit card number: ");
    scanf("%s", credit_card_number);

    for (i = 0; i < 20; i++)
    {
        if (credit_card_number[i] < '0' || credit_card_number[i] > '9')
        {
            printf("Invalid credit card number.\n");
            exit(1);
        }
    }

    // Paranoid pin number validation
    printf("Enter your pin number: ");
    scanf("%s", pin_number);

    for (j = 0; j < 10; j++)
    {
        if (pin_number[j] < '0' || pin_number[j] > '9')
        {
            printf("Invalid pin number.\n");
            exit(1);
        }
    }

    // Subtract credits for fraudulent transaction
    credits--;

    // Print remaining credits
    printf("Your remaining credits are: %d\n", credits);

    return 0;
}