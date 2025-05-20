//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LENGTH 50

int main()
{
    double principal, interest_rate, monthly_payment, balance, total_interest;
    int months;

    char input[MAX_LENGTH];

    printf("MORTGAGE CALCULATOR\n");

    printf("Please enter the principal amount: ");
    fgets(input, MAX_LENGTH, stdin);
    principal = atof(input);

    printf("Please enter the interest rate (e.g. 3.6 for 3.6%%): ");
    fgets(input, MAX_LENGTH, stdin);
    interest_rate = atof(input) / 1200;

    printf("Please enter the number of years for the mortgage: ");
    fgets(input, MAX_LENGTH, stdin);
    months = atoi(input) * 12;

    printf("Please enter the monthly payment: ");
    fgets(input, MAX_LENGTH, stdin);
    monthly_payment = atof(input);

    balance = principal;
    total_interest = 0;

    printf("\nPayment Schedule\n");
    printf("----------------------------------------------------\n");
    printf("Month\tBalance\t\tPayment\tInterest\tPrincipal\n");

    for (int i = 0; i < months; i++) {
        double interest = balance * interest_rate;
        double principal_paid = monthly_payment - interest;
        balance = balance - principal_paid;
        total_interest = total_interest + interest;

        printf("%d\t$%.2lf\t$%.2lf\t$%.2lf\t$%.2lf\n",
               i + 1, balance, monthly_payment, interest, principal_paid);

        if (balance <= 0) {
            printf("\nMortgage paid off in %d years and %d months!\n", (i + 1) / 12, (i + 1) % 12);
            break;
        }
    }

    printf("----------------------------------------------------\n");
    printf("Total Interest Paid: $%.2lf\n", total_interest);

    return 0;
}