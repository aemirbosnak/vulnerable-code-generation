//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SPEED 10
#define MAX_ANGLE 45

typedef struct {
  double x;
  double y;
  double angle;
} Position;

typedef struct {
  double speed;
  double angle;
} Command;

Position updatePosition(Position position, Command command) {
  double dx = command.speed * cos(command.angle * M_PI / 180);
  double dy = command.speed * sin(command.angle * M_PI / 180);
  position.x += dx;
  position.y += dy;
  position.angle += command.angle;
  return position;
}

void printPosition(Position position) {
  printf("Position: (%.2f, %.2f, %.2f)\n", position.x, position.y, position.angle);
}

int main() {
  Position position = {0, 0, 0};
  Command command;
  while (1) {
    printf("Enter speed (0-10): ");
    scanf("%lf", &command.speed);
    if (command.speed < 0 || command.speed > MAX_SPEED) {
      printf("Invalid speed\n");
      continue;
    }
    printf("Enter angle (-45-45): ");
    scanf("%lf", &command.angle);
    if (command.angle < -MAX_ANGLE || command.angle > MAX_ANGLE) {
      printf("Invalid angle\n");
      continue;
    }
    position = updatePosition(position, command);
    printPosition(position);
  }
  return 0;
}