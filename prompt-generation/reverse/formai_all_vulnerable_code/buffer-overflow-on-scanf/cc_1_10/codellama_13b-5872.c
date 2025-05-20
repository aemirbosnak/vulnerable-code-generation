//Code Llama-13B DATASET v1.0 Category: Table Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 6
#define MAX_COLS 7

// Function to display the game board
void display_board(char board[MAX_ROWS][MAX_COLS]) {
  int i, j;
  for (i = 0; i < MAX_ROWS; i++) {
    for (j = 0; j < MAX_COLS; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a player has won the game
int check_win(char board[MAX_ROWS][MAX_COLS], char player) {
  int i, j, count = 0;
  for (i = 0; i < MAX_ROWS; i++) {
    for (j = 0; j < MAX_COLS; j++) {
      if (board[i][j] == player) {
        count++;
        if (count == 4) {
          return 1;
        }
      } else {
        count = 0;
      }
    }
  }
  return 0;
}

// Function to check if the game is a draw
int check_draw(char board[MAX_ROWS][MAX_COLS]) {
  int i, j;
  for (i = 0; i < MAX_ROWS; i++) {
    for (j = 0; j < MAX_COLS; j++) {
      if (board[i][j] == ' ') {
        return 0;
      }
    }
  }
  return 1;
}

// Function to play a turn
void play_turn(char board[MAX_ROWS][MAX_COLS], char player) {
  int row, col;
  printf("Enter a row (0-5): ");
  scanf("%d", &row);
  printf("Enter a column (0-6): ");
  scanf("%d", &col);
  board[row][col] = player;
}

int main() {
  char board[MAX_ROWS][MAX_COLS] = {
    {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' '}
  };
  char player = 'X';
  int turn = 0;
  while (1) {
    display_board(board);
    play_turn(board, player);
    turn++;
    if (check_win(board, player) || check_draw(board)) {
      break;
    }
    if (player == 'X') {
      player = 'O';
    } else {
      player = 'X';
    }
  }
  if (check_win(board, player)) {
    printf("Player %c wins!\n", player);
  } else {
    printf("It's a draw!\n");
  }
  return 0;
}