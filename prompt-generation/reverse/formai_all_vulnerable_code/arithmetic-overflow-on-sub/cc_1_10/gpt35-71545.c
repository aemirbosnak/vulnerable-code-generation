//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  time_t current_time;
  char* c_time_string;
  int year, month, day, hour, minute, second;

  /* Get current time as seconds since the Epoch. */
  current_time = time(NULL);

  /* Convert to local time format and print to stdout. */
  c_time_string = ctime(&current_time);
  printf("Current time is: %s", c_time_string);

  /* Prompt user for time to travel to. */
  printf("Enter year: ");
  scanf("%d", &year);
  printf("Enter month (1-12): ");
  scanf("%d", &month);
  printf("Enter day (1-31): ");
  scanf("%d", &day);
  printf("Enter hour (0-23): ");
  scanf("%d", &hour);
  printf("Enter minute (0-59): ");
  scanf("%d", &minute);
  printf("Enter second (0-59): ");
  scanf("%d", &second);

  /* Construct time struct from user input. */
  struct tm travel_time = {0};
  travel_time.tm_year = year - 1900;
  travel_time.tm_mon = month - 1;
  travel_time.tm_mday = day;
  travel_time.tm_hour = hour;
  travel_time.tm_min = minute;
  travel_time.tm_sec = second;

  /* Convert travel time to seconds since the Epoch. */
  time_t travel_time_seconds = mktime(&travel_time);

  /* Compare current time to travel time and determine direction of travel. */
  int time_diff = travel_time_seconds - current_time;
  char* direction = "";
  if (time_diff < 0)
  {
    direction = "backwards in time!";
    time_diff = -time_diff;
  }
  else if (time_diff > 0)
  {
    direction = "forwards in time!";
  }
  else
  {
    /* Travel time is same as current time. */
    printf("Why are you even bothering to go anywhere?\n");
    return 0;
  }

  /* Print travel direction to stdout. */
  printf("Travelling %s\n", direction);

  /* Sleep for the amount of time between current time and travel time. */
  printf("Waiting...\n");
  sleep(time_diff);

  /* Print arrival time to stdout. */
  current_time = time(NULL);
  c_time_string = ctime(&current_time);
  printf("Arriving at: %s", c_time_string);

  return 0;
}