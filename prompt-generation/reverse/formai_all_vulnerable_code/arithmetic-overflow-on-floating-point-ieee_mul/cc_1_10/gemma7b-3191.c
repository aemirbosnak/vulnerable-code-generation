//Gemma-7B DATASET v1.0 Category: Mortgage Calculator ; Style: peaceful
#include <stdio.h>
#include <math.h>

int main()
{
    float principal, interestRate, years, monthlyPayment, totalPayment, interest;
    char mortgageType;

    printf("Welcome to the tranquil mortgage calculator.\n");
    printf("Please provide the following information:\n");

    // Get the principal amount
    printf("Enter the loan amount: ");
    scanf("%f", &principal);

    // Get the interest rate
    printf("Enter the interest rate (%): ");
    scanf("%f", &interestRate);

    // Get the number of years
    printf("Enter the number of years you want to borrow for: ");
    scanf("%f", &years);

    // Get the mortgage type
    printf("Choose the mortgage type:\n");
    printf("a. Fixed-rate\n");
    printf("b. Adjustable-rate\n");
    scanf(" %c", &mortgageType);

    // Calculate the monthly payment
    monthlyPayment = principal * interestRate / 1200 + principal * years * interestRate / 100;

    // Calculate the total payment
    totalPayment = monthlyPayment * years * 12;

    // Calculate the interest
    interest = totalPayment - principal;

    // Display the results
    printf("Here is your mortgage calculator results:\n");
    printf("Principal: $%.2f\n", principal);
    printf("Interest Rate: %.2f%\n", interestRate);
    printf("Number of Years: %.2f\n", years);
    printf("Mortgage Type: %c\n", mortgageType);
    printf("Monthly Payment: $%.2f\n", monthlyPayment);
    printf("Total Payment: $%.2f\n", totalPayment);
    printf("Interest: $%.2f\n", interest);

    return 0;
}