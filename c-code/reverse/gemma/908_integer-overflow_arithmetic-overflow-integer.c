#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <time.h>

int main() {
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);

  int year = tm->tm_year + 1;
  int month = tm->tm_mon + 1;
  int day = tm->tm_mday + 1;
  int hour = tm->tm_hour;
  int minute = tm->tm_min;

  int duration = 10; // Time travel duration in hours

  // Calculate future date and time
  int future_year = year + duration / 365;
  int future_month = month + (duration % 365) / 30;
  int future_day = day + (duration % 365) % 30;
  int future_hour = hour + duration % 24;
  int future_minute = minute;

  // Handle potential integer overflows
  if (future_year > 2100) {
    printf("Date overflow!\n");
  } else if (future_month > 12) {
    printf("Month overflow!\n");
  } else if (future_day > 31) {
    printf("Day overflow!\n");
  } else if (future_hour > 23) {
    printf("Hour overflow!\n");
  } else if (future_minute > 59) {
    printf("Minute overflow!\n");
  } else {
    // Print future date and time
    printf("Future date: %d/%d/%d\n", future_year, future_month, future_day);
    printf("Future time: %d:%d\n", future_hour, future_minute);
  }

  return 0;
}
