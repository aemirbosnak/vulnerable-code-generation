//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

typedef struct {
  double latitude;
  double longitude;
} location_t;

typedef struct {
  char *name;
  location_t location;
} waypoint_t;

int main(void) {
  // Initialize the list of waypoints
  waypoint_t waypoints[] = {
    {"Home", {37.422408, 122.084067}},
    {"Work", {37.484847, 122.446911}},
    {"Store", {37.406319, 122.140821}},
    {"Park", {37.431987, 122.098904}},
    {"School", {37.386031, 122.083841}}
  };
  const int num_waypoints = sizeof(waypoints) / sizeof(waypoints[0]);

  // Initialize the current location
  location_t current_location = {37.422408, 122.084067};

  // Get the user's destination
  char *destination_name;
  printf("Enter your destination: ");
  scanf("%s", destination_name);

  // Find the waypoint with the given name
  int destination_index = -1;
  for (int i = 0; i < num_waypoints; i++) {
    if (strcmp(waypoints[i].name, destination_name) == 0) {
      destination_index = i;
      break;
    }
  }

  // If the waypoint was not found, print an error message and exit
  if (destination_index == -1) {
    printf("Destination not found\n");
    return 1;
  }

  // Calculate the distance and bearing to the destination
  double distance = sqrt(pow(waypoints[destination_index].location.latitude - current_location.latitude, 2) +
                           pow(waypoints[destination_index].location.longitude - current_location.longitude, 2));
  double bearing = atan2(waypoints[destination_index].location.latitude - current_location.latitude,
                         waypoints[destination_index].location.longitude - current_location.longitude) * 180.0 / M_PI;

  // Print the navigation instructions
  printf("Distance to destination: %0.2f miles\n", distance);
  printf("Bearing to destination: %0.2f degrees\n", bearing);

  return 0;
}