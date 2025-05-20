//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  time_t currentTime;
  struct tm *localTime;
  int yearsAgo;
  int month, day, year;

  /* Get the current time */
  currentTime = time(NULL);
  localTime = localtime(&currentTime);

  /* Print out the current date and time */
  printf("Current date and time: %s", asctime(localTime));

  /* Set a date to travel to */
  printf("Enter a date to travel to (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &month, &day, &year);

  /* Calculate number of years ago to travel */
  yearsAgo = localTime->tm_year - (year - 1900);

  /* Set the time struct to the travel date */
  localTime->tm_year = year - 1900;
  localTime->tm_mon = month - 1;
  localTime->tm_mday = day;

  /* Adjust for any years in between */
  for (int i = 0; i < yearsAgo; i++) {
    localTime->tm_year--;
    if (localTime->tm_year % 4 == 0 && localTime->tm_year % 100 != 0 || localTime->tm_year % 400 == 0) {
      localTime->tm_yday += 366;
    }
    else {
      localTime->tm_yday += 365;
    }
  }

  /* Set the calendar time to the travel date and print it out */
  time_t travelTime = mktime(localTime);
  printf("Traveling to %s", asctime(localtime(localTime)));

  /* Wait for 5 seconds */
  printf("Traveling through time...");
  sleep(5);

  /* Print out the new date and time */
  localTime = localtime(&travelTime);
  printf("Welcome to %s", asctime(localTime));

  return 0;
}