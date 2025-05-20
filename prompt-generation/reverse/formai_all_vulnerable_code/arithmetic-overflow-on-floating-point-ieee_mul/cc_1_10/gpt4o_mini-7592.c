//GPT-4o-mini DATASET v1.0 Category: Mortgage Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
    double principal;
    double annual_interest;
    int years;
    double monthly_payment;
} MortgageInfo;

void *calculate_monthly_payment(void *arg) {
    MortgageInfo *mortgage = (MortgageInfo *) arg;
    double monthly_interest = (mortgage->annual_interest / 100) / 12;
    int total_payments = mortgage->years * 12;

    mortgage->monthly_payment = (mortgage->principal * monthly_interest) /
                                (1 - pow(1 + monthly_interest, -total_payments));
    return NULL;
}

void print_amortization_schedule(MortgageInfo *mortgage) {
    double balance = mortgage->principal;
    double monthly_interest = (mortgage->annual_interest / 100) / 12;
    double total_payment = mortgage->monthly_payment;
    double interest_payment, principal_payment;

    printf("\nAmortization Schedule:\n");
    printf("Payment#\tPrincipal\tInterest\tBalance\n");
    
    for (int i = 1; i <= mortgage->years * 12; i++) {
        interest_payment = balance * monthly_interest;
        principal_payment = total_payment - interest_payment;
        balance -= principal_payment;

        printf("%d\t\t%.2f\t\t%.2f\t\t%.2f\n", i, principal_payment, interest_payment, balance);
        usleep(500000);  // Simulate a delay for showing the schedule
    }
}

int main() {
    MortgageInfo mortgage;
    pthread_t payment_thread;

    printf("Welcome to the Mortgage Calculator!\n");
    printf("Enter the principal amount: ");
    scanf("%lf", &mortgage.principal);
    printf("Enter the annual interest rate (%%): ");
    scanf("%lf", &mortgage.annual_interest);
    printf("Enter the term (in years): ");
    scanf("%d", &mortgage.years);

    // Start the thread to calculate the monthly payment
    pthread_create(&payment_thread, NULL, calculate_monthly_payment, &mortgage);

    // While the payment is being calculated, print the amortization schedule
    print_amortization_schedule(&mortgage);

    // Wait for the payment calculation to complete
    pthread_join(payment_thread, NULL);

    // Display the monthly payment
    printf("\nMonthly Payment: %.2f\n", mortgage.monthly_payment);
    
    return 0;
}