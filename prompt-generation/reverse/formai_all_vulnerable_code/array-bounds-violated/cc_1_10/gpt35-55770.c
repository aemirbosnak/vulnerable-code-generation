//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: future-proof
#include <stdio.h>
#include <stdbool.h>

// The size of the Tic Tac Toe board (3 for a standard 3x3 game of Tic Tac Toe)
#define BOARD_SIZE 3

// The possible states of each cell in the board
enum CellState {
  EMPTY,
  PLAYER_X,
  PLAYER_O
};

// The state of the game board
enum CellState board[BOARD_SIZE][BOARD_SIZE];

// The current player's turn
enum CellState current_player;

// The heuristic value of each possible move for the AI
int move_values[BOARD_SIZE][BOARD_SIZE] = {
  {1, 2, 1},
  {2, 4, 2},
  {1, 2, 1}
};

bool did_win(enum CellState player) {
  // Check rows
  for (int row = 0; row < BOARD_SIZE; row++) {
    bool won = true;
    for (int col = 0; col < BOARD_SIZE; col++) {
      if (board[row][col] != player) {
        won = false;
      }
    }
    if (won) {
      return true;
    }
  }

  // Check columns
  for (int col = 0; col < BOARD_SIZE; col++) {
    bool won = true;
    for (int row = 0; row < BOARD_SIZE; row++) {
      if (board[row][col] != player) {
        won = false;
      }
    }
    if (won) {
      return true;
    }
  }

  // Check diagonal top-left to bottom-right
  bool won = true;
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][i] != player) {
      won = false;
    }
  }
  if (won) {
    return true;
  }

  // Check diagonal top-right to bottom-left
  won = true;
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][BOARD_SIZE - i - 1] != player) {
      won = false;
    }
  }
  if (won) {
    return true;
  }

  return false;
}

bool is_board_full() {
  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      if (board[row][col] == EMPTY) {
        return false;
      }
    }
  }
  return true;
}

void print_board() {
  printf("\n");
  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      if (board[row][col] == PLAYER_X) {
        printf("X");
      } else if (board[row][col] == PLAYER_O) {
        printf("O");
      } else {
        printf("-");
      }
    }
    printf("\n");
  }
}

void make_move(int row, int col) {
  board[row][col] = current_player;
  if (did_win(current_player)) {
    printf("Player %d wins!\n", current_player);
    exit(0);
  } else if (is_board_full()) {
    printf("Tie game!\n");
    exit(0);
  } else {
    current_player = (current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
  }
}

void make_ai_move() {
  int max_row = 0;
  int max_col = 0;
  int max_value = move_values[0][0];

  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      if (board[row][col] == EMPTY && move_values[row][col] > max_value) {
        max_row = row;
        max_col = col;
        max_value = move_values[row][col];
      }
    }
  }

  make_move(max_row, max_col);
}

int main() {
  printf("Welcome to Tic Tac Toe!\n");

  // Initialize the board to be empty
  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      board[row][col] = EMPTY;
    }
  }

  // Randomly choose who goes first
  current_player = rand() % 2 == 0 ? PLAYER_X : PLAYER_O;

  // Main game loop
  while (true) {
    print_board();

    if (current_player == PLAYER_X) {
      printf("Player X's turn:\n");
      int row, col;
      scanf("%d %d", &row, &col);
      make_move(row, col);
    } else {
      printf("AI's turn:\n");
      make_ai_move();
    }
  }

  return 0;
}