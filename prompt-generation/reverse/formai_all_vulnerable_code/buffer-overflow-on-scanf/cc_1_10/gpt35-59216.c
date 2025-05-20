//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  time_t currentTime;
  struct tm *timeInfo;
  int year, month, day;

  // Get current time
  time(&currentTime);
  timeInfo = localtime(&currentTime);

  // Print current time in readable format
  printf("Current time: %s", asctime(timeInfo));

  // Prompt user for desired date
  printf("Enter a year to travel to (YYYY): ");
  scanf("%d", &year);
  printf("Enter a month to travel to (1-12): ");
  scanf("%d", &month);
  printf("Enter a day to travel to (1-31): ");
  scanf("%d", &day);

  // Set desired date and time
  struct tm desiredTime = {0};
  desiredTime.tm_year = year - 1900;
  desiredTime.tm_mon = month - 1;
  desiredTime.tm_mday = day;

  // Calculate time difference in seconds
  time_t desiredTimeInSeconds = mktime(&desiredTime);
  double timeDiff = difftime(desiredTimeInSeconds, currentTime);

  // Print time travel results
  if (timeDiff > 0) {
    // Future travel
    printf("Jumping to the future...\n");
    printf("Time travel successful! You have arrived in %s", asctime(&desiredTime));
  } else if (timeDiff < 0) {
    // Past travel
    printf("Jumping to the past...\n");
    printf("Time travel successful! You have arrived in %s", asctime(&desiredTime));
  } else {
    // No travel
    printf("You are already in the desired time. No time travel necessary.\n");
  }

  return 0;
}