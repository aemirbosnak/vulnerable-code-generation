//MISTRAL-7B DATASET v1.0 Category: Mortgage Calculator ; Style: scientific
#include <stdio.h>
#include <math.h>

// Constants
#define MONTHS_PER_YEAR 12
#define PI M_PI

// Structures
typedef struct {
    double principal;
    double annual_rate;
    int term;
    int payments_per_year;
} Mortgage;

// Function prototypes
double factorial(int n);
double mortgage_payment(Mortgage mortgage);

// Function definitions
double mortgage_payment(Mortgage mortgage) {
    double monthly_rate = mortgage.annual_rate / (100.0 * MONTHS_PER_YEAR);
    double number_of_payments = mortgage.term * mortgage.payments_per_year;
    double loan = mortgage.principal;

    double numerator = pow(1 + monthly_rate, number_of_payments);
    double denominator = pow(1 + monthly_rate, number_of_payments) - pow(1 + monthly_rate, number_of_payments - 1);

    double monthly_payment = loan * monthly_rate * denominator / factorial(number_of_payments);

    return monthly_payment;
}

double factorial(int n) {
    if (n <= 0) {
        return 1;
    }

    return n * factorial(n - 1);
}

// Main function
int main() {
    Mortgage mortgage = {
        .principal = 250000.0,
        .annual_rate = 4.5,
        .term = 30,
        .payments_per_year = MONTHS_PER_YEAR
    };

    double monthly_payment = mortgage_payment(mortgage);

    printf("Monthly mortgage payment: $%.2f\n", monthly_payment);

    return 0;
}