//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  int x;
  int y;
  int z;
} Point;

typedef struct {
  Point position;
  float speed;
  float heading;
} Drone;

int main() {
  Drone drone = {
    .position = {0, 0, 0},
    .speed = 0.0f,
    .heading = 0.0f
  };

  char command;
  while (scanf(" %c", &command) == 1) {
    switch (command) {
      case 'U':
        drone.position.z += 1;
        break;
      case 'D':
        drone.position.z -= 1;
        break;
      case 'F':
        drone.position.x += cos(drone.heading) * drone.speed;
        drone.position.y += sin(drone.heading) * drone.speed;
        break;
      case 'B':
        drone.position.x -= cos(drone.heading) * drone.speed;
        drone.position.y -= sin(drone.heading) * drone.speed;
        break;
      case 'L':
        drone.heading -= M_PI / 2.0f;
        break;
      case 'R':
        drone.heading += M_PI / 2.0f;
        break;
      case 'S':
        drone.speed += 0.1f;
        break;
      case 'A':
        drone.speed -= 0.1f;
        break;
      case 'P':
        printf("Position: (%d, %d, %d)\n", drone.position.x, drone.position.y, drone.position.z);
        printf("Speed: %.2f\n", drone.speed);
        printf("Heading: %.2f\n", drone.heading);
        break;
      default:
        printf("Invalid command: %c\n", command);
    }
  }

  return 0;
}