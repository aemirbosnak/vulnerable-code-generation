//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define the game board
char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

// Define the player symbols
char player1_symbol = 'X';
char player2_symbol = 'O';

// Define the game state
enum game_state {
  IN_PROGRESS,
  PLAYER1_WIN,
  PLAYER2_WIN,
  DRAW
};

// Check if the game is over
enum game_state check_game_over() {
  // Check for horizontal wins
  for (int i = 0; i < 3; i++) {
    if (board[i * 3] == board[i * 3 + 1] && board[i * 3 + 1] == board[i * 3 + 2] && board[i * 3] != ' ') {
      return board[i * 3] == player1_symbol ? PLAYER1_WIN : PLAYER2_WIN;
    }
  }

  // Check for vertical wins
  for (int i = 0; i < 3; i++) {
    if (board[i] == board[i + 3] && board[i + 3] == board[i + 6] && board[i] != ' ') {
      return board[i] == player1_symbol ? PLAYER1_WIN : PLAYER2_WIN;
    }
  }

  // Check for diagonal wins
  if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ') {
    return board[0] == player1_symbol ? PLAYER1_WIN : PLAYER2_WIN;
  }
  if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ') {
    return board[2] == player1_symbol ? PLAYER1_WIN : PLAYER2_WIN;
  }

  // Check for a draw
  if (!strchr(board, ' ')) {
    return DRAW;
  }

  // Otherwise, the game is still in progress
  return IN_PROGRESS;
}

// Print the game board
void print_board() {
  printf("\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("| %c ", board[i * 3 + j]);
    }
    printf("|\n");
  }
  printf("\n");
}

// Get the player's move
int get_player_move(char player_symbol) {
  int move;
  do {
    printf("Player %c, enter your move (1-9): ", player_symbol);
    scanf("%d", &move);
  } while (move < 1 || move > 9 || board[move - 1] != ' ');
  return move - 1;
}

// Play the game
void play_game() {
  // Initialize the game state
  enum game_state state = IN_PROGRESS;

  // Loop until the game is over
  while (state == IN_PROGRESS) {
    // Get the player 1 move
    int move1 = get_player_move(player1_symbol);

    // Update the game board
    board[move1] = player1_symbol;

    // Print the game board
    print_board();

    // Check if the game is over
    state = check_game_over();

    // If the game is over, break out of the loop
    if (state != IN_PROGRESS) {
      break;
    }

    // Get the player 2 move
    int move2 = get_player_move(player2_symbol);

    // Update the game board
    board[move2] = player2_symbol;

    // Print the game board
    print_board();

    // Check if the game is over
    state = check_game_over();
  }

  // Print the game result
  switch (state) {
    case PLAYER1_WIN:
      printf("Player 1 wins!\n");
      break;
    case PLAYER2_WIN:
      printf("Player 2 wins!\n");
      break;
    case DRAW:
      printf("Draw!\n");
      break;
  }
}

int main() {
  // Play the game
  play_game();

  return 0;
}