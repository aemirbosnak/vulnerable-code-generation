//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: shocked
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Global variables
int year = 2023;
int month = 1;
int day = 1;

// Function to travel through time
void timeTravel(int years, int months, int days) {
  // Check if the time travel is valid
  if (years < 1 || months < 1 || days < 1) {
    printf("Invalid time travel! Please enter positive values.\n");
    return;
  }

  // Add the time to the current date
  year += years;
  month += months;
  day += days;

  // Handle the case when the month is greater than 12
  if (month > 12) {
    month -= 12;
    year++;
  }

  // Handle the case when the day is greater than the number of days in the month
  int daysInMonth = 31;
  if (month == 2) {
    daysInMonth = 28;
  } else if (month == 4 || month == 6 || month == 9 || month == 11) {
    daysInMonth = 30;
  }
  if (day > daysInMonth) {
    day -= daysInMonth;
    month++;
  }

  // Print the new date
  printf("You have traveled to: %d-%d-%d\n", year, month, day);

  // Check if the time travel is in the past or future
  int timeDifference = year - 2023;
  if (timeDifference < 0) {
    printf("You have traveled %d years into the past.\n", abs(timeDifference));
  } else if (timeDifference > 0) {
    printf("You have traveled %d years into the future.\n", timeDifference);
  } else {
    printf("You have not traveled through time.\n");
  }
}

// Main function
int main() {
  // Get the time travel input from the user
  int years, months, days;
  printf("Enter the number of years, months, and days you want to travel through time (separated by spaces): ");
  scanf("%d %d %d", &years, &months, &days);

  // Validate the user input
  if (years < 0 || months < 0 || days < 0) {
    printf("Invalid time travel! Please enter non-negative values.\n");
    return 1;
  }

  // Perform the time travel
  timeTravel(years, months, days);

  return 0;
}