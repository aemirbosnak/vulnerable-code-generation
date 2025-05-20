//Falcon-180B DATASET v1.0 Category: Mortgage Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

// Function to validate user input for positive values
int validate_input(char* input) {
    int value = atoi(input);
    if (value <= 0) {
        printf("Invalid input. Please enter a positive value.\n");
        return 0;
    }
    return 1;
}

// Function to calculate mortgage payments
void calculate_mortgage(double loan_amount, double interest_rate, int term, double down_payment) {
    double monthly_interest_rate = interest_rate / 1200;
    double monthly_payment = (loan_amount - down_payment) * monthly_interest_rate / (1 - pow(1 + monthly_interest_rate, -term));
    printf("Your monthly mortgage payment will be $%.2f.\n", monthly_payment);
}

int main() {
    char loan_amount_str[MAX_STRING_LENGTH];
    char interest_rate_str[MAX_STRING_LENGTH];
    char term_str[MAX_STRING_LENGTH];
    char down_payment_str[MAX_STRING_LENGTH];

    // Get user input for loan amount
    printf("Enter the loan amount: ");
    scanf("%s", loan_amount_str);
    if (!validate_input(loan_amount_str)) {
        return 1;
    }
    double loan_amount = atof(loan_amount_str);

    // Get user input for interest rate
    printf("Enter the interest rate: ");
    scanf("%s", interest_rate_str);
    if (!validate_input(interest_rate_str)) {
        return 1;
    }
    double interest_rate = atof(interest_rate_str);

    // Get user input for term
    printf("Enter the term in years: ");
    scanf("%s", term_str);
    if (!validate_input(term_str)) {
        return 1;
    }
    int term = atoi(term_str);

    // Get user input for down payment
    printf("Enter the down payment amount: ");
    scanf("%s", down_payment_str);
    if (!validate_input(down_payment_str)) {
        return 1;
    }
    double down_payment = atof(down_payment_str);

    // Calculate mortgage payments
    calculate_mortgage(loan_amount, interest_rate, term, down_payment);

    return 0;
}