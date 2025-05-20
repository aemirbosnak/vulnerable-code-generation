//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DAYS_IN_YEAR 365
#define NUM_DAYS_IN_MONTH 31

static int day_of_year(int month, int day) {
  int days_in_month[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

  return days_in_month[month - 1] + day;
}

static int convert_datetime_to_seconds(int year, int month, int day, int hour, int minute, int second) {
  time_t t = mktime((time_t *)NULL);
  struct tm *tm = localtime(&t);

  tm->tm_year = year - 1900;
  tm->tm_mon = month - 1;
  tm->tm_mday = day;
  tm->tm_hour = hour;
  tm->tm_min = minute;
  tm->tm_sec = second;

  return timegm(tm);
}

int main() {
  int year, month, day, hour, minute, second;

  printf("Enter the year: ");
  scanf("%d", &year);

  printf("Enter the month (1-12): ");
  scanf("%d", &month);

  printf("Enter the day (1-31): ");
  scanf("%d", &day);

  printf("Enter the hour (0-23): ");
  scanf("%d", &hour);

  printf("Enter the minute (0-59): ");
  scanf("%d", &minute);

  printf("Enter the second (0-59): ");
  scanf("%d", &second);

  int seconds = convert_datetime_to_seconds(year, month, day, hour, minute, second);

  printf("The number of seconds since January 1, 1900 at the specified datetime is: %d", seconds);

  return 0;
}