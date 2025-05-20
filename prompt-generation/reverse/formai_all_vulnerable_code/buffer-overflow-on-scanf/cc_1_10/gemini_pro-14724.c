//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Forward declarations
int playRound(int player1Score, int player2Score, int maxScore);
int main(void);

// Function to play a single round of the game
int playRound(int player1Score, int player2Score, int maxScore) {
  int player1Roll, player2Roll;

  // Get the player 1 roll
  printf("Player 1's turn: ");
  player1Roll = rand() % 6 + 1;
  printf("%d\n", player1Roll);

  // Get the player 2 roll
  printf("Player 2's turn: ");
  player2Roll = rand() % 6 + 1;
  printf("%d\n", player2Roll);

  // Update the scores
  player1Score += player1Roll;
  player2Score += player2Roll;

  // Check for a winner
  if (player1Score >= maxScore && player2Score >= maxScore) {
    printf("Tie!\n");
    return 0;
  } else if (player1Score >= maxScore) {
    printf("Player 1 wins!\n");
    return 1;
  } else if (player2Score >= maxScore) {
    printf("Player 2 wins!\n");
    return 2;
  }

  // Play the next round
  return playRound(player1Score, player2Score, maxScore);
}

// Main function
int main(void) {
  int maxScore;

  // Get the maximum score
  printf("Enter the maximum score: ");
  scanf("%d", &maxScore);

  // Play the game
  playRound(0, 0, maxScore);

  return 0;
}