//Code Llama-13B DATASET v1.0 Category: Mortgage Calculator ; Style: relaxed
// Mortgage Calculator in C
#include <stdio.h>

// Define constants
const double MORTGAGE_RATE = 0.06; // 6% interest rate
const double MORTGAGE_TERM = 15; // 15 years term

// Define struct for mortgage data
typedef struct {
    double principal;
    double interest;
    double term;
} MortgageData;

// Function to calculate monthly mortgage payment
double calculateMonthlyPayment(MortgageData data) {
    double interest = data.principal * (MORTGAGE_RATE / 12);
    double principal = data.principal - interest;
    double payment = principal + interest;
    return payment;
}

// Function to calculate total mortgage cost
double calculateTotalCost(MortgageData data) {
    double totalCost = data.principal * MORTGAGE_RATE;
    return totalCost;
}

// Main function
int main() {
    // Ask user for mortgage data
    printf("Enter mortgage principal: ");
    double principal;
    scanf("%lf", &principal);

    printf("Enter interest rate: ");
    double interest;
    scanf("%lf", &interest);

    printf("Enter mortgage term (in years): ");
    double term;
    scanf("%lf", &term);

    // Calculate monthly payment and total cost
    MortgageData data = { principal, interest, term };
    double monthlyPayment = calculateMonthlyPayment(data);
    double totalCost = calculateTotalCost(data);

    // Print results
    printf("Monthly payment: %.2lf\n", monthlyPayment);
    printf("Total cost: %.2lf\n", totalCost);

    return 0;
}