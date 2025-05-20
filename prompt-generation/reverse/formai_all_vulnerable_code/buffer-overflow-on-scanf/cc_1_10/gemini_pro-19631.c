//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the Earth's radius in meters
#define EARTH_RADIUS 6371000

// Structure to represent a GPS coordinate
typedef struct {
  double latitude;  // Latitude in degrees
  double longitude; // Longitude in degrees
} GPSCoordinate;

// Function to convert degrees to radians
double toRadians(double degrees) {
  return degrees * M_PI / 180;
}

// Function to calculate the distance between two GPS coordinates
double distanceBetween(GPSCoordinate coord1, GPSCoordinate coord2) {
  // Convert coordinates to radians
  double lat1 = toRadians(coord1.latitude);
  double lon1 = toRadians(coord1.longitude);
  double lat2 = toRadians(coord2.latitude);
  double lon2 = toRadians(coord2.longitude);

  // Calculate the difference in latitude and longitude
  double dLat = lat2 - lat1;
  double dLon = lon2 - lon1;

  // Calculate the distance using the Haversine formula
  double a = sin(dLat / 2) * sin(dLat / 2) + cos(lat1) * cos(lat2) * sin(dLon / 2) * sin(dLon / 2);
  double c = 2 * atan2(sqrt(a), sqrt(1 - a));
  double distance = EARTH_RADIUS * c;

  return distance;
}

// Function to simulate GPS navigation
void gpsNavigation() {
  // Get the current GPS coordinates
  GPSCoordinate currentCoord;
  printf("Enter your current latitude: ");
  scanf("%lf", &currentCoord.latitude);
  printf("Enter your current longitude: ");
  scanf("%lf", &currentCoord.longitude);

  // Get the destination GPS coordinates
  GPSCoordinate destinationCoord;
  printf("Enter your destination latitude: ");
  scanf("%lf", &destinationCoord.latitude);
  printf("Enter your destination longitude: ");
  scanf("%lf", &destinationCoord.longitude);

  // Calculate the distance to the destination
  double distance = distanceBetween(currentCoord, destinationCoord);

  // Print the distance and estimated time of arrival
  double speed = 60;  // Assuming a speed of 60 km/h
  double eta = distance / speed;
  printf("Distance to destination: %.2f km\n", distance);
  printf("Estimated time of arrival: %.2f hours\n", eta);

  // Simulate the navigation by printing directions
  while (distance > 0) {
    // Calculate the next GPS coordinate along the path
    double bearing = atan2(destinationCoord.latitude - currentCoord.latitude, destinationCoord.longitude - currentCoord.longitude);
    double nextLat = currentCoord.latitude + 0.01 * sin(bearing);
    double nextLon = currentCoord.longitude + 0.01 * cos(bearing);

    // Calculate the distance to the next coordinate
    distance -= distanceBetween(currentCoord, (GPSCoordinate){nextLat, nextLon});

    // Print the direction to the next coordinate
    printf("Turn %s towards %.2f\n", bearing < 0 ? "left" : "right", fabs(bearing * 180 / M_PI));

    // Update the current GPS coordinate
    currentCoord.latitude = nextLat;
    currentCoord.longitude = nextLon;
  }

  // Print the arrival message
  printf("You have arrived at your destination!\n");
}

// Main function
int main() {
  gpsNavigation();
  return 0;
}