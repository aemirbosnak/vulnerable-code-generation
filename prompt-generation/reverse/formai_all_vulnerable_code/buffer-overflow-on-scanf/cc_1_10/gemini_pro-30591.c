//GEMINI-pro DATASET v1.0 Category: Mortgage Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure to hold mortgage data
typedef struct {
    double principal;  // Loan amount
    double interest;   // Annual interest rate
    int years;       // Loan term in years
    double payment;   // Monthly payment
    double balance;   // Current loan balance
} mortgage_t;

// Function to calculate the monthly payment
double calculate_payment(mortgage_t *m) {
    double r = m->interest / 1200;  // Monthly interest rate
    double n = m->years * 12;       // Number of monthly payments
    return (r * m->principal) / (1 - pow(1 + r, -n));
}

// Function to simulate a single month of mortgage payments
void make_payment(mortgage_t *m) {
    // Calculate the interest paid this month
    double interest = m->balance * m->interest / 1200;
    
    // Calculate the principal paid this month
    double principal = m->payment - interest;
    
    // Update the loan balance
    m->balance -= principal;
}

// Function to run the mortgage simulation
void *run_simulation(void *arg) {
    mortgage_t *m = (mortgage_t *)arg;  // Cast the argument to a mortgage struct
    
    // Calculate the monthly payment
    m->payment = calculate_payment(m);
    
    // Simulate the mortgage payments
    for (int i = 0; i < m->years * 12; i++) {
        make_payment(m);
    }
    
    return NULL;  // Return NULL to indicate success
}

int main() {
    // Create a mortgage struct
    mortgage_t m;
    
    // Get the mortgage data from the user
    printf("Enter the loan amount: ");
    scanf("%lf", &m.principal);
    
    printf("Enter the annual interest rate: ");
    scanf("%lf", &m.interest);
    
    printf("Enter the loan term in years: ");
    scanf("%d", &m.years);
    
    // Create a thread to run the simulation
    pthread_t thread;
    pthread_create(&thread, NULL, run_simulation, &m);
    
    // Wait for the thread to finish
    pthread_join(thread, NULL);
    
    // Print the results of the simulation
    printf("The monthly payment is: $%.2f\n", m.payment);
    printf("The total interest paid is: $%.2f\n", m.interest * m.years * m.principal);
    printf("The total amount paid is: $%.2f\n", m.payment * m.years * 12);
    
    return 0;
}