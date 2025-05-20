//Gemma-7B DATASET v1.0 Category: Mortgage Calculator ; Style: innovative
#include <stdio.h>
#include <math.h>

int main()
{
    float principal, rate, years, monthlyPayment, totalInterest, balance;
    char paymentType;

    // Get the principal amount
    printf("Enter the principal amount: ");
    scanf("%f", &principal);

    // Get the interest rate
    printf("Enter the interest rate (as a decimal): ");
    scanf("%f", &rate);

    // Get the number of years
    printf("Enter the number of years: ");
    scanf("%f", &years);

    // Get the payment type (monthly/annual)
    printf("Enter the payment type (m/a): ");
    scanf(" %c", &paymentType);

    // Calculate the monthly interest rate
    float monthlyRate = rate / 12;

    // Calculate the number of months
    int months = years * 12;

    // Calculate the total interest
    totalInterest = principal * monthlyRate * months;

    // Calculate the monthly payment
    monthlyPayment = totalInterest / months + principal / months;

    // Calculate the balance
    balance = principal - monthlyPayment * months;

    // Print the results
    printf("\n**Mortgage Calculator Results:**\n");
    printf("------------------------\n");
    printf("Principal: $%.2f\n", principal);
    printf("Interest Rate: %.2f%\n", rate);
    printf("Number of Years: %.2f\n", years);
    printf("Monthly Payment: $%.2f\n", monthlyPayment);
    printf("Total Interest: $%.2f\n", totalInterest);
    printf("Balance: $%.2f\n", balance);

    return 0;
}