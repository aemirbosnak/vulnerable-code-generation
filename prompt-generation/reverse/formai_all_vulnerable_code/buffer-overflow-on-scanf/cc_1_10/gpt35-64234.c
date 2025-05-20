//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Cryptic
// The following program is a cryptic C remote control vehicle simulation example.
#include<stdio.h>

// Function to move vehicle forward
void fwd(int speed) {
  printf("Vehicle moves forward at speed %d\n", speed);
}

// Function to move vehicle backward
void bwd(int speed) {
  printf("Vehicle moves backward at speed %d\n", speed);
}

// Function to turn vehicle left
void left(int degrees) {
  printf("Vehicle turns left by %d degrees\n", degrees);
}

// Function to turn vehicle right
void right(int degrees) {
  printf("Vehicle turns right by %d degrees\n", degrees);
}

int main() {
  int direction = 0;
  printf("Welcome to remote control vehicle simulation\n");

  // Continue taking input from user until they exit
  while(1) {
    printf("Enter command (f,b,l,r,q): ");
    char input;
    scanf(" %c", &input);
    printf("\n");

    switch(input) {
      case 'f':
        fwd(10);
        break;

      case 'b':
        bwd(8);
        break;

      case 'l':
        left(45);
        break;

      case 'r':
        right(90);
        break;

      case 'q':
        printf("Exiting program...\n");
        exit(0);

      default:
        printf("Invalid command!\n");
        break;
    }
  }

  return 0;
}