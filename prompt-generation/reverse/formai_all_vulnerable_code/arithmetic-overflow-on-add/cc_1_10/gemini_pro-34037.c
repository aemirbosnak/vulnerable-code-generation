//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
} Date;

Date get_current_date() {
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);

  Date date;
  date.year = tm->tm_year + 1900;
  date.month = tm->tm_mon + 1;
  date.day = tm->tm_mday;
  date.hour = tm->tm_hour;
  date.minute = tm->tm_min;
  date.second = tm->tm_sec;

  return date;
}

void print_date(Date date) {
  printf("%d-%02d-%02d %02d:%02d:%02d\n",
         date.year, date.month, date.day,
         date.hour, date.minute, date.second);
}

int main() {
  Date current_date = get_current_date();

  printf("Current date: ");
  print_date(current_date);

  int years_to_travel;
  printf("How many years do you want to travel? ");
  scanf("%d", &years_to_travel);

  Date future_date = current_date;
  future_date.year += years_to_travel;

  printf("Future date: ");
  print_date(future_date);

  return 0;
}