//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: high level of detail
#include <stdio.h>

/* Function to print out the player's coordinates */
void printPosition(int currentX, int currentY) {
  printf("You are currently at position (%d, %d)\n", currentX, currentY);
}

/* Function to move the player north */
void moveNorth(int *currentX, int *currentY) {
  *currentY += 1;
  printf("You move north.\n");
  printPosition(*currentX, *currentY);
}

/* Function to move the player south */
void moveSouth(int *currentX, int *currentY) {
  *currentY -= 1;
  printf("You move south.\n");
  printPosition(*currentX, *currentY);
}

/* Function to move the player east */
void moveEast(int *currentX, int *currentY) {
  *currentX += 1;
  printf("You move east.\n");
  printPosition(*currentX, *currentY);
}

/* Function to move the player west */
void moveWest(int *currentX, int *currentY) {
  *currentX -= 1;
  printf("You move west.\n");
  printPosition(*currentX, *currentY);
}

/* Function to initiate the game and print the starting position */
void startGame() {
  int currentX = 0;
  int currentY = 0;
  printf("Welcome to Procedural Space Adventure!\n");
  printf("Your starting position is (%d, %d)\n", currentX, currentY);
  printf("Use 'n', 's', 'e', and 'w' to move north, south, east, and west.\n");

  int gameRunning = 1;
  while(gameRunning) {
    char userChoice;
    scanf(" %c", &userChoice);

    /* Handle user input to move the player */
    switch(userChoice) {
      case 'n':
        moveNorth(&currentX, &currentY);
        break;
      case 's':
        moveSouth(&currentX, &currentY);
        break;
      case 'e':
        moveEast(&currentX, &currentY);
        break;
      case 'w':
        moveWest(&currentX, &currentY);
        break;
      default:
        printf("Invalid input. Please use 'n', 's', 'e', or 'w'.\n");
    }
  }
}

int main() {
  startGame();

  return 0;
}