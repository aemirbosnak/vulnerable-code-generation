//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define NUM_DRONES 4
#define MAX_DISTANCE 100

typedef enum { UP, DOWN, LEFT, RIGHT } Direction;

typedef struct {
  int x, y;
} Position;

typedef struct {
  int id;
  Position current_position;
} Drone;

// Generate a random position within the range 0 to MAX_DISTANCE for initialization
Position get_random_position() {
  Position position;
  position.x = rand() % MAX_DISTANCE;
  position.y = rand() % MAX_DISTANCE;
  return position;
}

// Move the drone in the given direction by one unit and update its position
void move_drone(Drone *drone, Direction direction) {
  switch (direction) {
    case UP:
      drone->current_position.y++;
      break;
    case DOWN:
      drone->current_position.y--;
      break;
    case LEFT:
      drone->current_position.x--;
      break;
    case RIGHT:
      drone->current_position.x++;
      break;
  }
}

// Print the current position of all drones
void print_drone_positions(Drone drones[NUM_DRONES]) {
  printf("Current drone positions:\n");
  for (int i = 0; i < NUM_DRONES; i++) {
    printf("Drone %d: (%d, %d)\n", drones[i].id, drones[i].current_position.x,
           drones[i].current_position.y);
  }
}

// Main function to control the drones
int main() {
  // Initialize drones with random positions
  srand(time(NULL));
  Drone drones[NUM_DRONES];
  for (int i = 1; i <= NUM_DRONES; i++) {
    drones[i - 1].id = i;
    drones[i - 1].current_position = get_random_position();
  }
  
  // Print initial drone positions
  print_drone_positions(drones);

  // Take input from user to move the drones
  while (1) {
    int drone_id;
    printf("\nEnter drone id (1-%d): ", NUM_DRONES);
    scanf("%d", &drone_id);
    if (drone_id < 1 || drone_id > NUM_DRONES) {
      printf("Invalid drone id. Try again.\n");
      continue;
    }

    char direction_input[10];
    printf("Enter direction (up/down/left/right): ");
    scanf("%s", direction_input);
    Direction direction;
    if (strcmp(direction_input, "up") == 0) {
      direction = UP;
    } else if (strcmp(direction_input, "down") == 0) {
      direction = DOWN;
    } else if (strcmp(direction_input, "left") == 0) {
      direction = LEFT;
    } else if (strcmp(direction_input, "right") == 0) {
      direction = RIGHT;
    } else {
      printf("Invalid direction. Try again.\n");
      continue;
    }

    // Move the selected drone in the specified direction
    move_drone(&drones[drone_id - 1], direction);

    // Print current drone positions
    print_drone_positions(drones);
  }
  return 0;
}