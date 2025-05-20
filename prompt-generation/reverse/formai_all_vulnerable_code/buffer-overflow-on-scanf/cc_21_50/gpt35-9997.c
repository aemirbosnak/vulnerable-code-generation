//FormAI DATASET v1.0 Category: Table Game ; Style: decentralized
#include <stdio.h>

int main() {
  int board[5][5] = {0}; // initialize the game board to all zeros

  printf("Welcome to the Decentralized C Table Game!\n\n");

  int turn = 1; // player 1 starts first

  while (1) { // loop until someone wins or the board is full
    printf("Player %d's turn:\n", turn);

    // ask the player to make a move
    int row, col;
    do {
      printf("Enter the row and column of your move (e.g. 2 3): ");
      scanf("%d %d", &row, &col);
      if (row < 0 || row > 4 || col < 0 || col > 4) {
        printf("Invalid move! Row and column numbers must be between 0 and 4.\n");
      } else if (board[row][col] != 0) {
        printf("Invalid move! That space is already occupied.\n");
      }
    } while (row < 0 || row > 4 || col < 0 || col > 4 || board[row][col] != 0);

    board[row][col] = turn; // update the board with the player's move

    // print the current state of the board
    printf("\n");
    printf("     0   1   2   3   4\n");
    for (int i = 0; i < 5; i++) {
      printf("   +---+---+---+---+---+\n");
      printf(" %d |", i);
      for (int j = 0; j < 5; j++) {
        char symbol = ' ';
        if (board[i][j] == 1) {
          symbol = 'X';
        } else if (board[i][j] == 2) {
          symbol = 'O';
        }
        printf(" %c |", symbol);
      }
      printf("\n");
    }
    printf("   +---+---+---+---+---+\n\n");

    // check if the game is over
    int winner = 0; // 0 = no winner yet, 1 = player 1 wins, 2 = player 2 wins
    for (int i = 0; i < 5; i++) {
      // check rows
      if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][3] == board[i][4]) {
        winner = board[i][0];
      }
      // check columns
      if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == board[3][i] && board[3][i] == board[4][i]) {
        winner = board[0][i];
      }
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] == board[4][4]) {
      winner = board[0][0];
    }
    if (board[0][4] == board[1][3] && board[1][3] == board[2][2] && board[2][2] == board[3][1] && board[3][1] == board[4][0]) {
      winner = board[0][4];
    }

    if (winner != 0) { // if there is a winner
      printf("Player %d wins!\n", winner);
      break;
    } else { // if there is no winner yet
      int board_full = 1; // assume the board is full until proven otherwise
      for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
          if (board[i][j] == 0) {
            board_full = 0;
            break;
          }
        }
        if (!board_full) {
          break;
        }
      }
      if (board_full) { // if the board is full and there is no winner
        printf("Tie game!\n");
        break;
      }
    }

    // switch to the other player's turn
    if (turn == 1) {
      turn = 2;
    } else {
      turn = 1;
    }
  }

  return 0;
}