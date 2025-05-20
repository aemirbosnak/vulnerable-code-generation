//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVEL 1000000

typedef struct {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
} Time;

Time generate_random_time() {
  Time time;
  time.year = rand() % 2023 + 1;
  time.month = rand() % 12 + 1;
  time.day = rand() % 31 + 1;
  time.hour = rand() % 24;
  time.minute = rand() % 60;
  time.second = rand() % 60;
  return time;
}

Time time_travel(Time time, int years, int months, int days, int hours, int minutes, int seconds) {
  time.year += years;
  time.month += months;
  time.day += days;
  time.hour += hours;
  time.minute += minutes;
  time.second += seconds;

  if (time.year < 1) {
    time.year = 1;
  }
  if (time.month < 1) {
    time.month = 1;
  }
  if (time.day < 1) {
    time.day = 1;
  }
  if (time.hour < 0) {
    time.hour = 0;
  }
  if (time.minute < 0) {
    time.minute = 0;
  }
  if (time.second < 0) {
    time.second = 0;
  }

  if (time.month > 12) {
    time.month = 12;
  }
  if (time.day > 31) {
    time.day = 31;
  }
  if (time.hour > 23) {
    time.hour = 23;
  }
  if (time.minute > 59) {
    time.minute = 59;
  }
  if (time.second > 59) {
    time.second = 59;
  }

  return time;
}

int main() {
  srand(time(NULL));

  Time time = generate_random_time();

  printf("Current time: %04d-%02d-%02d %02d:%02d:%02d\n", time.year, time.month, time.day, time.hour, time.minute, time.second);

  int years, months, days, hours, minutes, seconds;

  printf("Enter the number of years to travel: ");
  scanf("%d", &years);

  printf("Enter the number of months to travel: ");
  scanf("%d", &months);

  printf("Enter the number of days to travel: ");
  scanf("%d", &days);

  printf("Enter the number of hours to travel: ");
  scanf("%d", &hours);

  printf("Enter the number of minutes to travel: ");
  scanf("%d", &minutes);

  printf("Enter the number of seconds to travel: ");
  scanf("%d", &seconds);

  if (years > MAX_TIME_TRAVEL || months > MAX_TIME_TRAVEL || days > MAX_TIME_TRAVEL || hours > MAX_TIME_TRAVEL || minutes > MAX_TIME_TRAVEL || seconds > MAX_TIME_TRAVEL) {
    printf("Error: Time travel distance is too large.\n");
    return 1;
  }

  time = time_travel(time, years, months, days, hours, minutes, seconds);

  printf("New time: %04d-%02d-%02d %02d:%02d:%02d\n", time.year, time.month, time.day, time.hour, time.minute, time.second);

  return 0;
}