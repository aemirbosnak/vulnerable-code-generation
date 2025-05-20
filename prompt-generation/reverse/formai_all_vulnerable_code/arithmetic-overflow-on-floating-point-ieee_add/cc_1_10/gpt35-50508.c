//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: recursive
#include <stdio.h>

double calculateMortgage(double principal, double interestRate, double term, double monthlyPayment);
double calculateRemainingBalance(double principal, double interestRate, double term, double monthlyPayment, int month);

int main() {
    double principal, interestRate, term, monthlyPayment;
    printf("Enter the Principal Value: ");
    scanf("%lf", &principal);

    printf("Enter the Interest Rate: ");
    scanf("%lf", &interestRate);

    printf("Enter the Term: ");
    scanf("%lf", &term);

    printf("Enter Monthly Payment: ");
    scanf("%lf", &monthlyPayment);

    double mortgage = calculateMortgage(principal, interestRate, term, monthlyPayment);

    printf("Total Mortgage: %.2lf\n", mortgage);

    for (int i = 0; i <= term; i++) {
        printf("Remaining Balance after %d months: %.2lf\n", i, calculateRemainingBalance(principal, interestRate, term, monthlyPayment, i));
    }

    return 0;
}

double calculateMortgage(double principal, double interestRate, double term, double monthlyPayment) {
    if (term == 0) {
        return principal;
    }
    double remainingBalance = calculateRemainingBalance(principal, interestRate, term - 1, monthlyPayment, 0);
    double interest = remainingBalance * (interestRate / 12);
    double newPrincipal = remainingBalance + interest - monthlyPayment;
    return calculateMortgage(newPrincipal, interestRate, term - 1, monthlyPayment) + monthlyPayment;
}

double calculateRemainingBalance(double principal, double interestRate, double term, double monthlyPayment, int month) {
    if (term == -1) {
        return principal;
    }
    if (month == 0) {
        return principal;
    }
    double remainingBalance = calculateRemainingBalance(principal, interestRate, term, monthlyPayment, month - 1);
    double interest = remainingBalance * (interestRate / 12);
    double newPrincipal = remainingBalance + interest - monthlyPayment;
    return newPrincipal;
}