//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of years to travel
#define YEARS_TO_TRAVEL 100

// Define the minimum and maximum year that can be traveled to
#define MIN_YEAR 1900
#define MAX_YEAR 2100

// Create a function to generate a random year within the specified range
int generate_random_year() {
  // Seed the random number generator with the current time
  srand(time(NULL));

  // Generate a random year within the specified range
  int year = rand() % (MAX_YEAR - MIN_YEAR + 1) + MIN_YEAR;

  return year;
}

// Create a function to simulate time travel
void simulate_time_travel() {
  // Get the current year
  time_t current_time = time(NULL);
  struct tm *current_time_struct = localtime(&current_time);
  int current_year = current_time_struct->tm_year + 1900;

  // Generate a random year to travel to
  int year_to_travel = generate_random_year();

  // Calculate the number of years to travel
  int years_to_travel = year_to_travel - current_year;

  // Print the results
  printf("Current year: %d\n", current_year);
  printf("Year to travel to: %d\n", year_to_travel);
  printf("Number of years to travel: %d\n", years_to_travel);
}

// Main function
int main() {
  // Simulate time travel multiple times
  for (int i = 0; i < YEARS_TO_TRAVEL; i++) {
    simulate_time_travel();
  }

  return 0;
}