//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int playerScore = 0;
int computerScore = 0;

int rollDice() {
  return (rand() % 6) + 1;
}

void displayScores() {
  printf("\n\n ===== Scores =====");
  printf("\n Player: %d", playerScore);
  printf("\n Computer: %d", computerScore);
  printf("\n ==================");
}

int main() {
  int numRounds;
  
  // Initialize random seed
  srand(time(NULL));
  
  // Greet the player
  printf("Welcome to Dice Duel!\n\n");
  
  // Ask the player for the number of rounds to play
  printf("How many rounds would you like to play? ");
  scanf("%d", &numRounds);
  
  // Play the game for numRounds rounds
  for (int i = 1; i <= numRounds; i++) {
    printf("\n\n ~~ Round %d ~~", i);
    
    // Player's turn
    printf("\n\n ========== Player's Turn ==========");
    int playerRoll = rollDice();
    printf("\n You rolled: %d", playerRoll);
    playerScore += playerRoll;
    displayScores();
    
    // Computer's turn
    printf("\n\n ======== Computer's Turn ========");
    int computerRoll = rollDice();
    printf("\n The computer rolled: %d", computerRoll);
    computerScore += computerRoll;
    displayScores();
  }
  
  // Print the final scores
  printf("\n\n ========== Final Scores ==========");
  displayScores();
  
  // Determine the winner
  if (playerScore > computerScore) {
    printf("\n\n Congratulations, you won!");
  } else if (playerScore < computerScore) {
    printf("\n\n Sorry, the computer won.");
  } else {
    printf("\n\n It's a tie!");
  }
  
  return 0;
}