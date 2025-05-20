//Gemma-7B DATASET v1.0 Category: Mortgage Calculator ; Style: funny
#include <stdio.h>
#include <math.h>

int main()
{

    double home_price, down_payment, mortgage_interest_rate, monthly_payment, total_interest;
    int years_to_pay;

    printf("Welcome to the Dream Home Mortgage Calculator!\n");
    printf("Please enter the home price: ");
    scanf("%lf", &home_price);

    printf("Please enter your down payment: ");
    scanf("%lf", &down_payment);

    printf("Please enter the mortgage interest rate: ");
    scanf("%lf", &mortgage_interest_rate);

    printf("Please enter the number of years you're planning to pay: ");
    scanf("%d", &years_to_pay);

    // Calculate the down payment percentage
    double down_payment_percentage = (down_payment / home_price) * 100;

    // Calculate the monthly interest rate
    double monthly_interest_rate = mortgage_interest_rate / 12;

    // Calculate the number of months to pay
    int num_months_to_pay = years_to_pay * 12;

    // Calculate the total interest
    total_interest = home_price * monthly_interest_rate * num_months_to_pay / 100;

    // Calculate the monthly payment
    monthly_payment = home_price * monthly_interest_rate * num_months_to_pay / 1000;

    // Print the results
    printf("\nCongratulations, you're pre-approved for a mortgage on your dream home!\n");
    printf("Here are your results: \n");
    printf("Home price: $%.2lf\n", home_price);
    printf("Down payment: $%.2lf\n", down_payment);
    printf("Down payment percentage: %.2lf%%\n", down_payment_percentage);
    printf("Monthly interest rate: %.2lf%\n", monthly_interest_rate);
    printf("Number of years to pay: %d\n", years_to_pay);
    printf("Total interest: $%.2lf\n", total_interest);
    printf("Monthly payment: $%.2lf\n", monthly_payment);

    return 0;
}