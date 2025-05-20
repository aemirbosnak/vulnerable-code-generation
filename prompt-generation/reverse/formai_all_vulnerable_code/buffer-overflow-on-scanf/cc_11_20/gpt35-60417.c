//FormAI DATASET v1.0 Category: Robot movement control ; Style: energetic
#include <stdio.h>

int main() {
  
  //Welcome message
  printf("Welcome to Robot Control! Energize your programming skills and get started...\n\n");

  //Movement control commands
  int forward = 1;
  int backward = 0;
  int left = 0;
  int right = 1;
  int up = 1;
  int down = 0;

  //Initial robot position
  int x_pos = 0;
  int y_pos = 0;
  int z_pos = 0;

  printf("Robot initialized at position (%d, %d, %d)\n", x_pos, y_pos, z_pos);
  printf("Get ready to program some high-energy movement commands!\n\n");

  //Energy level
  int energy = 100;

  //Movement loop
  while (energy > 0) {

    //Prompt user for movement command
    printf("Enter a movement command (f = forward, b = backward, l = left, r = right, u = up, d = down): ");
    char command;
    scanf(" %c", &command);

    //Execute movement command
    switch (command) {
      case 'f':
        if (forward) {
          x_pos++;
          printf("Moving forward...\n");
        } else {
          printf("Cannot move forward!\n");
        }
        break;

      case 'b':
        if (backward) {
          x_pos--;
          printf("Moving backward...\n");
        } else {
          printf("Cannot move backward!\n");
        }
        break;

      case 'l':
        if (left) {
          y_pos--;
          printf("Moving left...\n");
        } else {
          printf("Cannot move left!\n");
        }
        break;

      case 'r':
        if (right) {
          y_pos++;
          printf("Moving right...\n");
        } else {
          printf("Cannot move right!\n");
        }
        break;

      case 'u':
        if (up) {
          z_pos++;
          printf("Moving up...\n");
        } else {
          printf("Cannot move up!\n");
        }
        break;

      case 'd':
        if (down) {
          z_pos--;
          printf("Moving down...\n");
        } else {
          printf("Cannot move down!\n");
        }
        break;

      //Invalid movement command
      default:
        printf("Invalid command. Please enter a valid movement command.\n");
        continue; //Restart while loop
    }

    //Decrease energy level
    energy -= 10;
    printf("Energy level: %d\n", energy);

    //Robot reaches maximum energy level
    if (energy == 100) {
      printf("Maximum energy level reached! Back to full power!\n");
    }

    //Robot reaches minimum energy level
    if (energy == 0) {
      printf("Energy levels critical! Robot shutting down...\n");
    }

    //Print new robot position
    printf("Current position: (%d, %d, %d)\n", x_pos, y_pos, z_pos);
    printf("\n");

  }

  //Program ends
  printf("Robot Control program has ended. Thank you for using our service!\n");

  return 0;
}