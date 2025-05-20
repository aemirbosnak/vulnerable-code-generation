//Gemma-7B DATASET v1.0 Category: Mortgage Calculator ; Style: thoughtful
#include <stdio.h>
#include <math.h>

int main()
{
    float principal, rate, years, monthlyPayment, totalPayment, interest, balance;
    char loanType;

    // Get loan type
    printf("Enter loan type (F, B, P): ");
    scanf("%c", &loanType);

    // Get principal
    printf("Enter principal amount: ");
    scanf("%f", &principal);

    // Get interest rate
    printf("Enter interest rate (%): ");
    scanf("%f", &rate);

    // Get number of years
    printf("Enter number of years: ");
    scanf("%f", &years);

    // Calculate monthly payment
    monthlyPayment = principal * rate / (100 - rate) * years / 12;

    // Calculate total payment
    totalPayment = monthlyPayment * years * 12;

    // Calculate interest
    interest = totalPayment - principal;

    // Calculate balance
    balance = principal - totalPayment;

    // Display results
    printf("---------------------------------------------------\n");
    printf("Loan Details:\n");
    printf("Loan Type: %c\n", loanType);
    printf("Principal: %.2f\n", principal);
    printf("Interest Rate: %.2f%%\n", rate);
    printf("Number of Years: %.2f\n", years);
    printf("Monthly Payment: %.2f\n", monthlyPayment);
    printf("Total Payment: %.2f\n", totalPayment);
    printf("Interest Paid: %.2f\n", interest);
    printf("Balance Remaining: %.2f\n", balance);
    printf("---------------------------------------------------\n");

    return 0;
}