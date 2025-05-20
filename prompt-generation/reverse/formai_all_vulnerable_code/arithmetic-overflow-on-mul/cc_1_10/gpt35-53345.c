//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Linus Torvalds
/*
 * My Bingo Simulator - a unique program that allows the user to play Bingo with a Linux twist!
 * Written by [Your Name]
 * Inspired by Linus Torvalds
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Define global variables
#define ROWS 5
#define COLS 5

// Define function prototypes
void display_board(char board[ROWS][COLS]);
int call_number();
void mark_board(char board[ROWS][COLS], int num);
int check_bingo(char board[ROWS][COLS]);

// Begin main function
int main() {
  char board[ROWS][COLS] = {
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '}
  };
  int num, bingo = 0;

  printf("Welcome to My Bingo Simulator!\nLet's get started...\n\n");

  while (!bingo) {
    // Display board
    display_board(board);

    // Get next number and mark board
    num = call_number();
    mark_board(board, num);

    // Check for bingo
    bingo = check_bingo(board);
  }

  // Display final board and winning message
  printf("\n\nBINGO!!!\n\n");
  display_board(board);

  return 0;
}

// Function to display the board
void display_board(char board[ROWS][COLS]) {
  printf("-------------------------\n");
  for (int i = 0; i < ROWS; i++) {
    printf("| ");
    for (int j = 0; j < COLS; j++) {
      printf("%c | ", board[i][j]);
    }
    printf("\n-------------------------\n");
  }
}

// Function to get next number
int call_number() {
  srand(time(0));
  int num = rand() % 25 + 1;
  printf("Next Number: %d\n", num);
  return num;
}

// Function to mark board
void mark_board(char board[ROWS][COLS], int num) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (board[i][j] == ' ' && num == i * COLS + j + 1) {
        board[i][j] = 'X';
        return;
      }
    }
  }
}

// Function to check for bingo
int check_bingo(char board[ROWS][COLS]) {
  int row, col, diag1 = 1, diag2 = 1;
  for (row = 0; row < ROWS; row++) {
    int sum = 0;
    for (col = 0; col < COLS; col++) {
      sum += board[row][col];
    }
    if (sum == 4 * 'X') return 1;
  }
  for (col = 0; col < COLS; col++) {
    int sum = 0;
    for (row = 0; row < ROWS; row++) {
      sum += board[row][col];
    }
    if (sum == 4 * 'X') return 1;
  }
  for (row = 0; row < ROWS; row++) {
    diag1 *= board[row][row];
    diag2 *= board[row][COLS - row - 1];
  }
  if (diag1 == 'X' * 'X' * 'X' * 'X') return 1;
  if (diag2 == 'X' * 'X' * 'X' * 'X') return 1;
  return 0;
}