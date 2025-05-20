//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The Surreal Bingo Card
int bingoCard[5][5] = {
  {1, 2, 3, 4, 5},
  {6, 7, 8, 9, 10},
  {11, 12, 13, 14, 15},
  {16, 17, 18, 19, 20},
  {21, 22, 23, 24, 25}
};

// The Surreal Bingo Caller
int bingoCaller[75] = {
  1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
  11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
  21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
  31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
  41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
  51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
  61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
  71, 72, 73, 74, 75
};

// The Surreal Bingo Game
void playBingo() {
  // Initialize the game
  int gameOver = 0;
  int numbersDrawn = 0;
  int player1Wins = 0;
  int player2Wins = 0;

  // Get the players' names
  char player1Name[20];
  char player2Name[20];
  printf("Enter the name of player 1: ");
  scanf("%s", player1Name);
  printf("Enter the name of player 2: ");
  scanf("%s", player2Name);

  // Start the game
  while (!gameOver) {
    // Draw a number
    int number = bingoCaller[rand() % 75];
    numbersDrawn++;

    // Check if the number is on the players' cards
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (bingoCard[i][j] == number) {
          // Mark the number as drawn
          bingoCard[i][j] = -1;

          // Check if the player has won
          if (checkBingo(i, j)) {
            gameOver = 1;
            if (player1Wins == player2Wins) {
              printf("Tie! Both %s and %s won in %d numbers drawn.\n", player1Name, player2Name, numbersDrawn);
            } else if (player1Wins > player2Wins) {
              printf("%s won in %d numbers drawn.\n", player1Name, numbersDrawn);
            } else {
              printf("%s won in %d numbers drawn.\n", player2Name, numbersDrawn);
            }
          }
        }
      }
    }
  }
}

// Check if a player has won
int checkBingo(int row, int col) {
  // Check the row
  int rowBingo = 1;
  for (int i = 0; i < 5; i++) {
    if (bingoCard[row][i] != -1) {
      rowBingo = 0;
    }
  }

  // Check the column
  int colBingo = 1;
  for (int i = 0; i < 5; i++) {
    if (bingoCard[i][col] != -1) {
      colBingo = 0;
    }
  }

  // Check the diagonals
  int diagBingo1 = 1;
  for (int i = 0; i < 5; i++) {
    if (bingoCard[i][i] != -1) {
      diagBingo1 = 0;
    }
  }

  int diagBingo2 = 1;
  for (int i = 0; i < 5; i++) {
    if (bingoCard[i][4-i] != -1) {
      diagBingo2 = 0;
    }
  }

  // Return true if any of the lines have bingo
  return rowBingo || colBingo || diagBingo1 || diagBingo2;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play the game
  playBingo();

  return 0;
}