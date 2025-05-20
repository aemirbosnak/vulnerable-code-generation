//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {
  time_t present_time = time(NULL); // Get present time
  struct tm *present = localtime(&present_time); // Convert present time to tm struct
  printf("Welcome to Time Travel Simulator!\n");
  printf("The current year is: %d\n", present->tm_year + 1900);

  int target_year;
  printf("Enter a year to travel to: ");
  scanf("%d", &target_year);

  // Validate user input for target year
  if (target_year < 0 || target_year > present->tm_year + 1900) {
    printf("Invalid input or time travel not possible.\n");
    return 0;
  }

  // Calculate time difference
  int time_diff = target_year - (present->tm_year + 1900);

  // Simulate time travel
  bool is_traveling = true;
  while (is_traveling) {
    printf("\nYear %d\n", present->tm_year + 1900);

    // Simulate events at different time periods
    switch (present->tm_year + 1900) {
      case 1900:
        printf("The Wright brothers make their first flight.\n");
        break;
      case 1969:
        printf("Neil Armstrong lands on the Moon.\n");
        break;
      case 2021:
        printf("COVID-19 pandemic still ongoing.\n");
        break;
      default:
        printf("Nothing significant happened this year.\n");
        break;
    }

    // Check if time travel is completed
    if (present->tm_year + 1900 == target_year) {
      is_traveling = false;
    } else {
      // Update tm struct to reflect time difference
      present->tm_year += time_diff;
      present_time = mktime(present);
      present = localtime(&present_time);
    }
  }

  printf("\nYou have reached your destination!\n");
  printf("The year is now: %d\n", present->tm_year + 1900);

  return 0;
}