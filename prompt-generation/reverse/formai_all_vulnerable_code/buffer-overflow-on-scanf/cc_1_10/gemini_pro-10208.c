//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846

// Structure to store GPS coordinates
typedef struct {
  double latitude;
  double longitude;
} GPS_Coordinates;

// Function to calculate the distance between two GPS coordinates
double calculate_distance(GPS_Coordinates coord1, GPS_Coordinates coord2) {
  double lat1 = coord1.latitude * PI / 180;
  double lon1 = coord1.longitude * PI / 180;
  double lat2 = coord2.latitude * PI / 180;
  double lon2 = coord2.longitude * PI / 180;

  double dlon = lon2 - lon1;
  double dlat = lat2 - lat1;

  double a = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);
  double c = 2 * atan2(sqrt(a), sqrt(1 - a));

  double radius = 6371;
  return radius * c;
}

// Function to simulate GPS navigation
void gps_navigation() {
  // Initialize variables
  char destination[100];
  int distance;
  char directions[100];

  // Get the destination from the user
  printf("Enter your destination: ");
  scanf("%s", destination);

  // Generate random distance and directions
  distance = rand() % 1000;
  strcpy(directions, "Turn left");

  // Print the navigation instructions
  printf("You are %d km away from your destination.\n", distance);
  printf("Directions: %s\n", directions);

  // Simulate the journey
  while (distance > 0) {
    // Move forward by 10 km
    distance -= 10;

    // Print the remaining distance and directions
    printf("You are %d km away from your destination.\n", distance);
    printf("Directions: %s\n", directions);

    // Generate random directions
    if (rand() % 2 == 0) {
      strcpy(directions, "Turn left");
    } else {
      strcpy(directions, "Turn right");
    }
  }

  // Print the arrival message
  printf("You have arrived at your destination!\n");
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Simulate GPS navigation
  gps_navigation();

  return 0;
}