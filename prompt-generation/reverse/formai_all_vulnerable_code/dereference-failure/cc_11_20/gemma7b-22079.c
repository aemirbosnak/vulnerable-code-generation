//Gemma-7B DATASET v1.0 Category: Time Travel Simulator ; Style: futuristic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  int year = tm->tm_year + 1900;
  int month = tm->tm_mon + 1;
  int day = tm->tm_mday;
  int hour = tm->tm_hour;
  int minute = tm->tm_min;
  int second = tm->tm_sec;

  printf("The current date and time is:");
  printf("\nYear: %d", year);
  printf("\nMonth: %d", month);
  printf("\nDay: %d", day);
  printf("\nHour: %d", hour);
  printf("\nMinute: %d", minute);
  printf("\nSecond: %d", second);

  // Time Travel Simulator

  printf("\nYou have activated the Time Travel Simulator.");
  printf("\nPlease enter the year you want to travel to:");
  int target_year = atoi(stdin);

  if (target_year < year)
  {
    printf("\nSorry, you cannot travel to the past.");
  }
  else if (target_year > year)
  {
    printf("\nSorry, you cannot travel to the future.");
  }
  else
  {
    int target_month = 0;
    printf("\nPlease enter the month you want to travel to (1-12):");
    target_month = atoi(stdin);

    if (target_month < 1 || target_month > 12)
    {
      printf("\nSorry, invalid month.");
    }
    else
    {
      int target_day = 0;
      printf("\nPlease enter the day you want to travel to (1-31):");
      target_day = atoi(stdin);

      if (target_day < 1 || target_day > 31)
      {
        printf("\nSorry, invalid day.");
      }
      else
      {
        int target_hour = 0;
        printf("\nPlease enter the hour you want to travel to (0-23):");
        target_hour = atoi(stdin);

        if (target_hour < 0 || target_hour > 23)
        {
          printf("\nSorry, invalid hour.");
        }
        else
        {
          int target_minute = 0;
          printf("\nPlease enter the minute you want to travel to (0-59):");
          target_minute = atoi(stdin);

          if (target_minute < 0 || target_minute > 59)
          {
            printf("\nSorry, invalid minute.");
          }
          else
          {
            // Calculate the time difference
            int seconds_traveled = (target_year - year) * 365 * 24 * 60 * 60 +
              (target_month - month) * 365 * 24 * 60 * 60 +
              (target_day - day) * 24 * 60 * 60 +
              (target_hour - hour) * 60 * 60 +
              (target_minute - minute) * 60;

            // Travel back in time
            t = time(NULL) - seconds_traveled;
            tm = localtime(&t);
            year = tm->tm_year + 1900;
            month = tm->tm_mon + 1;
            day = tm->tm_mday;
            hour = tm->tm_hour;
            minute = tm->tm_min;
            second = tm->tm_sec;

            printf("\nYou have traveled back in time to:");
            printf("\nYear: %d", year);
            printf("\nMonth: %d", month);
            printf("\nDay: %d", day);
            printf("\nHour: %d", hour);
            printf("\nMinute: %d", minute);
            printf("\nSecond: %d", second);
          }
        }
      }
    }
  }

  return 0;
}