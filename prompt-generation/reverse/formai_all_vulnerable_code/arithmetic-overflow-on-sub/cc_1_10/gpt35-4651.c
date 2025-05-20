//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

int main() {
  int year, month, day, hour, minute;

  printf("Enter the current year: ");
  scanf("%d", &year);

  printf("Enter the current month: ");
  scanf("%d", &month);

  printf("Enter the current day: ");
  scanf("%d", &day);

  printf("Enter the current hour: ");
  scanf("%d", &hour);

  printf("Enter the current minute: ");
  scanf("%d", &minute);

  printf("Current time: %02d/%02d/%04d %02d:%02d\n", day, month, year, hour, minute);

  // Configuration for time travel
  int years_to_travel = 0;
  int months_to_travel = 0;
  int days_to_travel = 0;
  int hours_to_travel = 0;
  int minutes_to_travel = 0;

  printf("Enter the number of years to travel: ");
  scanf("%d", &years_to_travel);

  printf("Enter the number of months to travel: ");
  scanf("%d", &months_to_travel);

  printf("Enter the number of days to travel: ");
  scanf("%d", &days_to_travel);

  printf("Enter the number of hours to travel: ");
  scanf("%d", &hours_to_travel);

  printf("Enter the number of minutes to travel: ");
  scanf("%d", &minutes_to_travel);

  // Add time travel values to current time
  minute += minutes_to_travel;
  hour += hours_to_travel;
  day += days_to_travel;
  month += months_to_travel;
  year += years_to_travel;

  // Adjust for excess minutes
  if (minute > 59) {
    hour += minute / 60;
    minute = minute % 60;
  }

  // Adjust for excess hours
  if (hour > 23) {
    day += hour / 24;
    hour = hour % 24;
  }

  // Adjust for excess days
  int days_in_month;
  while (day > (days_in_month = 31 - (month - 1) % 7 % 2 - (month == 2) * (2 - !(year % 4)))) {
    day -= days_in_month;
    month++;

    if (month > 12) {
      year++;
      month = 1;
    }
  }

  printf("Time travel result: %02d/%02d/%04d %02d:%02d\n", day, month, year, hour, minute);

  return 0;
}