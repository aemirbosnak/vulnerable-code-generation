//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOOR 10
#define MAX_PASSENGERS 5

typedef struct Passenger {
  char name[20];
  int floor;
  int destination;
} Passenger;

void simulate_elevator(Passenger *passengers, int num_passengers) {
  // Randomly select the destination floor for each passenger
  for (int i = 0; i < num_passengers; i++) {
    passengers[i].destination = rand() % MAX_FLOOR + 1;
  }

  // Create a queue of passengers waiting on each floor
  int floors[MAX_FLOOR] = {0};
  for (int i = 0; i < num_passengers; i++) {
    floors[passengers[i].floor]++;
  }

  // Simulate the elevator moving between floors
  int current_floor = 1;
  time_t start_time = time(NULL);
  while (current_floor != MAX_FLOOR || time(NULL) - start_time < 5) {
    // Check if the elevator is at the destination floor for any passenger
    for (int i = 0; i < num_passengers; i++) {
      if (current_floor == passengers[i].destination) {
        printf("%s has reached floor %d.\n", passengers[i].name, current_floor);
        floors[passengers[i].floor]--;
        passengers[i].destination = -1;
      }
    }

    // Move the elevator to the next floor
    current_floor++;
    if (floors[current_floor] > 0) {
      current_floor--;
    }

    // Sleep for a random amount of time
    sleep(rand() % 2);
  }

  // Print the final status of the elevator and passengers
  printf("The elevator has reached the top floor.\n");
  for (int i = 0; i < num_passengers; i++) {
    if (passengers[i].destination != -1) {
      printf("%s has not reached their destination.\n", passengers[i].name);
    }
  }
}

int main() {
  // Create an array of passengers
  Passenger passengers[MAX_PASSENGERS];

  // Simulate the elevator
  simulate_elevator(passengers, MAX_PASSENGERS);

  return 0;
}