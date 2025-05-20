//MISTRAL-7B DATASET v1.0 Category: Mortgage Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define MONTHS_IN_YEAR 12

typedef struct {
    float principal;
    float annual_interest_rate;
    float number_of_payments;
} mortgage_info;

void print_mortgage_info(mortgage_info *m) {
    printf("Principal: %f\n", m->principal);
    printf("Annual Interest Rate: %f%%\n", m->annual_interest_rate);
    printf("Number of Payments: %d\n\n", m->number_of_payments);
}

mortgage_info* calculate_mortgage(float purchase_price, float down_payment, float annual_interest_rate, float loan_term_in_years) {
    mortgage_info *m = (mortgage_info*) malloc(sizeof(mortgage_info));

    m->principal = purchase_price - down_payment;
    m->annual_interest_rate = annual_interest_rate / 100.0 / MONTHS_IN_YEAR;
    m->number_of_payments = pow(1 + m->annual_interest_rate, MONTHS_IN_YEAR * loan_term_in_years);

    return m;
}

void print_monthly_payment(mortgage_info *m) {
    float monthly_interest_rate = m->annual_interest_rate / MONTHS_IN_YEAR;
    float monthly_payment = m->principal * monthly_interest_rate / (1 - pow(1 + monthly_interest_rate, -MONTHS_IN_YEAR));

    printf("Monthly Payment: %f\n", monthly_payment);
}

int main(void) {
    float purchase_price = 250000.0;
    float down_payment = 50000.0;
    float annual_interest_rate = 3.5;
    float loan_term_in_years = 30;

    mortgage_info *m = calculate_mortgage(purchase_price, down_payment, annual_interest_rate, loan_term_in_years);
    print_mortgage_info(m);
    print_monthly_payment(m);

    free(m);

    return EXIT_SUCCESS;
}