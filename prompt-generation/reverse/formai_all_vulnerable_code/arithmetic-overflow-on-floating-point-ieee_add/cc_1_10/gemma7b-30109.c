//Gemma-7B DATASET v1.0 Category: Mortgage Calculator ; Style: medieval
#include <stdio.h>
#include <math.h>

int main()
{
    float principal, rate, years, payment, total_interest, balance;
    int i;

    // Create a banner
    printf("****************************************************\n");
    printf("Welcome to the Grand Mortgage Calculator!\n");
    printf("****************************************************\n");

    // Get the principal amount
    printf("Enter the principal amount: ");
    scanf("%f", &principal);

    // Get the interest rate
    printf("Enter the interest rate (as a decimal): ");
    scanf("%f", &rate);

    // Get the number of years
    printf("Enter the number of years: ");
    scanf("%f", &years);

    // Calculate the payment
    payment = principal * rate * years / 100 + principal;

    // Calculate the total interest
    total_interest = payment - principal;

    // Calculate the balance
    balance = principal - payment;

    // Print the results
    printf("----------------------------------------------------\n");
    printf("Your monthly payment: $%.2f\n", payment);
    printf("Total interest paid: $%.2f\n", total_interest);
    printf("Remaining balance: $%.2f\n", balance);
    printf("----------------------------------------------------\n");

    // Create a table of payments
    printf("Here is a table of your payments:\n");
    for (i = 0; i < years; i++)
    {
        payment = principal * rate * i / 100 + principal;
        printf("Year %d: $%.2f\n", i + 1, payment);
    }

    // Close the banner
    printf("****************************************************\n");
    printf("Thank you for using the Grand Mortgage Calculator!\n");
    printf("****************************************************\n");

    return 0;
}