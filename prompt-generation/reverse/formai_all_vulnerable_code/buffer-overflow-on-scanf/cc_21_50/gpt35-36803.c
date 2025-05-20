//FormAI DATASET v1.0 Category: Table Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); //Seeded random number generator

  //Creating the game board
  int board[3][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  };

  //2 players represented as numerical values 1 and 2
  int player = 1;

  printf("Welcome to the C Table Game!\n");

  while (1) { //Loop until a winner is found or there's a tie

    //Display the current board
    printf("\n");
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        printf(" %d ", board[i][j]);
      }
      printf("\n");
    }

    printf("\nPlayer %d's turn\n", player);

    //Get user input for row and column
    int row, col;
    printf("Enter a row (0-2): ");
    scanf("%d", &row);
    printf("Enter a column (0-2): ");
    scanf("%d", &col);

    //Check if the user input is valid
    if (row < 0 || row > 2 || col < 0 || col > 2) {
      printf("\nInvalid input! Try again.\n");
      continue;
    }

    //Check if the cell is already occupied
    if (board[row][col] != 0) {
      printf("\nCell already occupied! Try again.\n");
      continue;
    }

    //Place the player's piece on the board
    board[row][col] = player;

    //Check if the game has ended in a tie
    int tie = 1;
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        if (board[i][j] == 0) {
          tie = 0;
          break;
        }
      }
      if (!tie) {
        break;
      }
    }
    if (tie) {
      printf("\nIt's a tie!\n");
      break;
    }

    //Check if the player has won horizontally
    for(int i = 0; i < 3; i++) {
      if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
        printf("\nPlayer %d wins!\n", player);
        return 0;
      }
    }

    //Check if the player has won vertically
    for(int j = 0; j < 3; j++) {
      if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
        printf("\nPlayer %d wins!\n", player);
        return 0;
      }
    }

    //Check if the player has won diagonally (top left to bottom right)
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
      printf("\nPlayer %d wins!\n", player);
      return 0;
    }

    //Check if the player has won diagonally (top right to bottom left)
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
      printf("\nPlayer %d wins!\n", player);
      return 0;
    }

    //Switch to the other player's turn
    if (player == 1) {
      player = 2;
    } else {
      player = 1;
    }
  }

  return 0;
}