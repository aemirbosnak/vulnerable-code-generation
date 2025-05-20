//Gemma-7B DATASET v1.0 Category: Mortgage Calculator ; Style: funny
#include <stdio.h>
#include <math.h>

int main()
{
    float home_price, down_payment, mortgage_amount, interest_rate, monthly_payment, total_interest;
    int years;

    printf("Welcome to the C Mortgage Calculator, where dreams go to die!\n");

    // Get the home price
    printf("What's the price of the home you're buying? $");
    scanf("%f", &home_price);

    // Get the down payment
    printf("How much are you putting down? $");
    scanf("%f", &down_payment);

    // Calculate the mortgage amount
    mortgage_amount = home_price - down_payment;

    // Get the interest rate
    printf("What's the interest rate? (%): ");
    scanf("%f", &interest_rate);

    // Calculate the number of years
    printf("How many years will you be paying? ");
    scanf("%d", &years);

    // Calculate the monthly payment
    monthly_payment = mortgage_amount * interest_rate / 100 + mortgage_amount / years;

    // Calculate the total interest
    total_interest = mortgage_amount * interest_rate * years;

    // Print the results
    printf("Here's your mortgage breakdown:\n");
    printf("------------------------\n");
    printf("Home price: $%.2f\n", home_price);
    printf("Down payment: $%.2f\n", down_payment);
    printf("Mortgage amount: $%.2f\n", mortgage_amount);
    printf("Interest rate: %.2f%\n", interest_rate);
    printf("Number of years: %d\n", years);
    printf("Monthly payment: $%.2f\n", monthly_payment);
    printf("Total interest: $%.2f\n", total_interest);
    printf("------------------------\n");
    printf("So, are you ready to be a homeowner? Hopefully not!\n");

    return 0;
}