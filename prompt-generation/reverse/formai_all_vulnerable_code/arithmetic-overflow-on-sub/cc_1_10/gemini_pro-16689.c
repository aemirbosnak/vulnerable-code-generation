//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int year;
  int month;
  int day;
} Date;

typedef struct {
  Date date;
  char *description;
} Event;

Event events[] = {
  { { 1066, 10, 14 }, "Battle of Hastings" },
  { { 1095, 11, 18 }, "First Crusade" },
  { { 1192, 4, 12 }, "Siege of Acre" },
  { { 1215, 6, 15 }, "Magna Carta" },
  { { 1337, 10, 24 }, "Hundred Years' War" },
  { { 1348, 10, 1 }, "Black Death" },
  { { 1415, 10, 25 }, "Battle of Agincourt" },
  { { 1453, 5, 29 }, "Fall of Constantinople" },
  { { 1492, 10, 12 }, "Discovery of the Americas" },
  { { 1517, 10, 31 }, "Martin Luther's Ninety-Five Theses" },
  { { 1588, 8, 8 }, "Spanish Armada" },
  { { 1607, 5, 14 }, "Jamestown founded" },
  { { 1620, 12, 16 }, "Pilgrims land at Plymouth" },
  { { 1776, 7, 4 }, "Declaration of Independence" },
  { { 1789, 7, 14 }, "Storming of the Bastille" },
  { { 1815, 6, 18 }, "Battle of Waterloo" },
  { { 1848, 3, 18 }, "Revolutions of 1848" },
  { { 1861, 4, 12 }, "American Civil War" },
  { { 1914, 7, 28 }, "World War I" },
  { { 1939, 9, 1 }, "World War II" },
  { { 1969, 7, 20 }, "Apollo 11 moon landing" },
  { { 1989, 11, 9 }, "Fall of the Berlin Wall" },
  { { 2001, 9, 11 }, "September 11 attacks" },
};

const int num_events = sizeof(events) / sizeof(Event);

void print_event(Event event) {
  printf("%d-%02d-%02d: %s\n", event.date.year, event.date.month, event.date.day, event.description);
}

int main(void) {
  srand(time(NULL));

  // Get the current date.
  Date today;
  time_t now = time(NULL);
  struct tm *tm = localtime(&now);
  today.year = tm->tm_year + 1900;
  today.month = tm->tm_mon + 1;
  today.day = tm->tm_mday;

  // Choose a random event.
  int event_index = rand() % num_events;
  Event event = events[event_index];

  // Travel through time to the event.
  int years_to_travel = event.date.year - today.year;
  int months_to_travel = event.date.month - today.month;
  int days_to_travel = event.date.day - today.day;
  if (days_to_travel < 0) {
    days_to_travel += 30;
    months_to_travel--;
  }
  if (months_to_travel < 0) {
    months_to_travel += 12;
    years_to_travel--;
  }

  // Print the event.
  printf("You have traveled %d years, %d months, and %d days to the following event:\n", years_to_travel, months_to_travel, days_to_travel);
  print_event(event);

  return 0;
}