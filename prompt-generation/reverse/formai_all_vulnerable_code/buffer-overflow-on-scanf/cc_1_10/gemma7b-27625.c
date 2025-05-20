//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define TURN_RADIUS 50

typedef struct Car {
  int x, y, direction, speed;
  char name[20];
} Car;

Car createCar(char *name) {
  Car car;
  car.x = 0;
  car.y = 0;
  car.direction = 0;
  car.speed = 0;
  strcpy(car.name, name);
  return car;
}

void moveCar(Car *car, int direction, int speed) {
  switch (direction) {
    case 0:
      car->x++;
      break;
    case 1:
      car->y++;
      break;
    case 2:
      car->x--;
      break;
    case 3:
      car->y--;
      break;
  }

  car->speed = speed;
  car->direction = direction;
}

void turnCar(Car *car, int angle) {
  int newDirection = (car->direction + angle) % 4;
  car->direction = newDirection;
  car->speed = 0;
}

int main() {
  Car myCar = createCar("My Car");

  while (1) {
    printf("Enter command (s/n/t/r/q): ");
    char command;
    scanf(" %c", &command);

    switch (command) {
      case 's':
        moveCar(&myCar, 0, MAX_SPEED);
        break;
      case 'n':
        moveCar(&myCar, 1, MAX_SPEED);
        break;
      case 't':
        moveCar(&myCar, 2, MAX_SPEED);
        break;
      case 'r':
        moveCar(&myCar, 3, MAX_SPEED);
        break;
      case 'q':
        exit(0);
    }

    printf("Car position: (%d, %d)\n", myCar.x, myCar.y);
    printf("Car direction: %d\n", myCar.direction);
  }

  return 0;
}