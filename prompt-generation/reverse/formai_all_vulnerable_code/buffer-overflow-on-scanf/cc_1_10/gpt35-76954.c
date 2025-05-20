//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define constants for the drone's movement
#define FORWARD 'w'
#define BACKWARD 's'
#define LEFT 'a'
#define RIGHT 'd'
#define UP 'u'
#define DOWN 'j'

// Define constants for settings
#define SPEED 'p'
#define EXIT 'q'

int main() {
  char input;
  int speed = 50; // default speed is 50%

  // Display an introductory message
  printf("***Drone Control***\n");
  printf("Use 'w', 'a', 's', 'd' to move the drone\n");
  printf("Use 'u' to move up and 'j' to move down\n");
  printf("Use 'p' to adjust speed\n");
  printf("Use 'q' to exit\n");

  // Loop indefinitely to accept input
  while(1) {
    printf("\nEnter command: ");
    scanf(" %c", &input);

    // Check for the various available commands
    if(input == FORWARD) {
      printf("Moving forward\n");
    } else if(input == BACKWARD) {
      printf("Moving backward\n");
    } else if(input == LEFT) {
      printf("Moving left\n");
    } else if(input == RIGHT) {
      printf("Moving right\n");
    } else if(input == UP) {
      printf("Moving up\n");
    } else if(input == DOWN) {
      printf("Moving down\n");
    } else if(input == SPEED) {
      printf("Enter new speed (0-100): ");
      scanf("%d", &speed);
      printf("Speed set to %d%%\n", speed);
    } else if(input == EXIT) {
      printf("Exiting...\n");
      break;
    } else {
      printf("Invalid command\n");
    }
  }

  return 0;
}