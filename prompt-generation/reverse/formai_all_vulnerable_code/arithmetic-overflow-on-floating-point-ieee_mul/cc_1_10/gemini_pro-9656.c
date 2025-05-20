//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MONTHS_IN_YEAR 12

typedef struct {
    double income;
    double expenses;
    double savings;
    double investments;
} Budget;

typedef struct {
    double principal;
    double interest_rate;
    int years;
} Loan;

typedef struct {
    double balance;
    double interest_rate;
    int years;
} Investment;

double calculate_savings_rate(Budget budget) {
    return budget.savings / budget.income;
}

double calculate_investment_return(Investment investment) {
    return investment.balance * pow(1 + investment.interest_rate, investment.years) - investment.balance;
}

double calculate_loan_payment(Loan loan) {
    double monthly_interest_rate = loan.interest_rate / MONTHS_IN_YEAR;
    double monthly_payment = loan.principal * monthly_interest_rate / (1 - pow(1 + monthly_interest_rate, -loan.years * MONTHS_IN_YEAR));
    return monthly_payment;
}

int main() {
    // Define a budget
    Budget budget = {
        .income = 5000,
        .expenses = 3000,
        .savings = 500,
        .investments = 1000
    };

    // Calculate the savings rate
    double savings_rate = calculate_savings_rate(budget);

    // Print the savings rate
    printf("Savings rate: %.2f%%\n", savings_rate * 100);

    // Define a loan
    Loan loan = {
        .principal = 10000,
        .interest_rate = 0.05,
        .years = 5
    };

    // Calculate the loan payment
    double loan_payment = calculate_loan_payment(loan);

    // Print the loan payment
    printf("Loan payment: $%.2f\n", loan_payment);

    // Define an investment
    Investment investment = {
        .balance = 10000,
        .interest_rate = 0.07,
        .years = 10
    };

    // Calculate the investment return
    double investment_return = calculate_investment_return(investment);

    // Print the investment return
    printf("Investment return: $%.2f\n", investment_return);

    return 0;
}