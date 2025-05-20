//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the haunted house
#define HAUNTED_HOUSE_WIDTH  10
#define HAUNTED_HOUSE_HEIGHT 10
int hauntedHouse[HAUNTED_HOUSE_WIDTH][HAUNTED_HOUSE_HEIGHT];

// Define the player
#define PLAYER_WIDTH  1
#define PLAYER_HEIGHT 1
int player[PLAYER_WIDTH][PLAYER_HEIGHT];

// Define the ghost
#define GHOST_WIDTH  1
#define GHOST_HEIGHT 1
int ghost[GHOST_WIDTH][GHOST_HEIGHT];

// Initialize the haunted house
void initializeHauntedHouse() {
  for (int i = 0; i < HAUNTED_HOUSE_WIDTH; i++) {
    for (int j = 0; j < HAUNTED_HOUSE_HEIGHT; j++) {
      hauntedHouse[i][j] = 0;
    }
  }
}

// Initialize the player
void initializePlayer() {
  player[0][0] = 5;
  player[0][1] = 5;
}

// Initialize the ghost
void initializeGhost() {
  ghost[0][0] = rand() % HAUNTED_HOUSE_WIDTH;
  ghost[0][1] = rand() % HAUNTED_HOUSE_HEIGHT;
}

// Print the haunted house
void printHauntedHouse() {
  for (int i = 0; i < HAUNTED_HOUSE_WIDTH; i++) {
    for (int j = 0; j < HAUNTED_HOUSE_HEIGHT; j++) {
      if (hauntedHouse[i][j] == 0) {
        printf(" ");
      } else if (hauntedHouse[i][j] == 1) {
        printf("#");
      } else if (hauntedHouse[i][j] == 2) {
        printf("P");
      } else if (hauntedHouse[i][j] == 3) {
        printf("G");
      }
    }
    printf("\n");
  }
}

// Move the player
void movePlayer(int direction) {
  if (direction == 'w') {
    player[0][1]--;
  } else if (direction == 's') {
    player[0][1]++;
  } else if (direction == 'a') {
    player[0][0]--;
  } else if (direction == 'd') {
    player[0][0]++;
  }
}

// Move the ghost
void moveGhost() {
  int dx = player[0][0] - ghost[0][0];
  int dy = player[0][1] - ghost[0][1];

  if (abs(dx) > abs(dy)) {
    if (dx > 0) {
      ghost[0][0]++;
    } else {
      ghost[0][0]--;
    }
  } else {
    if (dy > 0) {
      ghost[0][1]++;
    } else {
      ghost[0][1]--;
    }
  }
}

// Check if the player has been caught by the ghost
int checkIfPlayerCaught() {
  if (player[0][0] == ghost[0][0] && player[0][1] == ghost[0][1]) {
    return 1;
  } else {
    return 0;
  }
}

// Main game loop
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Initialize the haunted house
  initializeHauntedHouse();

  // Initialize the player
  initializePlayer();

  // Initialize the ghost
  initializeGhost();

  // Main game loop
  while (1) {
    // Print the haunted house
    printHauntedHouse();

    // Get the player's input
    char direction = getchar();

    // Move the player
    movePlayer(direction);

    // Move the ghost
    moveGhost();

    // Check if the player has been caught by the ghost
    if (checkIfPlayerCaught()) {
      printf("You have been caught by the ghost!\n");
      break;
    }
  }

  return 0;
}