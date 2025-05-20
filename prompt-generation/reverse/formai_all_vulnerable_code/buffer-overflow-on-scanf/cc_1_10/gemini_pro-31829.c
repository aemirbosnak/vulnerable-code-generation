//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int days, months, years;
  char choice;

  // Get the user's choice
  printf("What do you want to convert?\n");
  printf("1. Days to months and years\n");
  printf("2. Months to days and years\n");
  printf("3. Years to days and months\n");
  printf("Enter your choice (1/2/3): ");
  scanf(" %c", &choice);

  // Convert the days to months and years
  if (choice == '1') {
    printf("Enter the number of days: ");
    scanf(" %d", &days);

    months = days / 30;
    years = days / 365;

    printf("%d days is equal to %d months and %d years\n", days, months, years);
  }
  // Convert the months to days and years
  else if (choice == '2') {
    printf("Enter the number of months: ");
    scanf(" %d", &months);

    days = months * 30;
    years = months / 12;

    printf("%d months is equal to %d days and %d years\n", months, days, years);
  }
  // Convert the years to days and months
  else if (choice == '3') {
    printf("Enter the number of years: ");
    scanf(" %d", &years);

    days = years * 365;
    months = years * 12;

    printf("%d years is equal to %d days and %d months\n", years, days, months);
  }
  // Invalid choice
  else {
    printf("Invalid choice\n");
  }

  return 0;
}