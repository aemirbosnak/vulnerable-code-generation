//FormAI DATASET v1.0 Category: Date and time ; Style: bold
#include <stdio.h>
#include <time.h>

int main(void) {
  // Get current time as a Unix timestamp
  time_t current_time = time(NULL);

  // Convert Unix timestamp to struct tm
  struct tm *local_time = localtime(&current_time);

  // Format the local time as a string
  char time_string[50];
  strftime(time_string, sizeof(time_string), "%A, %B %d %Y %I:%M:%S %p", local_time);

  // Print the formatted time string in bold
  printf("\033[1mThe current date and time is:\n\033[0m");
  printf("\033[1m%s\n\033[0m", time_string);

  // Get the time one hour from now
  time_t future_time = current_time + 3600;
  struct tm *new_local_time = localtime(&future_time);
  char future_time_string[50];
  strftime(future_time_string, sizeof(future_time_string), "%I:%M %p", new_local_time);

  // Print the time one hour from now in bold
  printf("\033[1mOne hour from now it will be:\n\033[0m");
  printf("\033[1m%s\n\033[0m", future_time_string);

  // Get the last day of the current month
  int year = local_time->tm_year + 1900;
  int month = local_time->tm_mon + 1;
  int last_day;
  if (month == 2) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
      last_day = 29;
    } else {
      last_day = 28;
    }
  } else if (month == 4 || month == 6 || month == 9 || month == 11) {
    last_day = 30;
  } else {
    last_day = 31;
  }

  // Print the last day of the current month in bold
  printf("\033[1mThe last day of the current month is:\n\033[0m");
  printf("\033[1m%d\n\033[0m", last_day);

  return 0;
}