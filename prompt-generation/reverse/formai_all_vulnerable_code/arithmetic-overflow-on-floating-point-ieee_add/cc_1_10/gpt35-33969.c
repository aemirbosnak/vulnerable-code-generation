//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Donald Knuth
#include <stdio.h>

int main() {
  float principal, rate, monthly_payment, loan_term, total_interest, total_paid;
  int num_payments;

  printf("Welcome to the Mortgage Calculator!\n");

  printf("Enter the principal amount of the loan: ");
  scanf("%f", &principal);

  printf("Enter the annual interest rate of the loan: ");
  scanf("%f", &rate);

  printf("Enter the length of the loan term in years: ");
  scanf("%f", &loan_term);

  printf("Enter the monthly payment amount: ");
  scanf("%f", &monthly_payment);

  rate /= 100.0;
  num_payments = loan_term * 12;
  total_interest = 0.0;

  printf("\n");

  printf("Loan Summary: \n");
  printf("Principal amount: $%.2f\n", principal);
  printf("Annual interest rate: %.2f%%\n", rate * 100);
  printf("Loan term in years: %.2f\n", loan_term);
  printf("Monthly payment amount: $%.2f\n\n", monthly_payment);

  printf("Payment Schedule:\n");
  printf("%-7s %-15s %-15s %-15s\n", "Month", "Payment", "Interest", "Principal");

  for (int i = 1; i <= num_payments; i++) {
    float monthly_interest, principal_paid;

    monthly_interest = principal * rate / 12.0;
    total_interest += monthly_interest;

    if (i == num_payments) {
      monthly_payment = principal + monthly_interest;
    }

    principal_paid = monthly_payment - monthly_interest;
    total_paid += monthly_payment;

    if (principal_paid > principal) {
      principal_paid = principal;
      monthly_payment = principal + monthly_interest;
    }

    printf("%-7d $%-14.2f $%-14.2f $%.2f\n", i, monthly_payment, monthly_interest, principal_paid);

    principal -= principal_paid;

    if (principal <= 0.0) {
      printf("\nPaid in full in %d months.\n", i);
      break;
    }
  }

  printf("\nTotal interest paid: $%.2f\n", total_interest);
  printf("Total amount paid: $%.2f\n", total_paid);

  return 0;
}