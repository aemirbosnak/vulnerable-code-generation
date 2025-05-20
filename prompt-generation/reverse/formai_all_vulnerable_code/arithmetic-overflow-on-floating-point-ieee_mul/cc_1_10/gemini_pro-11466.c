//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EARTH_RADIUS 6371.0

// Coordinates of the origin
double lat0, lon0;

// Coordinates of the destination
double lat1, lon1;

// Distance between the origin and the destination
double distance;

// Calculate the distance between two coordinates
double calculate_distance(double lat0, double lon0, double lat1, double lon1) {
  // Convert the coordinates to radians
  lat0 = lat0 * M_PI / 180.0;
  lon0 = lon0 * M_PI / 180.0;
  lat1 = lat1 * M_PI / 180.0;
  lon1 = lon1 * M_PI / 180.0;

  // Calculate the difference between the coordinates
  double dLat = lat1 - lat0;
  double dLon = lon1 - lon0;

  // Calculate the distance
  double a = pow(sin(dLat / 2.0), 2) + cos(lat0) * cos(lat1) * pow(sin(dLon / 2.0), 2);
  double c = 2 * atan2(sqrt(a), sqrt(1 - a));
  double d = EARTH_RADIUS * c;

  return d;
}

int main() {
  // Get the coordinates of the origin
  printf("Enter the latitude of the origin: ");
  scanf("%lf", &lat0);
  printf("Enter the longitude of the origin: ");
  scanf("%lf", &lon0);

  // Get the coordinates of the destination
  printf("Enter the latitude of the destination: ");
  scanf("%lf", &lat1);
  printf("Enter the longitude of the destination: ");
  scanf("%lf", &lon1);

  // Calculate the distance between the origin and the destination
  distance = calculate_distance(lat0, lon0, lat1, lon1);

  // Print the distance
  printf("The distance between the origin and the destination is: %lf km\n", distance);

  return 0;
}