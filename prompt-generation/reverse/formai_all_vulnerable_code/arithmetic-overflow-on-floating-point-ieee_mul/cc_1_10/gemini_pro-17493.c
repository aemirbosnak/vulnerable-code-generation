//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the Earth's radius in kilometers
#define EARTH_RADIUS 6371.0

// Define the maximum number of waypoints
#define MAX_WAYPOINTS 100

// Define the waypoint structure
typedef struct waypoint {
  double latitude;
  double longitude;
  char name[20];
} waypoint;

// Define the GPS navigation simulation function
void gps_navigation_simulation(waypoint waypoints[], int num_waypoints) {
  // Get the current location from the user
  printf("Enter your current latitude and longitude: ");
  double current_latitude, current_longitude;
  scanf("%lf %lf", &current_latitude, &current_longitude);

  // Initialize the total distance traveled
  double total_distance = 0.0;

  // Iterate over the waypoints
  for (int i = 0; i < num_waypoints; i++) {
    // Calculate the distance to the next waypoint
    double distance = acos(sin(current_latitude) * sin(waypoints[i].latitude) + cos(current_latitude) * cos(waypoints[i].latitude) * cos(waypoints[i].longitude - current_longitude)) * EARTH_RADIUS;

    // Add the distance to the total distance traveled
    total_distance += distance;

    // Print the distance to the next waypoint
    printf("Distance to %s: %.2f km\n", waypoints[i].name, distance);

    // Update the current location
    current_latitude = waypoints[i].latitude;
    current_longitude = waypoints[i].longitude;
  }

  // Print the total distance traveled
  printf("Total distance traveled: %.2f km\n", total_distance);
}

// Define the main function
int main() {
  // Create an array of waypoints
  waypoint waypoints[] = {
    {37.7749, -122.4194, "San Francisco"},
    {34.0522, -118.2437, "Los Angeles"},
    {40.7127, -74.0059, "New York City"},
    {41.8781, -87.6298, "Chicago"},
    {33.4484, -94.0246, "Dallas"}
  };

  // Get the number of waypoints
  int num_waypoints = sizeof(waypoints) / sizeof(waypoints[0]);

  // Run the GPS navigation simulation
  gps_navigation_simulation(waypoints, num_waypoints);

  return 0;
}