//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

// The board is represented as a 2D array of characters.
char board[BOARD_SIZE][BOARD_SIZE];

// The player's symbol.
char player_symbol;

// The AI's symbol.
char ai_symbol;

// The current player.
char current_player;

// The winner of the game.
char winner;

// Initialize the game.
void init_game() {
  // Set all the board positions to empty.
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }

  // Set the player's symbol.
  player_symbol = 'X';

  // Set the AI's symbol.
  ai_symbol = 'O';

  // Set the current player to the player.
  current_player = player_symbol;

  // Set the winner to no winner yet.
  winner = ' ';
}

// Print the game board.
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

// Check if the game is over.
int is_game_over() {
  // Check if there is a winner.
  if (winner != ' ') {
    return 1;
  }

  // Check if there are any empty positions.
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        return 0;
      }
    }
  }

  // The game is a draw.
  return 1;
}

// Get the winner of the game.
char get_winner() {
  return winner;
}

// Make a move.
void make_move(int row, int col) {
  // Check if the move is valid.
  if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != ' ') {
    printf("Invalid move.\n");
    return;
  }

  // Make the move.
  board[row][col] = current_player;

  // Check if the move wins the game.
  if (check_for_win(row, col)) {
    winner = current_player;
  }

  // Switch the current player.
  if (current_player == player_symbol) {
    current_player = ai_symbol;
  } else {
    current_player = player_symbol;
  }
}

// Check if the move wins the game.
int check_for_win(int row, int col) {
  // Check the row.
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[row][i] != current_player) {
      break;
    }
    if (i == BOARD_SIZE - 1) {
      return 1;
    }
  }

  // Check the column.
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][col] != current_player) {
      break;
    }
    if (i == BOARD_SIZE - 1) {
      return 1;
    }
  }

  // Check the diagonal.
  if (row == col) {
    for (int i = 0; i < BOARD_SIZE; i++) {
      if (board[i][i] != current_player) {
        break;
      }
      if (i == BOARD_SIZE - 1) {
        return 1;
      }
    }
  }

  // Check the other diagonal.
  if (row + col == BOARD_SIZE - 1) {
    for (int i = 0; i < BOARD_SIZE; i++) {
      if (board[i][BOARD_SIZE - i - 1] != current_player) {
        break;
      }
      if (i == BOARD_SIZE - 1) {
        return 1;
      }
    }
  }

  // The move does not win the game.
  return 0;
}

// Get the AI's move.
void get_ai_move(int *row, int *col) {
  // TODO: Implement the AI's move.

  // For now, just make a random move.
  *row = rand() % BOARD_SIZE;
  *col = rand() % BOARD_SIZE;
}

// Play the game.
void play_game() {
  // Initialize the game.
  init_game();

  // Print the game board.
  print_board();

  // Play until the game is over.
  while (!is_game_over()) {
    // Get the player's move.
    int row;
    int col;
    printf("Enter your move (row, col): ");
    scanf("%d %d", &row, &col);

    // Make the player's move.
    make_move(row, col);

    // Print the game board.
    print_board();

    // Check if the player won.
    if (winner == player_symbol) {
      printf("You win!\n");
      break;
    }

    // Get the AI's move.
    get_ai_move(&row, &col);

    // Make the AI's move.
    make_move(row, col);

    // Print the game board.
    print_board();

    // Check if the AI won.
    if (winner == ai_symbol) {
      printf("You lose!\n");
      break;
    }
  }

  // Print the winner.
  if (winner == ' ') {
    printf("Draw!\n");
  }
}

// Main function.
int main() {
  // Play the game.
  play_game();

  return 0;
}