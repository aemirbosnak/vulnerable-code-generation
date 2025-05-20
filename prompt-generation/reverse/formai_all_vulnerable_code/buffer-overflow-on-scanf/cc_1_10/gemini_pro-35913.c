//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define the game board
#define BOARD_SIZE 5
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player symbols
#define PLAYER1_SYMBOL 'X'
#define PLAYER2_SYMBOL 'O'

// Initialize the game board
void init_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }
}

// Display the game board
void print_board() {
  printf("   0 1 2 3 4\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i);
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Check if the game is over
int check_game_over() {
  // Check for a win in rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][3] == board[i][4]) {
      return 1;
    }
  }

  // Check for a win in columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] == board[3][j] && board[3][j] == board[4][j]) {
      return 1;
    }
  }

  // Check for a win in diagonals
  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] == board[4][4]) {
    return 1;
  }
  if (board[0][4] != ' ' && board[0][4] == board[1][3] && board[1][3] == board[2][2] && board[2][2] == board[3][1] && board[3][1] == board[4][0]) {
    return 1;
  }

  // Check for a tie
  int tie = 1;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        tie = 0;
      }
    }
  }
  if (tie) {
    return 2;
  }

  // The game is not over yet
  return 0;
}

// Get the player's move
int get_player_move(char player_symbol) {
  int move;
  printf("Player %c, enter your move (0-4): ", player_symbol);
  scanf("%d", &move);
  return move;
}

// Make the player's move
void make_move(int move, char player_symbol) {
  int row = move / BOARD_SIZE;
  int col = move % BOARD_SIZE;
  board[row][col] = player_symbol;
}

// Play the game
void play_game() {
  // Initialize the game board
  init_board();

  // Main game loop
  int game_over = 0;
  char current_player_symbol = PLAYER1_SYMBOL;
  while (!game_over) {
    // Display the game board
    print_board();

    // Get the player's move
    int move = get_player_move(current_player_symbol);

    // Make the player's move
    make_move(move, current_player_symbol);

    // Check if the game is over
    game_over = check_game_over();

    // Switch to the other player
    current_player_symbol = current_player_symbol == PLAYER1_SYMBOL ? PLAYER2_SYMBOL : PLAYER1_SYMBOL;
  }

  // Display the game result
  if (game_over == 1) {
    printf("Player %c wins!\n", current_player_symbol == PLAYER1_SYMBOL ? PLAYER2_SYMBOL : PLAYER1_SYMBOL);
  } else {
    printf("Tie game!\n");
  }
}

int main() {
  // Play the game
  play_game();

  return 0;
}