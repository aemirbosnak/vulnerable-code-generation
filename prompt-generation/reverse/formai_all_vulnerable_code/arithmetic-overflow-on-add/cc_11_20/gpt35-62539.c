//FormAI DATASET v1.0 Category: Date and time ; Style: brave
#include <stdio.h>
#include <time.h>

int main() {
  time_t current_time;
  struct tm *local_time;
  int month, year, days_in_month, i, j, current_day = 0;

  time(&current_time); // Get current time
  local_time = localtime(&current_time); // Convert to local time
  month = local_time->tm_mon + 1; // Get current month
  year = local_time->tm_year + 1900; // Get current year

  // Calculate days in the current month
  if (month == 2) {
    days_in_month = (year % 4 == 0) ? 29 : 28; // Leap year logic
  } else if (month == 4 || month == 6 || month == 9 || month == 11) {
    days_in_month = 30;
  } else {
    days_in_month = 31;
  }

  // Print calendar header
  printf("=====================\n");
  printf("    %d/%d Calendar\n", month, year);
  printf("=====================\n");
  printf(" Sun Mon Tue Wed Thu Fri Sat\n");

  // Calculate the day of the week for the first day of the month
  current_time = time(NULL);
  local_time = localtime(&current_time);
  local_time->tm_year = year - 1900;
  local_time->tm_mon = month - 1;
  local_time->tm_mday = 1;
  mktime(local_time);
  current_day = local_time->tm_wday;

  // Print blank cells for days before the first day
  for (i = 0; i < current_day; i++) {
    printf("    ");
  }

  // Print days of the month
  for (i = 1; i <= days_in_month; i++) {
    printf("%4d", i);

    // Get current time for this cell
    time(&current_time);
    local_time = localtime(&current_time);
    local_time->tm_year = year - 1900;
    local_time->tm_mon = month - 1;
    local_time->tm_mday = i;
    mktime(local_time);

    // Print time in the cell
    printf(" ");
    printf("%02d:%02d:%02d", local_time->tm_hour, local_time->tm_min, local_time->tm_sec);

    // Move to next line if it's a Saturday
    if ((i + current_day) % 7 == 0) {
      printf("\n");
    }
  }

  // Print blank cells for days after the last day
  for (j = i + current_day - 1; j % 7 != 0; j++) {
    printf("    ");
  }

  printf("\n=====================\n");

  return 0;
}