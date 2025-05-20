//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MIN_FLOORS 2
#define MAX_ELEVATORS 4
#define MIN_ELEVATORS 1
#define MAX_WAIT_TIME 10
#define MIN_WAIT_TIME 1

typedef enum {
  UP,
  DOWN,
  IDLE
} ElevatorDirection;

typedef struct {
  int current_floor;
  int destination_floor;
  ElevatorDirection direction;
  int wait_time;
} Elevator;

int main() {
  srand(time(NULL));

  // Initialize the elevator system
  int num_floors = rand() % (MAX_FLOORS - MIN_FLOORS + 1) + MIN_FLOORS;
  int num_elevators = rand() % (MAX_ELEVATORS - MIN_ELEVATORS + 1) + MIN_ELEVATORS;
  Elevator elevators[num_elevators];

  for (int i = 0; i < num_elevators; i++) {
    elevators[i].current_floor = rand() % num_floors;
    elevators[i].destination_floor = -1;
    elevators[i].direction = IDLE;
    elevators[i].wait_time = 0;
  }

  // Run the elevator system until the user quits
  while (1) {
    // Handle user input
    printf("Enter a floor number (-1 to quit): ");
    int floor;
    scanf("%d", &floor);

    if (floor == -1) {
      break;
    }

    // Find the closest elevator to the user's floor
    int closest_elevator_index = -1;
    int closest_elevator_distance = num_floors;

    for (int i = 0; i < num_elevators; i++) {
      int distance = abs(elevators[i].current_floor - floor);

      if (distance < closest_elevator_distance) {
        closest_elevator_index = i;
        closest_elevator_distance = distance;
      }
    }

    // Send the closest elevator to the user's floor
    elevators[closest_elevator_index].destination_floor = floor;
    elevators[closest_elevator_index].direction = floor > elevators[closest_elevator_index].current_floor ? UP : DOWN;

    // Update the elevator system
    for (int i = 0; i < num_elevators; i++) {
      // Move the elevator if it has a destination floor
      if (elevators[i].destination_floor != -1) {
        if (elevators[i].current_floor == elevators[i].destination_floor) {
          elevators[i].destination_floor = -1;
          elevators[i].direction = IDLE;
        } else {
          elevators[i].current_floor += elevators[i].direction == UP ? 1 : -1;
        }
      }

      // Decrement the wait time for each elevator
      if (elevators[i].wait_time > 0) {
        elevators[i].wait_time--;
      }
    }

    // Print the elevator system status
    printf("Elevator system status:\n");

    for (int i = 0; i < num_elevators; i++) {
      printf("Elevator %d: current floor %d, destination floor %d, direction %s, wait time %d\n",
             i, elevators[i].current_floor, elevators[i].destination_floor, elevators[i].direction == UP ? "UP" : elevators[i].direction == DOWN ? "DOWN" : "IDLE", elevators[i].wait_time);
    }
  }

  return 0;
}