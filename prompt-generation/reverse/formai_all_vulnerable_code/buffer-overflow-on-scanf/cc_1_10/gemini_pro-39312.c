//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Linus Torvalds
// Remote Control Vehicle Simulation

#include <stdio.h>
#include <stdlib.h>

// Vehicle state
enum {
  STOPPED,
  MOVING
};

// Remote control commands
enum {
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT,
  STOP
};

// Vehicle structure
struct vehicle {
  int state;
  int x;
  int y;
};

// Initialize the vehicle
void init_vehicle(struct vehicle *v) {
  v->state = STOPPED;
  v->x = 0;
  v->y = 0;
}

// Process remote control command
void process_command(struct vehicle *v, int command) {
  switch (command) {
    case FORWARD:
      if (v->state == STOPPED) {
        v->state = MOVING;
      }
      v->y++;
      break;
    case BACKWARD:
      if (v->state == STOPPED) {
        v->state = MOVING;
      }
      v->y--;
      break;
    case LEFT:
      if (v->state == STOPPED) {
        v->state = MOVING;
      }
      v->x--;
      break;
    case RIGHT:
      if (v->state == STOPPED) {
        v->state = MOVING;
      }
      v->x++;
      break;
    case STOP:
      v->state = STOPPED;
      break;
  }
}

// Print the vehicle state
void print_vehicle(struct vehicle *v) {
  printf("Vehicle state: %s\n", v->state == STOPPED ? "STOPPED" : "MOVING");
  printf("Vehicle position: (%d, %d)\n", v->x, v->y);
}

// Main function
int main(void) {
  // Initialize the vehicle
  struct vehicle v;
  init_vehicle(&v);

  // Process remote control commands
  while (1) {
    int command;
    scanf("%d", &command);

    process_command(&v, command);

    // Print the vehicle state
    print_vehicle(&v);
  }

  return 0;
}