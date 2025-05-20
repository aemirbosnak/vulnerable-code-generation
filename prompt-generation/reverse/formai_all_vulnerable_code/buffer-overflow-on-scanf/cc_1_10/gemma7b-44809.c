//Gemma-7B DATASET v1.0 Category: Mortgage Calculator ; Style: satisfied
#include <stdio.h>
#include <math.h>

int main()
{
    float principal, rate, years, monthly_payment, total_interest, total_cost;
    char payment_type;

    printf("Welcome to the C Mortgage Calculator!\n");

    // Get the loan amount
    printf("Enter the loan amount: ");
    scanf("%f", &principal);

    // Get the interest rate
    printf("Enter the interest rate (as a decimal): ");
    scanf("%f", &rate);

    // Get the number of years
    printf("Enter the number of years: ");
    scanf("%f", &years);

    // Get the payment type
    printf("Enter the payment type (M for monthly, Y for yearly): ");
    scanf(" %c", &payment_type);

    // Calculate the monthly interest rate
    float monthly_rate = rate / 12;

    // Calculate the number of payments
    int num_payments = years * 12;

    // Calculate the total interest
    total_interest = principal * monthly_rate * num_payments;

    // Calculate the total cost
    total_cost = principal + total_interest;

    // Display the results
    printf("----------------------------------------------------\n");
    printf("Loan Amount: $%.2f\n", principal);
    printf("Interest Rate: %.2f%\n", rate);
    printf("Number of Years: %.2f\n", years);
    printf("Payment Type: %c\n", payment_type);
    printf("Total Interest: $%.2f\n", total_interest);
    printf("Total Cost: $%.2f\n", total_cost);
    printf("----------------------------------------------------\n");

    return 0;
}