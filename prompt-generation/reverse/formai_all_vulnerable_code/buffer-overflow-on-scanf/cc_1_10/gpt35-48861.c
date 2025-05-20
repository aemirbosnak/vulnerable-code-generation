//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: creative
#include <stdio.h>

char board[3][3];
char player = 'X';
int moves = 0;

void printBoard() {
  printf("\n");
  for(int i = 0; i < 3; i++) {
    printf("\t\t %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
    if(i != 2) printf("\t\t-----------\n");
  }
  printf("\n");
}

int checkWin() {
  //horizontal win
  for(int i = 0; i < 3; i++) {
    if(board[i][0] == player && board[i][1] == player && board[i][2] == player) return 1;
  }
  //vertical win
  for(int i = 0; i < 3; i++) {
    if(board[0][i] == player && board[1][i] == player && board[2][i] == player) return 1;
  }
  //diagonal win
  if(board[0][0] == player && board[1][1] == player && board[2][2] == player) return 1;
  if(board[0][2] == player && board[1][1] == player && board[2][0] == player) return 1;

  return 0;
}

void makeMove() {
  int row, col;
  printf("Enter row and column for %c (with space in between): ", player);
  scanf("%d %d", &row, &col);
  
  if(row < 0 || row > 2 || col < 0 || col > 2) {
    printf("Invalid move!\n");
    makeMove();
    return;
  }

  if(board[row][col] != '-') {
    printf("Position already taken!\n");
    makeMove();
    return;
  }

  board[row][col] = player;
  moves++;
  printBoard();
  
  if(checkWin()) {
    printf("Player %c has won!\n", player);
    return;
  }

  if(moves == 9) {
    printf("It's a tie!\n");
    return;
  }

  player = player == 'X' ? 'O' : 'X';
  makeMove();
}

int main() {
  printf("Welcome to Tic Tac Toe!\n\n");
  printf("Player 1 is X and Player 2 is O.\n\n");
  printf("Rows and columns are numbered from 0 to 2.\n\n");
  printf("Let's Begin!\n\n");
  
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      board[i][j] = '-';
    }
  }
  
  printBoard();
  makeMove();

  return 0;
}