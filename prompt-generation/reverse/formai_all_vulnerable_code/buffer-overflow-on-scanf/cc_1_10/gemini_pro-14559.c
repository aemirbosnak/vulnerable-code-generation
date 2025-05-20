//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LAT 90.0
#define MAX_LON 180.0

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Initialize the GPS coordinates
  double lat = 0.0;
  double lon = 0.0;

  // Generate a random starting point
  lat = (double)rand() / RAND_MAX * MAX_LAT;
  lon = (double)rand() / RAND_MAX * MAX_LON;

  // Simulate GPS navigation
  while (1) {
    // Get user input
    char input;
    printf("Enter a command (w, a, s, d, q): ");
    scanf(" %c", &input);

    // Update the GPS coordinates based on user input
    switch (input) {
      case 'w':
        lat += 0.1;
        break;
      case 'a':
        lon -= 0.1;
        break;
      case 's':
        lat -= 0.1;
        break;
      case 'd':
        lon += 0.1;
        break;
      case 'q':
        return 0;
    }

    // Display the updated GPS coordinates
    printf("Latitude: %.2f\n", lat);
    printf("Longitude: %.2f\n", lon);
  }

  return 0;
}