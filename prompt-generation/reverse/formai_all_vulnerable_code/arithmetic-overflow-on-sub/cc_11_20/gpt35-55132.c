//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for time travel
#define PRESENT 2021
#define MIN_YEAR 1
#define MAX_YEAR 3000
#define NUM_YEARS 2000000

int main() {
  int year, option;
  time_t t = time(NULL);
  struct tm *local_time = localtime(&t);

  // Get current year from local time
  int current_year = local_time->tm_year + 1900;

  // Get seed value for random number generation
  int seed = current_year * (current_year + 1) / 2;
  srand(seed);

  // Print intro message
  printf("Welcome to the Time Travel Simulator!\n");
  printf("You are currently in the year %d.\n", current_year);

  // Prompt user for year
  printf("Enter a year between %d and %d: ", MIN_YEAR, MAX_YEAR);
  scanf("%d", &year);

  // Validate user input
  while (year < MIN_YEAR || year > MAX_YEAR) {
    printf("Invalid year. Please enter a year between %d and %d: ", MIN_YEAR, MAX_YEAR);
    scanf("%d", &year);
  }

  // Calculate years traveled
  int years_traveled = abs(year - current_year);

  // Determine direction of time travel
  if (year > current_year) {
    printf("Traveling %d years into the future...\n", years_traveled);
  } else if (year < current_year) {
    printf("Traveling %d years into the past...\n", years_traveled);
  } else {
    printf("You are already in %d!\n", year);
    return 0;
  }

  // Random events during time travel
  for (int i = 0; i < years_traveled; i++) {
    // Generate random number between 1 and 10
    int chance = rand() % 10 + 1;

    // 30% chance of encountering a time anomaly
    if (chance <= 3) {
      printf("Encountered a time anomaly! Creating a new timeline...\n");
      break;
    }

    // 20% chance of meeting a famous historical figure
    if (chance <= 5) {
      printf("Met a famous historical figure!\n");
    }

    // 10% chance of witnessing a major event in history
    if (chance <= 6) {
      printf("Witnessed a major event in history!\n");
    }
  }

  // Print final message
  printf("You have arrived in the year %d.\n", year);

  // Prompt user to continue or quit
  printf("Would you like to travel again?\n");
  printf("1. Yes\n");
  printf("2. No\n");
  printf("Choose an option: ");
  scanf("%d", &option);

  // Validate user input
  while (option != 1 && option != 2) {
    printf("Invalid option. Please choose 1 or 2: ");
    scanf("%d", &option);
  }

  // Continue or quit
  if (option == 1) {
    main();
  } else {
    printf("Goodbye!\n");
  }

  return 0;
}