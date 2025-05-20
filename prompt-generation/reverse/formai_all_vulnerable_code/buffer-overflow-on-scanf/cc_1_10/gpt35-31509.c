//FormAI DATASET v1.0 Category: Table Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void displayTable(int[]);
void shuffleTable(int[]);
int getGuess(void);

int main(void) {
  // initialize the table
  int table[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  printf("Welcome to Table Shuffle!\n");
  printf("The objective of the game is to guess the correctly shuffled table.\n");

  // display the original table
  printf("\nOriginal Table: \n");
  displayTable(table);

  // shuffle the table
  shuffleTable(table);

  // get the player's guess
  int guess = getGuess();

  // compare the player's guess with the shuffled table
  printf("\nYou guessed: %d\n", guess);
  printf("The shuffled table: \n");
  displayTable(table);

  if (guess == table[0]) {
    printf("Congratulations, you guessed correctly! You win!\n");
  } else {
    printf("Sorry, you guessed incorrectly. Better luck next time!\n");
  }

  return 0;
}

// function to display the table
void displayTable(int table[]) {
  for (int i = 0; i < 10; i++) {
    printf("%d ", table[i]);
  }
  printf("\n");
}

// function to shuffle the table
void shuffleTable(int table[]) {
  srand(time(NULL));
  // Fisher-Yates shuffle algorithm
  for (int i = 9; i > 0; i--) {
    int j = rand() % (i + 1);
    int temp = table[i];
    table[i] = table[j];
    table[j] = temp;
  }
}

// function to get the player's guess
int getGuess(void) {
  int guess;
  printf("\nEnter your guess: ");
  scanf("%d", &guess);
  return guess;
}