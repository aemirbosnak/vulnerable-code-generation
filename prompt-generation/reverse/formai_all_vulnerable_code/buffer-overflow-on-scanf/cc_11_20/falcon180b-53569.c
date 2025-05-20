//Falcon-180B DATASET v1.0 Category: Mortgage Calculator ; Style: paranoid
#include <stdio.h>
#include <math.h>

#define MAX_LOAN_AMOUNT 1000000 // Maximum loan amount allowed
#define MAX_LOAN_TERM 30 // Maximum loan term allowed
#define MAX_INTEREST_RATE 0.10 // Maximum interest rate allowed

int main()
{
    double loan_amount, interest_rate, loan_term, monthly_payment, total_interest;
    int valid_input = 0;

    // Get user input for loan amount
    while (!valid_input)
    {
        printf("Enter the loan amount (up to $%d): ", MAX_LOAN_AMOUNT);
        if (scanf("%lf", &loan_amount)!= 1 || loan_amount <= 0)
        {
            printf("Invalid input. Please enter a valid loan amount.\n");
        }
        else if (loan_amount > MAX_LOAN_AMOUNT)
        {
            printf("Loan amount is too high. Maximum allowed is $%d.\n", MAX_LOAN_AMOUNT);
        }
        else
        {
            valid_input = 1;
        }
    }

    // Get user input for interest rate
    while (!valid_input)
    {
        printf("Enter the interest rate (up to %.2f%%): ", MAX_INTEREST_RATE * 100);
        if (scanf("%lf", &interest_rate)!= 1 || interest_rate <= 0 || interest_rate > MAX_INTEREST_RATE)
        {
            printf("Invalid input. Please enter a valid interest rate.\n");
        }
        else
        {
            valid_input = 1;
        }
    }

    // Get user input for loan term
    while (!valid_input)
    {
        printf("Enter the loan term (up to %d years): ", MAX_LOAN_TERM);
        if (scanf("%d", &loan_term)!= 1 || loan_term <= 0 || loan_term > MAX_LOAN_TERM)
        {
            printf("Invalid input. Please enter a valid loan term.\n");
        }
        else
        {
            valid_input = 1;
        }
    }

    // Calculate monthly payment
    monthly_payment = loan_amount * interest_rate / (1 - pow(1 + interest_rate, -loan_term * 12));

    // Calculate total interest
    total_interest = monthly_payment * loan_term * 12 - loan_amount;

    // Print results
    printf("Monthly payment: $%.2f\n", monthly_payment);
    printf("Total interest: $%.2f\n", total_interest);

    return 0;
}