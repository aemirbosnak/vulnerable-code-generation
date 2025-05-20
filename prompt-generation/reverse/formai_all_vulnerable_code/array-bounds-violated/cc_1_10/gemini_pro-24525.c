//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the game board
char board[3][3];

// Define the player symbols
char player1_symbol = 'X';
char player2_symbol = 'O';

// Define the game state
enum GameState {
  PLAYING,
  PLAYER1_WON,
  PLAYER2_WON,
  DRAW
};

// Function to initialize the game board
void initialize_board() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }
}

// Function to print the game board
void print_board() {
  printf("\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// Function to check if a player has won
enum GameState check_winner() {
  // Check rows
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
      return board[i][0] == player1_symbol ? PLAYER1_WON : PLAYER2_WON;
    }
  }

  // Check columns
  for (int i = 0; i < 3; i++) {
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
      return board[0][i] == player1_symbol ? PLAYER1_WON : PLAYER2_WON;
    }
  }

  // Check diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    return board[0][0] == player1_symbol ? PLAYER1_WON : PLAYER2_WON;
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
    return board[0][2] == player1_symbol ? PLAYER1_WON : PLAYER2_WON;
  }

  // Check for draw
  int num_empty_cells = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
        num_empty_cells++;
      }
    }
  }
  if (num_empty_cells == 0) {
    return DRAW;
  }

  // No winner yet
  return PLAYING;
}

// Function to get the next player's move
int get_next_move(char player_symbol) {
  int row, col;
  printf("Player %c's turn: ", player_symbol);
  scanf("%d %d", &row, &col);
  return row * 3 + col;
}

// Function to play the game
void play_game() {
  // Initialize the game board
  initialize_board();

  // Print the initial game board
  print_board();

  // Get the first player's move
  int move = get_next_move(player1_symbol);

  // Loop until the game is over
  while (check_winner() == PLAYING) {
    // Place the player's symbol on the board
    int row = move / 3;
    int col = move % 3;
    board[row][col] = player1_symbol;

    // Print the updated game board
    print_board();

    // Check if the player has won
    if (check_winner() == PLAYER1_WON) {
      printf("Player 1 wins!\n");
      break;
    }

    // Get the second player's move
    move = get_next_move(player2_symbol);

    // Place the player's symbol on the board
    row = move / 3;
    col = move % 3;
    board[row][col] = player2_symbol;

    // Print the updated game board
    print_board();

    // Check if the player has won
    if (check_winner() == PLAYER2_WON) {
      printf("Player 2 wins!\n");
      break;
    }
  }

  // Check for draw
  if (check_winner() == DRAW) {
    printf("Draw!\n");
  }
}

int main() {
  // Play the game
  play_game();

  return 0;
}