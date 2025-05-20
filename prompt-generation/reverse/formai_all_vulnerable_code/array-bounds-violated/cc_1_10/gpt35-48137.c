//FormAI DATASET v1.0 Category: Checkers Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

void init_board(void) {
  int row, col;

  for (row = 0; row < BOARD_SIZE; row++)
    for (col = 0; col < BOARD_SIZE; col++)
      board[row][col] = '-';
}

void print_board(void) {
  int row, col;
  
  printf("  1 2 3 4 5 6 7 8\n");
  for (row = 0; row < BOARD_SIZE; row++) {
    printf("%c ", 'a' + row);
    for (col = 0; col < BOARD_SIZE; col++)
      printf("%c ", board[row][col]);
    printf("\n");
  }
}

int main(void) {
  int player = 1;
  int game_over = 0;
  char input[5];

  init_board();

  while (!game_over) {
    printf("\n");
    printf("Player %d, make your move (e.g. a2 to b3): ", player);
    fgets(input, sizeof(input), stdin);
    int from_col = input[0] - 'a';
    int from_row = input[1] - '1';
    int to_col = input[3] - 'a';
    int to_row = input[4] - '1';

    if (board[from_row][from_col] == '-') {
      printf("Invalid move. Try again.\n");
      continue;
    }

    if (board[to_row][to_col] != '-') {
      printf("You cannot move there. Try again.\n");
      continue;
    }

    board[from_row][from_col] = '-';
    board[to_row][to_col] = (player == 1) ? 'O' : 'X';

    print_board();
    
    // Check for end of game
    game_over = 1; // Assume game is over until we find a move
    for (int row = 0; row < BOARD_SIZE; row++) {
      for (int col = 0; col < BOARD_SIZE; col++) {
        if (board[row][col] == '-') {
          game_over = 0; // Found a move, game is not over yet
          break;
        }
      }
    }

    // Switch to other player
    player = (player == 1) ? 2 : 1;
  }

  printf("Game over!\n");
  return 0;
}