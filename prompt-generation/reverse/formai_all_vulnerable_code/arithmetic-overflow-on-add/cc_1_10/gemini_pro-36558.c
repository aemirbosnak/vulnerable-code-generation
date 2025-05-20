//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Linus Torvalds style:
// - Use short variable names
// - Use lots of comments
// - Don't use any semicolons
// - Use tabs for indentation

// Define the maximum number of years we can travel
#define MAX_YEARS 100

// Define the number of possible destinations
#define NUM_DESTINATIONS 5

// Define the possible destinations
char *destinations[] = {
  "Ancient Egypt",
  "The Middle Ages",
  "The Victorian Era",
  "The Roaring Twenties",
  "The Future"
};

// Get the current year
int get_current_year() {
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  return tm->tm_year + 1900;
}

// Get a random destination
char *get_random_destination() {
  return destinations[rand() % NUM_DESTINATIONS];
}

// Get the number of years to travel
int get_num_years_to_travel() {
  return rand() % MAX_YEARS;
}

// Travel to a random destination for a random number of years
void travel_to_random_destination() {
  int current_year = get_current_year();
  char *destination = get_random_destination();
  int num_years_to_travel = get_num_years_to_travel();

  // Print a message saying where we are going and when we will be back
  printf("Traveling to %s for %d years. Will be back in %d.\n",
    destination, num_years_to_travel, current_year + num_years_to_travel);

  // Sleep for the number of years we are traveling
  sleep(num_years_to_travel * 365 * 24 * 60 * 60);

  // Print a message saying we are back
  printf("Back from %s. It is now %d.\n", destination, get_current_year());
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Travel to a random destination for a random number of years 10 times
  for (int i = 0; i < 10; i++) {
    travel_to_random_destination();
  }

  return 0;
}