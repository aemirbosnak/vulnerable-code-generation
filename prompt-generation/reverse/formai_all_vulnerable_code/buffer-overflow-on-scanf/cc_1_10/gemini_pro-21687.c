//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PLAYERS 2
#define BOARD_SIZE 3

// Define the game board
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player symbols
char player_symbols[] = {'X', 'O'};

// Initialize the game board
void init_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }
}

// Print the game board
void print_board() {
  printf("\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Check if a player has won
int check_win(char player_symbol) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    int count = 0;
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == player_symbol) {
        count++;
      }
    }
    if (count == BOARD_SIZE) {
      return 1;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
      if (board[i][j] == player_symbol) {
        count++;
      }
    }
    if (count == BOARD_SIZE) {
      return 1;
    }
  }

  // Check diagonals
  int count1 = 0;
  int count2 = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][i] == player_symbol) {
      count1++;
    }
    if (board[i][BOARD_SIZE - i - 1] == player_symbol) {
      count2++;
    }
  }
  if (count1 == BOARD_SIZE || count2 == BOARD_SIZE) {
    return 1;
  }

  // No winner yet
  return 0;
}

// Get the next player's move
int get_player_move(int player_index) {
  int row, col;
  printf("Player %d's turn (row, col): ", player_index + 1);
  scanf("%d %d", &row, &col);
  return row * BOARD_SIZE + col;
}

// Play the game
void play_game() {
  int player_index = 0;
  int move;

  // Initialize the game board
  init_board();

  // Print the game board
  print_board();

  // Loop until a player wins or there is a tie
  while (1) {
    // Get the next player's move
    move = get_player_move(player_index);

    // Check if the move is valid
    if (move < 0 || move >= BOARD_SIZE * BOARD_SIZE || board[move / BOARD_SIZE][move % BOARD_SIZE] != ' ') {
      printf("Invalid move. Try again.\n");
      continue;
    }

    // Place the player's symbol on the board
    board[move / BOARD_SIZE][move % BOARD_SIZE] = player_symbols[player_index];

    // Print the game board
    print_board();

    // Check if the player has won
    if (check_win(player_symbols[player_index])) {
      printf("Player %d wins!\n", player_index + 1);
      break;
    }

    // Switch to the next player
    player_index = (player_index + 1) % PLAYERS;
  }
}

int main() {
  // Play the game
  play_game();

  return 0;
}