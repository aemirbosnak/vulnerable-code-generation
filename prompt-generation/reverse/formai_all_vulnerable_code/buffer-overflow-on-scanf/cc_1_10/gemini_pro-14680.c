//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// House dimensions
#define WIDTH 10
#define HEIGHT 10

// Player position
int playerX, playerY;

// Ghost positions
int ghostX[4], ghostY[4];

// Game state
enum {PLAYING, WON, LOST} state;

// Initialize the game world
void init() {
  // Set the player position
  playerX = WIDTH / 2;
  playerY = HEIGHT / 2;

  // Set the ghost positions
  for (int i = 0; i < 4; ++i) {
    ghostX[i] = rand() % WIDTH;
    ghostY[i] = rand() % HEIGHT;
  }

  // Set the game state to PLAYING
  state = PLAYING;
}

// Update the game world
void update() {
  // Get the player's input
  char input;
  scanf(" %c", &input);

  // Update the player's position
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

  // Check for collisions with ghosts
  for (int i = 0; i < 4; ++i) {
    if (playerX == ghostX[i] && playerY == ghostY[i]) {
      // The player has lost
      state = LOST;
      return;
    }
  }

  // Check if the player has won
  if (playerX == WIDTH - 1 && playerY == HEIGHT - 1) {
    // The player has won
    state = WON;
    return;
  }
}

// Draw the game world
void draw() {
  // Clear the screen
  printf("\033[2J");

  // Draw the house
  for (int i = 0; i < WIDTH; ++i) {
    for (int j = 0; j < HEIGHT; ++j) {
      if (i == 0 || i == WIDTH - 1 || j == 0 || j == HEIGHT - 1) {
        // Draw the walls
        printf("#");
      } else if (i == playerX && j == playerY) {
        // Draw the player
        printf("@");
      } else {
        // Draw the floor
        printf(".");
      }
    }
    printf("\n");
  }

  // Draw the ghosts
  for (int i = 0; i < 4; ++i) {
    printf("G ");
  }
  printf("\n");
}

// Main game loop
int main() {
  // Initialize the game world
  init();

  // Main game loop
  while (state == PLAYING) {
    // Update the game world
    update();

    // Draw the game world
    draw();
  }

  // Print the game over message
  if (state == WON) {
    printf("You win!\n");
  } else if (state == LOST) {
    printf("You lose!\n");
  }

  return 0;
}