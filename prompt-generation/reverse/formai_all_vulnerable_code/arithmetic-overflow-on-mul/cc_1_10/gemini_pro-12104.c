//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Convert a date from MM/DD/YYYY to YYYYMMDD
int date_convert(char *date) {
  int month, day, year;
  sscanf(date, "%d/%d/%d", &month, &day, &year);
  return year * 10000 + month * 100 + day;
}

// Get the current date in YYYYMMDD format
int get_current_date() {
  time_t now = time(NULL);
  struct tm *tm = localtime(&now);
  return tm->tm_year + 1900 * 10000 + (tm->tm_mon + 1) * 100 + tm->tm_mday;
}

// Print a calendar for a given month
void print_calendar(int month, int year) {
  // Get the first day of the month
  int first_day = date_convert("01/01/0001");
  int first_day_of_month = (first_day + (month - 1) * 30 + year * 365) % 7;

  // Print the days of the week
  printf("Su Mo Tu We Th Fr Sa\n");

  // Print the days of the month
  int day = 1;
  for (int i = 0; i < first_day_of_month; i++) {
    printf("   ");
  }
  while (day <= 31) {
    printf("%2d ", day);
    if ((day + first_day_of_month) % 7 == 0) {
      printf("\n");
    }
    day++;
  }
  printf("\n");
}

int main() {
  // Get the current date
  int current_date = get_current_date();

  // Print the current date
  printf("Today's date is: %d\n", current_date);

  // Convert the current date to MM/DD/YYYY format
  char current_date_str[11];
  sprintf(current_date_str, "%02d/%02d/%04d", current_date / 10000, (current_date % 10000) / 100, current_date % 100);

  // Print the current date in MM/DD/YYYY format
  printf("Today's date in MM/DD/YYYY format is: %s\n", current_date_str);

  // Get a month and year from the user
  int month, year;
  printf("Enter a month (1-12): ");
  scanf("%d", &month);
  printf("Enter a year (YYYY): ");
  scanf("%d", &year);

  // Print the calendar for the given month and year
  print_calendar(month, year);

  return 0;
}