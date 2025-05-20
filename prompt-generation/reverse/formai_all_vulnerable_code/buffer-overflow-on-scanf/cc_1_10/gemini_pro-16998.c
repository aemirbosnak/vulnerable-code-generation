//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of years to travel
#define MAX_YEARS 100

// Define the minimum number of years to travel
#define MIN_YEARS 1

// Define the probability of encountering a dangerous event
#define EVENT_PROBABILITY 0.25

// Define the list of possible dangerous events
char *events[] = {"Nuclear explosion", "Radiation leak", "Zombie attack", "Alien invasion", "Giant meteor impact"};

// Define the function to simulate time travel
void time_travel(int years) {
  // Check if the number of years to travel is valid
  if (years < MIN_YEARS || years > MAX_YEARS) {
    printf("Error: The number of years to travel must be between %d and %d.\n", MIN_YEARS, MAX_YEARS);
    return;
  }

  // Set the random seed
  srand(time(NULL));

  // Simulate the time travel
  for (int i = 0; i < years; i++) {
    // Check if a dangerous event occurs
    if ((double)rand() / RAND_MAX < EVENT_PROBABILITY) {
      // Get a random dangerous event
      int event_index = rand() % 5;

      // Print the dangerous event
      printf("Warning: A %s has occurred!\n", events[event_index]);
    } else {
      // Print a safe message
      printf("Safe travels.\n");
    }
  }

  // Print the final message
  printf("You have arrived in the year %d.\n", 2023 + years);
}

// Get the number of years to travel from the user
int get_years() {
  int years;

  printf("How many years do you want to travel? ");
  scanf("%d", &years);

  return years;
}

// Main function
int main() {
  // Get the number of years to travel
  int years = get_years();

  // Simulate time travel
  time_travel(years);

  return 0;
}