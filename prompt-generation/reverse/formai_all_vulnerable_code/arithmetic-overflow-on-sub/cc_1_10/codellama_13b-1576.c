//Code Llama-13B DATASET v1.0 Category: Game ; Style: cheerful
// Cheerful C Game Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WINNER 3
#define PLAYERS 4

// Function Declarations
void print_board(int board[PLAYERS][PLAYERS]);
void get_player_move(int board[PLAYERS][PLAYERS], int player, int *row, int *col);
void make_move(int board[PLAYERS][PLAYERS], int player, int row, int col);
int check_win(int board[PLAYERS][PLAYERS]);

int main() {
  int board[PLAYERS][PLAYERS] = {0};
  int player = 1;
  int row, col;

  // Initialize board
  for (int i = 0; i < PLAYERS; i++) {
    for (int j = 0; j < PLAYERS; j++) {
      board[i][j] = 0;
    }
  }

  // Print initial board
  print_board(board);

  // Play game until a winner is found
  while (1) {
    // Get player move
    get_player_move(board, player, &row, &col);

    // Make move
    make_move(board, player, row, col);

    // Print updated board
    print_board(board);

    // Check for winner
    if (check_win(board)) {
      printf("Player %d wins!\n", player);
      break;
    }

    // Next player
    player++;
    if (player > PLAYERS) player = 1;
  }

  return 0;
}

// Function Definitions

void print_board(int board[PLAYERS][PLAYERS]) {
  printf(" 1 | 2 | 3 \n");
  printf(" ---------\n");
  printf(" 4 | 5 | 6 \n");
  printf(" ---------\n");
  printf(" 7 | 8 | 9 \n");
  printf("\n");
}

void get_player_move(int board[PLAYERS][PLAYERS], int player, int *row, int *col) {
  printf("Player %d, enter row and column (1-9): ", player);
  scanf("%d %d", row, col);
  while (board[*row - 1][*col - 1] != 0) {
    printf("Invalid move, try again: ");
    scanf("%d %d", row, col);
  }
}

void make_move(int board[PLAYERS][PLAYERS], int player, int row, int col) {
  board[row - 1][col - 1] = player;
}

int check_win(int board[PLAYERS][PLAYERS]) {
  // Check rows
  for (int i = 0; i < PLAYERS; i++) {
    int count = 0;
    for (int j = 0; j < PLAYERS; j++) {
      if (board[i][j] == 1) count++;
    }
    if (count == WINNER) return 1;
  }

  // Check columns
  for (int i = 0; i < PLAYERS; i++) {
    int count = 0;
    for (int j = 0; j < PLAYERS; j++) {
      if (board[j][i] == 1) count++;
    }
    if (count == WINNER) return 1;
  }

  // Check diagonals
  int count = 0;
  for (int i = 0; i < PLAYERS; i++) {
    if (board[i][i] == 1) count++;
  }
  if (count == WINNER) return 1;

  count = 0;
  for (int i = 0; i < PLAYERS; i++) {
    if (board[i][PLAYERS - i - 1] == 1) count++;
  }
  if (count == WINNER) return 1;

  return 0;
}