//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: all-encompassing
#include <stdio.h>

// Function to calculate simple interest
float simpleInterest(float principal, float rate, float time) {
    float interest = (principal * rate * time) / 100;
    return interest;
}

// Function to calculate compound interest
float compoundInterest(float principal, float rate, float time, int frequency) {
    float interest = principal;
    float tempRate = rate / frequency;
    float n = frequency * time;
    for (int i = 0; i < n; i++) {
        interest = interest + (interest * tempRate);
    }
    return interest - principal;
}

// Function to calculate tax savings
float taxSavings(float taxRate, float maxLimit, float investmentAmount) {
    float taxSaved = 0;
    if (investmentAmount > maxLimit) {
        taxSaved = maxLimit * taxRate;
    } else {
        taxSaved = investmentAmount * taxRate;
    }
    return taxSaved;
}

int main() {
    printf("Welcome to Personal Finance Planner\n");

    // Taking user inputs
    printf("Enter your principal amount: ");
    float principal;
    scanf("%f", &principal);

    printf("Enter the interest rate per annum: ");
    float rate;
    scanf("%f", &rate);

    printf("Enter the time period in years: ");
    float time;
    scanf("%f", &time);

    printf("Enter the frequency of compounding (1, 2, 4, ..): ");
    int frequency;
    scanf("%d", &frequency);

    printf("Enter your tax rate: ");
    float taxRate;
    scanf("%f", &taxRate);

    printf("Enter the maximum investment limit for tax savings: ");
    float maxLimit;
    scanf("%f", &maxLimit);

    printf("Enter your investment amount: ");
    float investmentAmount;
    scanf("%f", &investmentAmount);

    // Calculating interests
    float simpleInt = simpleInterest(principal, rate, time);
    printf("\nYour Simple Interest for Rs. %0.2f is Rs. %0.2f\n", principal, simpleInt);

    float compoundInt = compoundInterest(principal, rate, time, frequency);
    printf("Your Compound Interest for Rs. %0.2f is Rs. %0.2f\n", principal, compoundInt);

    // Calculating tax savings
    float taxSaved = taxSavings(taxRate, maxLimit, investmentAmount);
    printf("Your Tax Savings on investment of Rs. %0.2f is Rs. %0.2f\n", investmentAmount, taxSaved);

    printf("\nThank you for using Personal Finance Planner.\n");
    return 0;
}