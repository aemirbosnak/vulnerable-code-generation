//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 10
#define TURN_RADIUS 50

typedef struct Car {
  int x, y;
  int direction;
  int speed;
} Car;

Car car;

void moveCar() {
  switch (car.direction) {
    case 0:
      car.x++;
      break;
    case 1:
      car.y++;
      break;
    case 2:
      car.x--;
      break;
    case 3:
      car.y--;
      break;
  }

  car.speed++;

  if (car.speed > MAX_SPEED) {
    car.speed = MAX_SPEED;
  }
}

void turnCar(int angle) {
  car.direction = (car.direction + angle) % 4;
  car.speed = 0;
}

int main() {
  car.x = 0;
  car.y = 0;
  car.direction = 0;
  car.speed = 0;

  while (1) {
    printf("Enter command (move, turn, stop): ");
    char command[20];
    scanf("%s", command);

    if (strcmp(command, "move") == 0) {
      moveCar();
    } else if (strcmp(command, "turn") == 0) {
      int angle;
      printf("Enter angle of turn: ");
      scanf("%d", &angle);
      turnCar(angle);
    } else if (strcmp(command, "stop") == 0) {
      car.speed = 0;
    } else {
      printf("Invalid command.\n");
    }
  }

  return 0;
}