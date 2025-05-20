//Falcon2-11B DATASET v1.0 Category: Mortgage Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct mortgage
{
    double interestRate;
    double loanAmount;
    int loanTerm;
    int years;
    int months;
    double totalPayment;
    double interestPaid;
    double principalPaid;
    double remainingBalance;
};

void calculate(struct mortgage mortgage)
{
    double payment = 0.0;
    double r = mortgage.interestRate;
    double n = mortgage.loanTerm;
    double p = mortgage.loanAmount;
    double i = 1 + r;
    double a = 1;

    for(int i = 0; i < n; i++)
    {
        a = a * i;
        payment += mortgage.loanAmount * i;
        mortgage.totalPayment = mortgage.totalPayment + payment;
        mortgage.interestPaid += payment * mortgage.interestRate;
        mortgage.principalPaid += payment - mortgage.interestPaid;
        mortgage.remainingBalance = mortgage.remainingBalance - mortgage.principalPaid;
    }

    mortgage.years = ceil(log(a) / log(i + r));
    mortgage.months = mortgage.years * 12;
}

int main()
{
    struct mortgage mortgage;
    mortgage.interestRate = 0.04;
    mortgage.loanAmount = 200000;
    mortgage.loanTerm = 360;

    calculate(mortgage);

    printf("Monthly payment: $%.2f\n", mortgage.totalPayment / 12);
    printf("Total interest paid: $%.2f\n", mortgage.interestPaid);
    printf("Total principal paid: $%.2f\n", mortgage.principalPaid);
    printf("Remaining balance: $%.2f\n", mortgage.remainingBalance);

    return 0;
}