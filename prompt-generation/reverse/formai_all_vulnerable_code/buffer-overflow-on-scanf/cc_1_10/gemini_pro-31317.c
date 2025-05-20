//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BOARD_SIZE 3

// Define the possible states of a cell
typedef enum {
  EMPTY,
  X,
  O
} cell_state;

// Define the game board
cell_state board[BOARD_SIZE][BOARD_SIZE];

// Function to initialize the game board to empty
void init_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = EMPTY;
    }
  }
}

// Function to print the game board
void print_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      switch (board[i][j]) {
        case EMPTY:
          printf(" . ");
          break;
        case X:
          printf(" X ");
          break;
        case O:
          printf(" O ");
          break;
      }
    }
    printf("\n");
  }
}

// Function to check if a player has won
int check_win(cell_state player) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return 1;
    }
  }

  // Check columns
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
      return 1;
    }
  }

  // Check diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return 1;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return 1;
  }

  return 0;
}

// Function to get the best move for the AI
int get_best_move(cell_state player) {
  // Initialize the best move to -1
  int best_move = -1;

  // Iterate over all possible moves
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      // If the cell is empty, consider it as a potential move
      if (board[i][j] == EMPTY) {
        // Place the AI's symbol in the cell
        board[i][j] = player;

        // Check if the AI has won
        if (check_win(player)) {
          // If the AI has won, return the move
          return i * BOARD_SIZE + j;
        }

        // If the AI has not won, undo the move
        board[i][j] = EMPTY;

        // Check if the opponent can win with the next move
        if (check_win(player == X ? O : X)) {
          // If the opponent can win, block the move
          best_move = i * BOARD_SIZE + j;
        }
      }
    }
  }

  // If the AI cannot win or block the opponent, choose a random move
  if (best_move == -1) {
    while (1) {
      int move = rand() % (BOARD_SIZE * BOARD_SIZE);
      if (board[move / BOARD_SIZE][move % BOARD_SIZE] == EMPTY) {
        best_move = move;
        break;
      }
    }
  }

  return best_move;
}

// Function to play a game of Tic-Tac-Toe
void play_game() {
  // Initialize the game board
  init_board();

  // Print the initial game board
  print_board();

  // Determine which player starts first
  cell_state player = X;

  // Game loop
  while (1) {
    // Get the player's move
    int move;
    if (player == X) {
      printf("Enter your move (0-8): ");
      scanf("%d", &move);
    } else {
      move = get_best_move(player);
    }

    // Place the player's symbol on the board
    board[move / BOARD_SIZE][move % BOARD_SIZE] = player;

    // Print the updated game board
    print_board();

    // Check if the player has won
    if (check_win(player)) {
      printf("%s wins!\n", player == X ? "Human" : "AI");
      break;
    }

    // Check if the game is a draw
    int draw = 1;
    for (int i = 0; i < BOARD_SIZE; i++) {
      for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[i][j] == EMPTY) {
          draw = 0;
        }
      }
    }
    if (draw) {
      printf("Draw!\n");
      break;
    }

    // Switch the player
    player = player == X ? O : X;
  }
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play the game
  play_game();

  return 0;
}