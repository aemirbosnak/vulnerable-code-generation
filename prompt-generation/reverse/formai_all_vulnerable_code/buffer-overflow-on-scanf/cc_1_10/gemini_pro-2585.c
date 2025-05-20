//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the table size.
#define TABLE_SIZE 5

// Define the number of players.
#define NUM_PLAYERS 2

// Define the game states.
#define STATE_PLAYING 0
#define STATE_OVER 1

// Define the table.
int table[TABLE_SIZE][TABLE_SIZE];

// Define the players.
int players[NUM_PLAYERS];

// Define the current player.
int current_player;

// Define the game state.
int game_state;

// Initialize the table.
void init_table() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    for (int j = 0; j < TABLE_SIZE; j++) {
      table[i][j] = 0;
    }
  }
}

// Initialize the players.
void init_players() {
  for (int i = 0; i < NUM_PLAYERS; i++) {
    players[i] = 0;
  }
}

// Initialize the game state.
void init_game_state() {
  game_state = STATE_PLAYING;
}

// Print the table.
void print_table() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    for (int j = 0; j < TABLE_SIZE; j++) {
      printf("%d ", table[i][j]);
    }
    printf("\n");
  }
}

// Check if the game is over.
int check_game_over() {
  // Check if all the cells are filled.
  for (int i = 0; i < TABLE_SIZE; i++) {
    for (int j = 0; j < TABLE_SIZE; j++) {
      if (table[i][j] == 0) {
        return 0;
      }
    }
  }

  // Check if any player has won.
  for (int i = 0; i < NUM_PLAYERS; i++) {
    // Check if the player has won horizontally.
    for (int j = 0; j < TABLE_SIZE; j++) {
      if (table[i][j] != i + 1) {
        break;
      }
      if (j == TABLE_SIZE - 1) {
        return 1;
      }
    }

    // Check if the player has won vertically.
    for (int j = 0; j < TABLE_SIZE; j++) {
      if (table[j][i] != i + 1) {
        break;
      }
      if (j == TABLE_SIZE - 1) {
        return 1;
      }
    }

    // Check if the player has won diagonally.
    if (table[0][0] == i + 1) {
      for (int j = 1; j < TABLE_SIZE; j++) {
        if (table[j][j] != i + 1) {
          break;
        }
        if (j == TABLE_SIZE - 1) {
          return 1;
        }
      }
    }

    if (table[0][TABLE_SIZE - 1] == i + 1) {
      for (int j = 1; j < TABLE_SIZE; j++) {
        if (table[j][TABLE_SIZE - 1 - j] != i + 1) {
          break;
        }
        if (j == TABLE_SIZE - 1) {
          return 1;
        }
      }
    }
  }

  // The game is not over.
  return 0;
}

// Get the next player.
int get_next_player() {
  // Increment the current player.
  current_player++;

  // If the current player is greater than the number of players, reset it to 0.
  if (current_player >= NUM_PLAYERS) {
    current_player = 0;
  }

  // Return the next player.
  return current_player;
}

// Get the player's move.
int get_player_move() {
  // Get the player's input.
  int move;
  printf("Player %d, enter your move (1-%d): ", current_player + 1, TABLE_SIZE * TABLE_SIZE);
  scanf("%d", &move);

  // Validate the player's input.
  while (move < 1 || move > TABLE_SIZE * TABLE_SIZE || table[(move - 1) / TABLE_SIZE][(move - 1) % TABLE_SIZE] != 0) {
    printf("Invalid move. Please enter a valid move (1-%d): ", TABLE_SIZE * TABLE_SIZE);
    scanf("%d", &move);
  }

  // Return the player's move.
  return move;
}

// Play the game.
void play_game() {
  // Initialize the game.
  init_table();
  init_players();
  init_game_state();

  // Print the initial table.
  print_table();

  // Loop until the game is over.
  while (game_state == STATE_PLAYING) {
    // Get the next player's move.
    int move = get_player_move();

    // Place the player's move on the table.
    table[(move - 1) / TABLE_SIZE][(move - 1) % TABLE_SIZE] = current_player + 1;

    // Print the updated table.
    print_table();

    // Check if the game is over.
    game_state = check_game_over();

    // Get the next player.
    current_player = get_next_player();
  }

  // Print the final table.
  print_table();

  // Declare the winner.
  int winner = current_player;
  if (winner == 0) {
    printf("It's a draw!\n");
  } else {
    printf("Player %d wins!\n", winner);
  }
}

// Main function.
int main() {
  //srand(time(NULL));

  // Play the game.
  play_game();

  return 0;
}