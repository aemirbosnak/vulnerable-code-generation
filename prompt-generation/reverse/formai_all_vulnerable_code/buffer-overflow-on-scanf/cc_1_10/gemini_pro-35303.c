//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Define the game board
#define BOARD_SIZE 4
int board[BOARD_SIZE][BOARD_SIZE];

// Define the player's turn
typedef enum {
  PLAYER_1,
  PLAYER_2
} Player;

// Define the game state
typedef enum {
  IN_PROGRESS,
  PLAYER_1_WIN,
  PLAYER_2_WIN,
  DRAW
} GameState;

// Initialize the game board
void init_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = 0;
    }
  }
}

// Print the game board
void print_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

// Get the player's move
Player get_move() {
  int row, col;
  printf("Enter your move (row, col): ");
  scanf("%d %d", &row, &col);

  // Check if the move is valid
  if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != 0) {
    printf("Invalid move!\n");
    return get_move();
  }

  return (board[row][col] == 0) ? PLAYER_1 : PLAYER_2;
}

// Make a move
void make_move(Player player, int row, int col) {
  board[row][col] = (player == PLAYER_1) ? 1 : 2;
}

// Check if the game is over
GameState check_game_over() {
  // Check for a win
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3]) {
      return (board[i][0] == 1) ? PLAYER_1_WIN : PLAYER_2_WIN;
    }
  }

  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] != 0 && board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] == board[3][j]) {
      return (board[0][j] == 1) ? PLAYER_1_WIN : PLAYER_2_WIN;
    }
  }

  // Check for a draw
  int count = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] != 0) {
        count++;
      }
    }
  }

  if (count == BOARD_SIZE * BOARD_SIZE) {
    return DRAW;
  }

  // The game is still in progress
  return IN_PROGRESS;
}

int main() {
  // Initialize the game
  init_board();

  // Play the game
  GameState state = IN_PROGRESS;
  Player current_player = PLAYER_1;
  while (state == IN_PROGRESS) {
    // Print the game board
    print_board();

    // Get the player's move
    Player player = get_move();

    // Make the move
    int row, col;
    printf("Enter the row and column of your move: ");
    scanf("%d %d", &row, &col);
    make_move(player, row, col);

    // Check if the game is over
    state = check_game_over();
  }

  // Print the game result
  switch (state) {
    case PLAYER_1_WIN:
      printf("Player 1 wins!\n");
      break;
    case PLAYER_2_WIN:
      printf("Player 2 wins!\n");
      break;
    case DRAW:
      printf("Draw!\n");
      break;
  }

  return 0;
}