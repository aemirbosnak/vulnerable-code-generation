//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A futuristic date converter that converts between Earth dates and Martian dates.

// The number of days in each Martian month.
const int MARTIAN_MONTHS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// The number of days in each Earth month.
const int EARTH_MONTHS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// The number of days in a Martian year.
const int MARTIAN_YEAR_DAYS = 687;

// The number of days in an Earth year.
const int EARTH_YEAR_DAYS = 365;

// Converts an Earth date to a Martian date.
void earth_to_mars(int earth_year, int earth_month, int earth_day, int *mars_year, int *mars_month, int *mars_day) {
  // Convert the Earth date to the number of days since the start of the Martian epoch.
  int earth_days_since_epoch = (earth_year - 1) * EARTH_YEAR_DAYS;
  for (int i = 0; i < earth_month - 1; i++) {
    earth_days_since_epoch += EARTH_MONTHS[i];
  }
  earth_days_since_epoch += earth_day;

  // Convert the number of days since the start of the Martian epoch to a Martian date.
  *mars_year = earth_days_since_epoch / MARTIAN_YEAR_DAYS;
  int mars_days_since_year_start = earth_days_since_epoch % MARTIAN_YEAR_DAYS;
  for (*mars_month = 0; mars_days_since_year_start >= MARTIAN_MONTHS[*mars_month]; *mars_month += 1) {
    mars_days_since_year_start -= MARTIAN_MONTHS[*mars_month];
  }
  *mars_day = mars_days_since_year_start + 1;
}

// Converts a Martian date to an Earth date.
void mars_to_earth(int mars_year, int mars_month, int mars_day, int *earth_year, int *earth_month, int *earth_day) {
  // Convert the Martian date to the number of days since the start of the Earth epoch.
  int mars_days_since_epoch = (mars_year - 1) * MARTIAN_YEAR_DAYS;
  for (int i = 0; i < mars_month - 1; i++) {
    mars_days_since_epoch += MARTIAN_MONTHS[i];
  }
  mars_days_since_epoch += mars_day;

  // Convert the number of days since the start of the Earth epoch to an Earth date.
  *earth_year = mars_days_since_epoch / EARTH_YEAR_DAYS;
  int earth_days_since_year_start = mars_days_since_epoch % EARTH_YEAR_DAYS;
  for (*earth_month = 0; earth_days_since_year_start >= EARTH_MONTHS[*earth_month]; *earth_month += 1) {
    earth_days_since_year_start -= EARTH_MONTHS[*earth_month];
  }
  *earth_day = earth_days_since_year_start + 1;
}

int main() {
  // Get the current Earth date.
  time_t now = time(NULL);
  struct tm *tm = localtime(&now);
  int earth_year = tm->tm_year + 1900;
  int earth_month = tm->tm_mon + 1;
  int earth_day = tm->tm_mday;

  // Convert the Earth date to a Martian date.
  int mars_year, mars_month, mars_day;
  earth_to_mars(earth_year, earth_month, earth_day, &mars_year, &mars_month, &mars_day);

  // Print the Martian date.
  printf("The current Martian date is: %d-%d-%d\n", mars_year, mars_month, mars_day);

  // Convert the Martian date back to an Earth date.
  int earth_year2, earth_month2, earth_day2;
  mars_to_earth(mars_year, mars_month, mars_day, &earth_year2, &earth_month2, &earth_day2);

  // Print the Earth date.
  printf("The original Earth date is: %d-%d-%d\n", earth_year2, earth_month2, earth_day2);

  return 0;
}