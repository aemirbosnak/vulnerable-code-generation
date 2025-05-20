//FormAI DATASET v1.0 Category: Table Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Set up the game
  int playerScore = 0;
  int computerScore = 0;
  char playAgain = 'y';
  
  printf("\n\nWelcome to 'Romeo and Juliet's Duel Dice Game!'\n\n");
  
  // Start the game loop
  while (playAgain == 'y') {
    
    // Roll the dice
    srand(time(0));
    int playerRoll = rand() % 6 + 1;
    int computerRoll = rand() % 6 + 1;
    
    // Display the rolls
    printf("Romeo rolls: %d\n", playerRoll);
    printf("Juliet rolls: %d\n", computerRoll);
    
    // Determine the winner
    if (playerRoll > computerRoll) {
      printf("Romeo wins!\n");
      playerScore++;
    } else if (computerRoll > playerRoll) {
      printf("Juliet wins!\n");
      computerScore++;
    } else {
      printf("It's a tie!\n");
    }
    
    // Display the current score
    printf("Romeo: %d\tJuliet: %d\n", playerScore, computerScore);
    
    // Ask if the player wants to play again
    printf("\nPlay again? (y/n): ");
    fflush(stdin);
    scanf("%c", &playAgain);
    
    // Clear the screen for the next round
    system("clear");
    
  }
  
  // Display the final score
  printf("\nFinal score:\n");
  printf("Romeo: %d\tJuliet: %d\n", playerScore, computerScore);
  
  // Determine the winner of the game
  if (playerScore > computerScore) {
    printf("Romeo wins the game!\n");
  } else if (computerScore > playerScore) {
    printf("Juliet wins the game!\n");
  } else {
    printf("The game is a tie!\n");
  }
  
  return 0;
}