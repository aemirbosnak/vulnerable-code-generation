//FormAI DATASET v1.0 Category: Table Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLUMNS 3

// Function to display the game board
void display_board(char board[][COLUMNS]) {
  int i, j;
  printf("\n");
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLUMNS; j++) {
      printf(" %c \t", board[i][j]);
      if (j != COLUMNS - 1) printf("|");
    }
    printf("\n");
    if (i != ROWS - 1) printf("----------------------------\n");
  }
  printf("\n");
}

// Function to check if the game board is full
int is_full(char board[][COLUMNS]) {
  int i, j;
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLUMNS; j++) {
      if (board[i][j] == ' ') return 0;
    }
  }
  return 1;
}

// Function to check if the player has won
int is_winner(char board[][COLUMNS], char player) {
  if ((board[0][0] == player && board[0][1] == player && board[0][2] == player) ||
      (board[1][0] == player && board[1][1] == player && board[1][2] == player) ||
      (board[2][0] == player && board[2][1] == player && board[2][2] == player) ||
      (board[0][0] == player && board[1][0] == player && board[2][0] == player) ||
      (board[0][1] == player && board[1][1] == player && board[2][1] == player) ||
      (board[0][2] == player && board[1][2] == player && board[2][2] == player) ||
      (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
      (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
    return 1;
  }
  return 0;
}

// Function to get the player's move
void get_move(char board[][COLUMNS], char player) {
  int row, col;
  do {
    printf("Player %c, enter row and column (e.g. 1 2): ", player);
    scanf("%d %d", &row, &col);
  } while (board[row-1][col-1] != ' ');
  board[row-1][col-1] = player;
}

// Main function
int main() {
  char board[ROWS][COLUMNS] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
  char players[2] = {'X', 'O'};
  int current_player = 0;
  srand(time(NULL));
  int random_index = rand() % 2;
  int winner = 0;
  display_board(board);
  printf("Player %c will go first.\n", players[random_index]);
  while (!is_full(board) && !winner) {
    current_player = (current_player + random_index) % 2;
    get_move(board, players[current_player]);
    display_board(board);
    if (is_winner(board, players[current_player])) {
      printf("Player %c wins!\n", players[current_player]);
      winner = 1;
    }
  }
  if (!winner) {
    printf("Tie game.\n");
  }
  return 0;
}