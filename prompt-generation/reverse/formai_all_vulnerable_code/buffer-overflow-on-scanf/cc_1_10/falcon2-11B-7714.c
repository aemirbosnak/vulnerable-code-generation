//Falcon2-11B DATASET v1.0 Category: Mortgage Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Define a structure to hold the mortgage details
typedef struct {
    double loanAmount;
    double interestRate;
    int numPayments;
    int paymentPeriod;
} Mortgage;

// Function to calculate the total interest paid over the life of the mortgage
double calculateInterest(Mortgage mortgage) {
    double totalInterest = 0.0;
    for (int i = 0; i < mortgage.numPayments; i++) {
        totalInterest += mortgage.loanAmount * (mortgage.interestRate / 100.0) * (i + 1);
    }
    return totalInterest;
}

int main() {
    // Prompt the user for mortgage details
    printf("Enter the loan amount:\n");
    double loanAmount;
    scanf("%lf", &loanAmount);

    printf("Enter the interest rate:\n");
    double interestRate;
    scanf("%lf", &interestRate);

    printf("Enter the number of payments:\n");
    int numPayments;
    scanf("%d", &numPayments);

    printf("Enter the payment period (monthly, quarterly, semi-annually, or annually):\n");
    char paymentPeriod;
    scanf(" %c", &paymentPeriod);

    // Create a mortgage object and calculate the total interest paid
    Mortgage mortgage = {loanAmount, interestRate, numPayments, paymentPeriod};
    double totalInterest = calculateInterest(mortgage);

    // Display the results
    printf("Loan Amount: %.2lf\n", loanAmount);
    printf("Interest Rate: %.2lf%%\n", interestRate * 100.0);
    printf("Number of Payments: %d\n", numPayments);
    printf("Payment Period: %s\n", paymentPeriod =='m'? "Monthly" :
        paymentPeriod == 'q'? "Quarterly" :
        paymentPeriod =='s'? "Semi-Annually" : "Annually");
    printf("Total Interest Paid: %.2lf\n", totalInterest);

    return 0;
}