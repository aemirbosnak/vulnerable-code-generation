//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: retro
#include <stdio.h>

// Define actions
#define MOVE_FORWARD 'w'
#define MOVE_BACKWARD 's'
#define TURN_LEFT 'a'
#define TURN_RIGHT 'd'
#define HOVER 'h'

// Define commands
#define COMMAND_ONE '1'
#define COMMAND_TWO '2'
#define COMMAND_THREE '3'

// Initialize drone position
int xPos = 0;
int yPos = 0;

// Function to print drone position
void printPosition() {
  printf("Drone position: (%d, %d)\n", xPos, yPos);
}

// Main function
int main() {
  printf("RETRO DRONE REMOTE CONTROL\n\n");

  printf("Use WASD keys to move the drone. Press 'h' to hover in place.\n");
  printf("Press '1', '2', or '3' to execute a command.\n");
  printf("Commands:\n");
  printf("1. Move to (5, 5)\n");
  printf("2. Move to (10, 10)\n");
  printf("3. Move in a square pattern (0, 0) to (5, 0) to (5, 5) to (0, 5)\n\n");

  printPosition(); // Initial position

  // Input loop
  char input;
  do {
    scanf("%c", &input);

    // Handle movement commands
    switch(input) {
      case MOVE_FORWARD:
        yPos++;
        break;
      case MOVE_BACKWARD:
        yPos--;
        break;
      case TURN_LEFT:
        xPos--;
        break;
      case TURN_RIGHT:
        xPos++;
        break;
      case HOVER:
        printf("Drone hovering in place.\n");
        break;
      case COMMAND_ONE:
        xPos = 5;
        yPos = 5;
        break;
      case COMMAND_TWO:
        xPos = 10;
        yPos = 10;
        break;
      case COMMAND_THREE:
        xPos = 0;
        yPos = 0;
        printPosition();
        yPos = 5;
        printPosition();
        xPos = 5;
        printPosition();
        yPos = 0;
        printPosition();
        break;
      default:
        printf("Invalid input. Please try again.\n");
        break;
    }

    printPosition(); // Print updated drone position

  } while(input != 'q'); // Exit loop when 'q' is entered

  printf("Program terminated.\n");
  return 0;
}