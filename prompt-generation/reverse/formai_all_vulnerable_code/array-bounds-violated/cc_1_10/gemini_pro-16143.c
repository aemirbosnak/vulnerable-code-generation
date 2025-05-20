//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the bingo card
#define CARD_SIZE 5

// Define the number of rows and columns in the bingo card
#define NUM_ROWS 5
#define NUM_COLS 5

// Define the maximum number of balls that can be drawn
#define MAX_BALLS 75

// Define the number of balls to draw before a winner is declared
#define WINNING_BALLS 5

// Define the prize for winning bingo
#define PRIZE 1000000

// Create a bingo card
int card[CARD_SIZE][CARD_SIZE];

// Create an array to store the balls that have been drawn
int drawn_balls[MAX_BALLS];

// Create a function to generate a random bingo card
void generate_card() {
  // Loop through the rows of the card
  for (int i = 0; i < NUM_ROWS; i++) {
    // Loop through the columns of the card
    for (int j = 0; j < NUM_COLS; j++) {
      // Generate a random number between 1 and 75
      int number = rand() % 75 + 1;

      // Check if the number has already been drawn
      while (drawn_balls[number] != 0) {
        // If the number has already been drawn, generate a new number
        number = rand() % 75 + 1;
      }

      // Add the number to the card
      card[i][j] = number;
    }
  }
}

// Create a function to draw a ball
int draw_ball() {
  // Generate a random number between 1 and 75
  int ball = rand() % 75 + 1;

  // Check if the ball has already been drawn
  while (drawn_balls[ball] != 0) {
    // If the ball has already been drawn, draw a new ball
    ball = rand() % 75 + 1;
  }

  // Add the ball to the array of drawn balls
  drawn_balls[ball] = 1;

  // Return the ball
  return ball;
}

// Create a function to check if a card has won
int check_card(int card[CARD_SIZE][CARD_SIZE]) {
  // Loop through the rows of the card
  for (int i = 0; i < NUM_ROWS; i++) {
    // Check if all of the numbers in the row have been drawn
    int row_count = 0;
    for (int j = 0; j < NUM_COLS; j++) {
      if (drawn_balls[card[i][j]] != 0) {
        row_count++;
      }
    }

    // If all of the numbers in the row have been drawn, the card has won
    if (row_count == NUM_COLS) {
      return 1;
    }
  }

  // Loop through the columns of the card
  for (int j = 0; j < NUM_COLS; j++) {
    // Check if all of the numbers in the column have been drawn
    int col_count = 0;
    for (int i = 0; i < NUM_ROWS; i++) {
      if (drawn_balls[card[i][j]] != 0) {
        col_count++;
      }
    }

    // If all of the numbers in the column have been drawn, the card has won
    if (col_count == NUM_ROWS) {
      return 1;
    }
  }

  // Check if all of the numbers on the diagonal have been drawn
  int diag_count = 0;
  for (int i = 0; i < NUM_ROWS; i++) {
    if (drawn_balls[card[i][i]] != 0) {
      diag_count++;
    }
  }

  if (diag_count == NUM_ROWS) {
    return 1;
  }

  // Check if all of the numbers on the anti-diagonal have been drawn
  diag_count = 0;
  for (int i = 0; i < NUM_ROWS; i++) {
    if (drawn_balls[card[i][NUM_COLS - 1 - i]] != 0) {
      diag_count++;
    }
  }

  if (diag_count == NUM_ROWS) {
    return 1;
  }

  // If none of the above conditions are met, the card has not won
  return 0;
}

// Create a function to play a game of bingo
void play_bingo() {
  // Generate a bingo card
  generate_card();

  // Print the bingo card
  printf("Your bingo card:\n");
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      printf("%d ", card[i][j]);
    }
    printf("\n");
  }

  // Draw balls until a winner is declared
  int num_balls_drawn = 0;
  int winner = 0;
  while (num_balls_drawn < MAX_BALLS && !winner) {
    // Draw a ball
    int ball = draw_ball();

    // Print the ball
    printf("Ball drawn: %d\n", ball);

    // Check if the ball is on the card
    for (int i = 0; i < NUM_ROWS; i++) {
      for (int j = 0; j < NUM_COLS; j++) {
        if (card[i][j] == ball) {
          // Mark the ball as drawn
          card[i][j] = 0;

          // Check if the card has won
          if (check_card(card)) {
            winner = 1;
            break;
          }
        }
      }
    }

    // Increment the number of balls drawn
    num_balls_drawn++;
  }

  // If a winner was declared, print the winning message
  if (winner) {
    printf("You won!\n");
  } else {
    // If no winner was declared, print the losing message
    printf("You lost.\n");
  }
}

// The main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play a game of bingo
  play_bingo();

  return 0;
}