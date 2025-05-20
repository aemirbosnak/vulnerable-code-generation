//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: introspective
#include <stdio.h>

int main() {
  float loan_amount, interest_rate, monthly_payment, total_payment, total_interest;
  int years;

  printf("Enter the loan amount: $");
  scanf("%f", &loan_amount);

  printf("Enter the interest rate: ");
  scanf("%f", &interest_rate);

  printf("Enter the number of years: ");
  scanf("%d", &years);

  printf("Enter the monthly payment: $");
  scanf("%f", &monthly_payment);

  printf("\n");

  float monthly_interest_rate = interest_rate / 1200; // 12 months in a year, divide by 100 to get percentage, divide by 12 for monthly rate.
  int months = years * 12; // total number of months

  // calculate total payment and interest
  float balance = loan_amount;
  total_interest = 0;
  for (int i = 0; i < months; i++) {
    float interest = balance * monthly_interest_rate;
    total_interest += interest;
    balance += interest;
    balance -= monthly_payment;
    if (balance < 0) {
      total_payment = i * monthly_payment + balance;
      break;
    }
  }

  // print results
  printf("Loan amount: $%.2f\n", loan_amount);
  printf("Interest rate: %.2f%%\n", interest_rate);
  printf("Years: %d\n", years);
  printf("Monthly payment: $%.2f\n", monthly_payment);
  printf("Total interest: $%.2f\n", total_interest);
  if (total_payment) {
    printf("Total payment: $%.2f\n", total_payment);
  } else {
    printf("Total payment: $%.2f\n", months * monthly_payment);
  }

  return 0;
}