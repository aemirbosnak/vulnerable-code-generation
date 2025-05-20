//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Game constants
#define TABLE_SIZE 10
#define PLAYER_COUNT 4
#define DICE_SIDES 6

// Game state
int table[TABLE_SIZE][TABLE_SIZE];
int player_positions[PLAYER_COUNT];
int current_player;

// Function prototypes
void initialize_game();
void print_table();
void roll_dice();
void move_player();
int check_winner();

int main() {
  // Initialize the game
  initialize_game();

  // Game loop
  while (1) {
    // Print the table
    print_table();

    // Get the current player's input
    printf("Player %d, roll the dice:\n", current_player + 1);
    roll_dice();

    // Move the player
    move_player();

    // Check if there is a winner
    int winner = check_winner();
    if (winner != -1) {
      printf("Player %d wins!\n", winner + 1);
      break;
    }

    // Switch to the next player
    current_player = (current_player + 1) % PLAYER_COUNT;
  }

  return 0;
}

void initialize_game() {
  // Initialize the table to all zeros
  for (int i = 0; i < TABLE_SIZE; i++) {
    for (int j = 0; j < TABLE_SIZE; j++) {
      table[i][j] = 0;
    }
  }

  // Initialize the player positions to the starting position
  for (int i = 0; i < PLAYER_COUNT; i++) {
    player_positions[i] = 0;
  }

  // Set the current player to the first player
  current_player = 0;
}

void print_table() {
  // Print the table header
  printf("    ");
  for (int i = 0; i < TABLE_SIZE; i++) {
    printf("%2d ", i + 1);
  }
  printf("\n\n");

  // Print the table rows
  for (int i = 0; i < TABLE_SIZE; i++) {
    printf("%2d ", i + 1);
    for (int j = 0; j < TABLE_SIZE; j++) {
      printf("%2d ", table[i][j]);
    }
    printf("\n");
  }
}

void roll_dice() {
  // Get a random number between 1 and 6
  int dice_roll = rand() % DICE_SIDES + 1;

  // Add the dice roll to the current player's position
  player_positions[current_player] += dice_roll;
}

void move_player() {
  // Get the current player's position
  int position = player_positions[current_player];

  // Check if the player has reached the end of the table
  if (position >= TABLE_SIZE) {
    // The player has reached the end of the table, so move them to the start
    player_positions[current_player] = 0;
  }

  // Update the table to reflect the player's new position
  table[position][current_player] = 1;
}

int check_winner() {
  // Check if any player has reached the end of the table
  for (int i = 0; i < PLAYER_COUNT; i++) {
    if (player_positions[i] >= TABLE_SIZE) {
      return i;
    }
  }

  // No player has reached the end of the table yet, so return -1
  return -1;
}