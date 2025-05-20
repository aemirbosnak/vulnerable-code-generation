//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define DAYS_PER_YEAR 365
#define DAYS_PER_MONTH 30
#define MONTHS_PER_YEAR 12

typedef struct {
  int year;
  int month;
  int day;
} Date;

Date* new_date(int year, int month, int day) {
  Date* date = malloc(sizeof(Date));
  date->year = year;
  date->month = month;
  date->day = day;
  return date;
}

void print_date(Date* date) {
  printf("%d-%02d-%02d\n", date->year, date->month, date->day);
}

int days_between(Date* date1, Date* date2) {
  int days1 = date1->year * DAYS_PER_YEAR + date1->month * DAYS_PER_MONTH + date1->day;
  int days2 = date2->year * DAYS_PER_YEAR + date2->month * DAYS_PER_MONTH + date2->day;
  return abs(days1 - days2);
}

Date* add_days(Date* date, int days) {
  Date* new_date = malloc(sizeof(Date));
  new_date->year = date->year + days / DAYS_PER_YEAR;
  new_date->month = date->month + (days % DAYS_PER_YEAR) / DAYS_PER_MONTH;
  new_date->day = date->day + (days % DAYS_PER_YEAR) % DAYS_PER_MONTH;
  return new_date;
}

Date* subtract_days(Date* date, int days) {
  return add_days(date, -days);
}

int main() {
  // Get the current date and time.
  time_t now = time(NULL);
  struct tm* tm = localtime(&now);

  // Create a date object for the current date.
  Date* today = new_date(tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday);

  // Print the current date.
  printf("Today's date: ");
  print_date(today);

  // Get the number of days between today and a given date.
  printf("Enter a date (YYYY-MM-DD): ");
  char date_str[11];
  scanf("%s", date_str);

  int year, month, day;
  sscanf(date_str, "%d-%d-%d", &year, &month, &day);

  Date* given_date = new_date(year, month, day);

  int days_diff = days_between(today, given_date);

  // Print the number of days between the two dates.
  printf("Days between today and %s: %d\n", date_str, days_diff);

  // Add or subtract days from the given date.
  printf("Enter a number of days to add or subtract: ");
  int days;
  scanf("%d", &days);

  Date* new_date = NULL;
  if (days >= 0) {
    new_date = add_days(given_date, days);
  } else {
    new_date = subtract_days(given_date, -days);
  }

  // Print the new date.
  printf("New date: ");
  print_date(new_date);

  // Free the allocated memory.
  free(today);
  free(given_date);
  free(new_date);

  return 0;
}