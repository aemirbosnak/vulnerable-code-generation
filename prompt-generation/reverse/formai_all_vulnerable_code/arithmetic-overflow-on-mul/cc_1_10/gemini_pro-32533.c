//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for the number of days in each month
const int DAYS_IN_MONTHS[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Function to check if a year is a leap year
int is_leap_year(int year) {
  return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

// Function to convert a date from the Gregorian calendar to the Julian calendar
void gregorian_to_julian(int year, int month, int day) {
  // Check if the year is a leap year
  int is_leap = is_leap_year(year);

  // Calculate the Julian day number
  int julian_day = day + DAYS_IN_MONTHS[month - 1];
  if (month > 2) {
    julian_day += is_leap;
  }
  julian_day += 365 * (year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;

  // Print the Julian day number
  printf("The Julian day number is: %d\n", julian_day);
}

// Function to convert a date from the Julian calendar to the Gregorian calendar
void julian_to_gregorian(int julian_day, int year, int month, int day) {
  // Calculate the Gregorian year
  year = (julian_day - 1721119) / 36525;
  year -= 1;

  // Calculate the Gregorian month
  int a = julian_day + 373248 * year;
  int b = a % 36525;
  a /= 36525;
  month = b / 3060;
  b %= 3060;

  // Calculate the Gregorian day
  day = b / 30;
  b %= 30;

  // Print the Gregorian date
  printf("The Gregorian date is: %d-%02d-%02d\n", year, month, day);
}

// Main function
int main() {
  // Get the current date and time
  time_t now;
  struct tm *t;
  time(&now);
  t = localtime(&now);

  // Convert the date to the Julian calendar
  int year = t->tm_year + 1900;
  int month = t->tm_mon + 1;
  int day = t->tm_mday;
  gregorian_to_julian(year, month, day);

  // Convert the date back to the Gregorian calendar
  int julian_day = 2459218;
  julian_to_gregorian(julian_day, year, month, day);

  return 0;
}