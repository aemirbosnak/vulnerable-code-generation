//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_FLOORS 10

int current_floor = 1;  // current floor
int destination_floor;  // destination floor
int total_stops = 0;    // total number of stops made by elevator
bool direction_up = true;  // true if elevator moves up, false if down

void open_doors() {
  printf("Ding! Doors opening.\n");
  printf("Welcome to floor %d.\n", current_floor);
  printf("Please enter the elevator.\n");
}

void close_doors() {
  printf("Ding! Doors closing.\n");
}

void move_to_next_floor() {
  if (direction_up) {
    current_floor++;
  } else {
    current_floor--;
  }
  printf("Elevator moving to floor %d...\n", current_floor);
}

int get_random_floor() {
  int random_floor = rand() % MAX_FLOORS + 1;
  while (random_floor == current_floor) {
    random_floor = rand() % MAX_FLOORS + 1;
  }
  return random_floor;
}

void simulate_elevator() {
  srand(time(NULL));

  printf("Elevator simulation starting...\n");
  printf("Elevator is currently on floor %d.\n", current_floor);

  while (true) {
    int choice;
  
    // Prompt user
    printf("\nPlease select an option:\n");
    printf("1. Move elevator to a specific floor.\n");
    printf("2. Simulate random elevator ride.\n");
    printf("3. Quit simulation.\n");
    scanf("%d", &choice);

    if (choice == 1) {
      printf("Enter destination floor: ");
      scanf("%d", &destination_floor);
      
      // Ensure destination floor is valid
      if (destination_floor > MAX_FLOORS || destination_floor < 1) {
        printf("Invalid floor entered.\n");
        continue;
      }

      // Move elevator to destination floor
      while (current_floor != destination_floor) {
        move_to_next_floor();
        total_stops++;
      }

      open_doors();
      close_doors();
    } else if (choice == 2) {
      destination_floor = get_random_floor();

      // Travel to random floor
      while (current_floor != destination_floor) {
        move_to_next_floor();
        total_stops++;
      }
      
      open_doors();
      close_doors();
    } else if (choice == 3) {
      printf("\nElevator simulation ending...\n");
      printf("Elevator made %d stops in total.\n", total_stops);
      break;
    } else {
      printf("Invalid choice selected. Please try again.\n");
    }
  }
}

int main() {
  simulate_elevator();  
  
  return 0;
}