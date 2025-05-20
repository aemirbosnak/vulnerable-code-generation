//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 5
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player symbols
#define PLAYER1_SYMBOL 'X'
#define PLAYER2_SYMBOL 'O'

// Define the game states
#define GAME_STATE_PLAYING 0
#define GAME_STATE_PLAYER1_WIN 1
#define GAME_STATE_PLAYER2_WIN 2
#define GAME_STATE_DRAW 3

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
      printf("| %c ", board[i][j]);
    }
    printf("|\n");
  }
  printf("\n");
}

// Function to check if a move is valid
int is_valid_move(int row, int col) {
  return (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ');
}

// Function to make a move
void make_move(int player, int row, int col) {
  if (player == 1) {
    board[row][col] = PLAYER1_SYMBOL;
  } else {
    board[row][col] = PLAYER2_SYMBOL;
  }
}

// Function to check if a player has won
int has_won(int player) {
  char symbol = (player == 1) ? PLAYER1_SYMBOL : PLAYER2_SYMBOL;

  // Check for horizontal wins
  for (int i = 0; i < BOARD_SIZE; i++) {
    int count = 0;
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == symbol) {
        count++;
      }
    }
    if (count == BOARD_SIZE) {
      return 1;
    }
  }

  // Check for vertical wins
  for (int i = 0; i < BOARD_SIZE; i++) {
    int count = 0;
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[j][i] == symbol) {
        count++;
      }
    }
    if (count == BOARD_SIZE) {
      return 1;
    }
  }

  // Check for diagonal wins
  int count = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][i] == symbol) {
      count++;
    }
  }
  if (count == BOARD_SIZE) {
    return 1;
  }

  count = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][BOARD_SIZE - i - 1] == symbol) {
      count++;
    }
  }
  if (count == BOARD_SIZE) {
    return 1;
  }

  return 0;
}

// Function to check if the game is a draw
int is_draw() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        return 0;
      }
    }
  }
  return 1;
}

// Function to get the next player
int get_next_player(int player) {
  return (player == 1) ? 2 : 1;
}

// Function to play the game
void play_game() {
  int game_state = GAME_STATE_PLAYING;
  int player = 1;

  while (game_state == GAME_STATE_PLAYING) {
    print_board();

    int row, col;
    printf("Player %d, enter your move (row, col): ", player);
    scanf("%d %d", &row, &col);

    if (is_valid_move(row, col)) {
      make_move(player, row, col);

      if (has_won(player)) {
        game_state = (player == 1) ? GAME_STATE_PLAYER1_WIN : GAME_STATE_PLAYER2_WIN;
      } else if (is_draw()) {
        game_state = GAME_STATE_DRAW;
      } else {
        player = get_next_player(player);
      }
    } else {
      printf("Invalid move. Please try again.\n");
    }
  }

  print_board();

  if (game_state == GAME_STATE_PLAYER1_WIN) {
    printf("Player 1 wins!\n");
  } else if (game_state == GAME_STATE_PLAYER2_WIN) {
    printf("Player 2 wins!\n");
  } else {
    printf("Draw!\n");
  }
}

// Main function
int main() {
  srand(time(NULL));

  initialize_board();
  play_game();

  return 0;
}