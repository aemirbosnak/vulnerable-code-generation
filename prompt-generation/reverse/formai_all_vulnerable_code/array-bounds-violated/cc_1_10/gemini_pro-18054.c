//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the bingo card size
#define CARD_SIZE 5

// Define the number of rows and columns in the bingo card
#define ROWS 5
#define COLS 5

// Define the maximum number that can be on a bingo card
#define MAX_NUMBER 75

// Define the number of numbers to draw
#define NUM_DRAWS 75

// Create a bingo card
int card[CARD_SIZE][CARD_SIZE];

// Create an array to store the numbers that have been drawn
int drawnNumbers[NUM_DRAWS];

// Function to generate a random number
int randomNumber(int max) {
  return rand() % max + 1;
}

// Function to create a bingo card
void createCard() {
  // Loop through each row and column of the bingo card
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      // Generate a random number and make sure it is not already on the card
      int number;
      do {
        number = randomNumber(MAX_NUMBER);
      } while (card[i][j] == number);

      // Add the number to the card
      card[i][j] = number;
    }
  }
}

// Function to print the bingo card
void printCard() {
  // Loop through each row and column of the bingo card
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      // Print the number
      printf("%d ", card[i][j]);
    }
    // Print a newline
    printf("\n");
  }
}

// Function to draw a number
int drawNumber() {
  // Generate a random number and make sure it has not been drawn already
  int number;
  do {
    number = randomNumber(MAX_NUMBER);
  } while (drawnNumbers[number] == 1);

  // Add the number to the array of drawn numbers
  drawnNumbers[number] = 1;

  // Return the number
  return number;
}

// Function to check if the card has a winning pattern
int checkCard() {
  // Loop through each row and column of the bingo card
  for (int i = 0; i < ROWS; i++) {
    // Check if all the numbers in the row or column have been drawn
    int count = 0;
    for (int j = 0; j < COLS; j++) {
      if (drawnNumbers[card[i][j]] == 1) {
        count++;
      }
    }
    if (count == ROWS || count == COLS) {
      return 1;
    }
  }

  // Loop through each diagonal of the bingo card
  int count = 0;
  for (int i = 0; i < ROWS; i++) {
    if (drawnNumbers[card[i][i]] == 1) {
      count++;
    }
  }
  if (count == ROWS) {
    return 1;
  }

  count = 0;
  for (int i = 0; i < ROWS; i++) {
    if (drawnNumbers[card[i][ROWS - i - 1]] == 1) {
      count++;
    }
  }
  if (count == ROWS) {
    return 1;
  }

  // No winning pattern found
  return 0;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create a bingo card
  createCard();

  // Print the bingo card
  printCard();

  // Draw numbers until someone wins
  int number;
  int winner = 0;
  while (!winner) {
    // Draw a number
    number = drawNumber();

    // Check if the card has a winning pattern
    winner = checkCard();
  }

  // Print the winning number
  printf("The winning number is: %d\n", number);

  return 0;
}