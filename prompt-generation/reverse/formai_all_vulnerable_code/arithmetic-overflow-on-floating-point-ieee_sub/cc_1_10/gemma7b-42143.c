//Gemma-7B DATASET v1.0 Category: Mortgage Calculator ; Style: high level of detail
#include <stdio.h>
#include <math.h>

int main()
{
    double home_price, down_payment, closing_cost, mortgage_interest_rate, monthly_payment, principal_amount, interest_amount, total_cost;

    // Get the home price
    printf("Enter the home price: ");
    scanf("%lf", &home_price);

    // Get the down payment
    printf("Enter the down payment: ");
    scanf("%lf", &down_payment);

    // Get the closing cost
    printf("Enter the closing cost: ");
    scanf("%lf", &closing_cost);

    // Get the mortgage interest rate
    printf("Enter the mortgage interest rate (as a decimal): ");
    scanf("%lf", &mortgage_interest_rate);

    // Calculate the principal amount
    principal_amount = home_price - down_payment - closing_cost;

    // Calculate the interest amount
    interest_amount = principal_amount * mortgage_interest_rate;

    // Calculate the monthly payment
    monthly_payment = (interest_amount / 12) + principal_amount / 24;

    // Calculate the total cost
    total_cost = monthly_payment * 12 + closing_cost;

    // Print the results
    printf("--------------------------------------------------------\n");
    printf("Mortgage Calculator\n");
    printf("--------------------------------------------------------\n");
    printf("Home price: $%.2lf\n", home_price);
    printf("Down payment: $%.2lf\n", down_payment);
    printf("Closing cost: $%.2lf\n", closing_cost);
    printf("Mortgage interest rate: %.2lf%\n", mortgage_interest_rate);
    printf("Principal amount: $%.2lf\n", principal_amount);
    printf("Interest amount: $%.2lf\n", interest_amount);
    printf("Monthly payment: $%.2lf\n", monthly_payment);
    printf("Total cost: $%.2lf\n", total_cost);
    printf("--------------------------------------------------------\n");

    return 0;
}