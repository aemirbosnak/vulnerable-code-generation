//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DAYS 365

int main() {
  char str_date[20];
  int day, month, year;
  time_t t;
  struct tm *tm;

  printf("Enter a date in the format MM/DD/YYYY:");
  scanf("%s", str_date);

  day = atoi(str_date);
  month = atoi(str_date + 3);
  year = atoi(str_date + 6);

  t = mktime(&tm);
  tm->tm_year = year;
  tm->tm_mon = month - 1;
  tm->tm_mday = day;

  time_t t_now = time(NULL);
  struct tm *tm_now = localtime(&t_now);

  int years_diff = tm_now->tm_year - tm->tm_year;
  int months_diff = tm_now->tm_mon - tm->tm_mon;
  int days_diff = tm_now->tm_mday - tm->tm_mday;

  printf("The date you entered is:");
  printf("\n");
  printf("Year: %d", tm->tm_year);
  printf("\n");
  printf("Month: %d", tm->tm_mon + 1);
  printf("\n");
  printf("Day: %d", tm->tm_mday);
  printf("\n");

  printf("The number of years that have passed since the date you entered is:");
  printf("\n");
  printf("%d years", years_diff);
  printf("\n");

  printf("The number of months that have passed since the date you entered is:");
  printf("\n");
  printf("%d months", months_diff);
  printf("\n");

  printf("The number of days that have passed since the date you entered is:");
  printf("\n");
  printf("%d days", days_diff);
  printf("\n");

  return 0;
}