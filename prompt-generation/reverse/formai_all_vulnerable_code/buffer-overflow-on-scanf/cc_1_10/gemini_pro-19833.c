//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int getRandomNumber(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Function to roll a dice
int rollDice(int sides) {
  return getRandomNumber(1, sides);
}

// Function to play a dice game
void playDiceGame() {
  // Get the number of players and the number of sides of the dice
  int numPlayers, numSides;
  printf("Enter the number of players: ");
  scanf("%d", &numPlayers);
  printf("Enter the number of sides of the dice: ");
  scanf("%d", &numSides);

  // Initialize the array of player scores
  int playerScores[numPlayers];
  for (int i = 0; i < numPlayers; i++) {
    playerScores[i] = 0;
  }

  // Play the game
  for (int i = 0; i < 10; i++) {
    // Each player rolls the dice
    for (int j = 0; j < numPlayers; j++) {
      int roll = rollDice(numSides);
      playerScores[j] += roll;
      printf("Player %d rolled a %d\n", j + 1, roll);
    }

    // Print the current scores
    printf("\nCurrent scores:\n");
    for (int j = 0; j < numPlayers; j++) {
      printf("Player %d: %d\n", j + 1, playerScores[j]);
    }
  }

  // Find the winner
  int maxScore = playerScores[0];
  int winner = 1;
  for (int i = 1; i < numPlayers; i++) {
    if (playerScores[i] > maxScore) {
      maxScore = playerScores[i];
      winner = i + 1;
    }
  }

  // Print the winner
  printf("\nThe winner is Player %d with a score of %d\n", winner, maxScore);
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play the dice game
  playDiceGame();

  return 0;
}