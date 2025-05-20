//Code Llama-13B DATASET v1.0 Category: Elevator Simulation ; Style: enthusiastic
/*
 * Elevator Simulation
 *
 * This program simulates the operation of an elevator in a building.
 * It takes in the number of floors and the time interval between
 * each floor visit as inputs.
 *
 * Author: [Your Name]
 * Date:   [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define MAX_FLOORS 100
#define TIME_INTERVAL 5

// Function prototypes
void print_floor(int floor);
void simulate_elevator(int floors, int interval);

int main() {
  int floors, interval;

  printf("Welcome to the Elevator Simulation!\n");
  printf("How many floors in your building? ");
  scanf("%d", &floors);

  printf("How many seconds between each floor visit? ");
  scanf("%d", &interval);

  simulate_elevator(floors, interval);

  return 0;
}

void print_floor(int floor) {
  printf("Elevator is now on floor %d\n", floor);
}

void simulate_elevator(int floors, int interval) {
  int current_floor = 1, time_elapsed = 0;
  srand(time(NULL));

  while (current_floor <= floors) {
    print_floor(current_floor);
    time_elapsed += interval;

    // Randomly generate the next floor
    int next_floor = rand() % floors + 1;

    // Check if the next floor is the same as the current floor
    if (next_floor == current_floor) {
      next_floor = (current_floor == floors) ? 1 : current_floor + 1;
    }

    current_floor = next_floor;
  }

  printf("Elevator has completed all %d floors in %d seconds\n", floors, time_elapsed);
}