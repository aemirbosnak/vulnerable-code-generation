//Gemma-7B DATASET v1.0 Category: Drone Remote Control ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DRONE_MAX_SPEED 100

typedef struct Drone {
  int x, y, z;
  int speed;
  char direction;
} Drone;

Drone drone;

void moveDrone(char direction, int speed) {
  switch (direction) {
    case 'f':
      drone.x += speed;
      break;
    case 'b':
      drone.x -= speed;
      break;
    case 'l':
      drone.y += speed;
      break;
    case 'r':
      drone.y -= speed;
      break;
    case 'u':
      drone.z += speed;
      break;
    case 'd':
      drone.z -= speed;
      break;
  }

  drone.speed = speed;
  drone.direction = direction;
}

int main() {
  drone.x = 0;
  drone.y = 0;
  drone.z = 0;
  drone.speed = 0;
  drone.direction = 'n';

  char input;
  int speed;

  printf("Enter command (f/b/l/r/u/d/stop): ");
  scanf("%c", &input);

  if (input == 'stop') {
    drone.speed = 0;
    drone.direction = 'n';
  } else {
    printf("Enter speed (1-100): ");
    scanf("%d", &speed);

    moveDrone(input, speed);
  }

  return 0;
}