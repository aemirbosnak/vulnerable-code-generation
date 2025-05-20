//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the table size
#define TABLE_SIZE 5

// Define the player symbols
#define PLAYER_1 'X'
#define PLAYER_2 'O'

// Define the game state
#define GAME_IN_PROGRESS 0
#define PLAYER_1_WINS 1
#define PLAYER_2_WINS 2
#define DRAW 3

// Create the game table
char table[TABLE_SIZE][TABLE_SIZE];

// Create the game state variable
int game_state;

// Function to initialize the game table
void init_table() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    for (int j = 0; j < TABLE_SIZE; j++) {
      table[i][j] = ' ';
    }
  }
}

// Function to print the game table
void print_table() {
  printf("  ");
  for (int i = 0; i < TABLE_SIZE; i++) {
    printf("%d ", i + 1);
  }
  printf("\n");
  for (int i = 0; i < TABLE_SIZE; i++) {
    printf("%d ", i + 1);
    for (int j = 0; j < TABLE_SIZE; j++) {
      printf("%c ", table[i][j]);
    }
    printf("\n");
  }
}

// Function to get the player's move
int get_player_move(char player) {
  int move;
  while (1) {
    printf("Player %c, enter your move (1-%d): ", player, TABLE_SIZE * TABLE_SIZE);
    scanf("%d", &move);
    if (move >= 1 && move <= TABLE_SIZE * TABLE_SIZE) {
      return move;
    }
    printf("Invalid move. Please try again.\n");
  }
}

// Function to make a move
void make_move(int move, char player) {
  int row = (move - 1) / TABLE_SIZE;
  int col = (move - 1) % TABLE_SIZE;
  table[row][col] = player;
}

// Function to check if the game is over
int check_game_over() {
  // Check for rows
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (table[i][0] != ' ' && table[i][0] == table[i][1] && table[i][1] == table[i][2]) {
      return table[i][0] == PLAYER_1 ? PLAYER_1_WINS : PLAYER_2_WINS;
    }
  }

  // Check for columns
  for (int j = 0; j < TABLE_SIZE; j++) {
    if (table[0][j] != ' ' && table[0][j] == table[1][j] && table[1][j] == table[2][j]) {
      return table[0][j] == PLAYER_1 ? PLAYER_1_WINS : PLAYER_2_WINS;
    }
  }

  // Check for diagonals
  if (table[0][0] != ' ' && table[0][0] == table[1][1] && table[1][1] == table[2][2]) {
    return table[0][0] == PLAYER_1 ? PLAYER_1_WINS : PLAYER_2_WINS;
  }
  if (table[0][2] != ' ' && table[0][2] == table[1][1] && table[1][1] == table[2][0]) {
    return table[0][2] == PLAYER_1 ? PLAYER_1_WINS : PLAYER_2_WINS;
  }

  // Check for draw
  int count = 0;
  for (int i = 0; i < TABLE_SIZE; i++) {
    for (int j = 0; j < TABLE_SIZE; j++) {
      if (table[i][j] != ' ') {
        count++;
      }
    }
  }
  if (count == TABLE_SIZE * TABLE_SIZE) {
    return DRAW;
  }

  // Game is still in progress
  return GAME_IN_PROGRESS;
}

// Main game loop
int main() {
  // Initialize the game table
  init_table();

  // Print the game table
  print_table();

  // Set the game state to in progress
  game_state = GAME_IN_PROGRESS;

  // While the game is in progress
  while (game_state == GAME_IN_PROGRESS) {
    // Get the player 1 move
    int move1 = get_player_move(PLAYER_1);

    // Make the move
    make_move(move1, PLAYER_1);

    // Print the game table
    print_table();

    // Check if the game is over
    game_state = check_game_over();

    // If the game is not over, get the player 2 move
    if (game_state == GAME_IN_PROGRESS) {
      // Get the player 2 move
      int move2 = get_player_move(PLAYER_2);

      // Make the move
      make_move(move2, PLAYER_2);

      // Print the game table
      print_table();

      // Check if the game is over
      game_state = check_game_over();
    }
  }

  // Print the game result
  switch (game_state) {
    case PLAYER_1_WINS:
      printf("Player 1 wins!\n");
      break;
    case PLAYER_2_WINS:
      printf("Player 2 wins!\n");
      break;
    case DRAW:
      printf("Draw!\n");
      break;
  }

  return 0;
}