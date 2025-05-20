//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: systematic
#include <stdio.h>
#include <time.h>

int main(void) {
  time_t current_time;
  struct tm *time_info;
  char destination[50];
  int year;

  // Get current time
  time(&current_time);
  time_info = localtime(&current_time);

  // Ask for destination and year
  printf("Welcome to Time Travel Simulator 2021!\n");
  printf("Please enter your destination: ");
  scanf("%s", destination);
  printf("Please enter the year you want to travel to: ");
  scanf("%d", &year);

  printf("\nPreparing for time travel to %s in the year %d...\n\n", destination, year);

  // Calculate difference between current year and target year
  int year_diff = year - (time_info->tm_year + 1900);

  // Print travel details
  printf("Current date and time: %s", asctime(time_info));
  printf("Traveling to: %s\n", destination);
  printf("Year of travel: %d\n", year);
  printf("Years from present: %d\n\n", year_diff);

  // Set target time
  time_info->tm_year += year_diff;
  time_info->tm_isdst = -1;
  current_time = mktime(time_info);

  // Sleep for 3 seconds to simulate travel time
  printf("Initiating time travel sequence...\n");
  printf("3...\n");
  sleep(1);
  printf("2...\n");
  sleep(1);
  printf("1...\n");
  sleep(1);
  printf("Time travel successful!\n\n");

  // Get and print new time
  time_info = localtime(&current_time);
  printf("New date and time: %s\n", asctime(time_info));

  return 0;
}