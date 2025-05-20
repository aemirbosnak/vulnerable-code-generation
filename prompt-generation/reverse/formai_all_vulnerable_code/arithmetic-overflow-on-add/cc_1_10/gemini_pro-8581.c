//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A struct to represent a time traveler
typedef struct {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
} time_traveler;

// A function to initialize a time traveler to the current time
void init_time_traveler(time_traveler *tt) {
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  tt->year = tm->tm_year + 1900;
  tt->month = tm->tm_mon + 1;
  tt->day = tm->tm_mday;
  tt->hour = tm->tm_hour;
  tt->minute = tm->tm_min;
  tt->second = tm->tm_sec;
}

// A function to print a time traveler's current time
void print_time_traveler(time_traveler *tt) {
  printf("%d-%02d-%02d %02d:%02d:%02d\n", tt->year, tt->month, tt->day, tt->hour, tt->minute, tt->second);
}

// A function to travel a time traveler through time
void time_travel(time_traveler *tt, int years, int months, int days, int hours, int minutes, int seconds) {
  tt->year += years;
  tt->month += months;
  tt->day += days;
  tt->hour += hours;
  tt->minute += minutes;
  tt->second += seconds;

  // Handle any overflow or underflow
  if (tt->month > 12) {
    tt->month -= 12;
    tt->year++;
  } else if (tt->month < 1) {
    tt->month += 12;
    tt->year--;
  }
  if (tt->day > 31) {
    tt->day -= 31;
    tt->month++;
  } else if (tt->day < 1) {
    tt->day += 31;
    tt->month--;
  }
  if (tt->hour > 23) {
    tt->hour -= 24;
    tt->day++;
  } else if (tt->hour < 0) {
    tt->hour += 24;
    tt->day--;
  }
  if (tt->minute > 59) {
    tt->minute -= 60;
    tt->hour++;
  } else if (tt->minute < 0) {
    tt->minute += 60;
    tt->hour--;
  }
  if (tt->second > 59) {
    tt->second -= 60;
    tt->minute++;
  } else if (tt->second < 0) {
    tt->second += 60;
    tt->minute--;
  }
}

int main() {
  // Initialize a time traveler to the current time
  time_traveler tt;
  init_time_traveler(&tt);

  // Print the time traveler's current time
  printf("Current time: ");
  print_time_traveler(&tt);

  // Travel the time traveler through time
  time_travel(&tt, 1, 0, 0, 0, 0, 0);

  // Print the time traveler's new time
  printf("New time: ");
  print_time_traveler(&tt);

  return 0;
}