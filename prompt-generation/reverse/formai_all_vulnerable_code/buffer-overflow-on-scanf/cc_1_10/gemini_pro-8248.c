//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate time travel
void timeTravel(int year) {
  // Check if the year is valid
  if (year < 1900 || year > 2100) {
    printf("Invalid year! Please enter a year between 1900 and 2100.\n");
    return;
  }

  // Calculate the time difference between the current year and the target year
  time_t now = time(NULL);
  struct tm *now_tm = localtime(&now);
  struct tm *target_tm = localtime(&now);
  target_tm->tm_year = year - 1900;

  // Convert the time difference to seconds
  long int time_diff = difftime(mktime(target_tm), mktime(now_tm));

  // Print the time difference
  printf("Time difference: %ld seconds\n", time_diff);

  // Simulate time travel by sleeping for the time difference
  if (time_diff > 0) {
    printf("Traveling to the future...\n");
  } else {
    printf("Traveling to the past...\n");
  }
  sleep(abs(time_diff));

  // Print the current time
  time_t after = time(NULL);
  struct tm *after_tm = localtime(&after);
  printf("Current time: %s\n", asctime(after_tm));
}

// Main function
int main() {
  // Get the target year from the user
  int year;
  printf("Enter the year you want to travel to (between 1900 and 2100): ");
  scanf("%d", &year);

  // Simulate time travel
  timeTravel(year);

  return 0;
}