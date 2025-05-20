//Falcon-180B DATASET v1.0 Category: Mortgage Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LOAN_TERM 30
#define MIN_LOAN_TERM 1
#define MAX_LOAN_AMOUNT 1000000
#define MIN_LOAN_AMOUNT 1000
#define MAX_INTEREST_RATE 25
#define MIN_INTEREST_RATE 1

int main() {
    double loan_amount, interest_rate, loan_term, monthly_payment, total_interest, total_payment;
    int valid_input = 0;

    do {
        printf("Enter loan amount (between $%d and $%d): ", MIN_LOAN_AMOUNT, MAX_LOAN_AMOUNT);
        scanf("%lf", &loan_amount);

        if (loan_amount < MIN_LOAN_AMOUNT || loan_amount > MAX_LOAN_AMOUNT) {
            printf("Invalid input. Loan amount must be between $%d and $%d.\n", MIN_LOAN_AMOUNT, MAX_LOAN_AMOUNT);
        }
    } while (!valid_input);

    do {
        printf("Enter interest rate (between %d%% and %d%%): ", MIN_INTEREST_RATE, MAX_INTEREST_RATE);
        scanf("%lf", &interest_rate);

        if (interest_rate < MIN_INTEREST_RATE || interest_rate > MAX_INTEREST_RATE) {
            printf("Invalid input. Interest rate must be between %d%% and %d%%.\n", MIN_INTEREST_RATE, MAX_INTEREST_RATE);
        }
    } while (!valid_input);

    do {
        printf("Enter loan term (between %d and %d years): ", MIN_LOAN_TERM, MAX_LOAN_TERM);
        scanf("%d", &loan_term);

        if (loan_term < MIN_LOAN_TERM || loan_term > MAX_LOAN_TERM) {
            printf("Invalid input. Loan term must be between %d and %d years.\n", MIN_LOAN_TERM, MAX_LOAN_TERM);
        }
    } while (!valid_input);

    monthly_payment = loan_amount * interest_rate / (12 * 100) * pow((1 + interest_rate / 12), 12 * loan_term) / (pow((1 + interest_rate / 12), 12 * loan_term) - 1);
    total_interest = monthly_payment * 12 * loan_term - loan_amount;
    total_payment = monthly_payment * 12 * loan_term;

    printf("Monthly payment: $%.2lf\n", monthly_payment);
    printf("Total interest paid: $%.2lf\n", total_interest);
    printf("Total payment: $%.2lf\n", total_payment);

    return 0;
}