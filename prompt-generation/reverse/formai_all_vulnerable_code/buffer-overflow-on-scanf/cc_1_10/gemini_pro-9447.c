//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 6
int rollDice() {
  return (rand() % 6) + 1;
}

// Function to play the game
void playGame() {
  int player1Score = 0;
  int player2Score = 0;

  // Get the number of rounds to play
  printf("How many rounds would you like to play? ");
  int numRounds;
  scanf("%d", &numRounds);

  // Play the game
  for (int i = 0; i < numRounds; i++) {
    // Roll the dice for player 1
    int player1Roll = rollDice();

    // Roll the dice for player 2
    int player2Roll = rollDice();

    // Add the roll to the player's score
    player1Score += player1Roll;
    player2Score += player2Roll;

    // Print the results of the round
    printf("Player 1 rolled %d and has a score of %d\n", player1Roll, player1Score);
    printf("Player 2 rolled %d and has a score of %d\n", player2Roll, player2Score);
  }

  // Determine the winner
  if (player1Score > player2Score) {
    printf("Player 1 wins with a score of %d!\n", player1Score);
  } else if (player2Score > player1Score) {
    printf("Player 2 wins with a score of %d!\n", player2Score);
  } else {
    printf("It's a tie!\n");
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