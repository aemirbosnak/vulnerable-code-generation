//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define TURN_RADIUS 50

typedef struct Car
{
  int x, y, facing, speed;
} Car;

Car car;

void moveCar(int direction, int power)
{
  switch (direction)
  {
    case 0:
      car.x++;
      break;
    case 1:
      car.x--;
      break;
    case 2:
      car.y++;
      break;
    case 3:
      car.y--;
      break;
  }

  car.speed = power;
}

void turnCar(int angle)
{
  car.facing += angle;
  if (car.facing > 360)
    car.facing = 0;
  else if (car.facing < 0)
    car.facing = 360;
}

int main()
{
  car.x = 0;
  car.y = 0;
  car.facing = 0;
  car.speed = 0;

  while (1)
  {
    int direction, power, angle;

    printf("Enter direction (0-3): ");
    scanf("%d", &direction);

    printf("Enter power (0-10): ");
    scanf("%d", &power);

    printf("Enter angle (optional): ");
    scanf("%d", &angle);

    moveCar(direction, power);
    if (angle)
      turnCar(angle);

    printf("Car position: (%d, %d)\n", car.x, car.y);
    printf("Car facing: %d\n", car.facing);
  }

  return 0;
}