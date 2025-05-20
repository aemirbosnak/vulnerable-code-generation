//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: happy
#include <stdio.h>
#define MAX_SPEED 100
#define MIN_SPEED 0

typedef struct {
  int speed;
  int direction;
} Car;

void accelerate(Car *car, int amount) {
  car->speed += amount;
  if (car->speed > MAX_SPEED) {
    car->speed = MAX_SPEED;
  }
}

void decelerate(Car *car, int amount) {
  car->speed -= amount;
  if (car->speed < MIN_SPEED) {
    car->speed = MIN_SPEED;
  }
}

void turn(Car *car, int amount) {
  car->direction += amount;
  if (car->direction < 0) {
    car->direction += 360;
  } else if (car->direction >= 360) {
    car->direction -= 360;
  }
}

int main() {
  Car car;
  car.speed = 0;
  car.direction = 0;

  printf("Welcome to the remote control car simulator!\n");

  char command;
  int amount;

  do {
    printf("\nEnter a command (a/d/w/s/q): ");
    scanf(" %c", &command);

    switch (command) {
      case 'a':  // accelerate
        printf("Enter an amount to accelerate by: ");
        scanf("%d", &amount);
        accelerate(&car, amount);
        printf("Car is now accelerating at %d MPH.\n", car.speed);
        break;
      case 'd':  // decelerate
        printf("Enter an amount to decelerate by: ");
        scanf("%d", &amount);
        decelerate(&car, amount);
        printf("Car is now decelerating at %d MPH.\n", car.speed);
        break;
      case 'w':  // turn left
        printf("Enter an amount to turn left by: ");
        scanf("%d", &amount);
        turn(&car, amount);
        printf("Car is now facing %d degrees.\n", car.direction);
        break;
      case 's':  // turn right
        printf("Enter an amount to turn right by: ");
        scanf("%d", &amount);
        turn(&car, -amount);
        printf("Car is now facing %d degrees.\n", car.direction);
        break;
      case 'q':  // quit
        printf("Exiting the remote control car simulator.\n");
        break;
    }
  } while (command != 'q');

  return 0;
}