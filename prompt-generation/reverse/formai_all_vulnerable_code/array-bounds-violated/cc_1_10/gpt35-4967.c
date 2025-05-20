//FormAI DATASET v1.0 Category: Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3 // Board size is 3x3

// Function to print the current state of the board
void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
  printf("\n");
  for(int i=0;i<BOARD_SIZE;i++) {
    for(int j=0;j<BOARD_SIZE;j++) {
        printf(" %d ", board[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// Function to check if the game is over or not
int check_game_over(int board[BOARD_SIZE][BOARD_SIZE]) {
  // Check rows
  for(int i=0;i<BOARD_SIZE;i++) {
    if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return board[i][0];
    }
  }

  // Check columns
  for(int j=0;j<BOARD_SIZE;j++) {
    if(board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
      return board[0][j];
    }
  }

  // Check diagonals
  if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return board[0][0];
  }
  if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return board[0][2];
  }

  return 0;
}

// Main function
int main() {
  int board[BOARD_SIZE][BOARD_SIZE] = {0};
  int player = 1;
  int game_over = 0;
  int row, col;

  srand(time(NULL));

  printf("Welcome to the Tic Tac Toe Game!\n");
  printf("You will be playing against the computer.\n");
  printf("The board has 3 rows and 3 columns.\n");
  printf("Each player takes turn to place their symbol on the board.\n");
  printf("The player who gets 3 in a row, column or diagonal wins the game.\n");
  printf("Let's start the game!\n");

  while(!game_over) {
    printf("Player %d's turn\n", player);
    
    if(player == 1) { // Player's turn
      printf("Enter the row and column (0-2) to place your symbol: ");
      scanf("%d %d", &row, &col);
      if(board[row][col] == 0) {
        board[row][col] = player;
        player = 2; // Next turn is for computer
      }
      else {
        printf("Invalid move, try again.\n");
      }
    }
    else { // Computer's turn
      int rand_row = rand() % 3;
      int rand_col = rand() % 3;
      if(board[rand_row][rand_col] == 0) {
        board[rand_row][rand_col] = player;
        player = 1; // Next turn is for player
      }
    }

    print_board(board);
    game_over = check_game_over(board);
    
    if(game_over) {
        printf("Player %d wins the game!\n", game_over);
    }
    else {
        int is_full = 1;
        for(int i=0;i<BOARD_SIZE;i++) {
            for(int j=0;j<BOARD_SIZE;j++) {
                if(board[i][j] == 0) {
                    is_full = 0;
                }
            }
        }
        if(is_full) {
            printf("Game over, it's a tie!\n");
            game_over = 1;
        }
    }
  }

  return 0;
}