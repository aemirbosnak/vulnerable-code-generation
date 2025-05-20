//Gemma-7B DATASET v1.0 Category: Mortgage Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

int main()
{
    // Define variables
    double principal, rate, years, monthly_payment, interest, total_interest, balance;

    // Get the principal
    printf("Enter the principal amount: ");
    scanf("%lf", &principal);

    // Get the rate
    printf("Enter the interest rate (as a decimal): ");
    scanf("%lf", &rate);

    // Get the number of years
    printf("Enter the number of years: ");
    scanf("%lf", &years);

    // Calculate the monthly interest rate
    double monthly_rate = rate / 12;

    // Calculate the total number of payments
    int num_payments = years * 12;

    // Calculate the interest
    interest = principal * monthly_rate * num_payments;

    // Calculate the total cost of borrowing
    total_interest = interest + principal;

    // Calculate the monthly payment
    monthly_payment = total_interest / num_payments;

    // Print the results
    printf("----------------------------------------------------\n");
    printf("Loan Summary:\n");
    printf("----------------------------------------------------\n");
    printf("Principal: $%.2lf\n", principal);
    printf("Interest Rate: %f%%\n", rate * 100);
    printf("Number of Years: %.2lf\n", years);
    printf("Total Interest: $%.2lf\n", interest);
    printf("Total Cost of Borrowing: $%.2lf\n", total_interest);
    printf("Monthly Payment: $%.2lf\n", monthly_payment);
    printf("----------------------------------------------------\n");

    return 0;
}