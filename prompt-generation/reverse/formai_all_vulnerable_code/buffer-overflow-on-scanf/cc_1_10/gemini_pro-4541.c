//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int rooms[10][10]; // The haunted house
int playerX = 0; // The player's current X coordinate
int playerY = 0; // The player's current Y coordinate
int gameOver = 0; // Flag indicating whether the game is over

// Function prototypes
void printHouse();
void movePlayer(char direction);
int checkForMonster(int x, int y);
void gameOverScreen();

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Initialize the haunted house
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      rooms[i][j] = 0; // 0 represents an empty room
    }
  }

  // Place the player in the starting room
  rooms[0][0] = 1; // 1 represents the player

  // Place a monster in a random room
  int monsterX = rand() % 10;
  int monsterY = rand() % 10;
  rooms[monsterX][monsterY] = 2; // 2 represents a monster

  // Main game loop
  while (!gameOver) {
    // Print the haunted house
    printHouse();

    // Get the player's input
    char direction;
    printf("Enter a direction to move (w, a, s, d): ");
    scanf(" %c", &direction);

    // Move the player
    movePlayer(direction);

    // Check for a monster
    if (checkForMonster(playerX, playerY)) {
      // Game over
      gameOver = 1;
      gameOverScreen();
    }
  }

  return 0;
}

void printHouse() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (rooms[i][j] == 0) {
        printf("  "); // Empty room
      } else if (rooms[i][j] == 1) {
        printf("@@"); // Player
      } else if (rooms[i][j] == 2) {
        printf("!!"); // Monster
      }
    }
    printf("\n");
  }
}

void movePlayer(char direction) {
  switch (direction) {
    case 'w':
      if (playerY > 0) {
        rooms[playerY][playerX] = 0;
        playerY--;
        rooms[playerY][playerX] = 1;
      }
      break;
    case 'a':
      if (playerX > 0) {
        rooms[playerY][playerX] = 0;
        playerX--;
        rooms[playerY][playerX] = 1;
      }
      break;
    case 's':
      if (playerY < 9) {
        rooms[playerY][playerX] = 0;
        playerY++;
        rooms[playerY][playerX] = 1;
      }
      break;
    case 'd':
      if (playerX < 9) {
        rooms[playerY][playerX] = 0;
        playerX++;
        rooms[playerY][playerX] = 1;
      }
      break;
  }
}

int checkForMonster(int x, int y) {
  return rooms[x][y] == 2;
}

void gameOverScreen() {
  printf("\nYou have been eaten by a monster!\n");
  printf("Game over!\n");
}