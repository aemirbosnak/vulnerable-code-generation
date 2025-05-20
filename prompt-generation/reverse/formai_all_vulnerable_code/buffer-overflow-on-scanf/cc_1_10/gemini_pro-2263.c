//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int speed;
  int direction;
} Car;

Car car;

void initCar() {
  car.speed = 0;
  car.direction = 0;
}

void printCar() {
  printf("Speed: %d\nDirection: %d\n", car.speed, car.direction);
}

void accelerate() {
  car.speed++;
}

void decelerate() {
  car.speed--;
}

void turnLeft() {
  car.direction--;
}

void turnRight() {
  car.direction++;
}

int main() {
  initCar();
  printCar();

  char command[10];
  while (strcmp(command, "quit") != 0) {
    printf("Enter command (accelerate, decelerate, turn left, turn right, quit): ");
    scanf("%s", command);

    if (strcmp(command, "accelerate") == 0) {
      accelerate();
    } else if (strcmp(command, "decelerate") == 0) {
      decelerate();
    } else if (strcmp(command, "turn left") == 0) {
      turnLeft();
    } else if (strcmp(command, "turn right") == 0) {
      turnRight();
    } else if (strcmp(command, "print") == 0) {
      printCar();
    }
  }

  return 0;
}