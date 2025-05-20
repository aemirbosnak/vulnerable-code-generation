//FormAI DATASET v1.0 Category: Date and time ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize variables
  time_t current_time;
  struct tm *tm_info;
  char time_string[30];
  int year, month, day, hours, minutes, seconds;

  // Get current time
  current_time = time(NULL);
  tm_info = localtime(&current_time);

  // Format current time to string
  strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", tm_info);

  // Print current time
  printf("%s\n", time_string);

  // Get a specific date and time from user
  printf("Enter year: ");
  scanf("%d", &year);
  printf("Enter month: ");
  scanf("%d", &month);
  printf("Enter day: ");
  scanf("%d", &day);
  printf("Enter hours: ");
  scanf("%d", &hours);
  printf("Enter minutes: ");
  scanf("%d",&minutes);
  printf("Enter seconds: ");
  scanf("%d", &seconds);

  // Create struct tm from user input
  struct tm user_time;
  user_time.tm_year = year - 1900;
  user_time.tm_mon = month - 1;
  user_time.tm_mday = day;
  user_time.tm_hour = hours;
  user_time.tm_min = minutes;
  user_time.tm_sec = seconds;

  // Convert struct tm to time_t
  time_t user_time_t = mktime(&user_time);

  // Format user time to string
  strftime(time_string,sizeof(time_string), "%Y-%m-%d %H:%M:%S", localtime(&user_time_t));

  // Print user time
  printf("User time: %s\n", time_string);

  return 0;
}