//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a die
int rollDie() {
  // Seed the random number generator with the current time
  srand(time(NULL));

  // Generate a random number between 1 and 6
  int roll = rand() % 6 + 1;

  // Return the roll
  return roll;
}

int main() {
  // Declare variables to store the player's names and scores
  char player1Name[50];
  char player2Name[50];
  int player1Score = 0;
  int player2Score = 0;

  // Get the player's names
  printf("What is your name, fair maiden?\n");
  scanf("%s", player1Name);
  printf("And yours, noble sir?\n");
  scanf("%s", player2Name);

  // Roll the dice until one player reaches 100 points
  while (player1Score < 100 && player2Score < 100) {
    // Player 1's turn
    int roll1 = rollDie();
    int roll2 = rollDie();
    int total = roll1 + roll2;

    // Add the roll to the player's score
    player1Score += total;

    // Print the player's name and score
    printf("%s rolled a %d and a %d, for a total of %d.\n", player1Name, roll1, roll2, total);

    // Check if the player has reached 100 points
    if (player1Score >= 100) {
      printf("%s has reached 100 points and is victorious!\n", player1Name);
      break;
    }

    // Player 2's turn
    roll1 = rollDie();
    roll2 = rollDie();
    total = roll1 + roll2;

    // Add the roll to the player's score
    player2Score += total;

    // Print the player's name and score
    printf("%s rolled a %d and a %d, for a total of %d.\n", player2Name, roll1, roll2, total);

    // Check if the player has reached 100 points
    if (player2Score >= 100) {
      printf("%s has reached 100 points and is victorious!\n", player2Name);
      break;
    }
  }

  return 0;
}