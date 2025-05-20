//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: ultraprecise
#include <stdio.h> 

#define ELEVATOR_CAPACITY 10 
#define MAX_FLOORS 20 

// Declare variables 
int pickups[MAX_FLOORS], dropoffs[MAX_FLOORS], direction[MAX_FLOORS]; 
int n_pickups = 0, n_dropoffs = 0; 
int floors[MAX_FLOORS] = {0}; 
int current_floor = 1, num_passengers = 0; 
int moving_up = 1, moving_down = 0; 
int elevator_stopped = 1; 

int main() { 
  printf("Welcome to the Elevator Simulator\n"); 

  // Get user input
  while (1) { 
    int floor;
    printf("Enter pickup floor (or -1 to exit): "); 
    scanf("%d", &floor); 

    if (floor < -1 || floor >= MAX_FLOORS) { // Invalid input 
      printf("Invalid floor. Try again.\n"); 
    } else if (floor == -1) { // Exit 
      break; 
    } else { 
      printf("Enter pickup direction (0 for down, 1 for up): "); 
      scanf("%d", &direction[n_pickups]); 

      if (direction[n_pickups] != 0 && direction[n_pickups] != 1) { // Invalid input 
        printf("Invalid direction. Try again.\n"); 
      } else { 
        pickups[n_pickups] = floor; 
        n_pickups++; 
      } 
    } 
  } 

  // Run the simulation 
  while (1) { 
    // Check if there are any pickups or dropoffs at the current floor 
    for (int i = 0; i < n_pickups; i++) { 
      if (pickups[i] == current_floor && direction[i] == moving_up) { 
        floors[current_floor] = 1; 
        num_passengers++; 
      } 
    } 

    for (int i = 0; i < n_dropoffs; i++) { 
      if (dropoffs[i] == current_floor) { 
        floors[current_floor] = 0; 
        num_passengers--; 
      } 
    } 

    // Move the elevator 
    if (moving_up) { 
      current_floor++; 
    } else if (moving_down) { 
      current_floor--; 
    } 

    printf("Current floor: %d\n", current_floor); 

    // Check if the elevator has reached the top floor or bottom floor 
    if (current_floor == MAX_FLOORS) { 
      moving_up = 0; 
      moving_down = 1; 
    } else if (current_floor == 1) { 
      moving_up = 1; 
      moving_down = 0; 
    } 

    // Determine if the elevator should stop 
    if (!elevator_stopped) { 
      // Check if there are any passengers going in the current direction 
      for (int i = 0; i < n_pickups; i++) { 
        if (pickups[i] == current_floor && direction[i] == moving_up && num_passengers < ELEVATOR_CAPACITY) { 
          elevator_stopped = 1; 
          break; 
        } else if (pickups[i] == current_floor && direction[i] == moving_down && num_passengers < ELEVATOR_CAPACITY) { 
          elevator_stopped = 1; 
          break; 
        } 
      } 

      // Check if there are any passengers getting off at the current floor 
      for (int i = 0; i < n_dropoffs; i++) { 
        if (dropoffs[i] == current_floor) { 
          elevator_stopped = 1; 
          break; 
        } 
      } 
    } 

    // Stop the elevator if necessary 
    if (elevator_stopped) { 
      printf("Elevator stopped at floor %d\n", current_floor); 
      // Get user input 
      while (1) { 
        int floor; 
        printf("Enter dropoff floor (or -1 to continue): "); 
        scanf("%d", &floor); 

        if (floor < -1 || floor >= MAX_FLOORS) { // Invalid input 
          printf("Invalid floor. Try again.\n"); 
        } else if (floor == -1) { // Continue 
          break; 
        } else { 
          dropoffs[n_dropoffs] = floor; 
          n_dropoffs++; 
        } 
      } 

      // Clear the floors array 
      for (int i = 0; i < MAX_FLOORS; i++) { 
        floors[i] = 0; 
      } 

      // Set elevator_stopped to 0 
      elevator_stopped = 0; 
    } 
  } 

  return 0; 
}