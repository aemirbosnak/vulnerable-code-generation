//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: paranoid
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[50], c;
    double loan_amount, interest_rate, monthly_payment, principal, interest, balance;
    int num_payments;

    printf("Welcome to the Paranoid Mortgage Calculator! Are you being watched?\nEnter the loan amount:\n");
    fgets(input, sizeof(input), stdin);
    loan_amount = atof(input);

    printf("Enter the interest rate:\n");
    fgets(input, sizeof(input), stdin);
    interest_rate = atof(input);

    printf("Enter the number of payments:\n");
    fgets(input, sizeof(input), stdin);
    num_payments = atoi(input);

    printf("Enter the monthly payment amount:\n");
    fgets(input, sizeof(input), stdin);
    monthly_payment = atof(input);

    printf("\nCalculating your mortgage paranoidly, please wait...\n");
    printf("Loan Amount: %.2f\n", loan_amount);
    printf("Interest Rate: %.2f\n", interest_rate);
    printf("Number of Payments: %d\n", num_payments);
    printf("Monthly Payment: %.2f\n", monthly_payment);

    interest_rate /= 1200;
    balance = loan_amount;

    printf("\n    Payment #  |  Principal  |  Interest  |  Balance   \n");
    printf("------------------------------------------------------\n");

    for (int i = 1; i <= num_payments; i++) {
        interest = balance * interest_rate;
        principal = monthly_payment - interest;

        if (principal > balance) {
            printf("Monthly payment is too small!\nDumping data and deleting history...\n");
            memset(input, 0, sizeof(input));
            memset(&loan_amount, 0, sizeof(loan_amount));
            memset(&interest_rate, 0, sizeof(interest_rate));
            memset(&monthly_payment, 0, sizeof(monthly_payment));
            memset(&num_payments, 0, sizeof(num_payments));
            exit(0);
        }

        balance -= principal;
        printf("    %3d         |  $%7.2f  |  $%6.2f   |  $%7.2f  \n", i, principal, interest, balance);

        if (i == num_payments && balance > 0) {
            printf("\nYou still owe $%.2f at the end of the loan term.\n", balance);
            printf("Encrypting and transmitting data to our secure servers... done.\nErasing all local copies of data...\n");
            memset(input, 0, sizeof(input));
            memset(&loan_amount, 0, sizeof(loan_amount));
            memset(&interest_rate, 0, sizeof(interest_rate));
            memset(&monthly_payment, 0, sizeof(monthly_payment));
            memset(&num_payments, 0, sizeof(num_payments));
            exit(0);
        }
    }

    printf("\nYour paranoid mortgage has been successfully calculated!\n");
    
    return 0;
}