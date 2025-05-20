//Falcon-180B DATASET v1.0 Category: Mortgage Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TERM 30

struct term {
    double amount;
    int years;
};

int main(void) {
    struct term terms[MAX_TERM];
    int num_terms = 0;
    double total_amount = 0.0;
    double monthly_payment = 0.0;
    double total_interest = 0.0;
    double total_principal = 0.0;

    printf("Enter the amount of the mortgage: ");
    scanf("%lf", &total_amount);

    printf("Enter the interest rate (as a percentage): ");
    scanf("%lf", &terms[num_terms].amount);
    terms[num_terms].years = 0;
    num_terms++;

    printf("Enter the number of years for the mortgage: ");
    scanf("%d", &terms[num_terms].years);
    terms[num_terms].amount = 0.0;
    num_terms++;

    printf("Enter any additional terms (amount, years): ");
    while (scanf("%lf %d", &terms[num_terms].amount, &terms[num_terms].years) == 2 && num_terms < MAX_TERM) {
        num_terms++;
    }

    for (int i = 0; i < num_terms; i++) {
        if (terms[i].amount > 0.0) {
            total_amount += terms[i].amount;
        }
    }

    monthly_payment = total_amount * (0.01 * terms[0].years) / (1 - pow(1 + 0.01 * terms[0].years, -num_terms));

    printf("Monthly payment: $%.2f\n", monthly_payment);

    for (int i = 0; i < num_terms; i++) {
        if (terms[i].amount > 0.0) {
            double interest = terms[i].amount * (0.01 * terms[i].years) / (1 - pow(1 + 0.01 * terms[i].years, -num_terms));
            double principal = terms[i].amount - interest;
            total_interest += interest;
            total_principal += principal;
        }
    }

    printf("Total interest paid: $%.2f\n", total_interest);
    printf("Total principal paid: $%.2f\n", total_principal);

    return 0;
}