//GEMINI-pro DATASET v1.0 Category: Mortgage Calculator ; Style: configurable
#include <stdio.h>
#include <math.h>

typedef struct {
    double principal;
    double interest_rate;
    int term_years;
    int term_months;
} MortgageConfig;

typedef struct {
    double monthly_payment;
    double total_interest_paid;
    double total_cost;
} MortgageResults;

MortgageResults calculate_mortgage(MortgageConfig config) {
    double monthly_interest_rate = config.interest_rate / 12 / 100;
    int total_months = config.term_years * 12 + config.term_months;

    double monthly_payment = config.principal * monthly_interest_rate * pow(1 + monthly_interest_rate, total_months) / (pow(1 + monthly_interest_rate, total_months) - 1);

    double total_interest_paid = monthly_payment * total_months - config.principal;

    double total_cost = monthly_payment * total_months;

    return (MortgageResults){monthly_payment, total_interest_paid, total_cost};
}

void print_mortgage_results(MortgageConfig config, MortgageResults results) {
    printf("Mortgage Calculator Results\n");
    printf("------------------------------------\n");
    printf("Principal: $%.2f\n", config.principal);
    printf("Interest rate: %.2f%%\n", config.interest_rate);
    printf("Term: %d years, %d months\n", config.term_years, config.term_months);
    printf("------------------------------------\n");
    printf("Monthly payment: $%.2f\n", results.monthly_payment);
    printf("Total interest paid: $%.2f\n", results.total_interest_paid);
    printf("Total cost: $%.2f\n", results.total_cost);
}

int main() {
    MortgageConfig config = {
        .principal = 200000,
        .interest_rate = 3.5,
        .term_years = 30,
        .term_months = 0
    };

    MortgageResults results = calculate_mortgage(config);

    print_mortgage_results(config, results);

    return 0;
}