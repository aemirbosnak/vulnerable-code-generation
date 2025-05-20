#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <time.h>

int main() {
  int year, month, day, hour, minute, second, duration, result_year, result_month, result_day, result_hour, result_minute, result_second;
  time_t t, result_t;

  scanf("Enter the current year: ", &year);
  scanf("Enter the current month (1-12): ", &month);
  scanf("Enter the current day (1-31): ", &day);
  scanf("Enter the current hour (0-23): ", &hour);
  scanf("Enter the current minute (0-59): ", &minute);
  scanf("Enter the current second (0-59): ", &second);
  scanf("Enter the duration (positive or negative): ", &duration);

  t = time(NULL);
  result_t = t + duration * 3600;

  result_year = result_t / 31536000;
  result_month = (result_t % 31536000) / 2592000;
  result_day = (result_t % 2592000) / 86400;
  result_hour = (result_t % 86400) / 3600;
  result_minute = (result_t % 3600) / 60;
  result_second = result_t % 60;

  printf("The date and time after time travel is:\n");
  printf("Year: %d\n", result_year);
  printf("Month: %d\n", result_month);
  printf("Day: %d\n", result_day);
  printf("Hour: %d\n", result_hour);
  printf("Minute: %d\n", result_minute);
  printf("Second: %d\n", result_second);

  return 0;
}
