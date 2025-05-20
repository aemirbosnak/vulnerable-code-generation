//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int rooms[10][10]; // The haunted house
int playerX, playerY; // The player's position
int numGhosts; // The number of ghosts
int ghosts[10][2]; // The ghosts' positions
int gameOver; // The game over flag

// Initialize the game
void initGame() {
  // Set all rooms to empty
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      rooms[i][j] = 0;
    }
  }

  // Set the player's position
  playerX = 0;
  playerY = 0;

  // Set the number of ghosts
  numGhosts = 3;

  // Set the ghosts' positions
  for (int i = 0; i < numGhosts; i++) {
    ghosts[i][0] = rand() % 10;
    ghosts[i][1] = rand() % 10;
  }

  // Set the game over flag
  gameOver = 0;
}

// Draw the game
void drawGame() {
  // Clear the screen
  system("clear");

  // Draw the top border
  printf("╔═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╗\n");

  // Draw the rooms
  for (int i = 0; i < 10; i++) {
    // Draw the left border
    printf("║ ");

    // Draw the rooms
    for (int j = 0; j < 10; j++) {
      if (rooms[i][j] == 0) {
        printf("░░");
      } else if (rooms[i][j] == 1) {
        printf("▒▒");
      } else if (rooms[i][j] == 2) {
        printf("▓▓");
      } else if (rooms[i][j] == 3) {
        printf("██");
      }
    }

    // Draw the right border
    printf(" ║\n");
  }

  // Draw the bottom border
  printf("╚═══════╩═══════╩═══════╩═══════╩═══════╩═══════╩═══════╩═══════╩═══════╩═══════╝\n");
}

// Update the game
void updateGame() {
  // Move the ghosts
  for (int i = 0; i < numGhosts; i++) {
    // Get the ghost's current position
    int ghostX = ghosts[i][0];
    int ghostY = ghosts[i][1];

    // Get the player's current position
    int playerX = playerX;
    int playerY = playerY;

    // Calculate the distance between the ghost and the player
    int dx = playerX - ghostX;
    int dy = playerY - ghostY;

    // Move the ghost towards the player
    if (dx > 0) {
      ghostX++;
    } else if (dx < 0) {
      ghostX--;
    }

    if (dy > 0) {
      ghostY++;
    } else if (dy < 0) {
      ghostY--;
    }

    // Update the ghost's position
    ghosts[i][0] = ghostX;
    ghosts[i][1] = ghostY;
  }

  // Check for collisions between the player and the ghosts
  for (int i = 0; i < numGhosts; i++) {
    // Get the ghost's position
    int ghostX = ghosts[i][0];
    int ghostY = ghosts[i][1];

    // Check for a collision between the player and the ghost
    if (playerX == ghostX && playerY == ghostY) {
      // The player has been caught by the ghost
      gameOver = 1;
    }
  }
}

// Handle keyboard input
void handleInput() {
  // Get the player's input
  char input = getchar();

  // Move the player based on the input
  switch (input) {
    case 'w':
      playerY--;
      break;
    case 'a':
      playerX--;
      break;
    case 's':
      playerY++;
      break;
    case 'd':
      playerX++;
      break;
  }
}

// Main game loop
int main() {
  // Initialize the game
  initGame();

  // Game loop
  while (!gameOver) {
    // Draw the game
    drawGame();

    // Update the game
    updateGame();

    // Handle keyboard input
    handleInput();
  }

  // The game is over
  printf("Game over!\n");

  return 0;
}