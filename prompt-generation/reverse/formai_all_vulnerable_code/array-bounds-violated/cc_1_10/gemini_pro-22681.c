//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the bingo card size
#define CARD_SIZE 5

// Define the number of rows and columns in the bingo card
#define ROWS 5
#define COLS 5

// Define the number of balls to be drawn
#define NUM_BALLS 75

// Define the bingo card
int card[CARD_SIZE][CARD_SIZE];

// Define the array of drawn balls
int drawn_balls[NUM_BALLS];

// Define the current number of drawn balls
int num_drawn_balls = 0;

// Function to initialize the bingo card
void initialize_card() {
  // Initialize the random number generator
  srand(time(NULL));

  // Loop through the rows and columns of the bingo card
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      // Generate a random number between 1 and 75
      int number = rand() % 75 + 1;

      // Check if the number is already on the card
      while (card[i][j] == number) {
        // If the number is already on the card, generate a new number
        number = rand() % 75 + 1;
      }

      // Set the number on the card
      card[i][j] = number;
    }
  }
}

// Function to draw a ball
int draw_ball() {
  // Generate a random number between 1 and 75
  int ball = rand() % 75 + 1;

  // Check if the ball has already been drawn
  while (drawn_balls[ball] == 1) {
    // If the ball has already been drawn, generate a new ball
    ball = rand() % 75 + 1;
  }

  // Set the ball as drawn
  drawn_balls[ball] = 1;

  // Increment the number of drawn balls
  num_drawn_balls++;

  // Return the ball
  return ball;
}

// Function to check if the card has a winning combination
int check_card_for_win() {
  // Check for horizontal wins
  for (int i = 0; i < ROWS; i++) {
    int count = 0;
    for (int j = 0; j < COLS; j++) {
      if (card[i][j] == drawn_balls[card[i][j]]) {
        count++;
      }
    }
    if (count == COLS) {
      return 1;
    }
  }

  // Check for vertical wins
  for (int i = 0; i < COLS; i++) {
    int count = 0;
    for (int j = 0; j < ROWS; j++) {
      if (card[j][i] == drawn_balls[card[j][i]]) {
        count++;
      }
    }
    if (count == ROWS) {
      return 1;
    }
  }

  // Check for diagonal wins
  int count_left_to_right = 0;
  for (int i = 0; i < ROWS; i++) {
    if (card[i][i] == drawn_balls[card[i][i]]) {
      count_left_to_right++;
    }
  }
  if (count_left_to_right == ROWS) {
    return 1;
  }

  int count_right_to_left = 0;
  for (int i = 0; i < ROWS; i++) {
    if (card[i][ROWS - i - 1] == drawn_balls[card[i][ROWS - i - 1]]) {
      count_right_to_left++;
    }
  }
  if (count_right_to_left == ROWS) {
    return 1;
  }

  // No winning combination found
  return 0;
}

// Function to print the bingo card
void print_card() {
  // Loop through the rows and columns of the bingo card
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      // Print the number on the card
      printf("%2d ", card[i][j]);
    }
    printf("\n");
  }
}

// Function to print the drawn balls
void print_drawn_balls() {
  // Loop through the drawn balls
  for (int i = 0; i < NUM_BALLS; i++) {
    // Print the ball
    if (drawn_balls[i] == 1) {
      printf("%2d ", i + 1);
    }
  }
  printf("\n");
}

// Function to play a game of bingo
void play_bingo() {
  // Initialize the bingo card
  initialize_card();

  // Print the bingo card
  print_card();

  // Loop until a winning combination is found
  while (!check_card_for_win()) {
    // Draw a ball
    int ball = draw_ball();

    // Print the drawn ball
    printf("Drawn ball: %d\n", ball);

    // Print the drawn balls
    print_drawn_balls();

    // Print the bingo card
    print_card();
  }

  // Print the winning message
  printf("Bingo!\n");
}

// Main function
int main() {
  // Play a game of bingo
  play_bingo();

  return 0;
}