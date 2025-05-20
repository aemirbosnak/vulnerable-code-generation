//Code Llama-13B DATASET v1.0 Category: Bingo Simulator ; Style: automated
// C Bingo Simulator

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINGO_SIZE 5
#define BINGO_NUM_CELLS (BINGO_SIZE * BINGO_SIZE)
#define BINGO_NUM_ROWS (BINGO_SIZE * BINGO_SIZE)

// Define a struct to represent a bingo card
typedef struct {
  int cells[BINGO_NUM_CELLS];
} BingoCard;

// Generate a random number between 1 and BINGO_NUM_CELLS
int getRandomNumber() {
  return rand() % BINGO_NUM_CELLS + 1;
}

// Generate a random bingo card
BingoCard generateRandomBingoCard() {
  BingoCard card;
  for (int i = 0; i < BINGO_NUM_CELLS; i++) {
    card.cells[i] = getRandomNumber();
  }
  return card;
}

// Check if a card has a bingo
int checkBingo(BingoCard card) {
  // Check rows
  for (int i = 0; i < BINGO_NUM_ROWS; i++) {
    int rowSum = 0;
    for (int j = 0; j < BINGO_SIZE; j++) {
      rowSum += card.cells[i * BINGO_SIZE + j];
    }
    if (rowSum == BINGO_SIZE * (BINGO_SIZE + 1) / 2) {
      return 1;
    }
  }

  // Check columns
  for (int i = 0; i < BINGO_SIZE; i++) {
    int colSum = 0;
    for (int j = 0; j < BINGO_SIZE; j++) {
      colSum += card.cells[j * BINGO_SIZE + i];
    }
    if (colSum == BINGO_SIZE * (BINGO_SIZE + 1) / 2) {
      return 1;
    }
  }

  // Check diagonals
  int diagSum = 0;
  for (int i = 0; i < BINGO_SIZE; i++) {
    diagSum += card.cells[i * BINGO_SIZE + i];
  }
  if (diagSum == BINGO_SIZE * (BINGO_SIZE + 1) / 2) {
    return 1;
  }
  diagSum = 0;
  for (int i = 0; i < BINGO_SIZE; i++) {
    diagSum += card.cells[i * BINGO_SIZE + (BINGO_SIZE - i - 1)];
  }
  if (diagSum == BINGO_SIZE * (BINGO_SIZE + 1) / 2) {
    return 1;
  }

  return 0;
}

int main() {
  // Generate a random bingo card
  BingoCard card = generateRandomBingoCard();

  // Print the card
  printf("Your card:\n");
  for (int i = 0; i < BINGO_SIZE; i++) {
    for (int j = 0; j < BINGO_SIZE; j++) {
      printf("%d ", card.cells[i * BINGO_SIZE + j]);
    }
    printf("\n");
  }

  // Check if the card has a bingo
  int hasBingo = checkBingo(card);

  // Print the result
  if (hasBingo) {
    printf("You have a bingo!\n");
  } else {
    printf("Sorry, no bingo.\n");
  }

  return 0;
}