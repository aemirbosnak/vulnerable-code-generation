//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the game board size
#define BOARD_SIZE 4

// Define the player types
#define PLAYER_ONE 'X'
#define PLAYER_TWO 'O'

// Define the game state
#define GAME_NOT_OVER 0
#define GAME_OVER_TIE 1
#define GAME_OVER_PLAYER_ONE_WIN 2
#define GAME_OVER_PLAYER_TWO_WIN 3

// Define the function to print the game board
void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Define the function to check if the game is over
int check_game_over(char board[BOARD_SIZE][BOARD_SIZE]) {
  // Check for a tie
  int tie = 1;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        tie = 0;
        break;
      }
    }
  }
  if (tie) {
    return GAME_OVER_TIE;
  }

  // Check for a win
  for (int i = 0; i < BOARD_SIZE; i++) {
    // Check rows
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3]) {
      return board[i][0] == PLAYER_ONE ? GAME_OVER_PLAYER_ONE_WIN : GAME_OVER_PLAYER_TWO_WIN;
    }

    // Check columns
    if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == board[3][i]) {
      return board[0][i] == PLAYER_ONE ? GAME_OVER_PLAYER_ONE_WIN : GAME_OVER_PLAYER_TWO_WIN;
    }
  }

  // Check diagonals
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3]) {
    return board[0][0] == PLAYER_ONE ? GAME_OVER_PLAYER_ONE_WIN : GAME_OVER_PLAYER_TWO_WIN;
  }
  if (board[0][3] != ' ' && board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[2][1] == board[3][0]) {
    return board[0][3] == PLAYER_ONE ? GAME_OVER_PLAYER_ONE_WIN : GAME_OVER_PLAYER_TWO_WIN;
  }

  // The game is not over
  return GAME_NOT_OVER;
}

// Define the function to get the player's move
int get_player_move(char board[BOARD_SIZE][BOARD_SIZE], char player) {
  int move;

  do {
    printf("Player %c, enter your move (1-9): ", player);
    scanf("%d", &move);
  } while (move < 1 || move > 9 || board[(move - 1) / BOARD_SIZE][(move - 1) % BOARD_SIZE] != ' ');

  return move - 1;
}

// Define the function to play the game
void play_game() {
  // Create the game board
  char board[BOARD_SIZE][BOARD_SIZE];
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }

  // Set the current player
  char current_player = PLAYER_ONE;

  // Play the game until it is over
  int game_over = GAME_NOT_OVER;
  while (game_over == GAME_NOT_OVER) {
    // Print the game board
    print_board(board);

    // Get the player's move
    int move = get_player_move(board, current_player);

    // Place the player's move on the board
    board[move / BOARD_SIZE][move % BOARD_SIZE] = current_player;

    // Check if the game is over
    game_over = check_game_over(board);

    // Switch the current player
    current_player = current_player == PLAYER_ONE ? PLAYER_TWO : PLAYER_ONE;
  }

  // Print the game board
  print_board(board);

  // Announce the winner
  switch (game_over) {
    case GAME_OVER_TIE:
      printf("Tie game!\n");
      break;
    case GAME_OVER_PLAYER_ONE_WIN:
      printf("Player One wins!\n");
      break;
    case GAME_OVER_PLAYER_TWO_WIN:
      printf("Player Two wins!\n");
      break;
  }
}

// Define the main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play the game
  play_game();

  return 0;
}