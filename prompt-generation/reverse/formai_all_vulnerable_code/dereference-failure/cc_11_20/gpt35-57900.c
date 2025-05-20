//FormAI DATASET v1.0 Category: Checkers Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define EMPTY 0
#define PLAYER_1 1
#define PLAYER_2 2

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
  printf("  ");
  for (int c = 0; c < BOARD_SIZE; c++) {
    printf("%c ", c + 'A');
  }
  printf("\n");
  for (int r = 0; r < BOARD_SIZE; r++) {
    printf("%d ", r + 1);
    for (int c = 0; c < BOARD_SIZE; c++) {
      if (board[r][c] == EMPTY) {
        printf("- ");
      } else if (board[r][c] == PLAYER_1) {
        printf("O ");
      } else if (board[r][c] == PLAYER_2) {
        printf("X ");
      }
    }
    printf("%d\n", r + 1);
  }
  printf("  ");
  for (int c = 0; c < BOARD_SIZE; c++) {
    printf("%c ", c + 'A');
  }
  printf("\n");
}

int is_valid_move(int board[BOARD_SIZE][BOARD_SIZE], int player, int start_row, int start_col, int end_row, int end_col) {
  if (end_row < 0 || end_row >= BOARD_SIZE || end_col < 0 || end_col >= BOARD_SIZE) {
    return 0;
  }
  if (board[end_row][end_col] != EMPTY) {
    return 0;
  }
  if (player == PLAYER_1) {
    if (end_row > start_row) {
      return 0;
    }
    if (start_row - end_row == 1 && abs(start_col - end_col) == 1) {
      return 1;
    }
    if (start_row - end_row == 2 && abs(start_col - end_col) == 2 && board[(start_row + end_row)/2][(start_col + end_col)/2] == PLAYER_2) {
      return 1;
    }
  } else if (player == PLAYER_2) {
    if (end_row < start_row) {
      return 0;
    }
    if (end_row - start_row == 1 && abs(start_col - end_col) == 1) {
      return 1;
    }
    if (end_row - start_row == 2 && abs(start_col - end_col) == 2 && board[(start_row + end_row)/2][(start_col + end_col)/2] == PLAYER_1){
      return 1;
    }
  }
  return 0;
}

int main() {
  int board[BOARD_SIZE][BOARD_SIZE];
  for (int r = 0; r < BOARD_SIZE; r++) {
    for (int c = 0; c < BOARD_SIZE; c++) {
      if ((r + c) % 2 == 0 && r < 3) {
        board[r][c] = PLAYER_2;
      } else if ((r + c) % 2 == 0 && r > 4) {
        board[r][c] = PLAYER_1;
      } else {
        board[r][c] = EMPTY;
      }
    }
  }

  int current_player = PLAYER_1;

  while (1) {
    print_board(board);
    printf("Player %d's turn\n", current_player);

    int start_row, start_col, end_row, end_col;
    printf("Enter start position (row column): ");
    scanf("%d %d", &start_row, &start_col);
    printf("Enter end position (row column): ");
    scanf("%d %d", &end_row, &end_col);

    if (!is_valid_move(board, current_player, start_row - 1, start_col - 'A', end_row - 1, end_col - 'A')) {
      printf("Invalid move\n");
      continue;
    }

    board[start_row - 1][start_col - 'A'] = EMPTY;
    board[end_row - 1][end_col - 'A'] = current_player;

    if (current_player == PLAYER_1) {
      if (end_row == 0) {
        printf("Player 1 wins!\n");
        break;
      }
      current_player = PLAYER_2;
    } else if (current_player == PLAYER_2) {
      if (end_row == BOARD_SIZE - 1) {
        printf("Player 2 wins!\n");
        break;
      }
      current_player = PLAYER_1;
    }
  }

  return 0;
}