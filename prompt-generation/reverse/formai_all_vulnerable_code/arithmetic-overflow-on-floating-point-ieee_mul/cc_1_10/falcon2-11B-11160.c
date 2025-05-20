//Falcon2-11B DATASET v1.0 Category: Mortgage Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a struct to hold mortgage information
struct mortgage {
    double balance;
    double interest_rate;
    double term;
    double monthly_payment;
};

// Function to calculate monthly mortgage payment
double calculate_monthly_payment(double balance, double interest_rate, double term) {
    double payment = (balance * interest_rate) / (1 - (1 / (pow(1 + interest_rate, term))));
    return payment;
}

// Function to display mortgage details
void display_mortgage(struct mortgage* mortgage) {
    printf("Loan Balance: %.2f\n", mortgage->balance);
    printf("Interest Rate: %.2f%%\n", mortgage->interest_rate);
    printf("Term: %d years\n", mortgage->term);
    printf("Monthly Payment: %.2f\n", mortgage->monthly_payment);
}

// Function to simulate mortgage over time
void simulate_mortgage(struct mortgage* mortgage, int number_of_years) {
    for (int i = 0; i < number_of_years; i++) {
        double balance_decrease = calculate_monthly_payment(mortgage->balance, mortgage->interest_rate, mortgage->term) - mortgage->monthly_payment;
        mortgage->balance -= balance_decrease;
    }
    printf("Remaining balance after %d years: %.2f\n", number_of_years, mortgage->balance);
}

int main() {
    // Create a mortgage object
    struct mortgage mortgage = {
       .balance = 200000,
       .interest_rate = 0.05,
       .term = 30,
       .monthly_payment = 0
    };
    
    // Calculate and display mortgage details
    printf("Initial mortgage details:\n");
    display_mortgage(&mortgage);
    
    // Simulate mortgage over 20 years
    printf("\nSimulating mortgage over 20 years...\n");
    simulate_mortgage(&mortgage, 20);
    
    return 0;
}