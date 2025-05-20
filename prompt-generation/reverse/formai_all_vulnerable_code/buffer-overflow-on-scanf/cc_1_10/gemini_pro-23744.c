//GEMINI-pro DATASET v1.0 Category: Mortgage Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define YEARS_TO_PAY 25

struct loan_data
{
    int principal;
    float interest_rate;
    int years_to_pay;
};

void get_loan_data(struct loan_data *loan)
{
    char answer[10];
    int successful_scan = 0;

    printf("What is the principal amount of the loan?\n");
    while (!successful_scan)
    {
        scanf("%d", &loan->principal);
        if (loan->principal > 0)
        {
            successful_scan = 1;
        }
        else
        {
            printf("Invalid input. Please enter a positive integer.\n");
        }
    }

    successful_scan = 0;

    printf("What is the interest rate on the loan (as a percentage)?\n");
    while (!successful_scan)
    {
        scanf("%f", &loan->interest_rate);
        if (loan->interest_rate > 0)
        {
            successful_scan = 1;
        }
        else
        {
            printf("Invalid input. Please enter a positive number.\n");
        }
    }

    successful_scan = 0;

    printf("Over how many years would you like to pay off the loan?\n");
    while (!successful_scan)
    {
        scanf("%d", &loan->years_to_pay);
        if (loan->years_to_pay > 0)
        {
            successful_scan = 1;
        }
        else
        {
            printf("Invalid input. Please enter a positive integer.\n");
        }
    }
}

float calculate_monthly_payment(struct loan_data loan)
{
    float monthly_interest = loan.interest_rate / 100 / 12;
    float num_payments = loan.years_to_pay * 12;
    float monthly_payment = (loan.principal * monthly_interest) / (1 - pow((1 + monthly_interest), -num_payments));
    return monthly_payment;
}

int main()
{
    struct loan_data loan;
    float monthly_payment;

    get_loan_data(&loan);

    monthly_payment = calculate_monthly_payment(loan);

    printf("The monthly payment for your loan is $%.2f.\n", monthly_payment);

    return 0;
}