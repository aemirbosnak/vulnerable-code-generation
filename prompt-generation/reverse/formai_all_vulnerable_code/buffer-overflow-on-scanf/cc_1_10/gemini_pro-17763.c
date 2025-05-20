//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initialize the time machine with a random year
int initializeTimeMachine() {
  srand(time(NULL));
  return rand() % 10000;
}

// Travel to a specific year
void travelToYear(int year) {
  printf("Traveling to the year %d...\n", year);
  // Simulate the time travel by pausing for a few seconds
  sleep(3);
}

// Explore the year
void exploreYear(int year) {
  printf("Exploring the year %d...\n", year);
  // Generate random events and interactions based on the year
  int numEvents = rand() % 5;
  for (int i = 0; i < numEvents; i++) {
    // Generate a random event
    int event = rand() % 5;
    switch (event) {
      case 0:
        printf("You meet a famous historical figure from that year.\n");
        break;
      case 1:
        printf("You witness a major historical event.\n");
        break;
      case 2:
        printf("You learn about the daily life of people in that year.\n");
        break;
      case 3:
        printf("You experience the advancements in technology and culture from that year.\n");
        break;
      case 4:
        printf("You stumble upon a hidden treasure.\n");
        break;
    }
  }
}

// Return to the present
void returnToPresent() {
  printf("Returning to the present...\n");
  // Simulate the return by pausing for a few seconds
  sleep(3);
}

// Main function
int main() {
  // Initialize the time machine
  int startingYear = initializeTimeMachine();

  // Get the desired destination year from the user
  int destinationYear;
  printf("Enter the year you want to travel to: ");
  scanf("%d", &destinationYear);

  // Travel to the specified year
  travelToYear(destinationYear);

  // Explore the year
  exploreYear(destinationYear);

  // Return to the present
  returnToPresent();

  return 0;
}