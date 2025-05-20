//Code Llama-13B DATASET v1.0 Category: Elevator Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 10
#define FLOOR_DELAY 2

int main() {
  int i, j;
  int floor;
  int direction;
  int current_floor = 0;
  int destination_floor = 0;
  char *floor_names[NUM_FLOORS] = {
    "Ground Floor",
    "First Floor",
    "Second Floor",
    "Third Floor",
    "Fourth Floor",
    "Fifth Floor",
    "Sixth Floor",
    "Seventh Floor",
    "Eighth Floor",
    "Ninth Floor",
    "Tenth Floor"
  };

  printf("Welcome to the Elevator Simulation!\n");
  printf("You can enter a destination floor number or 'q' to quit.\n");

  while (1) {
    printf("Current floor: %s\n", floor_names[current_floor]);
    printf("Enter destination floor number: ");
    scanf("%d", &destination_floor);

    if (destination_floor == 'q') {
      break;
    }

    direction = (destination_floor > current_floor) ? 1 : -1;

    for (i = current_floor; i != destination_floor; i += direction) {
      current_floor = i;
      printf("Moving from %s to %s...\n", floor_names[current_floor], floor_names[current_floor + direction]);
      sleep(FLOOR_DELAY);
    }

    current_floor = destination_floor;
    printf("Arrived at %s!\n", floor_names[current_floor]);
  }

  printf("Bye bye!\n");

  return 0;
}