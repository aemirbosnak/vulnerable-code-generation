//Gemma-7B DATASET v1.0 Category: Mortgage Calculator ; Style: high level of detail
#include <stdio.h>
#include <math.h>

int main() {
    float principle, interestRate, years, monthlyPayment, totalInterest, totalPayment;
    char paymentType;

    printf("Welcome to the Mortgage Calculator!\n");
    printf("Please provide the following information:\n");

    // Get the principle
    printf("Principle (amount borrowed): $");
    scanf("%f", &principle);

    // Get the interest rate
    printf("Interest Rate (%): ");
    scanf("%f", &interestRate);

    // Get the number of years
    printf("Number of Years:");
    scanf("%f", &years);

    // Get the payment type
    printf("Select Payment Type (M/A): ");
    scanf(" %c", &paymentType);

    // Calculate the monthly interest rate
    float monthlyInterestRate = interestRate / 12;

    // Calculate the number of months
    int months = years * 12;

    // Calculate the total interest
    totalInterest = principle * monthlyInterestRate * months / 100;

    // Calculate the total payment
    totalPayment = principle + totalInterest;

    // Print the results
    printf("\n");
    printf("Summary:\n");
    printf("Principal: $%0.2f\n", principle);
    printf("Interest Rate: %0.2f%\n", interestRate);
    printf("Number of Years: %d\n", years);
    printf("Total Interest: $%0.2f\n", totalInterest);
    printf("Total Payment: $%0.2f\n", totalPayment);

    // Calculate the monthly payment
    if (paymentType == 'M') {
        monthlyPayment = totalPayment / months;
        printf("Monthly Payment: $%0.2f\n", monthlyPayment);
    } else if (paymentType == 'A') {
        monthlyPayment = totalPayment / months;
        printf("Annual Payment: $%0.2f\n", monthlyPayment);
    } else {
        printf("Invalid payment type.\n");
    }

    return 0;
}