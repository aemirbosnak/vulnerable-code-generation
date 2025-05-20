//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Function to print the Tic Tac Toe board
void print_board(char board[3][3]) {
  printf("\n");
  printf("\t %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
  printf("\t-----------\n");
  printf("\t %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
  printf("\t-----------\n");
  printf("\t %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

// Function to check win condition
int check_win_condition(char board[3][3], char player) {
  int i, j, row_win, col_win, diag_win;
  
  // Check rows
  for (i = 0; i < 3; i++) {
    row_win = 1;
    for (j = 0; j < 3; j++) {
      if (board[i][j] != player) {
        row_win = 0;
        break;
      }
    }
    if (row_win == 1) {
      return 1;
    }
  }
  
  // Check columns
  for (i = 0; i < 3; i++) {
    col_win = 1;
    for (j = 0; j < 3; j++) {
      if (board[j][i] != player) {
        col_win = 0;
        break;
      }
    }
    if (col_win == 1) {
      return 1;
    }
  }
  
  // Check diagonals
  diag_win = 1;
  for (i = 0; i < 3; i++) {
    if (board[i][i] != player) {
      diag_win = 0;
      break;
    }
  }
  if (diag_win == 1) {
    return 1;
  }
  
  diag_win = 1;
  for (i = 0; i < 3; i++) {
    if (board[i][2-i] != player) {
      diag_win = 0;
      break;
    }
  }
  if (diag_win == 1) {
    return 1;
  }
  
  return 0;
}

// Function to get the user's move
void get_user_move(char board[3][3], char player) {
  int row, col;
  
  printf("%c's turn. Enter row (1-3): ", player);
  scanf("%d", &row);
  printf("%c's turn. Enter column (1-3): ", player);
  scanf("%d", &col);
  
  if (board[row-1][col-1] != '-') {
    printf("Invalid move. Try again.\n");
    get_user_move(board, player);
  } else {
    board[row-1][col-1] = player;
  }
  
  print_board(board);
}

// Function to get the computer's move
void get_computer_move(char board[3][3], char player) {
  int i, j, row, col;
  srand(time(NULL));
  
  // Check for win condition
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (board[i][j] == '-') {
        board[i][j] = player;
        if (check_win_condition(board, player)) {
          return;
        } else {
          board[i][j] = '-';
        }
      }
    }
  }
  
  // Check for block condition
  if (player == 'X') {
    player = 'O';
  } else {
    player = 'X';
  }
  
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (board[i][j] == '-') {
        board[i][j] = player;
        if (check_win_condition(board, player)) {
          board[i][j] = 'O';
          return;
        } else {
          board[i][j] = '-';
        }
      }
    }
  }
  
  // Make a random move
  do {
    row = rand() % 3;
    col = rand() % 3;
  } while (board[row][col] != '-');
  
  board[row][col] = 'O';
}

// Main function
int main() {
  char board[3][3] = {
    {'-', '-', '-'},
    {'-', '-', '-'},
    {'-', '-', '-'}
  };
  char player = 'X';
  int i, j, num_moves = 0;
  
  printf("Welcome to C Tic Tac Toe!\n");
  print_board(board);
  
  // Game loop
  while (1) {
    if (player == 'X') {
      get_user_move(board, player);
    } else {
      printf("Computer's turn:\n");
      get_computer_move(board, player);
      print_board(board);
    }
    
    if (check_win_condition(board, player)) {
      printf("%c wins!\n", player);
      break;
    } else if (num_moves == 8) {
      printf("Draw!\n");
      break;
    }
    
    if (player == 'X') {
      player = 'O';
    } else {
      player = 'X';
    }
    
    num_moves++;
  }
  
  return 0;
}