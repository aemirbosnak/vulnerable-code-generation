//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVEL 100
#define MIN_TIME_TRAVEL -100

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Initialize the time machine
  int time = 0;

  // Run the time travel simulator
  while (1) {
    // Get the user's input
    printf("Enter a year to travel to (or 0 to quit): ");
    scanf("%d", &time);

    // Check if the user wants to quit
    if (time == 0) {
      break;
    }

    // Check if the user's input is valid
    if (time < MIN_TIME_TRAVEL || time > MAX_TIME_TRAVEL) {
      printf("Invalid year. Please enter a year between %d and %d.\n", MIN_TIME_TRAVEL, MAX_TIME_TRAVEL);
      continue;
    }

    // Travel to the user's specified year
    printf("Traveling to %d...\n", time);
    sleep(1);

    // Generate a random event for the user to experience
    int event = rand() % 3;

    // Print the event to the console
    switch (event) {
      case 0:
        printf("You meet a famous historical figure.\n");
        break;
      case 1:
        printf("You witness a major historical event.\n");
        break;
      case 2:
        printf("You experience a technological marvel from the future.\n");
        break;
    }

    // Return to the present
    printf("Returning to the present...\n");
    sleep(1);
  }

  // Print a goodbye message
  printf("Goodbye!\n");

  return 0;
}