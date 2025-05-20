//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main() {
    float loan_amount, annual_interest_rate, monthly_payment, principal, interest_rate, balance;
    int years, months, total_payments;

    printf("Enter the loan amount: ");
    scanf("%f", &loan_amount);

    printf("Enter the annual interest rate: ");
    scanf("%f", &annual_interest_rate);

    printf("Enter the loan period in years: ");
    scanf("%d", &years);

    printf("Enter the monthly payment: ");
    scanf("%f", &monthly_payment);

    total_payments = years * 12;
    interest_rate = annual_interest_rate / 1200;
    balance = loan_amount;

    printf("\n");

    printf("Loan Amount: $%.2f\n", loan_amount);
    printf("Annual Interest Rate: %.2f%%\n", annual_interest_rate);
    printf("Loan Period: %d years\n", years);
    printf("Monthly Payment: $%.2f\n", monthly_payment);
    printf("Total Number of Payments: %d\n", total_payments);

    printf("\n");

    printf("Payment#\t Payment Amount\t\t Interest Paid\t\t Principal Paid\t\t Remaining Balance\n");

    for (int i = 1; i <= total_payments; i++) {
        interest_rate = balance * interest_rate;
        principal = monthly_payment - interest_rate;
        balance = balance - principal;

        printf("%d\t\t $%.2f\t\t $%.2f\t\t $%.2f\t\t $%.2f\n", i, monthly_payment, interest_rate, principal, balance);

        if (balance < monthly_payment) {
            monthly_payment = balance + interest_rate;
            balance = 0;
            printf("%d\t\t $%.2f\t\t $%.2f\t\t $%.2f\t\t\t $0.00\n", i + 1, monthly_payment, interest_rate, balance);
            break;
        }
    }

    return 0;
}