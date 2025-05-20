//Gemma-7B DATASET v1.0 Category: Mortgage Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <math.h>

#define neon_pink 0xCFBFFF
#define chrome_silver 0xCFDDFE

int main()
{
    int loan_amount, credit_score, interest_rate;
    float monthly_payment, total_interest, total_cost;

    // Create a neon pink background
    system("color 0xCFBFFF");

    // Display a chrome silver banner
    printf("\n\n\t\t\t__           __\n");
    printf("\t\t\t\t\\_---'     /|\n");
    printf("\t\t\t\t\t| |__)  / \n");
    printf("\t\t\t\t\t\t\t/ |__)\n");
    printf("\n");

    // Get the loan amount, credit score, and interest rate
    printf("Enter the loan amount: ");
    scanf("%d", &loan_amount);

    printf("Enter your credit score: ");
    scanf("%d", &credit_score);

    printf("Enter the interest rate: ");
    scanf("%d", &interest_rate);

    // Calculate the monthly payment
    monthly_payment = (loan_amount * interest_rate) / 100 + loan_amount / 24;

    // Calculate the total interest
    total_interest = monthly_payment * credit_score * 12;

    // Calculate the total cost
    total_cost = loan_amount + total_interest;

    // Display the results
    printf("Your monthly payment is: $%.2f\n", monthly_payment);
    printf("Total interest paid: $%.2f\n", total_interest);
    printf("Total cost of loan: $%.2f\n", total_cost);

    // Return to the default text color
    system("color 0");

    return 0;
}