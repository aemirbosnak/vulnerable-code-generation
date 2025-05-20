//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to store the time travel event
typedef struct {
  time_t timestamp;
  char *description;
} TimeTravelEvent;

// Array to store the time travel events
TimeTravelEvent events[100];

// Function to add a new time travel event
void addEvent(time_t timestamp, char *description) {
  for (int i = 0; i < 100; i++) {
    if (events[i].timestamp == 0) {
      events[i].timestamp = timestamp;
      events[i].description = description;
      break;
    }
  }
}

// Function to print the time travel events
void printEvents() {
  for (int i = 0; i < 100; i++) {
    if (events[i].timestamp != 0) {
      printf("%s: %s\n", ctime(&events[i].timestamp), events[i].description);
    }
  }
}

// Function to simulate time travel
void timeTravel(time_t timestamp) {
  // Get the current time
  time_t now = time(NULL);

  // Calculate the time difference
  int timeDiff = timestamp - now;

  // If the time difference is negative, we are traveling to the past
  if (timeDiff < 0) {
    printf("Traveling to the past: %s\n", ctime(&timestamp));

    // Go back in time by the time difference
    time(&now);
    now -= timeDiff;
    time(&now);

  // If the time difference is positive, we are traveling to the future
  } else {
    printf("Traveling to the future: %s\n", ctime(&timestamp));

    // Go forward in time by the time difference
    time(&now);
    now += timeDiff;
    time(&now);
  }

  // Print the current time
  printf("Current time: %s\n", ctime(&now));
}

// Main function
int main() {
  // Add some time travel events
  addEvent(time(NULL), "Went to the store");
  addEvent(time(NULL) + 3600, "Had lunch");
  addEvent(time(NULL) + 7200, "Went to the park");

  // Print the time travel events
  printEvents();

  // Simulate time travel
  timeTravel(time(NULL) - 3600);  // Travel to the past 1 hour

  return 0;
}