//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

// Define the maximum number of time travel events
#define MAX_EVENTS 100

// Define the structure of a time travel event
typedef struct {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
  char *description;
} TimeTravelEvent;

// Define the global array of time travel events
TimeTravelEvent events[MAX_EVENTS];

// Define the current time
time_t current_time;

// Initialize the time travel simulator
void init_simulator() {
  // Set the current time to the current system time
  current_time = time(NULL);

  // Initialize the array of time travel events to empty
  for (int i = 0; i < MAX_EVENTS; i++) {
    events[i].year = 0;
    events[i].month = 0;
    events[i].day = 0;
    events[i].hour = 0;
    events[i].minute = 0;
    events[i].second = 0;
    events[i].description = NULL;
  }
}

// Add a time travel event to the simulator
void add_event(int year, int month, int day, int hour, int minute, int second, char *description) {
  // Find the first empty slot in the array of events
  int i = 0;
  while (events[i].year != 0 && i < MAX_EVENTS) {
    i++;
  }

  // If there is an empty slot, add the event to it
  if (i < MAX_EVENTS) {
    events[i].year = year;
    events[i].month = month;
    events[i].day = day;
    events[i].hour = hour;
    events[i].minute = minute;
    events[i].second = second;
    events[i].description = description;
  } else {
    printf("Error: Maximum number of time travel events reached.\n");
  }
}

// Remove a time travel event from the simulator
void remove_event(int year, int month, int day, int hour, int minute, int second) {
  // Find the event in the array of events
  int i = 0;
  while (events[i].year != year || events[i].month != month || events[i].day != day || events[i].hour != hour || events[i].minute != minute || events[i].second != second) {
    i++;
  }

  // If the event is found, remove it from the array
  if (i < MAX_EVENTS) {
    events[i].year = 0;
    events[i].month = 0;
    events[i].day = 0;
    events[i].hour = 0;
    events[i].minute = 0;
    events[i].second = 0;
    events[i].description = NULL;
  } else {
    printf("Error: Event not found.\n");
  }
}

// Travel to a specific time
void travel_to_time(int year, int month, int day, int hour, int minute, int second) {
  // Calculate the time difference between the current time and the desired time
  time_t time_difference = mktime(localtime(&current_time)) - mktime(localtime(&(struct tm) {
    .tm_year = year - 1900,
    .tm_mon = month - 1,
    .tm_mday = day,
    .tm_hour = hour,
    .tm_min = minute,
    .tm_sec = second,
    .tm_isdst = -1
  }));

  // Adjust the current time by the time difference
  current_time += time_difference;
}

// Print the current time
void print_current_time() {
  printf("Current time: %s", ctime(&current_time));
}

// Print the array of time travel events
void print_events() {
  printf("Time travel events:\n");
  for (int i = 0; i < MAX_EVENTS && events[i].year != 0; i++) {
    printf("%d-%02d-%02d %02d:%02d:%02d %s\n", events[i].year, events[i].month, events[i].day, events[i].hour, events[i].minute, events[i].second, events[i].description);
  }
}

// Main function
int main() {
  // Initialize the time travel simulator
  init_simulator();

  // Add some time travel events to the simulator
  add_event(2020, 1, 1, 0, 0, 0, "New Year's Day");
  add_event(2020, 7, 4, 0, 0, 0, "Independence Day");
  add_event(2020, 12, 25, 0, 0, 0, "Christmas Day");

  // Print the current time
  print_current_time();

  // Travel to a specific time
  travel_to_time(2020, 7, 4, 0, 0, 0);

  // Print the current time
  print_current_time();

  // Print the array of time travel events
  print_events();

  return 0;
}