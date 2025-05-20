//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
char game_board[3][3] = {
  {' ', ' ', ' '},
  {' ', ' ', ' '},
  {' ', ' ', ' '}
};

// Define the players
char player1 = 'X';
char player2 = 'O';

// Define the game state
enum game_state {
  PLAYING,
  PLAYER1_WINS,
  PLAYER2_WINS,
  DRAW
};

// Define the game functions
void print_board();
int check_game_state();
void make_move(int player, int row, int col);
int check_valid_move(int row, int col);

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Set the initial game state
  enum game_state state = PLAYING;

  // Play the game until someone wins or there is a draw
  while (state == PLAYING) {
    // Print the game board
    print_board();

    // Get the move from the current player
    int player = 1;
    int row, col;
    printf("Player %d, enter your move (row, col): ", player);
    scanf("%d %d", &row, &col);

    // Check if the move is valid
    if (!check_valid_move(row, col)) {
      printf("Invalid move. Please try again.\n");
      continue;
    }

    // Make the move
    make_move(player, row, col);

    // Check the game state
    state = check_game_state();
  }

  // Print the final game board
  print_board();

  // Print the game result
  switch (state) {
    case PLAYER1_WINS:
      printf("Player 1 wins!\n");
      break;
    case PLAYER2_WINS:
      printf("Player 2 wins!\n");
      break;
    case DRAW:
      printf("Draw!\n");
      break;
  }

  return 0;
}

void print_board() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%c", game_board[i][j]);
      if (j < 2) {
        printf("|");
      }
    }
    printf("\n");
    if (i < 2) {
      printf("---+---+---\n");
    }
  }
}

int check_game_state() {
  // Check if there is a winner
  for (int i = 0; i < 3; i++) {
    if (game_board[i][0] != ' ' && game_board[i][0] == game_board[i][1] && game_board[i][1] == game_board[i][2]) {
      return game_board[i][0] == player1 ? PLAYER1_WINS : PLAYER2_WINS;
    }
    if (game_board[0][i] != ' ' && game_board[0][i] == game_board[1][i] && game_board[1][i] == game_board[2][i]) {
      return game_board[0][i] == player1 ? PLAYER1_WINS : PLAYER2_WINS;
    }
  }
  if (game_board[0][0] != ' ' && game_board[0][0] == game_board[1][1] && game_board[1][1] == game_board[2][2]) {
    return game_board[0][0] == player1 ? PLAYER1_WINS : PLAYER2_WINS;
  }
  if (game_board[0][2] != ' ' && game_board[0][2] == game_board[1][1] && game_board[1][1] == game_board[2][0]) {
    return game_board[0][2] == player1 ? PLAYER1_WINS : PLAYER2_WINS;
  }

  // Check if there is a draw
  int num_empty_cells = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (game_board[i][j] == ' ') {
        num_empty_cells++;
      }
    }
  }
  if (num_empty_cells == 0) {
    return DRAW;
  }

  // Otherwise, the game is still playing
  return PLAYING;
}

void make_move(int player, int row, int col) {
  game_board[row][col] = player == 1 ? player1 : player2;
}

int check_valid_move(int row, int col) {
  return row >= 0 && row < 3 && col >= 0 && col < 3 && game_board[row][col] == ' ';
}