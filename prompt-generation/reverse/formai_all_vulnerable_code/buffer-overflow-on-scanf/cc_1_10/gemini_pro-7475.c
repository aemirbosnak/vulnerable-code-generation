//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define room types
#define ROOM_EMPTY 0
#define ROOM_GHOST 1
#define ROOM_SCARE 2
#define ROOM_EXIT 3

// Define sound effects
#define SOUND_NONE 0
#define SOUND_CREAK 1
#define SOUND_HOWL 2
#define SOUND_SCREAM 3

// Define movement direction
#define DIR_UP 1
#define DIR_DOWN 2
#define DIR_LEFT 3
#define DIR_RIGHT 4

// Initialize global variables
int hauntedHouse[5][5] = {0};
int playerPos[2] = {0, 0};
int playerHealth = 100;
int gameOver = 0;

// Function to generate a random room type
int generateRoomType() {
  int r = rand() % 4;
  if (r == 0) return ROOM_EMPTY;
  else if (r == 1) return ROOM_GHOST;
  else if (r == 2) return ROOM_SCARE;
  else return ROOM_EXIT;
}

// Function to generate a random sound effect
int generateSoundEffect() {
  int r = rand() % 4;
  if (r == 0) return SOUND_NONE;
  else if (r == 1) return SOUND_CREAK;
  else if (r == 2) return SOUND_HOWL;
  else return SOUND_SCREAM;
}

// Function to move the player in a given direction
void movePlayer(int direction) {
  switch (direction) {
    case DIR_UP:
      if (playerPos[0] > 0) playerPos[0]--;
      break;
    case DIR_DOWN:
      if (playerPos[0] < 4) playerPos[0]++;
      break;
    case DIR_LEFT:
      if (playerPos[1] > 0) playerPos[1]--;
      break;
    case DIR_RIGHT:
      if (playerPos[1] < 4) playerPos[1]++;
      break;
  }
}

// Function to handle a ghost encounter
void handleGhostEncounter() {
  printf("You encounter a ghost!\n");
  playerHealth -= 10;
  if (playerHealth <= 0) {
    gameOver = 1;
    printf("You have been killed by the ghost!\n");
  }
}

// Function to handle a scare encounter
void handleScareEncounter() {
  printf("You are scared by a loud noise!\n");
  playerHealth -= 5;
  if (playerHealth <= 0) {
    gameOver = 1;
    printf("You have been killed by the scare!\n");
  }
}

// Function to handle an exit encounter
void handleExitEncounter() {
  printf("You have found the exit!\n");
  gameOver = 1;
  printf("You have escaped the haunted house!\n");
}

// Function to print the haunted house
void printHauntedHouse() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (playerPos[0] == i && playerPos[1] == j) printf("P");
      else {
        switch (hauntedHouse[i][j]) {
          case ROOM_EMPTY:
            printf(".");
            break;
          case ROOM_GHOST:
            printf("G");
            break;
          case ROOM_SCARE:
            printf("S");
            break;
          case ROOM_EXIT:
            printf("E");
            break;
        }
      }
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Initialize the random seed
  srand(time(NULL));

  // Generate the haunted house
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      hauntedHouse[i][j] = generateRoomType();
    }
  }

  // Game loop
  while (!gameOver) {
    // Print the haunted house
    printHauntedHouse();

    // Get player input
    char input;
    printf("Enter a direction (U, D, L, R): ");
    scanf(" %c", &input);

    // Move the player
    int direction;
    switch (input) {
      case 'U':
        direction = DIR_UP;
        break;
      case 'D':
        direction = DIR_DOWN;
        break;
      case 'L':
        direction = DIR_LEFT;
        break;
      case 'R':
        direction = DIR_RIGHT;
        break;
    }
    movePlayer(direction);

    // Check for encounters
    int roomType = hauntedHouse[playerPos[0]][playerPos[1]];
    switch (roomType) {
      case ROOM_GHOST:
        handleGhostEncounter();
        break;
      case ROOM_SCARE:
        handleScareEncounter();
        break;
      case ROOM_EXIT:
        handleExitEncounter();
        break;
    }
  }

  return 0;
}