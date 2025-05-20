//Gemma-7B DATASET v1.0 Category: Mortgage Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159

int main()
{
    float principal, interestRate, years, monthlyPayment, totalInterest, totalCost;
    char* mortgageType;

    // Get the mortgage type
    printf("Enter the type of mortgage (fixed, adjustable, etc.): ");
    scanf("%s", mortgageType);

    // Get the principal
    printf("Enter the principal amount: ");
    scanf("%f", &principal);

    // Get the interest rate
    printf("Enter the interest rate (%): ");
    scanf("%f", &interestRate);

    // Get the number of years
    printf("Enter the number of years: ");
    scanf("%f", &years);

    // Calculate the monthly payment
    monthlyPayment = principal * interestRate / (100 - interestRate) * years / 12;

    // Calculate the total interest
    totalInterest = monthlyPayment * years * 12 - principal;

    // Calculate the total cost
    totalCost = totalInterest + principal;

    // Print the results
    printf("---------------------------------------------------\n");
    printf("Mortgage Calculator Results\n");
    printf("---------------------------------------------------\n");
    printf("Mortgage Type: %s\n", mortgageType);
    printf("Principal: %.2f\n", principal);
    printf("Interest Rate: %.2f%\n", interestRate);
    printf("Number of Years: %.2f\n", years);
    printf("Monthly Payment: %.2f\n", monthlyPayment);
    printf("Total Interest: %.2f\n", totalInterest);
    printf("Total Cost: %.2f\n", totalCost);
    printf("---------------------------------------------------\n");

    return 0;
}