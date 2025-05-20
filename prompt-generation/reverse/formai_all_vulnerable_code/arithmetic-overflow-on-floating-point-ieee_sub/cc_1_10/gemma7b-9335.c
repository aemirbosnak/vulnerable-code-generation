//Gemma-7B DATASET v1.0 Category: Mortgage Calculator ; Style: grateful
#include <stdio.h>
#include <math.h>

int main()
{
    // Define the variables
    double principal, rate, years, monthlyPayment, totalInterest, totalPayment;
    int i;

    // Get the principal amount
    printf("Enter the principal amount: ");
    scanf("%lf", &principal);

    // Get the interest rate
    printf("Enter the interest rate (%): ");
    scanf("%lf", &rate);

    // Get the number of years
    printf("Enter the number of years: ");
    scanf("%lf", &years);

    // Calculate the monthly payment
    monthlyPayment = principal * rate / 100 * years / 12;

    // Calculate the total interest
    totalInterest = principal * rate * years / 100 * (years / 12) - principal;

    // Calculate the total payment
    totalPayment = monthlyPayment * years * 12;

    // Print the results
    printf("---------------------------------------------------\n");
    printf("Loan Payment Calculator\n");
    printf("---------------------------------------------------\n");
    printf("Principal: $%.2lf\n", principal);
    printf("Interest Rate: %.2lf%\n", rate);
    printf("Number of Years: %.2lf\n", years);
    printf("Monthly Payment: $%.2lf\n", monthlyPayment);
    printf("Total Interest: $%.2lf\n", totalInterest);
    printf("Total Payment: $%.2lf\n", totalPayment);
    printf("---------------------------------------------------\n");

    // Calculate the number of monthly payments
    i = years * 12;

    // Print the number of monthly payments
    printf("Number of Monthly Payments: %d\n", i);

    return 0;
}