//Falcon-180B DATASET v1.0 Category: Mortgage Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_STRING_LENGTH 50
#define MAX_NUM_OF_YEARS 30

struct mortgage {
    char property_name[MAX_STRING_LENGTH];
    double loan_amount;
    double interest_rate;
    int num_of_years;
};

void get_mortgage_data(struct mortgage* mortgage) {
    printf("Please enter the property name: ");
    scanf("%s", mortgage->property_name);

    printf("Please enter the loan amount: $");
    scanf("%lf", &mortgage->loan_amount);

    printf("Please enter the interest rate (as a percentage): ");
    scanf("%lf", &mortgage->interest_rate);

    printf("Please enter the number of years for the mortgage: ");
    scanf("%d", &mortgage->num_of_years);
}

void calculate_mortgage(struct mortgage* mortgage) {
    double monthly_payment;
    double total_interest;
    double total_payment;

    // Calculate the monthly payment
    monthly_payment = mortgage->loan_amount * (mortgage->interest_rate / 1200);

    // Calculate the total interest paid over the life of the mortgage
    total_interest = mortgage->loan_amount * mortgage->interest_rate * mortgage->num_of_years;

    // Calculate the total payment (loan amount + total interest)
    total_payment = mortgage->loan_amount + total_interest;

    // Print the mortgage summary
    printf("\nMortgage Summary:\n");
    printf("Property name: %s\n", mortgage->property_name);
    printf("Loan amount: $%.2lf\n", mortgage->loan_amount);
    printf("Interest rate: %.2lf%%\n", mortgage->interest_rate * 100);
    printf("Number of years: %d\n", mortgage->num_of_years);
    printf("Monthly payment: $%.2lf\n", monthly_payment);
    printf("Total interest paid: $%.2lf\n", total_interest);
    printf("Total payment: $%.2lf\n\n", total_payment);
}

int main() {
    struct mortgage mortgage;
    int num_of_mortgages;

    printf("Welcome to the Mortgage Calculator!\n");
    printf("How many mortgages would you like to calculate? ");
    scanf("%d", &num_of_mortgages);

    for (int i = 1; i <= num_of_mortgages; i++) {
        printf("\nMortgage #%d:\n", i);
        get_mortgage_data(&mortgage);
        calculate_mortgage(&mortgage);
    }

    return 0;
}