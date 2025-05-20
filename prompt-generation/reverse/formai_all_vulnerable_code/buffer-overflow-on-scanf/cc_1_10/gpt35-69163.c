//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  printf("Welcome to the C Time Travel Simulator!\n\n");

  time_t now = time(NULL);

  printf("Your current date and time is: %s", ctime(&now));

  int year, month, day, hour, minute, second;

  printf("Enter the year you want to travel to: ");
  scanf("%d", &year);

  printf("Enter the month you want to travel to [1-12]: ");
  scanf("%d", &month);

  printf("Enter the day you want to travel to: ");
  scanf("%d", &day);

  printf("Enter the hour you want to travel to [0-23]: ");
  scanf("%d", &hour);

  printf("Enter the minute you want to travel to [0-59]: ");
  scanf("%d", &minute);

  printf("Enter the second you want to travel to [0-59]: ");
  scanf("%d", &second);

  struct tm travel_time = {
    .tm_year = year - 1900,
    .tm_mon = month - 1,
    .tm_mday = day,
    .tm_hour = hour,
    .tm_min = minute,
    .tm_sec = second
  };

  time_t travel_seconds = mktime(&travel_time);

  printf("\nYou are now time travelling to: %s", ctime(&travel_seconds));

  printf("3, 2, 1, GO!\n\n");

  for (int i = 10; i >= 0; i--) {
    printf("%d...\n", i);
    sleep(1);
  }

  printf("\nWelcome to the year %d!\n", year);

  return 0;
}