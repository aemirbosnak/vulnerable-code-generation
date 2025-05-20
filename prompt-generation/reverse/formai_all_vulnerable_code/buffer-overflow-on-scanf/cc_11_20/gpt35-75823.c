//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printBoard(int board[3][3]) { // function to print the board
  printf("\n\n\tTic Tac Toe\n\n");

  printf("Player 1 (X) - Player 2 (O)\n\n");
  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c \n", board[0][0] == 0 ? ' ' : board[0][0], board[0][1] == 0 ? ' ' : board[0][1], board[0][2] == 0 ? ' ' : board[0][2]);

  printf("_____|_____|_____\n");
  printf("     |     |     \n");

  printf("  %c  |  %c  |  %c \n", board[1][0] == 0 ? ' ' : board[1][0], board[1][1] == 0 ? ' ' : board[1][1], board[1][2] == 0 ? ' ' : board[1][2]);

  printf("_____|_____|_____\n");
  printf("     |     |     \n");

  printf("  %c  |  %c  |  %c \n", board[2][0] == 0 ? ' ' : board[2][0], board[2][1] == 0 ? ' ' : board[2][1], board[2][2] == 0 ? ' ' : board[2][2]);

  printf("     |     |     \n\n");
}

int checkWinner(int board[3][3]) { // function to check the winner
  int i;

  for(i = 0; i < 3; i++) {
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
      return board[i][0];
  }

  for(i = 0; i < 3; i++) {
    if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
      return board[0][i];
  }

  if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
    return board[0][0];

  if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return board[0][2];

  for(i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(board[i][j] == 0) {
        return -1;
      }
    }
  }

  return 0;
}

int main() {
  int board[3][3] = {0}; // initially empty board
  int player = 1, winner = 0, row, col, flag = 0;
  char choice;

  srand(time(0)); // seed the random number generator

  printf("Do you want to start the game? Press 'y' for Yes and 'n' for No\n");
  scanf("%c", &choice);

  if (choice == 'n') {
      player = 2; // if player chooses not to start, then player 2 starts
  } 

  while(winner == 0) {
    printBoard(board);

    if(flag == 1) { // if flag is 1, then computer plays
      printf("Computer is playing...\n");
      row = rand() % 3;
      col = rand() % 3;
    } else { // else human plays
      printf("Player %d, enter a row number (1-3): ", player);
      scanf("%d", &row);

      printf("Player %d, enter a column number (1-3): ", player);
      scanf("%d", &col);

      row--;
      col--;
    }

    if(board[row][col] == 0) {
      board[row][col] = player == 1 ? 'X' : 'O';
      
      flag = 1 - flag; // toggle the flag
      
      winner = checkWinner(board); // check if there is a winner
      if (winner == -1) {
          continue; // continue if no winner yet
      } else if(winner == 1) { // print the winner
        printBoard(board);
        printf("Player 1 wins!\n");
        break;
      } else if(winner == 2) {
        printBoard(board);
        printf("Player 2 wins!\n");
        break;
      } else if(winner == 0) {
          printBoard(board);
          printf("It's a tie!\n");
          break;
      }
    } else {
      printf("This cell is already occupied. Please try again!\n");
    }
  }
  return 0;
}