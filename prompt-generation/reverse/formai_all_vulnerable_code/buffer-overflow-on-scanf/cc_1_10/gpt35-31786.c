//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: portable
#include <stdio.h>
#include <stdbool.h>

enum Direction {
  STOP,
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT,
};

struct Vehicle {
  int x;
  int y;
  enum Direction dir;
};

// Simulate moving the vehicle in a direction
void move_vehicle(struct Vehicle *v, enum Direction dir) {
  switch (dir) {
    case STOP:
      printf("Vehicle stopped.\n");
      break;
    case FORWARD:
      printf("Vehicle moving forward.\n");
      v->y++;
      break;
    case BACKWARD:
      printf("Vehicle moving backward.\n");
      v->y--;
      break;
    case LEFT:
      printf("Vehicle turning left.\n");
      v->x--;
      break;
    case RIGHT:
      printf("Vehicle turning right.\n");
      v->x++;
      break;
  }
}

int main() {
  struct Vehicle my_vehicle = {0, 0, STOP};
  bool running = true;
  char input;

  printf("Remote Control Vehicle Simulator\n");
  printf("Commands:\n");
  printf("  w: move forward\n");
  printf("  s: move backward\n");
  printf("  a: turn left\n");
  printf("  d: turn right\n");
  printf("  q: quit\n\n");

  while(running) {
    printf("Vehicle at (%d, %d)\n", my_vehicle.x, my_vehicle.y);

    printf("Enter command: ");
    scanf(" %c", &input);

    switch(input) {
      case 'w':
        move_vehicle(&my_vehicle, FORWARD);
        break;
      case 's':
        move_vehicle(&my_vehicle, BACKWARD);
        break;
      case 'a':
        move_vehicle(&my_vehicle, LEFT);
        break;
      case 'd':
        move_vehicle(&my_vehicle, RIGHT);
        break;
      case 'q':
        printf("Exiting...\n");
        running = false;
        break;
      default:
        printf("Invalid command\n");
        break;
    }
  }
  
  return 0;
}