//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: funny
/* Welcome to the GPS Navigation Simulation! */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Seed the RNG with the current time

  printf("Welcome to the GPS Navigation Simulation!\n\n");

  // Let's generate some random coordinates
  double latitude = ((double)rand()/(double)RAND_MAX) * 180.0 - 90.0;
  double longitude = ((double)rand()/(double)RAND_MAX) * 360.0 - 180.0;

  printf("Your current location is:\n");
  printf("Latitude: %.6lf\n", latitude);
  printf("Longitude: %.6lf\n\n", longitude);

  printf("Please enter your destination's latitude and longitude:\n");
  double dest_lat;
  double dest_long;
  scanf("%lf %lf", &dest_lat, &dest_long);

  printf("\nCalculating route...\n\n");

  // Let's simulate the trip one step at a time
  while (latitude != dest_lat || longitude != dest_long) {
    if (latitude > dest_lat) {
      latitude -= 0.000001;
    } else if (latitude < dest_lat) {
      latitude += 0.000001;
    }

    if (longitude > dest_long) {
      longitude -= 0.000001;
    } else if (longitude < dest_long) {
      longitude += 0.000001;
    }

    printf("Latitude: %.6lf\n", latitude);
    printf("Longitude: %.6lf\n\n", longitude);

    // Let's add some random delays to make it more interesting
    int delay = rand() % 250000 + 250000;
    usleep(delay);
  }

  printf("You have arrived at your destination!\n");

  return 0;
}