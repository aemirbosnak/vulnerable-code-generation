//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATE_LEN 20

typedef struct Date {
  int year;
  int month;
  int day;
} Date;

int main() {
  char input_date[MAX_DATE_LEN];
  Date date;

  printf("Enter a date (YYYY-MM-DD): ");
  scanf("%s", input_date);

  if (parse_date(input_date, &date) == 0) {
    printf("Date: %d-%d-%d\n", date.year, date.month, date.day);
  } else {
    printf("Invalid date format.\n");
  }

  return 0;
}

int parse_date(char *date_str, Date *date) {
  char *year_str, *month_str, *day_str;
  int year, month, day;

  if (strlen(date_str) < 10) {
    return -1;
  }

  year_str = strchr(date_str, '-') - 1;
  month_str = strchr(year_str, '-') - 1;
  day_str = strchr(month_str, '-') - 1;

  year = atoi(year_str);
  month = atoi(month_str) - 1;
  day = atoi(day_str);

  date->year = year;
  date->month = month;
  date->day = day;

  return 0;
}