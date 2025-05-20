//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Sherlock's magnifying glass to find the winning numbers
int findWinningNumber(int *bingoCard, int size) {
  int i, j, count = 0;
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      if (bingoCard[i * size + j] == 0) {
        count++;
      }
    }
  }
  return count == size * size;
}

// Watson's assistance to generate random numbers
int generateRandomNumber(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

// The main game of wits
int main() {
  srand(time(NULL));
  int size, i, j, winningNumber, drawnNumbers[100] = {0}, bingoCard[100] = {0};

  printf("Welcome to the illustrious world of Bingo, dear Watson.\n");
  printf("Enter the size of your ingenious bingo card: ");
  scanf("%d", &size);

  // Initialize the bingo card with 'X'
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      bingoCard[i * size + j] = 'X';
    }
  }

  // The game is afoot!
  printf("The game is afoot, Watson! Let us draw the numbers:\n");
  for (i = 0; i < size * size; i++) {
    winningNumber = generateRandomNumber(1, size * size);
    while (drawnNumbers[winningNumber - 1] == 1) {
      winningNumber = generateRandomNumber(1, size * size);
    }
    drawnNumbers[winningNumber - 1] = 1;

    // Mark the drawn number on the bingo card
    for (j = 0; j < size; j++) {
      if (bingoCard[j * size + winningNumber - 1] == winningNumber) {
        bingoCard[j * size + winningNumber - 1] = 0;
      }
    }

    // Check if we have a winner
    if (findWinningNumber(bingoCard, size)) {
      printf("Elementary, my dear Watson! We have a winner!\n");
      break;
    }

    // Print the updated bingo card
    printf("The current state of our investigation:\n");
    for (i = 0; i < size; i++) {
      for (j = 0; j < size; j++) {
        printf("%c ", bingoCard[i * size + j]);
      }
      printf("\n");
    }
  }

  if (i == size * size) {
    printf("Alas, Watson, no winner today. Better luck next time.\n");
  }

  return 0;
}