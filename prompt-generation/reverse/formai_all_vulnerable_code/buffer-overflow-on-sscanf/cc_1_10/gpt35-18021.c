//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  time_t present = time(NULL);
  struct tm *local_time;
  char time_string[100];

  printf("Welcome to the Time Travel Simulator program!\n\n");

  // Prompt user to enter date and time to travel to
  printf("Enter the date and time you want to go to in the following format: YYYY-MM-DD HH:MM:SS\n");
  scanf("%s", time_string);

  // Convert user input to time_t format
  local_time = localtime(&present);
  sscanf(time_string, "%d-%d-%d %d:%d:%d",
         &local_time->tm_year, &local_time->tm_mon, &local_time->tm_mday,
         &local_time->tm_hour, &local_time->tm_min, &local_time->tm_sec);
  local_time->tm_year -= 1900;
  local_time->tm_mon--;

  // Calculate time difference
  time_t future = mktime(local_time);
  double seconds = difftime(future, present);

  // Time travel animation
  printf("\nPreparing for time travel...\n\n");
  printf("3..\n");
  printf("2..\n");
  printf("1..\n");
  printf("Buckle up!\n\n");
  printf("*** ZAP! ***\n\n");

  // Simulate time travel experience
  printf("You have been transported to %s", asctime(localtime(&future)));
  printf("You have time traveled %ld seconds in the past/future!\n\n", (long)seconds);

  // Check if time travel caused any paradoxes
  if (seconds < 0) {
    printf("Uh oh! You may have caused a paradox...\n");
    printf("Better hurry back to the present before it's too late!\n");
  } else {
    printf("Phew! Good thing you didn't cause any paradoxes...\n");
    printf("Enjoy your time travel experience!\n");
  }

  return 0;
}