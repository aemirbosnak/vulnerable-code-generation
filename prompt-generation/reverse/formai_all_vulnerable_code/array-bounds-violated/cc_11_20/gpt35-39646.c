//FormAI DATASET v1.0 Category: Checkers Game ; Style: funny
#include <stdio.h>

int main() {
  printf("Welcome to the Checkers game!\n");

  int board[8][8] = { // initialize board to starting position
    {2,0,2,0,2,0,2,0},
    {0,2,0,2,0,2,0,2},
    {2,0,2,0,2,0,2,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0},
    {0,1,0,1,0,1,0,1},
  };

  int turn = 1; // start with player 1's turn
  int gameOver = 0; // game is not yet over

  while (!gameOver) {
    printf("Player %d's turn.\n", turn);

    int validMove = 0;
    while (!validMove) {
      printf("Enter the row and column of the piece you want to move: ");
      int fromRow, fromCol;
      scanf("%d %d", &fromRow, &fromCol);
      printf("Enter the row and column of where you want to move it: ");
      int toRow, toCol;
      scanf("%d %d", &toRow, &toCol);

      // check if move is valid
      if (board[fromRow][fromCol] == turn && board[toRow][toCol] == 0) {
        // valid move, update board
        board[toRow][toCol] = turn;
        board[fromRow][fromCol] = 0;
        validMove = 1;
      } else {
        printf("Invalid move. Try again.\n");
      }
    }

    // check if player has won
    int player1Pieces = 0, player2Pieces = 0;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (board[i][j] == 1) {
          player1Pieces++;
        } else if (board[i][j] == 2) {
          player2Pieces++;
        }
      }
    }
    if (player1Pieces == 0) {
      printf("Player 2 wins!\n");
      gameOver = 1;
    } else if (player2Pieces == 0) {
      printf("Player 1 wins!\n");
      gameOver = 1;
    }

    // switch turns
    if (turn == 1) {
      turn = 2;
    } else {
      turn = 1;
    }
  }

  return 0;
}