//GEMINI-pro DATASET v1.0 Category: Mortgage Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define FORMAT_SPECIFIER "%20s: %s\n"

int main(int argc, char *argv[])
{
    // Check for the correct number of arguments
    if (argc != 7)
    {
        fprintf(stderr, "Usage: %s <principal> <interest rate> <loan term> <monthly payment> <extra payment> <extra payment start date>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse the command-line arguments
    double principal = atof(argv[1]);
    double interest_rate = atof(argv[2]);
    int loan_term = atoi(argv[3]);
    double monthly_payment = atof(argv[4]);
    double extra_payment = atof(argv[5]);
    int extra_payment_start_date = atoi(argv[6]);

    // Check for invalid arguments
    if (principal <= 0.0 || interest_rate <= 0.0 || loan_term <= 0 || monthly_payment <= 0.0 || extra_payment < 0.0 || extra_payment_start_date <= 0 || extra_payment_start_date > loan_term)
    {
        fprintf(stderr, "Invalid arguments\n");
        return EXIT_FAILURE;
    }

    // Calculate the monthly interest rate
    double monthly_interest_rate = interest_rate / 12.0;

    // Calculate the number of months in the loan term
    int number_of_months = loan_term * 12;

    // Initialize the variables used to track the loan balance and the total interest paid
    double loan_balance = principal;
    double total_interest_paid = 0.0;

    // Iterate over the months in the loan term
    for (int month = 1; month <= number_of_months; month++)
    {
        // Calculate the interest paid in the current month
        double interest_paid = monthly_interest_rate * loan_balance;

        // Calculate the principal paid in the current month
        double principal_paid = monthly_payment - interest_paid;

        // Apply the extra payment if it is the specified start date
        if (month >= extra_payment_start_date)
        {
            principal_paid += extra_payment;
        }

        // Update the loan balance
        loan_balance -= principal_paid;

        // Update the total interest paid
        total_interest_paid += interest_paid;

        // Print the status of the loan
        printf(FORMAT_SPECIFIER, "Month", month);
        printf(FORMAT_SPECIFIER, "Loan Balance", "$%.2f", loan_balance);
        printf(FORMAT_SPECIFIER, "Interest Paid", "$%.2f", interest_paid);
        printf(FORMAT_SPECIFIER, "Principal Paid", "$%.2f", principal_paid);
        printf(FORMAT_SPECIFIER, "Total Interest Paid", "$%.2f", total_interest_paid);
        printf("\n");
    }

    return EXIT_SUCCESS;
}