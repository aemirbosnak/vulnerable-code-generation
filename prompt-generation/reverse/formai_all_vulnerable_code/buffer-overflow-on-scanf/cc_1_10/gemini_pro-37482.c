//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 10
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player's position
int player_x, player_y;

// Define the monster's position
int monster_x, monster_y;

// Initialize the game board
void init_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = '.';
    }
  }

  // Place the player in the center of the board
  player_x = BOARD_SIZE / 2;
  player_y = BOARD_SIZE / 2;

  // Place the monster in a random location
  srand(time(NULL));
  monster_x = rand() % BOARD_SIZE;
  monster_y = rand() % BOARD_SIZE;
}

// Print the game board
void print_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (i == player_x && j == player_y) {
        printf("@");
      } else if (i == monster_x && j == monster_y) {
        printf("M");
      } else {
        printf("%c", board[i][j]);
      }
    }
    printf("\n");
  }
}

// Get the player's input
void get_input() {
  char input;
  scanf("%c", &input);

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
}

// Update the game state
void update_state() {
  // Check if the player has moved into the monster
  if (player_x == monster_x && player_y == monster_y) {
    printf("You lose!\n");
    exit(0);
  }

  // Move the monster towards the player
  int dx = player_x - monster_x;
  int dy = player_y - monster_y;
  if (abs(dx) > abs(dy)) {
    if (dx > 0) {
      monster_x++;
    } else {
      monster_x--;
    }
  } else {
    if (dy > 0) {
      monster_y++;
    } else {
      monster_y--;
    }
  }
}

// Main game loop
int main() {
  init_board();
  while (1) {
    print_board();
    get_input();
    update_state();
  }

  return 0;
}