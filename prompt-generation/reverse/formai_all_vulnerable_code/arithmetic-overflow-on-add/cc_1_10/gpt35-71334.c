//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  time_t current_time;
  char* c_time_string;

  /* Obtain current time as seconds elapsed since the Epoch. */
  current_time = time(NULL);

  /* Convert to local time format. */
  c_time_string = ctime(&current_time);

  /* Print to stdout. */
  printf("Current time is %s", c_time_string);

  /* Enter a year to travel to. */
  int year;
  printf("Enter the year you would like to travel to: ");
  scanf("%d", &year);

  /* Check if the year entered is before the current year. */
  if (year < 1900 || year > 2100)
  {
    printf("Invalid year entered!\n");
    return 0;
  }
  else if (year < 1970)
  {
    printf("Sorry, time travel is not possible before 1970.\n");
    return 0;
  }

  /* Calculate the seconds elapsed since January 1st, 1970 for the year entered. */
  struct tm time_info = {0};
  time_info.tm_year = year - 1900;
  time_info.tm_mday = 1;
  time_t time_since_epoch = mktime(&time_info);

  /* Combine the calculated seconds elapsed with the remaining seconds elapsed today. */
  time_t time_travel = time_since_epoch + (current_time % 86400);

  /* Convert to local time format. */
  c_time_string = ctime(&time_travel);

  /* Print the date and time of the specified year. */
  printf("Date and time in the year %d is: %s", year, c_time_string);

  return 0;
}