//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize the game board
void initializeBoard(char board[4][4]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      board[i][j] = '*';
    }
  }
}

// Function to print the game board
void printBoard(char board[4][4]) {
  printf("\n");
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Function to get the player's input
void getPlayerInput(char board[4][4], int *row1, int *col1, int *row2, int *col2) {
  printf("Enter the coordinates of the first card: ");
  scanf("%d %d", row1, col1);
  printf("Enter the coordinates of the second card: ");
  scanf("%d %d", row2, col2);
}

// Function to check if the two cards match
int checkMatch(char board[4][4], int row1, int col1, int row2, int col2) {
  if (board[row1][col1] == board[row2][col2]) {
    return 1;
  } else {
    return 0;
  }
}

// Function to play the game
void playGame(char board[4][4]) {
  int row1, col1, row2, col2;
  int matches = 0;

  while (matches < 8) {
    // Get the player's input
    getPlayerInput(board, &row1, &col1, &row2, &col2);

    // Check if the cards match
    if (checkMatch(board, row1, col1, row2, col2)) {
      matches++;
      printf("Match!\n");
    } else {
      printf("No match.\n");
    }

    // Print the game board
    printBoard(board);
  }

  printf("Congratulations! You won the game!\n");
}

int main() {
  // Initialize the game board
  char board[4][4];
  initializeBoard(board);

  // Shuffle the game board
  srand(time(NULL));
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      int r1 = rand() % 4;
      int c1 = rand() % 4;
      int r2 = rand() % 4;
      int c2 = rand() % 4;
      char temp = board[r1][c1];
      board[r1][c1] = board[r2][c2];
      board[r2][c2] = temp;
    }
  }

  // Play the game
  playGame(board);

  return 0;
}