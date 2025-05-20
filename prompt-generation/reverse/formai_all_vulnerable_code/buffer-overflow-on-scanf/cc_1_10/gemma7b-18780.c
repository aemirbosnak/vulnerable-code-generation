//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 10
#define MAX_TURN 90

typedef struct Vehicle {
  int x, y, facing;
  int speed, turn;
} Vehicle;

Vehicle vehicle;

void update_vehicle() {
  switch (vehicle.facing) {
    case 0:
      vehicle.x++;
      break;
    case 1:
      vehicle.y++;
      break;
    case 2:
      vehicle.x--;
      break;
    case 3:
      vehicle.y--;
      break;
  }

  vehicle.speed--;

  if (vehicle.speed <= 0) {
    vehicle.speed = 0;
  }
}

void handle_input() {
  char input;

  printf("Enter command (w, a, s, d, q): ");
  scanf("%c", &input);

  switch (input) {
    case 'w':
      vehicle.speed = MAX_SPEED;
      vehicle.facing = 0;
      break;
    case 'a':
      vehicle.turn = MAX_TURN;
      vehicle.facing = 3;
      break;
    case 's':
      vehicle.speed = MAX_SPEED;
      vehicle.facing = 2;
      break;
    case 'd':
      vehicle.turn = MAX_TURN;
      vehicle.facing = 1;
      break;
    case 'q':
      exit(0);
      break;
  }
}

int main() {
  vehicle.x = 0;
  vehicle.y = 0;
  vehicle.facing = 0;
  vehicle.speed = MAX_SPEED;
  vehicle.turn = MAX_TURN;

  while (1) {
    handle_input();
    update_vehicle();
  }

  return 0;
}