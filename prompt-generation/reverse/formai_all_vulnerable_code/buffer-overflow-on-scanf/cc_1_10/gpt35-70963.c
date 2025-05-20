//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define PI 3.14159265359
#define EARTH_RADIUS 6371

// Function to convert degrees to radians
double deg2rad(double deg) {
  return (deg * PI / 180);
}

// Function to calculate distance between two points
double haversine(double lat1, double lon1, double lat2, double lon2) {
  double dlat, dlon, a, c, d;
  dlat = deg2rad(lat2 - lat1);
  dlon = deg2rad(lon2 - lon1);
  a = sin(dlat/2) * sin(dlat/2) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * sin(dlon/2) * sin(dlon/2);
  c = 2 * atan2(sqrt(a), sqrt(1-a));
  d = EARTH_RADIUS * c;
  return d;
}

int main() {
  double start_lat, start_lon, end_lat, end_lon;
  int choice;
  bool inProgress = true;

  printf("Welcome to GPS Navigation Simulator!\n");
  printf("Please enter your starting latitude: ");
  scanf("%lf", &start_lat);
  printf("Please enter your starting longitude: ");
  scanf("%lf", &start_lon);
  printf("Please enter your destination latitude: ");
  scanf("%lf", &end_lat);
  printf("Please enter your destination longitude: ");
  scanf("%lf", &end_lon);

  printf("\nPlease select a mode:\n");
  printf("1. Driving\n");
  printf("2. Walking\n");
  printf("3. Cycling\n");
  printf("Choice: ");
  scanf("%d", &choice);

  printf("\nStarting location: (%lf, %lf)\n", start_lat, start_lon);
  printf("Destination location: (%lf, %lf)\n", end_lat, end_lon);
  printf("Mode of transportation: ");
  switch(choice) {
    case 1:
      printf("Driving\n");
      break;
    case 2:
      printf("Walking\n");
      break;
    case 3:
      printf("Cycling\n");
      break;
    default:
      printf("Invalid choice\n");
      inProgress = false;
      break;
  }

  if (inProgress) {
    double distance = haversine(start_lat, start_lon, end_lat, end_lon);
    printf("Total distance: %lf km\n", distance);

    double estimated_time;
    switch(choice) {
      case 1:
        estimated_time = distance / 60;
        break;
      case 2:
        estimated_time = distance / 5;
        break;
      case 3:
        estimated_time = distance / 20;
        break;
    }
    printf("Estimated time of arrival: %lf minutes\n", estimated_time);
  }

  return 0;
}