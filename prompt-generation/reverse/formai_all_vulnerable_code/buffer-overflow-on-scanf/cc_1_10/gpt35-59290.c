//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the Tic Tac Toe board
void print_board(char board[3][3]) {
  printf("\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf(" %c ", board[i][j]);
      if (j != 2) {
        printf("|");
      }
    }
    printf("\n");
    if (i != 2) {
      printf("---|---|---\n");
    }
  }
  printf("\n");
}

// Function to check if the game has ended
int game_over(char board[3][3]) {
  // Check rows
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return 1;
    }
  }
  // Check columns
  for (int j = 0; j < 3; j++) {
    if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
      return 1;
    }
  }
  // Check diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return 1;
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return 1;
  }
  // Check if board is full
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
        return 0;
      }
    }
  }
  return 2;
}

// Function for AI to make a move
void make_move(char board[3][3], char ai, char player) {
  // Check for winning move
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
        board[i][j] = ai;
        if (game_over(board) == 1) {
          return;
        }
        board[i][j] = ' ';
      }
    }
  }
  // Check for blocking move
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
        board[i][j] = player;
        if (game_over(board) == 1) {
          board[i][j] = ai;
          return;
        }
        board[i][j] = ' ';
      }
    }
  }
  // Random move
  srand(time(NULL));
  int i, j;
  do {
    i = rand() % 3;
    j = rand() % 3;
  } while (board[i][j] != ' ');
  board[i][j] = ai;
}

// Main function to play the game
int main() {
  char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
  };
  char player = 'X';
  char ai = 'O';
  int game_status = 0;
  printf("Welcome to Tic Tac Toe!\n");
  printf("You are %c and the AI is %c.\n\n", player, ai);
  while (game_status == 0) {
    if (player == 'X') {
      print_board(board);
      printf("Enter your move (row column): ");
      int row, col;
      scanf("%d %d", &row, &col);
      row--;
      col--;
      if (row < 0 || row > 2 || col < 0 || col > 2) {
        printf("Invalid move! Try again.\n\n");
        continue;
      }
      if (board[row][col] == ' ') {
        board[row][col] = player;
        player = ai;
      } else {
        printf("That spot is already taken! Try again.\n\n");
        continue;
      }
    } else {
      printf("AI is making a move...\n");
      make_move(board, ai, player);
      player = 'X';
    }
    game_status = game_over(board);
  }
  print_board(board);
  if (game_status == 1) {
    if (player == 'X') {
      printf("Congratulations, you win!\n");
    } else {
      printf("AI wins! Better luck next time.\n");
    }
  } else {
    printf("It's a tie!\n");
  }
  return 0;
}