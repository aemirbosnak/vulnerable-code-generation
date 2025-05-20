//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: beginner-friendly
#include <stdio.h>

void flyForward(int speed);
void flyBackward(int speed);
void flyLeft(int speed);
void flyRight(int speed);
void flyUp(int speed);
void flyDown(int speed);
void land();

int main() {
  int altitude = 0;
  int speed = 0;
  char command;

  printf("Welcome to the C Drone Remote Control\n");

  do {
    printf("\nCurrent Altitude: %d meters\n", altitude);
    printf("Current Speed: %d kph\n", speed);

    printf("What would you like to do?\n");
    printf("f = fly forward\n");
    printf("b = fly backward\n");
    printf("l = fly left\n");
    printf("r = fly right\n");
    printf("u = fly up\n");
    printf("d = fly down\n");
    printf("n = land\n");
    printf("q = quit\n");

    scanf(" %c", &command);

    switch (command) {
      case 'f':
        flyForward(speed);
        break;

      case 'b':
        flyBackward(speed);
        break;

      case 'l':
        flyLeft(speed);
        break;

      case 'r':
        flyRight(speed);
        break;

      case 'u':
        flyUp(speed);
        altitude += 10;
        break;

      case 'd':
        flyDown(speed);
        altitude -= 10;
        break;

      case 'n':
        land();
        altitude = 0;
        speed = 0;
        break;

      case 'q':
        printf("Shutting down...\n");
        break;

      default:
        printf("Invalid command\n");
        break;
    }

  } while (command != 'q');

  return 0;
}

void flyForward(int speed) {
  printf("Flying forward at %d kph\n", speed);
}

void flyBackward(int speed) {
  printf("Flying backward at %d kph\n", speed);
}

void flyLeft(int speed) {
  printf("Flying left at %d kph\n", speed);
}

void flyRight(int speed) {
  printf("Flying right at %d kph\n", speed);
}

void flyUp(int speed) {
  printf("Flying up at %d kph\n", speed);
}

void flyDown(int speed) {
  printf("Flying down at %d kph\n", speed);
}

void land() {
  printf("Landing...\n");
}