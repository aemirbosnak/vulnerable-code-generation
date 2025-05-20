//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPEED 50
#define MIN_SPEED 0
#define MAX_ANGLE 90
#define MIN_ANGLE -90

int speed = MIN_SPEED;
int angle = 0;

void checkInput(char* input) {
  if (strncmp(input, "speed", 5) == 0) {
    int newSpeed = atoi(input + 6);
    if (newSpeed <= MAX_SPEED && newSpeed >= MIN_SPEED) {
      speed = newSpeed;
      printf("\nSpeed set to: %d\n", speed);
    } else {
      printf("\nInvalid speed entered.\n");
    }
  } else if (strncmp(input, "angle", 5) == 0) {
    int newAngle = atoi(input + 6);
    if (newAngle <= MAX_ANGLE && newAngle >= MIN_ANGLE) {
      angle = newAngle;
      printf("\nAngle set to: %d\n", angle);
    } else {
      printf("\nInvalid angle entered.\n");
    }
  } else if (strncmp(input, "move", 4) == 0) {
    printf("\nMoving at speed %d and angle %d.\n", speed, angle);
  } else if (strncmp(input, "help", 4) == 0) {
    printf("\nAvailable commands:\n");
    printf("speed <integer> - sets speed (0-50)\n");
    printf("angle <integer> - sets angle (-90-90)\n");
    printf("move - moves vehicle at current speed and angle\n");
    printf("help - displays this help message\n");
  } else {
    printf("\nInvalid command. Type 'help' for a list of valid commands.\n");
  }
}

int main() {
  char input[256];

  printf("Welcome to the Remote Control Vehicle Simulator!\n\n");
  printf("Type 'help' for a list of available commands.\n\n");

  while (1) {
    printf("> ");
    scanf(" %[^\n]", input);
    checkInput(input);
  }

  return 0;
}