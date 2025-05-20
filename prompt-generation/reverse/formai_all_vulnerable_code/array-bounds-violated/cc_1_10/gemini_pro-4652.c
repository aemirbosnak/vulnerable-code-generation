//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare the bingo card
int bingoCard[5][5];

// Declare the bingo numbers
int bingoNumbers[75];

// Declare the function to generate the bingo card
void generateBingoCard() {
  // Initialize the bingo card with zeros
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      bingoCard[i][j] = 0;
    }
  }

  // Generate the random numbers for the bingo card
  srand(time(NULL));
  for (int i = 0; i < 25; i++) {
    int randomNumber = rand() % 75 + 1;
    while (bingoCard[randomNumber / 5][randomNumber % 5] != 0) {
      randomNumber = rand() % 75 + 1;
    }
    bingoCard[randomNumber / 5][randomNumber % 5] = randomNumber;
  }
}

// Declare the function to generate the bingo numbers
void generateBingoNumbers() {
  // Initialize the bingo numbers with zeros
  for (int i = 0; i < 75; i++) {
    bingoNumbers[i] = 0;
  }

  // Generate the random numbers for the bingo numbers
  srand(time(NULL));
  for (int i = 0; i < 75; i++) {
    int randomNumber = rand() % 75 + 1;
    while (bingoNumbers[randomNumber] != 0) {
      randomNumber = rand() % 75 + 1;
    }
    bingoNumbers[randomNumber] = randomNumber;
  }
}

// Declare the function to print the bingo card
void printBingoCard() {
  // Print the bingo card
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%2d ", bingoCard[i][j]);
    }
    printf("\n");
  }
}

// Declare the function to print the bingo numbers
void printBingoNumbers() {
  // Print the bingo numbers
  for (int i = 0; i < 75; i++) {
    printf("%2d ", bingoNumbers[i]);
  }
  printf("\n");
}

// Declare the function to play the bingo game
void playBingo() {
  // Generate the bingo card and the bingo numbers
  generateBingoCard();
  generateBingoNumbers();

  // Print the bingo card and the bingo numbers
  printBingoCard();
  printBingoNumbers();

  // Play the bingo game
  int gameOver = 0;
  while (!gameOver) {
    // Get the next bingo number
    int bingoNumber = bingoNumbers[rand() % 75];

    // Mark the bingo number on the bingo card
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (bingoCard[i][j] == bingoNumber) {
          bingoCard[i][j] = -1;
        }
      }
    }

    // Check if the player has won
    int bingo = 1;
    for (int i = 0; i < 5; i++) {
      int rowBingo = 1;
      int columnBingo = 1;
      for (int j = 0; j < 5; j++) {
        if (bingoCard[i][j] != -1) {
          rowBingo = 0;
        }
        if (bingoCard[j][i] != -1) {
          columnBingo = 0;
        }
      }
      if (rowBingo || columnBingo) {
        bingo = 0;
        break;
      }
    }
    if (bingo) {
      gameOver = 1;
    }

    // Print the bingo card
    printBingoCard();
  }

  // Print the winning message
  printf("You win!\n");
}

// Declare the main function
int main() {
  // Play the bingo game
  playBingo();

  return 0;
}