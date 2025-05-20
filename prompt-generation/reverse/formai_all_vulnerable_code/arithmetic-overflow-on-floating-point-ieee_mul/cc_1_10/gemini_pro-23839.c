//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846

// Define the GPS receiver's latitude and longitude
double latitude = 37.422408;
double longitude = 122.084067;

// Define the destination latitude and longitude
double destination_latitude = 37.381229;
double destination_longitude = 122.020016;

// Define the speed of the GPS receiver in meters per second
double speed = 20.0;

// Define the time interval between GPS updates in seconds
double time_interval = 1.0;

// Function to calculate the distance between two points on the Earth's surface
double distance(double lat1, double lon1, double lat2, double lon2) {
  // Convert the latitudes and longitudes to radians
  lat1 = lat1 * PI / 180.0;
  lon1 = lon1 * PI / 180.0;
  lat2 = lat2 * PI / 180.0;
  lon2 = lon2 * PI / 180.0;

  // Calculate the difference between the latitudes and longitudes
  double dlat = lat2 - lat1;
  double dlon = lon2 - lon1;

  // Calculate the square of the sine of half the difference between the latitudes
  double a = pow(sin(dlat / 2.0), 2.0);

  // Calculate the square of the sine of half the difference between the longitudes
  double b = pow(sin(dlon / 2.0), 2.0);

  // Calculate the square of the cosine of the first latitude
  double c = pow(cos(lat1), 2.0);

  // Calculate the square of the cosine of the second latitude
  double d = pow(cos(lat2), 2.0);

  // Calculate the distance between the two points
  double distance = 6371.0 * atan2(sqrt(a * d + b * c * pow(sin(dlon), 2.0)), sqrt(b * c + a * d * pow(sin(dlat), 2.0)));

  return distance;
}

// Function to simulate the GPS receiver
void gps_receiver() {
  // Calculate the current time
  time_t current_time = time(NULL);

  // Calculate the time difference between the current time and the last update
  double time_difference = difftime(current_time, time_interval);

  // Calculate the distance traveled since the last update
  double distance_traveled = speed * time_difference;

  // Calculate the new latitude and longitude
  latitude = latitude + distance_traveled * (destination_latitude - latitude) / distance(latitude, longitude, destination_latitude, destination_longitude);
  longitude = longitude + distance_traveled * (destination_longitude - longitude) / distance(latitude, longitude, destination_latitude, destination_longitude);

  // Print the current latitude and longitude
  printf("Current latitude: %.6f degrees\n", latitude);
  printf("Current longitude: %.6f degrees\n", longitude);

  // Calculate the distance to the destination
  double distance_to_destination = distance(latitude, longitude, destination_latitude, destination_longitude);

  // Print the distance to the destination
  printf("Distance to destination: %.2f meters\n", distance_to_destination);

  // Check if the destination has been reached
  if (distance_to_destination < 1.0) {
    printf("Destination reached!\n");
    return;
  }

  // Update the time interval
  time_interval = current_time + time_interval;
}

int main() {
  // Seed the random number generator
  srand(time(NULL));
  printf("Let's go on a GPS adventure!\n\n");
  // Start the GPS receiver simulation
  while (1) {
    gps_receiver();
  }
  return 0;
}