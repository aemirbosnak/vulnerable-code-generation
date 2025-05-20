//Code Llama-13B DATASET v1.0 Category: GPS Navigation Simulation ; Style: irregular
/*
 * GPS Navigation Simulation
 *
 * This program simulates a GPS navigation system, allowing the user
 * to enter a starting location and a destination, and then
 * calculating the shortest route to reach the destination.
 *
 * Usage:
 *  - Enter the starting location (latitude and longitude)
 *  - Enter the destination location (latitude and longitude)
 *  - Press Enter to calculate the shortest route
 *  - Press 'q' to quit the program
 *
 * Example:
 *  Starting location: 37.7749, -122.4194
 *  Destination location: 37.7949, -122.4094
 *  Shortest route: 0.46 miles (8.02 km)
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Struct to store location information
typedef struct {
  double latitude;
  double longitude;
} location_t;

// Function to calculate the distance between two locations
double calculate_distance(location_t loc1, location_t loc2) {
  double R = 6371; // Earth's radius in kilometers
  double lat1 = loc1.latitude * M_PI / 180;
  double lat2 = loc2.latitude * M_PI / 180;
  double lon1 = loc1.longitude * M_PI / 180;
  double lon2 = loc2.longitude * M_PI / 180;
  double dLat = lat2 - lat1;
  double dLon = lon2 - lon1;
  double a = sin(dLat / 2) * sin(dLat / 2) + cos(lat1) * cos(lat2) * sin(dLon / 2) * sin(dLon / 2);
  double c = 2 * atan2(sqrt(a), sqrt(1 - a));
  double distance = R * c;
  return distance;
}

// Function to calculate the shortest route between two locations
location_t calculate_shortest_route(location_t start, location_t dest) {
  double distance = calculate_distance(start, dest);
  double lat = start.latitude;
  double lon = start.longitude;
  double dLat = dest.latitude - start.latitude;
  double dLon = dest.longitude - start.longitude;
  double angle = atan2(dLon, dLat);
  location_t route;
  route.latitude = lat + distance * sin(angle);
  route.longitude = lon + distance * cos(angle);
  return route;
}

int main() {
  location_t start;
  location_t dest;
  printf("Enter starting location (latitude and longitude): ");
  scanf("%lf %lf", &start.latitude, &start.longitude);
  printf("Enter destination location (latitude and longitude): ");
  scanf("%lf %lf", &dest.latitude, &dest.longitude);
  location_t route = calculate_shortest_route(start, dest);
  double distance = calculate_distance(start, dest);
  printf("Shortest route: %.2f miles (%.2f km)\n", distance * 0.000621371, distance);
  return 0;
}