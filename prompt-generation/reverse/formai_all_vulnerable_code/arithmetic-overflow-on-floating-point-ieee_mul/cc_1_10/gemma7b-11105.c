//Gemma-7B DATASET v1.0 Category: Mortgage Calculator ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159

int main()
{
    // Define variables
    double principal, interestRate, years, monthlyPayment, totalInterest, totalPayment;
    int i;

    // Get the mortgage loan amount
    printf("Enter the mortgage loan amount: ");
    scanf("%lf", &principal);

    // Get the interest rate
    printf("Enter the interest rate (%): ");
    scanf("%lf", &interestRate);

    // Get the number of years
    printf("Enter the number of years you will live in the house: ");
    scanf("%lf", &years);

    // Calculate the monthly payment
    monthlyPayment = principal * (interestRate / 100) * years / 12;

    // Calculate the total interest
    totalInterest = principal * (interestRate / 100) * years;

    // Calculate the total payment
    totalPayment = monthlyPayment * years * 12;

    // Display the results
    printf("\nSummary of Mortgage Loan:**\n");
    printf("------------------------\n");
    printf("Principal: $%.2lf\n", principal);
    printf("Interest Rate: %.2lf%\n", interestRate);
    printf("Number of Years: %.2lf\n", years);
    printf("Monthly Payment: $%.2lf\n", monthlyPayment);
    printf("Total Interest: $%.2lf\n", totalInterest);
    printf("Total Payment: $%.2lf\n", totalPayment);

    // Calculate the number of mortgage payments
    i = years * 12;

    // Display the number of mortgage payments
    printf("\nNumber of Mortgage Payments: %d\n", i);

    return 0;
}