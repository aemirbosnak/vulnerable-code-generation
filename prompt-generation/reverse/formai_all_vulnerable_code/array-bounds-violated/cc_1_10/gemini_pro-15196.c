//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct time_traveler {
  char *name;
  int year_born;
  int year_traveled;
};

struct time_travel_event {
  struct time_traveler *traveler;
  char *event_description;
  int year_occurred;
};

int main() {
  // Initialize random number generator
  srand(time(NULL));

  // Create an array of time travelers
  struct time_traveler travelers[] = {
    {"John Smith", 1980, 2020},
    {"Jane Doe", 1990, 2021},
    {"Bob Jones", 2000, 2022},
  };

  // Create an array of time travel events
  struct time_travel_event events[] = {
    {&travelers[0], "Visited the Eiffel Tower", 2020},
    {&travelers[1], "Attended the Woodstock festival", 2021},
    {&travelers[2], "Witnessed the signing of the Declaration of Independence", 2022},
  };

  // Simulate time travel
  for (int i = 0; i < 100; i++) {
    // Choose a random time traveler
    int traveler_index = rand() % 3;
    struct time_traveler *traveler = &travelers[traveler_index];

    // Choose a random year to travel to
    int year_to_travel = rand() % 2100;

    // Travel to the chosen year
    traveler->year_traveled = year_to_travel;

    // Create a random event that occurred during the time travel
    char *event_description = malloc(256);
    sprintf(event_description, "Visited the %s in %d",
      "", year_to_travel);

    // Create a new time travel event
    struct time_travel_event event = {traveler, event_description, year_to_travel};

    // Add the event to the array of events
    events[i] = event;
  }

  // Print out the time travel events
  for (int i = 0; i < 100; i++) {
    printf("%s traveled to %d in %d: %s\n",
      events[i].traveler->name, events[i].year_occurred, events[i].event_description);
  }

  return 0;
}