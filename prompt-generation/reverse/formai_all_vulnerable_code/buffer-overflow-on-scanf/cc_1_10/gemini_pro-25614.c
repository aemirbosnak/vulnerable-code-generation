//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_range(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Function to play the dice game
int dice_game(int player1, int player2) {
  // Base case: if either player has reached or exceeded 100 points, the game is over
  if (player1 >= 100 || player2 >= 100) {
    return player1 >= 100 ? 1 : 2;
  }

  // Recursive case: roll the dice for both players and add the results to their scores
  int roll1 = rand_range(1, 6);
  int roll2 = rand_range(1, 6);
  player1 += roll1;
  player2 += roll2;

  // Print the results of the roll and the current scores
  printf("Player 1 rolled a %d and now has %d points.\n", roll1, player1);
  printf("Player 2 rolled a %d and now has %d points.\n", roll2, player2);

  // Recursively call the dice_game function with the updated scores
  return dice_game(player1, player2);
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the starting scores from the user
  int player1_score;
  int player2_score;
  printf("Enter the starting score for Player 1: ");
  scanf("%d", &player1_score);
  printf("Enter the starting score for Player 2: ");
  scanf("%d", &player2_score);

  // Play the dice game
  int winner = dice_game(player1_score, player2_score);

  // Print the winner
  printf("Player %d wins!\n", winner);

  return 0;
}