//Falcon2-11B DATASET v1.0 Category: Mortgage Calculator ; Style: genius
#include <stdio.h>
#include <math.h>

double mortgage_payment(double loan_amount, double interest_rate, double loan_term) {
    double monthly_rate = interest_rate / 12;
    double loan_balance = loan_amount;
    double monthly_payment = loan_balance * monthly_rate;
    
    for (int i = 1; i < loan_term; i++) {
        loan_balance -= monthly_payment;
        monthly_payment += loan_balance * monthly_rate;
    }
    
    return monthly_payment;
}

double mortgage_interest(double loan_amount, double interest_rate, double loan_term) {
    double monthly_rate = interest_rate / 12;
    double loan_balance = loan_amount;
    double total_interest = loan_amount * (1 + monthly_rate) * loan_term;
    
    for (int i = 1; i < loan_term; i++) {
        loan_balance -= monthly_rate;
        total_interest += loan_balance * monthly_rate;
    }
    
    return total_interest;
}

double mortgage_total(double loan_amount, double interest_rate, double loan_term) {
    double monthly_rate = interest_rate / 12;
    double loan_balance = loan_amount;
    double total_interest = loan_amount * (1 + monthly_rate) * loan_term;
    
    for (int i = 1; i < loan_term; i++) {
        loan_balance -= monthly_rate;
        total_interest += loan_balance * monthly_rate;
    }
    
    return loan_amount + total_interest;
}

int main() {
    double loan_amount;
    double interest_rate;
    double loan_term;
    
    printf("Enter the loan amount: ");
    scanf("%lf", &loan_amount);
    
    printf("Enter the interest rate: ");
    scanf("%lf", &interest_rate);
    
    printf("Enter the loan term: ");
    scanf("%lf", &loan_term);
    
    double monthly_payment = mortgage_payment(loan_amount, interest_rate, loan_term);
    double total_interest = mortgage_interest(loan_amount, interest_rate, loan_term);
    double total_amount = mortgage_total(loan_amount, interest_rate, loan_term);
    
    printf("Monthly payment: $%.2lf\n", monthly_payment);
    printf("Total interest paid: $%.2lf\n", total_interest);
    printf("Total amount paid: $%.2lf\n", total_amount);
    
    return 0;
}