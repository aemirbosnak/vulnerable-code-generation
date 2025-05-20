//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINGO_SIZE 5
#define BINGO_NUMBERS 75

// Bingo card
int bingo_card[BINGO_SIZE][BINGO_SIZE];

// Called numbers
int called_numbers[BINGO_NUMBERS];

// Generate a random number
int random_number() {
  return rand() % BINGO_NUMBERS + 1;
}

// Initialize the bingo card
void init_bingo_card() {
  for (int i = 0; i < BINGO_SIZE; i++) {
    for (int j = 0; j < BINGO_SIZE; j++) {
      bingo_card[i][j] = 0;
    }
  }
}

// Fill the bingo card with random numbers
void fill_bingo_card() {
  int number;
  for (int i = 0; i < BINGO_SIZE; i++) {
    for (int j = 0; j < BINGO_SIZE; j++) {
      do {
        number = random_number();
      } while (bingo_card[i][j] != 0 && number != 0);
      bingo_card[i][j] = number;
    }
  }
}

// Print the bingo card
void print_bingo_card() {
  for (int i = 0; i < BINGO_SIZE; i++) {
    for (int j = 0; j < BINGO_SIZE; j++) {
      printf("%d ", bingo_card[i][j]);
    }
    printf("\n");
  }
}

// Call a number
void call_number() {
  int number;
  do {
    number = random_number();
  } while (called_numbers[number] != 0);
  called_numbers[number] = 1;
  printf("Called number: %d\n", number);
}

// Check if a bingo card has won
int check_bingo_card() {
  // Check rows
  for (int i = 0; i < BINGO_SIZE; i++) {
    int count = 0;
    for (int j = 0; j < BINGO_SIZE; j++) {
      if (bingo_card[i][j] == 0) {
        count++;
      }
    }
    if (count == BINGO_SIZE) {
      return 1;
    }
  }

  // Check columns
  for (int i = 0; i < BINGO_SIZE; i++) {
    int count = 0;
    for (int j = 0; j < BINGO_SIZE; j++) {
      if (bingo_card[j][i] == 0) {
        count++;
      }
    }
    if (count == BINGO_SIZE) {
      return 1;
    }
  }

  // Check diagonals
  int count1 = 0;
  int count2 = 0;
  for (int i = 0; i < BINGO_SIZE; i++) {
    if (bingo_card[i][i] == 0) {
      count1++;
    }
    if (bingo_card[i][BINGO_SIZE - i - 1] == 0) {
      count2++;
    }
  }
  if (count1 == BINGO_SIZE || count2 == BINGO_SIZE) {
    return 1;
  }

  return 0;
}

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Initialize the bingo card
  init_bingo_card();

  // Fill the bingo card with random numbers
  fill_bingo_card();

  // Print the bingo card
  print_bingo_card();

  // Call numbers until someone wins
  int winner = 0;
  while (!winner) {
    // Call a number
    call_number();

    // Check if a bingo card has won
    winner = check_bingo_card();
  }

  // Print the winning bingo card
  print_bingo_card();

  return 0;
}