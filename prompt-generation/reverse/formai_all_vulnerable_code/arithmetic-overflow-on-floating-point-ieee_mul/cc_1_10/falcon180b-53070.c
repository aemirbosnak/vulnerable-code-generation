//Falcon-180B DATASET v1.0 Category: Mortgage Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the loan amount, interest rate, and loan term
#define LOAN_AMOUNT 500000.0
#define INTEREST_RATE 0.04
#define LOAN_TERM 30

// Function to calculate the monthly payment
double calculate_monthly_payment(double loan_amount, double interest_rate, int loan_term) {
    double monthly_rate = interest_rate / 12.0;
    double denominator = pow(1 + monthly_rate, loan_term) - 1;
    double numerator = monthly_rate * loan_term;
    double monthly_payment = (loan_amount * monthly_rate) / (denominator - pow(1 + monthly_rate, -1));
    return monthly_payment;
}

// Function to calculate the total interest paid
double calculate_total_interest(double loan_amount, double interest_rate, int loan_term) {
    double monthly_rate = interest_rate / 12.0;
    double denominator = pow(1 + monthly_rate, loan_term) - 1;
    double monthly_payment = (loan_amount * monthly_rate) / denominator;
    double total_interest = (loan_amount * monthly_rate * loan_term) - (monthly_payment * loan_term);
    return total_interest;
}

// Function to calculate the amortization schedule
void calculate_amortization_schedule(double loan_amount, double interest_rate, int loan_term) {
    double monthly_payment = calculate_monthly_payment(loan_amount, interest_rate, loan_term);
    double total_interest = calculate_total_interest(loan_amount, interest_rate, loan_term);

    printf("Amortization Schedule:\n");
    printf("Loan Amount: $%.2f\n", loan_amount);
    printf("Interest Rate: %.2f%%\n", interest_rate * 100);
    printf("Loan Term: %d years\n", loan_term);
    printf("Monthly Payment: $%.2f\n", monthly_payment);
    printf("Total Interest Paid: $%.2f\n", total_interest);

    printf("\n");
    printf("Payment\t\tPrincipal\t\tInterest\t\tBalance\n");
    printf("--------------------------------------------------------------------------------------------------------\n");

    double balance = loan_amount;
    int payment_number = 1;
    while (balance > 0) {
        double principal = monthly_payment - balance * interest_rate / 12.0;
        balance -= principal;

        printf("%d\t\t$%.2f\t\t$%.2f\t\t$%.2f\n", payment_number++, principal, monthly_payment - principal, balance);
    }
}

int main() {
    printf("Sherlock Holmes' Mortgage Calculator\n\n");
    printf("Welcome to the world of mortgage calculations, my dear Watson!\n");
    printf("Let's solve the mystery of your monthly payments and total interest paid.\n\n");

    calculate_amortization_schedule(LOAN_AMOUNT, INTEREST_RATE, LOAN_TERM);

    return 0;
}