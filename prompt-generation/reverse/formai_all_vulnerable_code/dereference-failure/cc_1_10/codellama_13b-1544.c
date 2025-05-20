//Code Llama-13B DATASET v1.0 Category: Mortgage Calculator ; Style: decentralized
// Decentralized Mortgage Calculator
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the structs for the mortgage and the payments
struct mortgage {
    float principal;
    float interest_rate;
    float term;
    float monthly_payment;
};

struct payment {
    float principal_paid;
    float interest_paid;
    float total_paid;
};

// Define the function to calculate the monthly payment
float calculate_monthly_payment(struct mortgage *mortgage) {
    float interest_rate = mortgage->interest_rate / 12;
    float payment = mortgage->principal * interest_rate / (1 - pow(1 + interest_rate, -mortgage->term));
    mortgage->monthly_payment = payment;
    return payment;
}

// Define the function to calculate the payments for a mortgage
void calculate_payments(struct mortgage *mortgage, struct payment *payments, int num_payments) {
    float principal = mortgage->principal;
    float interest_rate = mortgage->interest_rate / 12;
    float term = mortgage->term;
    float monthly_payment = mortgage->monthly_payment;

    for (int i = 0; i < num_payments; i++) {
        float interest_paid = principal * interest_rate;
        float principal_paid = monthly_payment - interest_paid;
        float total_paid = interest_paid + principal_paid;

        payments[i].principal_paid = principal_paid;
        payments[i].interest_paid = interest_paid;
        payments[i].total_paid = total_paid;

        principal -= principal_paid;
    }
}

// Define the function to print the payments for a mortgage
void print_payments(struct payment *payments, int num_payments) {
    for (int i = 0; i < num_payments; i++) {
        printf("Payment %d:\n", i + 1);
        printf("  Principal paid: $%.2f\n", payments[i].principal_paid);
        printf("  Interest paid: $%.2f\n", payments[i].interest_paid);
        printf("  Total paid: $%.2f\n", payments[i].total_paid);
    }
}

// Define the function to print the summary of the mortgage
void print_summary(struct mortgage *mortgage) {
    printf("Mortgage summary:\n");
    printf("  Principal: $%.2f\n", mortgage->principal);
    printf("  Interest rate: %f%%\n", mortgage->interest_rate);
    printf("  Term: %d months\n", mortgage->term);
    printf("  Monthly payment: $%.2f\n", mortgage->monthly_payment);
}

int main() {
    // Define the mortgage
    struct mortgage mortgage;
    mortgage.principal = 100000;
    mortgage.interest_rate = 6;
    mortgage.term = 30;

    // Calculate the monthly payment
    calculate_monthly_payment(&mortgage);

    // Calculate the payments
    int num_payments = mortgage.term * 12;
    struct payment *payments = malloc(num_payments * sizeof(struct payment));
    calculate_payments(&mortgage, payments, num_payments);

    // Print the payments
    print_payments(payments, num_payments);

    // Print the summary
    print_summary(&mortgage);

    free(payments);
    return 0;
}