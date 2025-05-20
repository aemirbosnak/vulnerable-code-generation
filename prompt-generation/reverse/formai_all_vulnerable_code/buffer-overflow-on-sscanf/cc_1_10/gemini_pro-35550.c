//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
} Timestamp;

void print_timestamp(Timestamp *timestamp) {
  printf("%04d-%02d-%02d %02d:%02d:%02d\n",
         timestamp->year, timestamp->month, timestamp->day,
         timestamp->hour, timestamp->minute, timestamp->second);
}

int main() {
  Timestamp now;

  // Get the current time.
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);

  now.year = tm->tm_year + 1900;
  now.month = tm->tm_mon + 1;
  now.day = tm->tm_mday;
  now.hour = tm->tm_hour;
  now.minute = tm->tm_min;
  now.second = tm->tm_sec;

  // Print the current time.
  printf("Current time: ");
  print_timestamp(&now);

  // Get the user's input.
  char input[100];
  printf("Enter a date and time in the format YYYY-MM-DD HH:MM:SS: ");
  scanf("%s", input);

  // Parse the user's input.
  int year, month, day, hour, minute, second;
  sscanf(input, "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);

  // Create a timestamp for the user's input.
  Timestamp user_timestamp;
  user_timestamp.year = year;
  user_timestamp.month = month;
  user_timestamp.day = day;
  user_timestamp.hour = hour;
  user_timestamp.minute = minute;
  user_timestamp.second = second;

  // Calculate the difference between the user's input and the current time.
  time_t diff = difftime(mktime(&user_timestamp), mktime(&now));

  // Print the difference.
  printf("Difference: %ld seconds\n", diff);

  if (diff > 0) {
    // The user's input is in the future.
    printf("Time travel to the future is not yet supported.\n");
  } else if (diff < 0) {
    // The user's input is in the past.
    printf("Time travel to the past is not yet supported.\n");
  } else {
    // The user's input is the same as the current time.
    printf("You are already at the time you specified.\n");
  }

  return 0;
}