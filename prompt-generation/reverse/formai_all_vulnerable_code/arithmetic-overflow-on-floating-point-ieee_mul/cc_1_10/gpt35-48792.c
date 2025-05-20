//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: retro
#include <stdio.h>

// Function to calculate monthly mortgage payment
double calculateMortgagePayment(double principle, double interestRate, int termInYears)
{
    double monthlyInterestRate = interestRate / 1200;
    int numberOfPayments = termInYears * 12;
    double monthlyPayment = (principle * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -numberOfPayments));
    return monthlyPayment;
}

// Function to calculate compounded interest
double calculateCompoundedInterest(double principle, double interestRate, int timeInYears)
{
    double finalAmount = principle * pow(1 + (interestRate / 100), timeInYears);
    return finalAmount;
}

int main()
{
    double principle = 100000.00;
    double interestRate = 3.50;
    int termInYears = 30;

    double monthlyMortgagePayment = calculateMortgagePayment(principle, interestRate, termInYears);
    double totalInterestPaid = (monthlyMortgagePayment * (termInYears * 12)) - principle;
    double totalPaid = (monthlyMortgagePayment * (termInYears * 12));

    printf("MORTGAGE\n");
    printf("--------------------------------------------------\n");
    printf("Principle:\t\t\t%.2lf\n", principle);
    printf("Interest rate:\t\t\t%.2lf%%\n", interestRate);
    printf("Term:\t\t\t\t%d years\n", termInYears);
    printf("--------------------------------------------------\n");
    printf("Monthly Payment:\t\t%.2lf\n", monthlyMortgagePayment);
    printf("Total Interest Paid:\t\t%.2lf\n", totalInterestPaid);
    printf("Total Paid:\t\t\t%.2lf\n", totalPaid);
    printf("\n");

    double initialInvestment = 5000.00;
    double annualRateOfReturn = 7.00;
    int yearsInvested = 20;

    double finalAmountInvested = calculateCompoundedInterest(initialInvestment, annualRateOfReturn, yearsInvested);

    printf("INVESTMENT\n");
    printf("--------------------------------------------------\n");
    printf("Initial investment:\t\t%.2lf\n", initialInvestment);
    printf("Annual rate of return:\t\t%.2lf%%\n", annualRateOfReturn);
    printf("Years invested:\t\t\t%d years\n", yearsInvested);
    printf("--------------------------------------------------\n");
    printf("Final amount:\t\t\t%.2lf\n", finalAmountInvested);
    printf("\n");

    double paycheckAmount = 1500.00;
    double savingsPercentage = 0.20;
    double monthlySavings = paycheckAmount * savingsPercentage;

    printf("SAVINGS\n");
    printf("--------------------------------------------------\n");
    printf("Paycheck amount:\t\t%.2lf\n", paycheckAmount);
    printf("Savings percentage:\t\t%.2lf%%\n", savingsPercentage * 100);
    printf("Monthly savings:\t\t%.2lf\n", monthlySavings);
    printf("\n");

    return 0;
}