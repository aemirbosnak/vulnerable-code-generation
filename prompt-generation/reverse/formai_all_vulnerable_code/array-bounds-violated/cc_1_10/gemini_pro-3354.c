//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the game world
#define WORLD_WIDTH 10
#define WORLD_HEIGHT 10
char world[WORLD_WIDTH][WORLD_HEIGHT];

// Define the player's position
int player_x, player_y;

// Define the game state
enum game_state {
  STATE_PLAYING,
  STATE_GAME_OVER
};
int game_state;

// Function to initialize the game world
void init_world() {
  for (int y = 0; y < WORLD_HEIGHT; y++) {
    for (int x = 0; x < WORLD_WIDTH; x++) {
      world[y][x] = '.';
    }
  }

  // Place the player in the center of the world
  player_x = WORLD_WIDTH / 2;
  player_y = WORLD_HEIGHT / 2;

  // Place some obstacles in the world
  world[0][0] = '#';
  world[0][1] = '#';
  world[1][0] = '#';
  world[1][1] = '#';
  world[2][0] = '#';
  world[2][1] = '#';
  world[3][0] = '#';
  world[3][1] = '#';
  world[4][0] = '#';
  world[4][1] = '#';
  world[5][0] = '#';
  world[5][1] = '#';
  world[6][0] = '#';
  world[6][1] = '#';
  world[7][0] = '#';
  world[7][1] = '#';
  world[8][0] = '#';
  world[8][1] = '#';
  world[9][0] = '#';
  world[9][1] = '#';
}

// Function to print the game world
void print_world() {
  for (int y = 0; y < WORLD_HEIGHT; y++) {
    for (int x = 0; x < WORLD_WIDTH; x++) {
      printf("%c", world[y][x]);
    }
    printf("\n");
  }
}

// Function to get input from the player
char get_input() {
  char input;
  scanf(" %c", &input);
  return input;
}

// Function to update the game state
void update_game_state() {
  if (world[player_y][player_x] == '#') {
    game_state = STATE_GAME_OVER;
  }
}

// Main game loop
int main() {
  // Initialize the game world
  init_world();

  // Main game loop
  while (game_state == STATE_PLAYING) {
    // Print the game world
    print_world();

    // Get input from the player
    char input = get_input();

    // Update the player's position
    switch (input) {
      case 'w':
        player_y--;
        break;
      case 's':
        player_y++;
        break;
      case 'a':
        player_x--;
        break;
      case 'd':
        player_x++;
        break;
    }

    // Update the game state
    update_game_state();
  }

  // Print the game over message
  if (game_state == STATE_GAME_OVER) {
    printf("Game over!\n");
  }

  return 0;
}