//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the table size
#define TABLE_SIZE 5

// Define the player types
#define PLAYER_1 1
#define PLAYER_2 2

// Define the game states
#define GAME_IN_PROGRESS 0
#define PLAYER_1_WINS 1
#define PLAYER_2_WINS 2
#define DRAW 3

// Define the table
char table[TABLE_SIZE][TABLE_SIZE];

// Function to initialize the table
void init_table() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    for (int j = 0; j < TABLE_SIZE; j++) {
      table[i][j] = ' ';
    }
  }
}

// Function to print the table
void print_table() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    for (int j = 0; j < TABLE_SIZE; j++) {
      printf("%c ", table[i][j]);
    }
    printf("\n");
  }
}

// Function to get the player's move
int get_player_move(int player) {
  int row, col;
  printf("Player %d, enter your move (row, col): ", player);
  scanf("%d %d", &row, &col);
  return row * TABLE_SIZE + col;
}

// Function to check if the move is valid
int is_valid_move(int move) {
  int row = move / TABLE_SIZE;
  int col = move % TABLE_SIZE;
  return row >= 0 && row < TABLE_SIZE && col >= 0 && col < TABLE_SIZE && table[row][col] == ' ';
}

// Function to make a move
void make_move(int move, int player) {
  int row = move / TABLE_SIZE;
  int col = move % TABLE_SIZE;
  table[row][col] = player == PLAYER_1 ? 'X' : 'O';
}

// Function to check if the game is over
int is_game_over() {
  // Check for horizontal wins
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (table[i][0] != ' ' && table[i][0] == table[i][1] && table[i][1] == table[i][2] && table[i][2] == table[i][3] && table[i][3] == table[i][4]) {
      return table[i][0] == 'X' ? PLAYER_1_WINS : PLAYER_2_WINS;
    }
  }

  // Check for vertical wins
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (table[0][i] != ' ' && table[0][i] == table[1][i] && table[1][i] == table[2][i] && table[2][i] == table[3][i] && table[3][i] == table[4][i]) {
      return table[0][i] == 'X' ? PLAYER_1_WINS : PLAYER_2_WINS;
    }
  }

  // Check for diagonal wins
  if (table[0][0] != ' ' && table[0][0] == table[1][1] && table[1][1] == table[2][2] && table[2][2] == table[3][3] && table[3][3] == table[4][4]) {
    return table[0][0] == 'X' ? PLAYER_1_WINS : PLAYER_2_WINS;
  }
  if (table[0][4] != ' ' && table[0][4] == table[1][3] && table[1][3] == table[2][2] && table[2][2] == table[3][1] && table[3][1] == table[4][0]) {
    return table[0][4] == 'X' ? PLAYER_1_WINS : PLAYER_2_WINS;
  }

  // Check for a draw
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

  // The game is still in progress
  return GAME_IN_PROGRESS;
}

int main() {
  // Initialize the table
  init_table();

  // Print the table
  print_table();

  // Get the players' moves
  int player = PLAYER_1;
  int move;
  while ((move = get_player_move(player)) != -1) {
    // Check if the move is valid
    if (!is_valid_move(move)) {
      printf("Invalid move. Please try again.\n");
      continue;
    }

    // Make the move
    make_move(move, player);

    // Print the table
    print_table();

    // Check if the game is over
    int game_state = is_game_over();
    if (game_state != GAME_IN_PROGRESS) {
      if (game_state == PLAYER_1_WINS) {
        printf("Player 1 wins!\n");
      } else if (game_state == PLAYER_2_WINS) {
        printf("Player 2 wins!\n");
      } else {
        printf("Draw!\n");
      }
      break;
    }

    // Switch players
    player = player == PLAYER_1 ? PLAYER_2 : PLAYER_1;
  }

  return 0;
}