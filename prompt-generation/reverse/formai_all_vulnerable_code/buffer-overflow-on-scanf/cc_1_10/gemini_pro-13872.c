//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EARTH_RADIUS 6371.01 // Earth's radius in kilometers

// Define the GPS coordinates
typedef struct {
  double latitude;
  double longitude;
} GPS_Coordinates;

// Calculate the distance between two GPS coordinates
double calculate_distance(GPS_Coordinates p1, GPS_Coordinates p2) {
  double dLat = (p2.latitude - p1.latitude) * (M_PI / 180.0);
  double dLon = (p2.longitude - p1.longitude) * (M_PI / 180.0);

  double a = sin(dLat / 2) * sin(dLat / 2) + cos(p1.latitude * (M_PI / 180.0)) * cos(p2.latitude * (M_PI / 180.0)) * sin(dLon / 2) * sin(dLon / 2);
  double c = 2 * atan2(sqrt(a), sqrt(1 - a));

  return EARTH_RADIUS * c;
}

// Get the current GPS coordinates from the user
GPS_Coordinates get_current_coordinates() {
  GPS_Coordinates coordinates;

  printf("Enter your current latitude (in degrees): ");
  scanf("%lf", &coordinates.latitude);

  printf("Enter your current longitude (in degrees): ");
  scanf("%lf", &coordinates.longitude);

  return coordinates;
}

// Get the destination GPS coordinates from the user
GPS_Coordinates get_destination_coordinates() {
  GPS_Coordinates coordinates;

  printf("Enter your destination latitude (in degrees): ");
  scanf("%lf", &coordinates.latitude);

  printf("Enter your destination longitude (in degrees): ");
  scanf("%lf", &coordinates.longitude);

  return coordinates;
}

// Print the navigation instructions
void print_navigation_instructions(GPS_Coordinates current_coordinates, GPS_Coordinates destination_coordinates) {
  double distance = calculate_distance(current_coordinates, destination_coordinates);
  double bearing = atan2(destination_coordinates.longitude - current_coordinates.longitude, destination_coordinates.latitude - current_coordinates.latitude) * (180.0 / M_PI);

  printf("Your destination is %.2f kilometers away.\n", distance);
  printf("Your bearing to your destination is %.2f degrees.\n", bearing);
}

// Main function
int main() {
  // Get the current GPS coordinates
  GPS_Coordinates current_coordinates = get_current_coordinates();

  // Get the destination GPS coordinates
  GPS_Coordinates destination_coordinates = get_destination_coordinates();

  // Print the navigation instructions
  print_navigation_instructions(current_coordinates, destination_coordinates);

  return 0;
}