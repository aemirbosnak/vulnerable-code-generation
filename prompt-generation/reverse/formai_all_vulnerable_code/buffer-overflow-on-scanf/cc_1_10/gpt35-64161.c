//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

// This program calculates monthly mortgage payments based on a given loan amount and interest rate
// It is written in an asynchronous style, using callbacks to handle user input and displaying results

typedef struct {
    double principal;
    double rate;
    int term;
    double payment;
} Mortgage;

// Define a callback function to handle user input for loan amount
void get_loan_amount(Mortgage *mortgage, void (*callback)(Mortgage *, double)) {
    double loan_amount;
    printf("Enter loan amount: $");
    scanf("%lf", &loan_amount);
    callback(mortgage, loan_amount);
}

// Define a callback function to handle user input for interest rate
void get_interest_rate(Mortgage *mortgage, void (*callback)(Mortgage *, double)) {
    double interest_rate;
    printf("Enter interest rate: ");
    scanf("%lf", &interest_rate);
    callback(mortgage, interest_rate);
}

// Define a callback function to handle user input for loan term
void get_loan_term(Mortgage *mortgage, void (*callback)(Mortgage *, int)) {
    int loan_term;
    printf("Enter loan term (in years): ");
    scanf("%d", &loan_term);
    callback(mortgage, loan_term);
}

// Define a function to calculate monthly mortgage payment
void calculate_payment(Mortgage *mortgage) {
    double monthly_rate = (mortgage->rate / 100) / 12;
    int num_payments = mortgage->term * 12;
    double numerator = mortgage->principal * monthly_rate * pow(1 + monthly_rate, num_payments);
    double denominator = pow(1 + monthly_rate, num_payments) - 1;
    mortgage->payment = numerator / denominator;
}

// Define a callback function to display monthly mortgage payment
void display_payment(Mortgage *mortgage) {
    printf("Your monthly mortgage payment is: $%.2f\n", mortgage->payment);
}

int main() {
    Mortgage my_mortgage;
    my_mortgage.principal = 0;
    my_mortgage.rate = 0;
    my_mortgage.term = 0;
    my_mortgage.payment = 0;
    
    // Get user input for loan amount asynchronously
    get_loan_amount(&my_mortgage, (void *) get_interest_rate);
    
    // Wait until all callbacks are finished
    while(my_mortgage.principal == 0 || my_mortgage.rate == 0 || my_mortgage.term == 0) {
        sleep(1);
    }
    
    // Calculate monthly mortgage payment
    calculate_payment(&my_mortgage);
    
    // Display monthly mortgage payment
    display_payment(&my_mortgage);
    
    return 0;
}