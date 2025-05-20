//Falcon-180B DATASET v1.0 Category: Mortgage Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 32

typedef struct {
    char name[MAX_SIZE];
    double principal;
    double interest;
    int term;
} mortgage;

void mortgage_calculator(mortgage *m) {
    double monthly_payment, total_payment, monthly_interest, principal_payment;
    int i;

    monthly_interest = (m->interest / 1200.0) * m->principal;
    monthly_payment = (monthly_interest + m->principal) / (1200.0 - 1.0);
    total_payment = monthly_payment * m->term;

    printf("Name: %s\n", m->name);
    printf("Principal: $%.2f\n", m->principal);
    printf("Interest Rate: %.2f%%\n", m->interest * 100.0);
    printf("Term (in years): %d\n", m->term);
    printf("Monthly Payment: $%.2f\n", monthly_payment);
    printf("Total Payment: $%.2f\n", total_payment);

    for (i = 0; i < m->term; i++) {
        principal_payment = monthly_payment - (monthly_interest * (1200.0 - 1.0));
        m->principal -= principal_payment;
        printf("Year %d: Principal remaining: $%.2f\n", i+1, m->principal);
    }
}

int main() {
    int i;
    mortgage m;

    printf("Enter the name of the borrower: ");
    scanf("%s", m.name);

    printf("Enter the principal amount of the mortgage: ");
    scanf("%lf", &m.principal);

    printf("Enter the interest rate of the mortgage (in percentage): ");
    scanf("%lf", &m.interest);

    printf("Enter the term of the mortgage (in years): ");
    scanf("%d", &m.term);

    mortgage_calculator(&m);

    return 0;
}