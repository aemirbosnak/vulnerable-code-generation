//GEMINI-pro DATASET v1.0 Category: Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 3
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player symbols
#define PLAYER_X 'X'
#define PLAYER_O 'O'

// Define the game states
#define GAME_STATE_PLAYING 0
#define GAME_STATE_DRAW 1
#define GAME_STATE_X_WIN 2
#define GAME_STATE_O_WIN 3

// Function to initialize the game board
void init_board() {
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
}

// Function to check if a player has won
int check_win(char player) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return player == PLAYER_X ? GAME_STATE_X_WIN : GAME_STATE_O_WIN;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
      return player == PLAYER_X ? GAME_STATE_X_WIN : GAME_STATE_O_WIN;
    }
  }

  // Check diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return player == PLAYER_X ? GAME_STATE_X_WIN : GAME_STATE_O_WIN;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return player == PLAYER_X ? GAME_STATE_X_WIN : GAME_STATE_O_WIN;
  }

  // No winner yet
  return GAME_STATE_PLAYING;
}

// Function to get the next player's move
int get_move(char player) {
  int row, col;

  printf("Player %c's turn: ", player);
  scanf("%d %d", &row, &col);

  // Validate the move
  while (row < 1 || row > BOARD_SIZE || col < 1 || col > BOARD_SIZE || board[row - 1][col - 1] != ' ') {
    printf("Invalid move. Try again: ");
    scanf("%d %d", &row, &col);
  }

  // Return the move
  return row - 1;
}

// Function to play the game
int play_game() {
  // Initialize the game board
  init_board();

  // Set the current player
  char current_player = PLAYER_X;

  // Play the game until a winner is declared or a draw occurs
  int game_state = GAME_STATE_PLAYING;
  while (game_state == GAME_STATE_PLAYING) {
    // Get the next player's move
    int row = get_move(current_player);

    // Place the player's symbol on the board
    board[row][0] = current_player;

    // Print the game board
    print_board();

    // Check if the player has won
    game_state = check_win(current_player);

    // Switch to the other player
    current_player = current_player == PLAYER_X ? PLAYER_O : PLAYER_X;
  }

  // Declare the winner or draw
  if (game_state == GAME_STATE_X_WIN) {
    printf("Player X wins!\n");
  } else if (game_state == GAME_STATE_O_WIN) {
    printf("Player O wins!\n");
  } else {
    printf("Draw!\n");
  }

  return 0;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play the game
  play_game();

  return 0;
}