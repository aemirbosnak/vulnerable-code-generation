//GEMINI-pro DATASET v1.0 Category: Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 3
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player symbols
#define PLAYER1 'X'
#define PLAYER2 'O'

// Define the game state
#define GAME_IN_PROGRESS 0
#define PLAYER1_WIN 1
#define PLAYER2_WIN 2
#define DRAW 3

// Function to initialize the game board
void initialize_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }
}

// Function to print the game board
void print_board() {
  printf("\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// Function to check if a player has won
int check_win() {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return board[i][0] == PLAYER1 ? PLAYER1_WIN : PLAYER2_WIN;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
      return board[0][j] == PLAYER1 ? PLAYER1_WIN : PLAYER2_WIN;
    }
  }

  // Check diagonals
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return board[0][0] == PLAYER1 ? PLAYER1_WIN : PLAYER2_WIN;
  }
  if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return board[0][2] == PLAYER1 ? PLAYER1_WIN : PLAYER2_WIN;
  }

  // Check for a draw
  int num_empty_cells = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        num_empty_cells++;
      }
    }
  }
  if (num_empty_cells == 0) {
    return DRAW;
  }

  // No winner yet
  return GAME_IN_PROGRESS;
}

// Function to get the next player's move
int get_next_move(char player) {
  int row, col;
  printf("Player %c, enter your move (row, column): ", player);
  scanf("%d %d", &row, &col);
  return row * BOARD_SIZE + col;
}

// Function to make a move on the game board
void make_move(int move, char player) {
  int row = move / BOARD_SIZE;
  int col = move % BOARD_SIZE;
  board[row][col] = player;
}

// Main game loop
int main() {
  // Initialize the game board
  initialize_board();

  // Set the current player to player 1
  char current_player = PLAYER1;

  // Game loop
  while (1) {
    // Print the game board
    print_board();

    // Get the next player's move
    int move = get_next_move(current_player);

    // Make the move on the game board
    make_move(move, current_player);

    // Check if the game has been won
    int game_state = check_win();

    // If the game has been won, print the winner and exit
    if (game_state != GAME_IN_PROGRESS) {
      if (game_state == PLAYER1_WIN) {
        printf("Player 1 wins!\n");
      } else if (game_state == PLAYER2_WIN) {
        printf("Player 2 wins!\n");
      } else {
        printf("Draw!\n");
      }
      break;
    }

    // Switch the current player
    current_player = current_player == PLAYER1 ? PLAYER2 : PLAYER1;
  }

  return 0;
}