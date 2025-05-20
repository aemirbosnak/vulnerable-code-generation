//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: creative
#include <stdio.h>
#include <time.h>

int main() {
  // initialize variables
  int year, month, day, hour, minute, second;
 
  // get current time
  time_t t = time(NULL);
  struct tm *current_time = localtime(&t);

  // prompt user to enter desired time travel date and time
  printf("Welcome to the Time Travel Simulator!\n");
  printf("Enter the year you want to travel to: ");
  scanf("%d", &year);
  printf("Enter the month as a number (1-12): ");
  scanf("%d", &month);
  printf("Enter the day of the month: ");
  scanf("%d", &day);
  printf("Enter the hour (0-23): ");
  scanf("%d", &hour);
  printf("Enter the minute (0-59): ");
  scanf("%d", &minute);
  printf("Enter the second (0-59): ");
  scanf("%d", &second);

  // create a time struct using user input
  struct tm travel_time = {
    .tm_year = year - 1900,
    .tm_mon = month - 1,
    .tm_mday = day,
    .tm_hour = hour,
    .tm_min = minute,
    .tm_sec = second
  };

  // convert user input time to seconds since epoch
  time_t travel_time_seconds = mktime(&travel_time);

  // calculate the time difference between current time and desired time
  int time_diff = (int)difftime(travel_time_seconds, t);

  // check if time travel is possible
  if (time_diff < 0) {
    printf("Time travel to the past is not possible. Please try again with a future date and time.\n");
    return 0;
  }

  // simulate time travel by printing time every second until desired time is reached
  printf("Preparing for time travel...\n");
  for (int i = 1; i <= time_diff; i++) {
    // increment current time by one second
    t = t + 1;
    current_time = localtime(&t);

    printf("Time Travel Simulation: %d/%02d/%02d %02d:%02d:%02d\n", 
          current_time->tm_year + 1900,
          current_time->tm_mon + 1,
          current_time->tm_mday,
          current_time->tm_hour,
          current_time->tm_min,
          current_time->tm_sec);

    // add delay to slow down the simulation
    for (int j = 1; j <= 100000000; j++);
  }

  printf("Welcome to the future!\n");
  printf("The date is %d/%02d/%02d and the time is %02d:%02d:%02d\n", 
        current_time->tm_year + 1900,
        current_time->tm_mon + 1,
        current_time->tm_mday,
        current_time->tm_hour,
        current_time->tm_min,
        current_time->tm_sec);

  return 0;
}