//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  time_t current_time;
  struct tm *time_info;
  char time_string[40];

  // Get the current time
  current_time = time(NULL);

  // Convert the current time to tm struct and format as string
  time_info = localtime(&current_time);
  strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);

  printf("Welcome to the Time Travel Simulator!\n");
  printf("Current Time: %s\n\n", time_string);

  int choice;

  // Loop until user decides to exit
  while (1) {
    printf("What year would you like to visit? Enter a number between 1900 and 2100 (0 to exit): ");
    scanf("%d", &choice);

    // If user chooses to exit, break out of loop
    if (choice == 0) {
      printf("\nThank you for using the Time Travel Simulator!\n");
      break;
    }

    // If user enters an invalid year, display an error message
    if (choice < 1900 || choice > 2100) {
      printf("\nError: Please enter a valid year between 1900 and 2100.\n\n");
      continue;
    }

    // Calculate the number of years to travel in time and update current_time variable
    int years = choice - (time_info->tm_year + 1900);
    current_time += (years * 31536000);

    // Update time_info structure and format as string
    time_info = localtime(&current_time);
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);

    // Display time travel message
    printf("\nTraveling %d years into the future...\n\n", years);

    // Display the new date and time
    printf("New Time: %s\n\n", time_string);
  }

  return 0;
}