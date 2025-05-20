//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board size
#define BOARD_SIZE 8

// Define the player symbols
#define PLAYER1 'X'
#define PLAYER2 'O'

// Define the game state
#define GAME_STATE_PLAYING 0
#define GAME_STATE_PLAYER1_WON 1
#define GAME_STATE_PLAYER2_WON 2
#define GAME_STATE_DRAW 3

// Define the game board
char board[BOARD_SIZE][BOARD_SIZE];

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
  printf("  ");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i + 1);
  }
  printf("\n");

  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i + 1);
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Check if the game is over
int check_game_over() {
  // Check for rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return board[i][0] == PLAYER1 ? GAME_STATE_PLAYER1_WON : GAME_STATE_PLAYER2_WON;
    }
  }

  // Check for columns
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
      return board[0][i] == PLAYER1 ? GAME_STATE_PLAYER1_WON : GAME_STATE_PLAYER2_WON;
    }
  }

  // Check for diagonals
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return board[0][0] == PLAYER1 ? GAME_STATE_PLAYER1_WON : GAME_STATE_PLAYER2_WON;
  }

  if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return board[0][2] == PLAYER1 ? GAME_STATE_PLAYER1_WON : GAME_STATE_PLAYER2_WON;
  }

  // Check for a draw
  int count = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] != ' ') {
        count++;
      }
    }
  }

  if (count == BOARD_SIZE * BOARD_SIZE) {
    return GAME_STATE_DRAW;
  }

  // The game is still playing
  return GAME_STATE_PLAYING;
}

// Get the player's move
int get_player_move(char player) {
  int move;

  while (1) {
    printf("Player %c, enter your move (1-%d): ", player, BOARD_SIZE);
    scanf("%d", &move);

    if (move >= 1 && move <= BOARD_SIZE) {
      return move - 1;
    } else {
      printf("Invalid move. Please try again.\n");
    }
  }
}

// Make the player's move
void make_move(char player, int move) {
  int row = move / BOARD_SIZE;
  int col = move % BOARD_SIZE;

  if (board[row][col] == ' ') {
    board[row][col] = player;
  } else {
    printf("Invalid move. Please try again.\n");
  }
}

// Play the game
void play_game() {
  char player = PLAYER1;
  int game_state = GAME_STATE_PLAYING;

  while (game_state == GAME_STATE_PLAYING) {
    print_board();

    int move = get_player_move(player);
    make_move(player, move);

    game_state = check_game_over();

    if (game_state == GAME_STATE_PLAYER1_WON) {
      printf("Player 1 wins!\n");
    } else if (game_state == GAME_STATE_PLAYER2_WON) {
      printf("Player 2 wins!\n");
    } else if (game_state == GAME_STATE_DRAW) {
      printf("Draw!\n");
    }

    // Switch players
    player = player == PLAYER1 ? PLAYER2 : PLAYER1;
  }
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Initialize the game board
  init_board();

  // Play the game
  play_game();

  return 0;
}