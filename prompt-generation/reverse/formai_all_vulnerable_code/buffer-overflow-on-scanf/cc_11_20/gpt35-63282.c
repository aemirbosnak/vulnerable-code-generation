//FormAI DATASET v1.0 Category: Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int main() {

  // Initializing the game board with '_' (Underscore)
  char gameBoard[ROWS][COLS];
  int i, j;
  for(i = 0; i < ROWS; i++) {
    for(j = 0; j < COLS; j++) {
      gameBoard[i][j] = '_';
    }
  }

  // Placing the treasure at random location on game board
  srand(time(NULL));
  int treasure_row = rand() % ROWS;
  int treasure_col = rand() % COLS;
  gameBoard[treasure_row][treasure_col] = 'T';

  // Player starts the game at location (0, 0)
  int player_row = 0;
  int player_col = 0;

  printf("Welcome to Treasure Hunt game!\n");

  while(1) {

    // Displaying the game board and player's current location
    printf("\nGame Board:\n");
    for(i = 0; i < ROWS; i++) {
      for(j = 0; j < COLS; j++) {
        printf("%c ", gameBoard[i][j]);
      }
      printf("\n");
    }
    printf("You are currently at: (%d, %d)\n", player_row, player_col);

    // Asking the player to make a move
    printf("Enter your move (u for up, d for down, l for left, r for right): ");
    char move;
    scanf(" %c", &move);

    // Updating the player's location based on the move
    switch(move) {
      case 'u':
        if(player_row > 0) {
          player_row--;
        }
        break;
      case 'd':
        if(player_row < ROWS-1) {
          player_row++;
        }
        break;
      case 'l':
        if(player_col > 0) {
          player_col--;
        }
        break;
      case 'r':
        if(player_col < COLS-1) {
          player_col++;
        }
        break;
      default:
        printf("Invalid move!\n");
    }

    // Checking if the player has found the treasure
    if(player_row == treasure_row && player_col == treasure_col) {
      printf("\nCongratulations! You found the treasure!\n");
      gameBoard[treasure_row][treasure_col] = 'F';
      printf("Game Board:\n");
      for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
          printf("%c ", gameBoard[i][j]);
        }
        printf("\n");
      }
      break;
    }
  }

  return 0;
}