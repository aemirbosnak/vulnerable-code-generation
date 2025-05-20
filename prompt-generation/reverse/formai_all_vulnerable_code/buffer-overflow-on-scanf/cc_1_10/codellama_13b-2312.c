//Code Llama-13B DATASET v1.0 Category: GPS Navigation Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 100
#define MAX_DESTINATIONS 10

typedef struct {
  char name[MAX_NAME_LEN];
  double latitude;
  double longitude;
} Destination;

void print_destination(Destination *dest) {
  printf("Destination: %s\n", dest->name);
  printf("Latitude: %f\n", dest->latitude);
  printf("Longitude: %f\n", dest->longitude);
}

int main(void) {
  Destination destinations[MAX_DESTINATIONS];
  int num_destinations = 0;

  // Get input from user
  printf("Enter destination names and coordinates (latitude, longitude):\n");
  for (int i = 0; i < MAX_DESTINATIONS; i++) {
    printf("Destination %d: ", i + 1);
    scanf("%s %lf %lf", destinations[i].name, &destinations[i].latitude, &destinations[i].longitude);
    num_destinations++;
  }

  // Print destinations
  for (int i = 0; i < num_destinations; i++) {
    print_destination(&destinations[i]);
  }

  // Calculate distance and time
  double distance = 0;
  double time = 0;
  for (int i = 0; i < num_destinations - 1; i++) {
    double lat1 = destinations[i].latitude;
    double lon1 = destinations[i].longitude;
    double lat2 = destinations[i + 1].latitude;
    double lon2 = destinations[i + 1].longitude;
    double d_lat = lat2 - lat1;
    double d_lon = lon2 - lon1;
    distance += sqrt(d_lat * d_lat + d_lon * d_lon) * 6371; // 6371 is the Earth's radius in km
    time += distance / 100; // 100 km/h is the average speed
  }

  // Print results
  printf("Total distance: %f km\n", distance);
  printf("Total time: %f hours\n", time / 3600);

  return 0;
}