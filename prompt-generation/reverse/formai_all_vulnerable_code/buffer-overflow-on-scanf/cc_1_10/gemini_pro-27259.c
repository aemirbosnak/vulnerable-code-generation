//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  // Define the bingo board
  int board[5][5];

  // Generate random numbers for the board
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      board[i][j] = rand() % 100 + 1;
    }
  }

  // Print the bingo board
  printf("Bingo board:\n");
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }

  // Get the input from the user
  int input;
  printf("Enter a number: ");
  scanf("%d", &input);

  // Check if the number is on the board
  int found = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (board[i][j] == input) {
        found = 1;
        break;
      }
    }
  }

  // Print the result
  if (found) {
    printf("The number %d is on the board.\n", input);
  } else {
    printf("The number %d is not on the board.\n", input);
  }

  return 0;
}