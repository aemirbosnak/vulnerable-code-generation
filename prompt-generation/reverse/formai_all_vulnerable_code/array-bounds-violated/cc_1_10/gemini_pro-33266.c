//GEMINI-pro DATASET v1.0 Category: Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 3
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player symbols
#define PLAYER_ONE 'X'
#define PLAYER_TWO 'O'

// Define the game states
#define GAME_STATE_PLAYING 1
#define GAME_STATE_PLAYER_ONE_WIN 2
#define GAME_STATE_PLAYER_TWO_WIN 3
#define GAME_STATE_TIE 4

// Check if the game is over
int check_game_over() {
  // Check if there are three of the same symbol in a row, column, or diagonal
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
      return board[i][0] == PLAYER_ONE ? GAME_STATE_PLAYER_ONE_WIN : GAME_STATE_PLAYER_TWO_WIN;
    }
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
      return board[0][i] == PLAYER_ONE ? GAME_STATE_PLAYER_ONE_WIN : GAME_STATE_PLAYER_TWO_WIN;
    }
  }
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    return board[0][0] == PLAYER_ONE ? GAME_STATE_PLAYER_ONE_WIN : GAME_STATE_PLAYER_TWO_WIN;
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
    return board[0][2] == PLAYER_ONE ? GAME_STATE_PLAYER_ONE_WIN : GAME_STATE_PLAYER_TWO_WIN;
  }

  // Check if the board is full
  int is_board_full = 1;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        is_board_full = 0;
        break;
      }
    }
  }
  if (is_board_full) {
    return GAME_STATE_TIE;
  }

  // The game is still playing
  return GAME_STATE_PLAYING;
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
  printf("\n");
}

// Get the player's move
int get_player_move(char player_symbol) {
  int row, column;

  // Get the player's row and column
  printf("Enter your move, %c (row, column): ", player_symbol);
  scanf("%d %d", &row, &column);

  // Check if the move is valid
  while (row < 1 || row > BOARD_SIZE || column < 1 || column > BOARD_SIZE || board[row - 1][column - 1] != ' ') {
    printf("Invalid move. Try again: ");
    scanf("%d %d", &row, &column);
  }

  // Return the move
  return row * BOARD_SIZE + column;
}

// Play the game
int play_game() {
  // Initialize the game board
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }

  // Set the current player
  char current_player = PLAYER_ONE;

  // Play the game until it is over
  int game_state;
  do {
    // Print the game board
    print_board();

    // Get the player's move
    int move = get_player_move(current_player);

    // Update the game board
    int row = (move - 1) / BOARD_SIZE;
    int column = (move - 1) % BOARD_SIZE;
    board[row][column] = current_player;

    // Check if the game is over
    game_state = check_game_over();

    // Switch to the other player
    current_player = current_player == PLAYER_ONE ? PLAYER_TWO : PLAYER_ONE;
  } while (game_state == GAME_STATE_PLAYING);

  // Print the game board
  print_board();

  // Print the game result
  switch (game_state) {
    case GAME_STATE_PLAYER_ONE_WIN:
      printf("Player One wins!\n");
      break;
    case GAME_STATE_PLAYER_TWO_WIN:
      printf("Player Two wins!\n");
      break;
    case GAME_STATE_TIE:
      printf("Tie game!\n");
      break;
  }

  return 0;
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play the game
  play_game();

  return 0;
}