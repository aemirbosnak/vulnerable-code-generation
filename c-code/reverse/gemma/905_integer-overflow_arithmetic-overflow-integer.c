#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <time.h>

int main() {
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);

  // Get user input for current date and time
  int year, month, day, hour, minute;
  printf("Enter the current year: ");
  scanf("%d", &year);
  printf("Enter the current month (1-12): ");
  scanf("%d", &month);
  printf("Enter the current day (1-31): ");
  scanf("%d", &day);
  printf("Enter the current hour (0-23): ");
  scanf("%d", &hour);
  printf("Enter the current minute (0-59): ");
  scanf("%d", &minute);

  // Get user input for time travel duration
  int duration;
  printf("Enter the time travel duration (in minutes): ");
  scanf("%d", &duration);

  // Get user input for timezone
  int timezone;
  printf("Enter the timezone offset (in hours): ");
  scanf("%d", &timezone);

  // Calculate the target time
  time_t target_t = t + duration * 60 + timezone * 3600;
  struct tm *target_tm = localtime(&target_t);

  // Print the target time
  printf("The target time is: ");
  printf("%d/%d/%d %d:%d", target_tm->tm_mon + 1, target_tm->tm_mday, target_tm->tm_year, target_tm->tm_hour, target_tm->tm_min);

  return 0;
}
