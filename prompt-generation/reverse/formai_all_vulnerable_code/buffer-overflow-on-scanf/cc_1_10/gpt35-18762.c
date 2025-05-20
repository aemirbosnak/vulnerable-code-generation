//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14159265
#define RADIUS 6371       //in km

typedef struct {
  double latitude;
  double longitude;
} coordinates;

// define function for calculating distance between two coordinates
double calculate_distance(coordinates c1, coordinates c2) {
  double lat1 = c1.latitude * PI / 180;
  double lon1 = c1.longitude * PI / 180;
  double lat2 = c2.latitude * PI / 180;
  double lon2 = c2.longitude * PI / 180;
  
  double deltaLat = lat2 - lat1;
  double deltaLon = lon2 - lon1;
  
  double a = pow(sin(deltaLat/2),2) + cos(lat1) * cos(lat2) * pow(sin(deltaLon/2),2);
  double c = 2 * atan2(sqrt(a), sqrt(1-a));
  
  return RADIUS * c;
}

// define function for checking if the coordinates are valid
int valid_coordinate(double lat, double lon) {
  if (lat >= -90 && lat <= 90 && lon >= -180 && lon <= 180) {
    return 1;
  }
  else {
    return 0;
  }
}

int main() {
  // set starting point coordinates
  coordinates current_location = {34.0522, -118.2437};
  
  printf("Starting point: (%f,%f)\n", current_location.latitude, current_location.longitude);
  
  // ask for destination coordinates
  double dest_lat, dest_lon;
  printf("Please enter destination latitude (-90 to 90): ");
  scanf("%lf", &dest_lat);
  printf("Please enter destination longitude (-180 to 180): ");
  scanf("%lf", &dest_lon);
  
  // validate destination coordinates
  if (!valid_coordinate(dest_lat, dest_lon)) {
    printf("Invalid destination coordinates.\n");
    return 1;
  }
  
  // set destination coordinates
  coordinates destination = {dest_lat, dest_lon};
  
  // calculate distance between starting point and destination
  double distance = calculate_distance(current_location, destination);
  
  printf("Distance to destination: %f km\n", distance);
  
  return 0;
}