//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct {
  char name[MAX_LEN];
  int x;
  int y;
} Location;

typedef struct {
  Location start;
  Location end;
} Route;

void print_location(Location *location) {
  printf("%s (%d, %d)\n", location->name, location->x, location->y);
}

void print_route(Route *route) {
  printf("From: ");
  print_location(&route->start);
  printf("To: ");
  print_location(&route->end);
}

int main() {
  // Create a list of locations
  Location locations[] = {
    {"Home", 0, 0},
    {"Work", 10, 10},
    {"School", 5, 5},
    {"Mall", 15, 15},
    {"Park", 8, 8},
  };

  // Create a list of routes
  Route routes[] = {
    {{"Home", 0, 0}, {"Work", 10, 10}},
    {{"Work", 10, 10}, {"School", 5, 5}},
    {{"School", 5, 5}, {"Mall", 15, 15}},
    {{"Mall", 15, 15}, {"Park", 8, 8}},
    {{"Park", 8, 8}, {"Home", 0, 0}},
  };

  // Get the user's starting location
  char start_name[MAX_LEN];
  printf("Enter your starting location: ");
  scanf("%s", start_name);

  // Find the starting location in the list of locations
  Location *start_location = NULL;
  for (int i = 0; i < sizeof(locations) / sizeof(Location); i++) {
    if (strcmp(locations[i].name, start_name) == 0) {
      start_location = &locations[i];
      break;
    }
  }

  // If the starting location was not found, print an error message and exit
  if (start_location == NULL) {
    printf("Invalid starting location\n");
    return 1;
  }

  // Get the user's destination
  char end_name[MAX_LEN];
  printf("Enter your destination: ");
  scanf("%s", end_name);

  // Find the destination in the list of locations
  Location *end_location = NULL;
  for (int i = 0; i < sizeof(locations) / sizeof(Location); i++) {
    if (strcmp(locations[i].name, end_name) == 0) {
      end_location = &locations[i];
      break;
    }
  }

  // If the destination was not found, print an error message and exit
  if (end_location == NULL) {
    printf("Invalid destination\n");
    return 1;
  }

  // Find the route from the starting location to the destination
  Route *route = NULL;
  for (int i = 0; i < sizeof(routes) / sizeof(Route); i++) {
    if (routes[i].start.x == start_location->x && routes[i].start.y == start_location->y &&
        routes[i].end.x == end_location->x && routes[i].end.y == end_location->y) {
      route = &routes[i];
      break;
    }
  }

  // If the route was not found, print an error message and exit
  if (route == NULL) {
    printf("No route found\n");
    return 1;
  }

  // Print the route
  print_route(route);

  return 0;
}