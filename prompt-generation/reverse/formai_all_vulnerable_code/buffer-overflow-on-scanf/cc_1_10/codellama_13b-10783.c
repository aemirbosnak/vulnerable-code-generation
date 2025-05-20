//Code Llama-13B DATASET v1.0 Category: Mortgage Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Define constants
#define MIN_PRINCIPAL 1000
#define MIN_TERM 1
#define MAX_TERM 30
#define INTEREST_RATE 0.05

// Define struct for mortgage calculation
struct Mortgage {
    double principal;
    int term;
    double interestRate;
};

// Define function to calculate monthly payment
double calculateMonthlyPayment(struct Mortgage mortgage) {
    double monthlyPayment = 0.0;
    double totalInterest = 0.0;

    // Calculate total interest
    for (int i = 1; i <= mortgage.term; i++) {
        totalInterest += mortgage.principal * mortgage.interestRate / 12;
    }

    // Calculate monthly payment
    monthlyPayment = (mortgage.principal + totalInterest) / mortgage.term;

    return monthlyPayment;
}

// Define function to calculate total payment
double calculateTotalPayment(struct Mortgage mortgage) {
    double totalPayment = 0.0;

    // Calculate total payment
    for (int i = 1; i <= mortgage.term; i++) {
        totalPayment += calculateMonthlyPayment(mortgage);
    }

    return totalPayment;
}

int main() {
    // Initialize mortgage struct
    struct Mortgage mortgage = {0};

    // Get input from user
    printf("Enter principal amount: ");
    scanf("%lf", &mortgage.principal);

    printf("Enter term (in years): ");
    scanf("%d", &mortgage.term);

    // Validate input
    if (mortgage.principal < MIN_PRINCIPAL) {
        printf("Principal amount must be at least %d.\n", MIN_PRINCIPAL);
        return 1;
    }
    if (mortgage.term < MIN_TERM || mortgage.term > MAX_TERM) {
        printf("Term must be between %d and %d.\n", MIN_TERM, MAX_TERM);
        return 1;
    }

    // Calculate monthly payment and total payment
    double monthlyPayment = calculateMonthlyPayment(mortgage);
    double totalPayment = calculateTotalPayment(mortgage);

    // Print results
    printf("Monthly payment: $%.2f\n", monthlyPayment);
    printf("Total payment: $%.2f\n", totalPayment);

    return 0;
}