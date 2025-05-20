//Falcon-180B DATASET v1.0 Category: Mortgage Calculator ; Style: configurable
#include <stdio.h>
#include <math.h>

#define PI 3.14159
#define MAX_YEARS 30

typedef struct {
    double principal;
    double interest_rate;
    double monthly_payment;
    int years;
} Mortgage;

Mortgage calculate_mortgage(Mortgage mortgage) {
    double monthly_interest_rate = mortgage.interest_rate / 1200.0;
    double term = pow(1 + monthly_interest_rate, 12 * mortgage.years);
    double monthly_payment = mortgage.principal * monthly_interest_rate * term / (term - 1);
    mortgage.monthly_payment = monthly_payment;
    return mortgage;
}

void print_mortgage(Mortgage mortgage) {
    printf("Mortgage Summary:\n");
    printf("Principal: $%.2f\n", mortgage.principal);
    printf("Interest Rate: %.2f%%\n", mortgage.interest_rate * 100.0);
    printf("Monthly Payment: $%.2f\n", mortgage.monthly_payment);
    printf("Term: %d years\n", mortgage.years);
    printf("Total Cost: $%.2f\n", mortgage.principal * (1 + (mortgage.interest_rate / 1200.0) * 12 * mortgage.years));
}

int main() {
    Mortgage mortgage = {0};
    printf("Enter principal amount: ");
    scanf("%lf", &mortgage.principal);

    printf("Enter interest rate: ");
    scanf("%lf", &mortgage.interest_rate);

    int years = 0;
    while (years < 1 || years > MAX_YEARS) {
        printf("Enter term in years: ");
        scanf("%d", &years);
    }

    mortgage.years = years;

    mortgage = calculate_mortgage(mortgage);
    print_mortgage(mortgage);

    return 0;
}