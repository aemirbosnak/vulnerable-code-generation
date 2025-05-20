//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the house layout
#define NUM_ROOMS 10
#define NUM_DOORS 5

int house[NUM_ROOMS][NUM_DOORS];

// Define the player's position
int player_room = 0;
int player_door = 0;

// Define the ghost's position
int ghost_room = 0;
int ghost_door = 0;

// Initialize the house
void init_house() {
  for (int i = 0; i < NUM_ROOMS; i++) {
    for (int j = 0; j < NUM_DOORS; j++) {
      house[i][j] = 0;
    }
  }

  // Add some doors to the house
  house[0][1] = 1;
  house[0][2] = 1;
  house[1][2] = 1;
  house[1][3] = 1;
  house[2][3] = 1;
  house[2][4] = 1;
  house[3][4] = 1;
  house[3][0] = 1;
  house[4][0] = 1;
  house[4][1] = 1;
}

// Initialize the player's position
void init_player() {
  player_room = 0;
  player_door = 0;
}

// Initialize the ghost's position
void init_ghost() {
  ghost_room = rand() % NUM_ROOMS;
  ghost_door = rand() % NUM_DOORS;
}

// Move the player
void move_player(int direction) {
  switch (direction) {
  case 'w':
    if (player_door > 0) {
      player_door--;
    }
    break;
  case 's':
    if (player_door < NUM_DOORS - 1) {
      player_door++;
    }
    break;
  case 'a':
    if (player_room > 0) {
      player_room--;
    }
    break;
  case 'd':
    if (player_room < NUM_ROOMS - 1) {
      player_room++;
    }
    break;
  }
}

// Move the ghost
void move_ghost() {
  int dx = player_room - ghost_room;
  int dy = player_door - ghost_door;

  if (abs(dx) > abs(dy)) {
    if (dx > 0) {
      ghost_room++;
    } else {
      ghost_room--;
    }
  } else {
    if (dy > 0) {
      ghost_door++;
    } else {
      ghost_door--;
    }
  }
}

// Check if the player has won
int check_win() {
  return player_room == ghost_room && player_door == ghost_door;
}

// Check if the player has lost
int check_lost() {
  return player_room == ghost_room && player_door == ghost_door;
}

// Print the house
void print_house() {
  for (int i = 0; i < NUM_ROOMS; i++) {
    for (int j = 0; j < NUM_DOORS; j++) {
      if (player_room == i && player_door == j) {
        printf("@");
      } else if (ghost_room == i && ghost_door == j) {
        printf("G");
      } else if (house[i][j] == 0) {
        printf("#");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

// Main game loop
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Initialize the house
  init_house();

  // Initialize the player's position
  init_player();

  // Initialize the ghost's position
  init_ghost();

  // Main game loop
  while (!check_win() && !check_lost()) {
    // Print the house
    print_house();

    // Get the player's move
    char move;
    printf("Enter your move (WASD to move, Q to quit): ");
    scanf(" %c", &move);

    // Move the player
    move_player(move);

    // Move the ghost
    move_ghost();
  }

  // Print the final message
  if (check_win()) {
    printf("You win!\n");
  } else {
    printf("You lose!\n");
  }

  return 0;
}