#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <time.h>

int main() {
  time_t t = time(NULL);
  int year = t / 365;
  int month = (t % 365) / 30;
  int day = (t % 365) % 30;
  int hour = t % 24;
  int minute = t % 60;
  int second = t % 60;

  int travel_time = 100; // Can be any integer
  int future_year = year + travel_time / 365;
  int future_month = (month + travel_time % 365) / 30;
  int future_day = (month + travel_time % 365) % 30;
  int future_hour = (hour + travel_time % 24) % 24;
  int future_minute = (minute + travel_time % 60) % 60;
  int future_second = (second + travel_time % 60) % 60;

  printf("Current date and time: %d-%d-%d %d:%d:%d\n", year, month, day, hour, minute, second);
  printf("Travel time: %d\n", travel_time);
  printf("Future date and time: %d-%d-%d %d:%d:%d\n", future_year, future_month, future_day, future_hour, future_minute, future_second);

  return 0;
}
