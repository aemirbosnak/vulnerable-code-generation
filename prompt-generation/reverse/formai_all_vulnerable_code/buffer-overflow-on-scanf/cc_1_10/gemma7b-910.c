//Gemma-7B DATASET v1.0 Category: Mortgage Calculator ; Style: Romeo and Juliet
#include <stdio.h>
#include <math.h>

int main()
{
    int downPayment, loanAmount, interestRate;
    float mortgagePayment, totalInterest, principalRemaining;
    char side;

    printf("Welcome to the Romeo and Juliet Mortgage Calculator!\n");
    printf("Please enter the side you are on: (R)ight or (L)eft?\n");
    scanf("%c", &side);

    switch (side)
    {
        case 'R':
            printf("Enter your down payment (in dollars): ");
            scanf("%d", &downPayment);
            printf("Enter the loan amount (in dollars): ");
            scanf("%d", &loanAmount);
            printf("Enter the interest rate (in percentage): ");
            scanf("%d", &interestRate);

            mortgagePayment = loanAmount - downPayment;
            totalInterest = mortgagePayment * interestRate / 100;
            principalRemaining = mortgagePayment - totalInterest;

            printf("Your monthly mortgage payment is: $%.2f\n", mortgagePayment);
            printf("Total interest paid: $%.2f\n", totalInterest);
            printf("Principal remaining: $%.2f\n", principalRemaining);

            break;

        case 'L':
            printf("Enter the total amount you can afford to spend (in dollars): ");
            scanf("%d", &loanAmount);
            printf("Enter the interest rate (in percentage): ");
            scanf("%d", &interestRate);

            principalRemaining = loanAmount;
            mortgagePayment = principalRemaining * interestRate / 100 + principalRemaining;

            printf("Your monthly mortgage payment is: $%.2f\n", mortgagePayment);
            printf("Total interest paid: $%.2f\n", principalRemaining * interestRate / 100);
            printf("Principal remaining: $%.2f\n", principalRemaining);

            break;
    }

    return 0;
}