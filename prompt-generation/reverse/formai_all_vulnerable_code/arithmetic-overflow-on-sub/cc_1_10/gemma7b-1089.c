//Gemma-7B DATASET v1.0 Category: Time Travel Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int year, month, day, hour, minute, second;
  time_t t;
  t = time(NULL);
  struct tm *tm = localtime(&t);

  year = tm->tm_year + 1900;
  month = tm->tm_mon + 1;
  day = tm->tm_mday;
  hour = tm->tm_hour;
  minute = tm->tm_min;
  second = tm->tm_sec;

  printf("The current date and time is:");
  printf("\nYear: %d", year);
  printf("\nMonth: %d", month);
  printf("\nDay: %d", day);
  printf("\nHour: %d", hour);
  printf("\nMinute: %d", minute);
  printf("\nSecond: %d", second);

  printf("\nPlease enter the year, month, day, hour, and minute you want to travel to:");
  scanf("%d %d %d %d %d", &year, &month, &day, &hour, &minute);

  t = mktime(&tm);
  tm->tm_year = year - 1900;
  tm->tm_mon = month - 1;
  tm->tm_mday = day;
  tm->tm_hour = hour;
  tm->tm_min = minute;

  t = mktime(tm);
  time_t t_future = time(NULL) + t;

  printf("\nYou will travel to:");
  printf("\nYear: %d", tm->tm_year + 1900);
  printf("\nMonth: %d", tm->tm_mon + 1);
  printf("\nDay: %d", tm->tm_mday);
  printf("\nHour: %d", tm->tm_hour);
  printf("\nMinute: %d", tm->tm_min);
  printf("\nSecond: %d", tm->tm_sec);

  printf("\nPlease wait for the time machine to activate...");

  sleep(5);

  printf("\nTime travel complete! You have arrived at your chosen time.");

  return 0;
}