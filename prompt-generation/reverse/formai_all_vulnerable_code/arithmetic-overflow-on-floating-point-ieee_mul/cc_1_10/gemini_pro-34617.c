//GEMINI-pro DATASET v1.0 Category: Mortgage Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Declare variables
    double principal, interest_rate, monthly_payment, term, total_interest;
    int num_payments;

    // Get user input
    printf("Enter the principal amount: ");
    scanf("%lf", &principal);

    printf("Enter the annual interest rate (as a percentage): ");
    scanf("%lf", &interest_rate);

    printf("Enter the monthly payment: ");
    scanf("%lf", &monthly_payment);

    printf("Enter the term in years: ");
    scanf("%lf", &term);

    // Calculate the number of payments
    num_payments = term * 12;

    // Calculate the monthly interest rate
    interest_rate /= 100.0;
    interest_rate /= 12.0;

    // Initialize the total interest to 0
    total_interest = 0.0;

    // Calculate the mortgage payment
    for (int i = 0; i < num_payments; i++) {
        // Calculate the interest paid in this month
        double interest_paid = interest_rate * principal;

        // Calculate the principal paid in this month
        double principal_paid = monthly_payment - interest_paid;

        // Update the principal
        principal -= principal_paid;

        // Add the interest paid to the total interest
        total_interest += interest_paid;

        // Print the payment information
        printf("Payment %d: Interest paid = $%.2f, principal paid = $%.2f, remaining principal = $%.2f\n", i + 1, interest_paid, principal_paid, principal);
    }

    // Print the total interest paid
    printf("Total interest paid: $%.2f\n", total_interest);

    return 0;
}