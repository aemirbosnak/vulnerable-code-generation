//GEMINI-pro DATASET v1.0 Category: Mortgage Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool valid_input = false;
float principal_loan, time_loan, annual_interest_rate;

int main() {
    while (!valid_input) {
        printf("\n");
        printf("I am so grateful for the opportunity to help you calculate your mortgage!\n");
        printf("Please enter the following information:\n");
        printf("Principal loan amount (in dollars): ");
        scanf("%f", &principal_loan);
        printf("Loan term (in years): ");
        scanf("%f", &time_loan);
        printf("Annual interest rate (as a percentage): ");
        scanf("%f", &annual_interest_rate);

        // Validate input values
        if (principal_loan <= 0) {
            printf("Invalid input: Principal loan amount must be greater than zero.\n");
        } else if (time_loan <= 0) {
            printf("Invalid input: Loan term must be greater than zero.\n");
        } else if (annual_interest_rate <= 0) {
            printf("Invalid input: Annual interest rate must be greater than zero.\n");
        } else {
            valid_input = true;
        }
    }

    // Calculate monthly interest rate
    float monthly_interest_rate = (annual_interest_rate / 100) / 12;

    // Calculate number of monthly payments
    int num_monthly_payments = time_loan * 12;

    // Calculate monthly payment
    float monthly_payment = principal_loan * (monthly_interest_rate * pow((1 + monthly_interest_rate), num_monthly_payments)) / (pow((1 + monthly_interest_rate), num_monthly_payments) - 1);

    // Calculate total interest paid
    float total_interest_paid = monthly_payment * num_monthly_payments - principal_loan;

    // Print loan information
    printf("\n");
    printf("Loan Information:\n");
    printf("Principal loan amount: $%.2f\n", principal_loan);
    printf("Loan term: %.1f years\n", time_loan);
    printf("Annual interest rate: %.2f%%\n", annual_interest_rate);

    // Print monthly payment and total interest paid
    printf("\n");
    printf("Monthly payment: $%.2f\n", monthly_payment);
    printf("Total interest paid: $%.2f\n", total_interest_paid);

    printf("\n");
    printf("Thank you for using our mortgage calculator. We're grateful for your business!");

    return 0;
}