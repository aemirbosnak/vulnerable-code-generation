//Falcon-180B DATASET v1.0 Category: Mortgage Calculator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_LEN 100

typedef struct {
    char name[MAX_LEN];
    double balance;
    double interest_rate;
    double monthly_payment;
    int term_months;
} mortgage;

void init_mortgage(mortgage* m) {
    memset(m->name, 0, MAX_LEN);
    m->balance = 0.0;
    m->interest_rate = 0.0;
    m->monthly_payment = 0.0;
    m->term_months = 0;
}

void print_mortgage(mortgage* m) {
    printf("Name: %s\n", m->name);
    printf("Balance: $%.2f\n", m->balance);
    printf("Interest Rate: %.2f%%\n", m->interest_rate * 100.0);
    printf("Monthly Payment: $%.2f\n", m->monthly_payment);
    printf("Term (months): %d\n\n", m->term_months);
}

double calculate_monthly_payment(double balance, double interest_rate, int term_months) {
    double monthly_interest_rate = interest_rate / 100.0 / 12.0;
    double num_payments = term_months * 12.0;
    double monthly_payment = (balance * monthly_interest_rate) / (1 - pow(1 + monthly_interest_rate, -num_payments));
    return monthly_payment;
}

int main() {
    mortgage m;
    init_mortgage(&m);

    printf("Enter name: ");
    scanf("%s", m.name);

    printf("Enter balance: $");
    scanf("%lf", &m.balance);

    printf("Enter interest rate: %%");
    scanf("%lf", &m.interest_rate);

    m.monthly_payment = calculate_monthly_payment(m.balance, m.interest_rate, 0);
    m.term_months = (int)round(m.balance / m.monthly_payment);

    print_mortgage(&m);

    return 0;
}