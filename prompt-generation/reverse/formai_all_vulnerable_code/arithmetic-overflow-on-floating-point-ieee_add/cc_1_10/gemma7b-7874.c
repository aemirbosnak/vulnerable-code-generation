//Gemma-7B DATASET v1.0 Category: Mortgage Calculator ; Style: sophisticated
#include <stdio.h>
#include <math.h>

int main() {
    double principal, interestRate, years, monthlyPayment, totalInterest, totalPayment;
    char paymentFrequency[20];

    printf("Welcome to the Mortgage Calculator!\n");

    // Get the principal amount
    printf("Enter the principal amount: ");
    scanf("%lf", &principal);

    // Get the interest rate
    printf("Enter the interest rate (%): ");
    scanf("%lf", &interestRate);

    // Get the number of years
    printf("Enter the number of years: ");
    scanf("%lf", &years);

    // Get the payment frequency
    printf("Enter the payment frequency (monthly/annual): ");
    scanf("%s", paymentFrequency);

    // Calculate the monthly interest rate
    double monthlyInterestRate = interestRate / 12;

    // Calculate the number of payments
    int numPayments = years * 12;

    // Calculate the total interest
    totalInterest = principal * monthlyInterestRate * numPayments / 100;

    // Calculate the total payment
    totalPayment = principal + totalInterest;

    // Display the results
    printf("----------------------------------------------------\n");
    printf("Mortgage Summary\n");
    printf("----------------------------------------------------\n");
    printf("Principal: $%.2lf\n", principal);
    printf("Interest Rate: %.2lf%\n", interestRate);
    printf("Number of Years: %.2lf\n", years);
    printf("Payment Frequency: %s\n", paymentFrequency);
    printf("Total Interest: $%.2lf\n", totalInterest);
    printf("Total Payment: $%.2lf\n", totalPayment);
    printf("----------------------------------------------------\n");

    return 0;
}