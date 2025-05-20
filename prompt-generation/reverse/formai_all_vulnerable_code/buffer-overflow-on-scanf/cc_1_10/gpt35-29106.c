//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int time_travel(int year, int month, int day, int hour, int minute, int second) {
  time_t current_time, travel_time;
  struct tm travel_tm;
  double diff;

  time(&current_time);
  travel_tm.tm_year = year - 1900;
  travel_tm.tm_mon = month - 1;
  travel_tm.tm_mday = day;
  travel_tm.tm_hour = hour;
  travel_tm.tm_min = minute;
  travel_tm.tm_sec = second;

  travel_time = mktime(&travel_tm);
  diff = difftime(current_time, travel_time);

  if (diff < 0) {
    printf("You've traveled to the future! You warped ahead by %.0f seconds!\n", abs(diff));
  } else {
    printf("You've traveled to the past! You warped back by %.0f seconds!\n", diff);
  }

  return 0;
}

int main() {
  int year, month, day, hour, minute, second;

  printf("Enter the year: ");
  scanf("%d", &year);

  printf("Enter the month: ");
  scanf("%d", &month);

  printf("Enter the day: ");
  scanf("%d", &day);

  printf("Enter the hour: ");
  scanf("%d", &hour);

  printf("Enter the minute: ");
  scanf("%d", &minute);

  printf("Enter the second: ");
  scanf("%d", &second);

  time_travel(year, month, day, hour, minute, second);

  return 0;
}