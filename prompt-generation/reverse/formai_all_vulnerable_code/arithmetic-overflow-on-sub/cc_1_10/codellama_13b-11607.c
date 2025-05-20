//Code Llama-13B DATASET v1.0 Category: Mortgage Calculator ; Style: thoughtful
#include <stdio.h>

struct Mortgage {
  int principal;
  int interest_rate;
  int years;
};

void calculate_mortgage(struct Mortgage *mortgage) {
  int monthly_payment = 0;
  int total_payment = 0;
  int interest_paid = 0;
  int principal_paid = 0;

  // Calculate monthly payment
  monthly_payment = (mortgage->principal * mortgage->interest_rate) / 100;

  // Calculate total payment
  total_payment = monthly_payment * 12 * mortgage->years;

  // Calculate interest paid
  interest_paid = total_payment - mortgage->principal;

  // Calculate principal paid
  principal_paid = mortgage->principal - (total_payment - mortgage->principal);

  // Print results
  printf("Mortgage Calculation:\n");
  printf("Monthly payment: $%d\n", monthly_payment);
  printf("Total payment: $%d\n", total_payment);
  printf("Interest paid: $%d\n", interest_paid);
  printf("Principal paid: $%d\n", principal_paid);
}

int main() {
  struct Mortgage mortgage;

  printf("Enter the principal amount: ");
  scanf("%d", &mortgage.principal);

  printf("Enter the interest rate: ");
  scanf("%d", &mortgage.interest_rate);

  printf("Enter the number of years: ");
  scanf("%d", &mortgage.years);

  calculate_mortgage(&mortgage);

  return 0;
}