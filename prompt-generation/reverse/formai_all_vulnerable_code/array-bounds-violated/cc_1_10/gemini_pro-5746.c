//GEMINI-pro DATASET v1.0 Category: Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 3
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player symbols
#define PLAYER_X 'X'
#define PLAYER_O 'O'

// Define the game state
#define STATE_PLAYING 0
#define STATE_DRAW 1
#define STATE_X_WIN 2
#define STATE_O_WIN 3

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
      printf(" %c ", board[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// Function to check if a player has won
int check_win() {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
      return board[i][0] == PLAYER_X ? STATE_X_WIN : STATE_O_WIN;
    }
  }

  // Check columns
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
      return board[0][i] == PLAYER_X ? STATE_X_WIN : STATE_O_WIN;
    }
  }

  // Check diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    return board[0][0] == PLAYER_X ? STATE_X_WIN : STATE_O_WIN;
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
    return board[0][2] == PLAYER_X ? STATE_X_WIN : STATE_O_WIN;
  }

  // Check for draw
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        return STATE_PLAYING;
      }
    }
  }

  return STATE_DRAW;
}

// Function to get the player's move
int get_move(char player) {
  int row, col;
  printf("Player %c, enter your move (row, column): ", player);
  scanf("%d %d", &row, &col);
  return row * BOARD_SIZE + col;
}

// Function to play the game
int play_game() {
  // Initialize the game board
  init_board();

  // Print the initial game board
  print_board();

  // Get the first player's move
  int move = get_move(PLAYER_X);

  // Set the first player's move on the board
  board[move / BOARD_SIZE][move % BOARD_SIZE] = PLAYER_X;

  // Print the updated game board
  print_board();

  // Loop until the game is over
  while (1) {
    // Get the second player's move
    move = get_move(PLAYER_O);

    // Set the second player's move on the board
    board[move / BOARD_SIZE][move % BOARD_SIZE] = PLAYER_O;

    // Print the updated game board
    print_board();

    // Check if the game is over
    int state = check_win();
    if (state != STATE_PLAYING) {
      return state;
    }

    // Get the first player's move
    move = get_move(PLAYER_X);

    // Set the first player's move on the board
    board[move / BOARD_SIZE][move % BOARD_SIZE] = PLAYER_X;

    // Print the updated game board
    print_board();

    // Check if the game is over
    state = check_win();
    if (state != STATE_PLAYING) {
      return state;
    }
  }
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Play the game
  int state = play_game();

  // Print the game result
  switch (state) {
    case STATE_DRAW:
      printf("The game ended in a draw.\n");
      break;
    case STATE_X_WIN:
      printf("Player X wins!\n");
      break;
    case STATE_O_WIN:
      printf("Player O wins!\n");
      break;
  }

  return 0;
}