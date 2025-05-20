//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: shocked
#include <stdio.h>
  #include <stdlib.h>
  #include <time.h>

  #define ROWS 3
  #define COLS 3

  void print_board(int board[ROWS][COLS]) {
      for (int i = 0; i < ROWS; i++) {
          for (int j = 0; j < COLS; j++) {
              printf("%c ", board[i][j]);
          }
          printf("\n");
      }
  }

  void make_move(int board[ROWS][COLS], int row, int col, char player) {
      board[row][col] = player;
  }

  int check_win(int board[ROWS][COLS]) {
      int i, j, k, l;
      for (i = 0; i < ROWS; i++) {
          for (j = 0; j < COLS; j++) {
              if (board[i][j] == 'X') {
                  for (k = 0; k < ROWS; k++) {
                      for (l = 0; l < COLS; l++) {
                          if (board[k][l] == 'X') {
                              if (i == k && j == l) {
                                  return 1;
                              }
                          }
                      }
                  }
              }
          }
      }
      return 0;
  }

  int main() {
      int board[ROWS][COLS] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
      int row, col;
      char player = 'X';
      while (1) {
          print_board(board);
          printf("Player %c's turn (row, col): ", player);
          scanf("%d, %d", &row, &col);
          if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
              printf("Invalid move!\n");
              continue;
          }
          if (board[row][col] != 0) {
              printf("Square is already occupied!\n");
              continue;
          }
          make_move(board, row, col, player);
          if (check_win(board)) {
              printf("Player %c wins!\n", player);
              break;
          }
          player = player == 'X' ? 'O' : 'X';
      }
      return 0;
  }