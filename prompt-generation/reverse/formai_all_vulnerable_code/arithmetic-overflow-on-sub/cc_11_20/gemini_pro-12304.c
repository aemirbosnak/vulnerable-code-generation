//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEAR 2100
#define MIN_YEAR 1900

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the current year
  int currentYear = time(NULL);

  // Get the year the user wants to travel to
  int targetYear;
  printf("Enter the year you want to travel to (between %d and %d): ", MIN_YEAR, MAX_YEAR);
  scanf("%d", &targetYear);

  // Check if the year is valid
  if (targetYear < MIN_YEAR || targetYear > MAX_YEAR) {
    printf("Invalid year. Please enter a year between %d and %d.\n", MIN_YEAR, MAX_YEAR);
    return 1;
  }

  // Calculate the time difference in years
  int timeDifference = targetYear - currentYear;

  // Print the time difference
  printf("You will travel %d years into the future.\n", timeDifference);

  // Simulate the time travel
  for (int i = 0; i < timeDifference; i++) {
    // Generate a random event
    int event = rand() % 100;

    // Print the event
    switch (event) {
      case 0:
        printf("You encounter a group of scavengers.\n");
        break;
      case 1:
        printf("You find a cache of food and supplies.\n");
        break;
      case 2:
        printf("You are attacked by a group of raiders.\n");
        break;
      case 3:
        printf("You find a safe haven.\n");
        break;
      case 4:
        printf("You die of starvation.\n");
        break;
      case 5:
        printf("You die of thirst.\n");
        break;
      case 6:
        printf("You die of disease.\n");
        break;
      case 7:
        printf("You die in a nuclear explosion.\n");
        break;
      case 8:
        printf("You die in a natural disaster.\n");
        break;
      case 9:
        printf("You die in a war.\n");
        break;
      default:
        printf("You survive the year.\n");
        break;
    }
  }

  // Print the final message
  if (timeDifference > 0) {
    printf("You have arrived in the year %d.\n", targetYear);
  } else {
    printf("You have returned to the present.\n");
  }

  return 0;
}