//GEMINI-pro DATASET v1.0 Category: Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 6
int rollDie() {
  return rand() % 6 + 1;
}

// Function to play the game
void playGame() {
  // Initialize the game state
  int player1Score = 0;
  int player2Score = 0;
  int turn = 1;

  // Play the game until one player reaches 100 points
  while (player1Score < 100 && player2Score < 100) {
    // Print the current game state
    printf("Player 1 score: %d\n", player1Score);
    printf("Player 2 score: %d\n", player2Score);
    printf("Turn: %d\n", turn);

    // Get the player's input
    int input;
    printf("Player %d, enter 1 to roll the die or 2 to pass: ", turn);
    scanf("%d", &input);

    // Roll the die
    int roll = rollDie();

    // Update the game state
    if (input == 1) {
      if (roll == 1) {
        // The player rolled a 1, so they lose their turn
        printf("Player %d rolled a 1 and loses their turn.\n", turn);
        turn = 3 - turn;
      } else {
        // The player rolled a number other than 1, so they add it to their score
        printf("Player %d rolled a %d and adds it to their score.\n", turn, roll);
        if (turn == 1) {
          player1Score += roll;
        } else {
          player2Score += roll;
        }
      }
    } else {
      // The player passed, so they end their turn
      printf("Player %d passed.\n", turn);
      turn = 3 - turn;
    }
  }

  // Print the winner of the game
  if (player1Score >= 100) {
    printf("Player 1 wins!\n");
  } else {
    printf("Player 2 wins!\n");
  }
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play the game
  playGame();

  return 0;
}