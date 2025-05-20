//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Ken Thompson
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// Defining constants
#define BOARD_SIZE 3
#define PLAYER_ONE 1
#define PLAYER_TWO 2

// Function prototypes
int evaluate_board(int board[BOARD_SIZE][BOARD_SIZE]);
int minimax(int board[BOARD_SIZE][BOARD_SIZE], int depth, bool is_maximizing);
void print_board(int board[BOARD_SIZE][BOARD_SIZE]);
bool is_valid_move(int x, int y, int board[BOARD_SIZE][BOARD_SIZE]);
void make_move(int x, int y, int player, int board[BOARD_SIZE][BOARD_SIZE]);
int get_winner(int board[BOARD_SIZE][BOARD_SIZE]);
bool is_board_full(int board[BOARD_SIZE][BOARD_SIZE]);

int main() {
  int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  int turn = PLAYER_ONE;
  int winner = 0;
  int x, y;

  printf("Welcome to Tic Tac Toe!\n");
  printf("Player 1 is X and Player 2 is O.\n");

  while (winner == 0 && !is_board_full(board)) {
    printf("\n");
    print_board(board);
    printf("\n");

    if (turn == PLAYER_ONE) {
      printf("Player 1's turn (X):\n");
    } else {
      printf("Player 2's turn (O):\n");
    }

    printf("Enter the x-coordinate (1-%d): ", BOARD_SIZE);
    scanf("%d", &x);
    printf("Enter the y-coordinate (1-%d): ", BOARD_SIZE);
    scanf("%d", &y);

    // Convert input to zero-indexed coordinates
    x--;
    y--;

    if (!is_valid_move(x, y, board)) {
      printf("That move is not valid, please try again.\n");
      continue;
    }

    make_move(x, y, turn, board);

    winner = get_winner(board);

    if (winner == PLAYER_ONE) {
      printf("Player 1 (X) wins!\n");
    } else if (winner == PLAYER_TWO) {
      printf("Player 2 (O) wins!\n");
    } else if (is_board_full(board)) {
      printf("It's a tie!\n");
    }

    turn = turn == PLAYER_ONE ? PLAYER_TWO : PLAYER_ONE;
  }

  return 0;
}

// Returns the score for the current board state
int evaluate_board(int board[BOARD_SIZE][BOARD_SIZE]) {
  int winner = get_winner(board);

  // If the game is over and player one wins
  if (winner == PLAYER_ONE) {
    return 10;
  }

  // If the game is over and player two wins
  if (winner == PLAYER_TWO) {
    return -10;
  }

  // If the game is over and it's a tie
  if (is_board_full(board)) {
    return 0;
  }

  // If the game is still ongoing
  return -1;
}

// Returns the optimal score for the current player
int minimax(int board[BOARD_SIZE][BOARD_SIZE], int depth, bool is_maximizing) {
  int score = evaluate_board(board);

  // If the game is over, return the score
  if (score != -1) {
    return score;
  }

  int best_score;

  if (is_maximizing) {
    best_score = -1000;

    for (int i = 0; i < BOARD_SIZE; i++) {
      for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[i][j] == 0) {
          board[i][j] = PLAYER_ONE;
          int current_score = minimax(board, depth + 1, false);
          board[i][j] = 0;
          best_score = current_score > best_score ? current_score : best_score;
        }
      }
    }
  } else {
    best_score = 1000;

    for (int i = 0; i < BOARD_SIZE; i++) {
      for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[i][j] == 0) {
          board[i][j] = PLAYER_TWO;
          int current_score = minimax(board, depth + 1, true);
          board[i][j] = 0;
          best_score = current_score < best_score ? current_score : best_score;
        }
      }
    }
  }

  return best_score;
}

// Prints the current state of the board
void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      char symbol = board[i][j] == 1 ? 'X' : board[i][j] == 2 ? 'O' : '_';
      printf("%c ", symbol);
    }
    printf("\n");
  }
}

// Returns true if the given move is valid, false otherwise
bool is_valid_move(int x, int y, int board[BOARD_SIZE][BOARD_SIZE]) {
  if (x < 0 || y < 0 || x >= BOARD_SIZE || y >= BOARD_SIZE) {
    return false;
  }

  if (board[x][y] != 0) {
    return false;
  }

  return true;
}

// Updates the board with the given move
void make_move(int x, int y, int player, int board[BOARD_SIZE][BOARD_SIZE]) {
  board[x][y] = player;
}

// Returns the winner of the game (PLAYER_ONE, PLAYER_TWO, or 0 if no winner)
int get_winner(int board[BOARD_SIZE][BOARD_SIZE]) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    int sum = board[i][0] + board[i][1] + board[i][2];
    if (sum == 3) {
      return PLAYER_ONE;
    } else if (sum == 6) {
      return PLAYER_TWO;
    }
  }

  // Check columns
  for (int i = 0; i < BOARD_SIZE; i++) {
    int sum = board[0][i] + board[1][i] + board[2][i];
    if (sum == 3) {
      return PLAYER_ONE;
    } else if (sum == 6) {
      return PLAYER_TWO;
    }
  }

  // Check diagonals
  int sum = board[0][0] + board[1][1] + board[2][2];
  if (sum == 3) {
    return PLAYER_ONE;
  } else if (sum == 6) {
    return PLAYER_TWO;
  }

  sum = board[0][2] + board[1][1] + board[2][0];
  if (sum == 3) {
    return PLAYER_ONE;
  } else if (sum == 6) {
    return PLAYER_TWO;
  }

  return 0;
}

// Returns true if the board is full, false otherwise
bool is_board_full(int board[BOARD_SIZE][BOARD_SIZE]) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == 0) {
        return false;
      }
    }
  }
  return true;
}