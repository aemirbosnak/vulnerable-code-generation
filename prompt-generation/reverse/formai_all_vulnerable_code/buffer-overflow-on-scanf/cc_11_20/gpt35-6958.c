//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {
  int current_lat = 0; // starting latitude
  int current_long = 0; // starting longitude
  int dest_lat, dest_long; // destination latitude and longitude
  int distance_travelled = 0; // keep track of distance travelled
  int distance_to_dest; // distance to destination
  int direction_to_dest; // direction to destination
  int speed = 60; // speed in kph
  int time_elapsed = 0; // keep track of time elapsed
  char direction[4][10] = {"North", "East", "South", "West"}; // direction array
  char option; // for user input

  // get destination latitude and longitude
  printf("Enter destination latitude: ");
  scanf("%d", &dest_lat);
  printf("Enter destination longitude: ");
  scanf("%d", &dest_long);

  // find distance and direction to destination
  distance_to_dest = abs(dest_lat - current_lat) + abs(dest_long - current_long);
  if (dest_lat > current_lat) {
    direction_to_dest = 0;
  } else if (dest_long > current_long) {
    direction_to_dest = 1;
  } else if (dest_lat < current_lat) {
    direction_to_dest = 2;
  } else if (dest_long < current_long) {
    direction_to_dest = 3;
  }

  // simulation loop
  while (distance_to_dest > 0) {
    printf("\n");
    printf("Latitude: %d\n", current_lat);
    printf("Longitude: %d\n", current_long);
    printf("Distance travelled: %dkm\n", distance_travelled);
    printf("Time elapsed: %d minutes\n", time_elapsed);
    printf("Direction: %s\n", direction[direction_to_dest]);

    // check if user wants to change direction
    printf("\nDo you want to change direction? (Y/N): ");
    scanf(" %c", &option);
    if (option == 'Y') {
      printf("Which direction? (N/E/S/W): ");
      scanf(" %c", &option);
      if (option == 'N') {
        direction_to_dest = 0;
      } else if (option == 'E') {
        direction_to_dest = 1;
      } else if (option == 'S') {
        direction_to_dest = 2;
      } else if (option == 'W') {
        direction_to_dest = 3;
      }
    }

    // move towards destination
    if (direction_to_dest == 0) {
      current_lat++;
    } else if (direction_to_dest == 1) {
      current_long++;
    } else if (direction_to_dest == 2) {
      current_lat--;
    } else if (direction_to_dest == 3) {
      current_long--;
    }

    // update distance and time elapsed
    distance_to_dest = abs(dest_lat - current_lat) + abs(dest_long - current_long);
    distance_travelled++;
    time_elapsed += 60 / speed;
  }

  // reached destination
  printf("\nYou have reached your destination!\n");
  printf("Total distance travelled: %dkm\n", distance_travelled);
  printf("Total time elapsed: %d minutes\n", time_elapsed);

  return 0;
}