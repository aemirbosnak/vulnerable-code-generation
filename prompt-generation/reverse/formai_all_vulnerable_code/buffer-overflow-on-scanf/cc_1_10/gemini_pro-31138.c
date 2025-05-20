//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the game board size
#define BOARD_SIZE 5

// Define the player symbols
#define PLAYER1 'X'
#define PLAYER2 'O'

// Define the game state
#define GAME_STATE_PLAYING 0
#define GAME_STATE_PLAYER1_WIN 1
#define GAME_STATE_PLAYER2_WIN 2
#define GAME_STATE_DRAW 3

// Define the game board
char board[BOARD_SIZE][BOARD_SIZE];

// Define the current player
char current_player = PLAYER1;

// Define the game state
int game_state = GAME_STATE_PLAYING;

// Function to initialise the game board
void initialise_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }
}

// Function to print the game board
void print_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Function to get the player's move
void get_move() {
  int row, col;

  printf("Enter the row and column of your move (1-5): ");
  scanf("%d %d", &row, &col);

  // Check if the move is valid
  if (row < 1 || row > BOARD_SIZE || col < 1 || col > BOARD_SIZE || board[row - 1][col - 1] != ' ') {
    printf("Invalid move. Please try again.\n");
    get_move();
  } else {
    // Place the player's symbol on the board
    board[row - 1][col - 1] = current_player;
  }
}

// Function to check if the game is over
int check_game_over() {
  // Check if there is a winner
  for (int i = 0; i < BOARD_SIZE; i++) {
    // Check rows
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][3] == board[i][4]) {
      return current_player == PLAYER1 ? GAME_STATE_PLAYER1_WIN : GAME_STATE_PLAYER2_WIN;
    }

    // Check columns
    if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == board[3][i] && board[3][i] == board[4][i]) {
      return current_player == PLAYER1 ? GAME_STATE_PLAYER1_WIN : GAME_STATE_PLAYER2_WIN;
    }
  }

  // Check diagonals
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] == board[4][4]) {
    return current_player == PLAYER1 ? GAME_STATE_PLAYER1_WIN : GAME_STATE_PLAYER2_WIN;
  }

  if (board[0][4] != ' ' && board[0][4] == board[1][3] && board[1][3] == board[2][2] && board[2][2] == board[3][1] && board[3][1] == board[4][0]) {
    return current_player == PLAYER1 ? GAME_STATE_PLAYER1_WIN : GAME_STATE_PLAYER2_WIN;
  }

  // Check if the game is a draw
  int num_empty_cells = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        num_empty_cells++;
      }
    }
  }

  if (num_empty_cells == 0) {
    return GAME_STATE_DRAW;
  }

  // The game is still playing
  return GAME_STATE_PLAYING;
}

// Function to play the game
void play_game() {
  // Initialise the game board
  initialise_board();

  // While the game is playing
  while (game_state == GAME_STATE_PLAYING) {
    // Print the game board
    print_board();

    // Get the player's move
    get_move();

    // Check if the game is over
    game_state = check_game_over();

    // Switch to the other player
    current_player = current_player == PLAYER1 ? PLAYER2 : PLAYER1;
  }

  // Print the game board
  print_board();

  // Announce the winner
  if (game_state == GAME_STATE_PLAYER1_WIN) {
    printf("Player 1 wins!\n");
  } else if (game_state == GAME_STATE_PLAYER2_WIN) {
    printf("Player 2 wins!\n");
  } else {
    printf("The game is a draw.\n");
  }
}

// Main function
int main() {
  srand(time(NULL));

  // Play the game
  play_game();

  return 0;
}