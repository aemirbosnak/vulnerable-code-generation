//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
  int days, months, years;
  printf("Enter your age in days, months, and years:\n");
  scanf("%d %d %d", &days, &months, &years);

  // Convert everything to days
  int total_days = days + months * 30 + years * 365;

  // Now, let's have some fun!
  printf("You have lived for %d days, which is:\n", total_days);

  // How many centuries?
  int centuries = total_days / 36525;
  if (centuries > 0) {
    printf("  %d centuries\n", centuries);
  }

  // How many decades?
  int decades = (total_days % 36525) / 3652;
  if (decades > 0) {
    printf("  %d decades\n", decades);
  }

  // How many years?
  years = (total_days % 3652) / 365;
  if (years > 0) {
    printf("  %d years\n", years);
  }

  // How many months?
  months = (total_days % 365) / 30;
  if (months > 0) {
    printf("  %d months\n", months);
  }

  // How many days?
  days = total_days % 30;
  if (days > 0) {
    printf("  %d days\n", days);
  }

  // And just for fun, let's calculate your age in "cat years"
  int cat_years = total_days / 365 / 7;
  printf("You are %d years old in cat years!\n", cat_years);

  return 0;
}