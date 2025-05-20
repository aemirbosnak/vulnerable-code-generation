//MISTRAL-7B DATASET v1.0 Category: Mortgage Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MONTHS_IN_YEAR 12
#define PRINT_WIDTH 60

// Struct for mortgage data
typedef struct mortgage {
    double principal;
    double annual_rate;
    int term_years;
    int term_months;
    double monthly_payment;
    double total_paid;
} mortgage;

// Function prototypes
void print_header();
void print_mortgage_data(mortgage mortgage);
void calculate_mortgage(mortgage *mortgage);

int main(void) {
    // Seed RNG for random loan term
    srand(time(NULL));

    // Create a new mortgage with randomized term
    mortgage my_mortgage;
    my_mortgage.term_years = 1 + (rand() % 30);
    my_mortgage.term_months = (my_mortgage.term_years % MONTHS_IN_YEAR) ? (MONTHS_IN_YEAR - my_mortgage.term_years % MONTHS_IN_YEAR) : 0;
    my_mortgage.principal = 250000.0;
    my_mortgage.annual_rate = 0.05; // 5% interest rate

    // Calculate mortgage details
    calculate_mortgage(&my_mortgage);

    // Print mortgage details
    print_header();
    print_mortgage_data(my_mortgage);

    return EXIT_SUCCESS;
}

void print_header() {
    printf("%.*s\n", PRINT_WIDTH, "==============================================================================================================");
    printf("%.*s\n", PRINT_WIDTH - 2, "| Mortgage Calculator v1.0 |");
    printf("%.*s\n", PRINT_WIDTH, "==============================================================================================================");
    printf("\n");
}

void print_mortgage_data(mortgage mortgage) {
    printf("%.*s\n", PRINT_WIDTH - 2, "| Principal: %12.2f   |", mortgage.principal);
    printf("%.*s\n", PRINT_WIDTH - 2, "| Annual Rate: %9.5f%% |", mortgage.annual_rate * 100);
    printf("%.*s\n", PRINT_WIDTH - 2, "| Term: %d year(s) %d month(s) |", mortgage.term_years, mortgage.term_months);
    printf("%.*s\n", PRINT_WIDTH - 2, "| Monthly Payment: %12.2f |", mortgage.monthly_payment);
    printf("%.*s\n", PRINT_WIDTH, "==============================================================================================================");
}

void calculate_mortgage(mortgage *mortgage) {
    // Calculate monthly payment using mortgage formula
    mortgage->monthly_payment = mortgage->principal * pow(1 + mortgage->annual_rate / MONTHS_IN_YEAR, MONTHS_IN_YEAR) / (pow(1 + mortgage->annual_rate / MONTHS_IN_YEAR, MONTHS_IN_YEAR) - 1);

    // Calculate total paid over the term
    mortgage->total_paid = mortgage->monthly_payment * (MONTHS_IN_YEAR * mortgage->term_years);
}