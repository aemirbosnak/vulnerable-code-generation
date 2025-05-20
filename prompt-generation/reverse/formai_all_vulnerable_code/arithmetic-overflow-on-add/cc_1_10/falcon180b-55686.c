//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

typedef struct {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
} Time;

void time_travel(Time *time, int direction) {
  if (direction == 1) {
    time->year += 100;
    time->month += 6;
    time->day += 15;
    time->hour += 12;
    time->minute += 30;
    time->second += 5;
  } else {
    time->year -= 100;
    time->month -= 6;
    time->day -= 15;
    time->hour -= 12;
    time->minute -= 30;
    time->second -= 5;
  }
}

int main() {
  Time current_time;
  time_t now = time(NULL);
  struct tm *t = localtime(&now);
  current_time.year = t->tm_year + 1900;
  current_time.month = t->tm_mon + 1;
  current_time.day = t->tm_mday;
  current_time.hour = t->tm_hour;
  current_time.minute = t->tm_min;
  current_time.second = t->tm_sec;

  int choice;
  do {
    printf("Current time: %d-%02d-%02d %02d:%02d:%02d\n", current_time.year, current_time.month, current_time.day, current_time.hour, current_time.minute, current_time.second);
    printf("1. Travel forward in time\n");
    printf("2. Travel backward in time\n");
    printf("3. Exit\n");
    scanf("%d", &choice);

    if (choice == 1) {
      time_travel(&current_time, 1);
    } else if (choice == 2) {
      time_travel(&current_time, -1);
    }

  } while (choice!= 3);

  return 0;
}