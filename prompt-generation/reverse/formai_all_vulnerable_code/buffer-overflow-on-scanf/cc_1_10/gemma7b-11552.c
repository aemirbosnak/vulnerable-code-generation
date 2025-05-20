//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MAX_TURN 45

typedef struct Vehicle {
  int x, y, direction, speed;
} Vehicle;

void moveVehicle(Vehicle *v) {
  switch (v->direction) {
    case 0:
      v->x++;
      break;
    case 1:
      v->y++;
      break;
    case 2:
      v->x--;
      break;
    case 3:
      v->y--;
      break;
  }
  v->speed++;
  if (v->speed > MAX_SPEED) {
    v->speed = MAX_SPEED;
  }
}

int main() {
  Vehicle car = {0, 0, 0, 0};

  // Simulate remote control
  while (1) {
    char input;

    printf("Enter command (forward, left, right, back, stop): ");
    scanf("%c", &input);

    switch (input) {
      case 'f':
        moveVehicle(&car);
        break;
      case 'l':
        car.direction--;
        if (car.direction < 0) {
          car.direction = MAX_TURN - 1;
        }
        break;
      case 'r':
        car.direction++;
        if (car.direction >= MAX_TURN) {
          car.direction = 0;
        }
        break;
      case 'b':
        moveVehicle(&car);
        car.direction = (car.direction + 1) % MAX_TURN;
        break;
      case 's':
        car.speed = 0;
        break;
    }

    // Print current position
    printf("Position: (%d, %d)\n", car.x, car.y);
  }

  return 0;
}