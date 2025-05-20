//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a die
int rollDie() {
  // Get a random number between 1 and 6
  int roll = rand() % 6 + 1;

  // Return the roll
  return roll;
}

// Function to play a dice rolling game
void playGame() {
  // Get the number of players
  int numPlayers;
  printf("How many players are playing? ");
  scanf("%d", &numPlayers);

  // Create an array to store the players' scores
  int scores[numPlayers];

  // Roll the dice for each player
  for (int i = 0; i < numPlayers; i++) {
    printf("Player %d, roll the dice! ", i + 1);
    int roll = rollDie();
    printf("You rolled a %d.\n", roll);

    // Add the roll to the player's score
    scores[i] += roll;
  }

  // Find the player with the highest score
  int highestScore = 0;
  int winner = -1;
  for (int i = 0; i < numPlayers; i++) {
    if (scores[i] > highestScore) {
      highestScore = scores[i];
      winner = i;
    }
  }

  // Print the winner
  printf("Congratulations to player %d for winning with a score of %d!\n", winner + 1, highestScore);
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Welcome the player
  printf("Welcome to the dice rolling game!\n");

  // Play the game
  playGame();

  // Thank the player for playing
  printf("Thanks for playing!\n");

  return 0;
}