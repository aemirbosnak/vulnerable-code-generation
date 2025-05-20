//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 5

int main() {
  int board[ROWS][COLUMNS];
  int selectedNums[75] = {0};
  int count = 0;

  srand(time(0));
  
  // Initialize the board with random numbers between 1 and 75
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      int num = 0;
      do {
        num = rand() % 75 + 1;
      } while (selectedNums[num] != 0);
      selectedNums[num] = 1;
      board[i][j] = num;
    }
  }

  // Print the initialized board
  printf("Welcome to BINGO!\n");
  printf("-----------------\n");
  printf("Here's your BINGO board:\n\n");
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      printf("%2d ", board[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  // Start the game
  while (count < 25) {
    int num = -1;
    do {
      num = rand() % 75 + 1;
    } while (selectedNums[num] != 0);
    selectedNums[num] = 1;

    printf("The number called is: %d\n", num);

    // Check if any of the numbers on the board match the called number
    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLUMNS; j++) {
        if (board[i][j] == num) {
          board[i][j] = -1;
          printf("You have %d numbers left to go!\n", 25 - count - 1);
          count++;
        }
      }
    }

    // Check for a winning board
    int bingo = 0;
    for (int i = 0; i < ROWS; i++) {
      int rowSum = 0;
      int colSum = 0;
      for (int j = 0; j < COLUMNS; j++) {
        rowSum += board[i][j];
        colSum += board[j][i];
      }
      if (rowSum == -5*ROWS || colSum == -5*COLUMNS) {
        bingo = 1;
        break;
      }
    }
    if (bingo) {
      printf("BINGO! You win!\n");
      return 0;
    }
  }

  printf("Sorry, you did not get a BINGO.\n");

  return 0;
}