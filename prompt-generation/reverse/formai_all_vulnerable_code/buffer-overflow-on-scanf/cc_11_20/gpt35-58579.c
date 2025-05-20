//FormAI DATASET v1.0 Category: Table Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize random number generator
  srand(time(0));
  
  // Initialize game variables
  int playerScore = 0;
  int computerScore = 0;
  int playerCurrent = 0;
  int computerCurrent = 0;
  int turn = 1;
  
  printf("Let's play a game of C Table!\n");
  
  // Loop until one player reaches 100 points
  while (playerScore < 100 && computerScore < 100) {
    printf("Round %d:\n", turn);
    
    // Player's turn
    printf("It's your turn!\n");
    int roll = rand() % 6 + 1;
    printf("You rolled a %d\n", roll);
    
    if (roll == 1) {
      printf("You rolled a 1, your current score is reset to 0\n");
      playerCurrent = 0;
    } else {
      playerCurrent += roll;
      printf("Your current score is %d\n", playerCurrent);
      printf("Do you want to roll again? (y/n)\n");
      char choice;
      scanf(" %c", &choice);
      while (choice != 'n' && choice != 'N') {
        roll = rand() % 6 + 1;
        printf("You rolled a %d\n", roll);
        if (roll == 1) {
          printf("You rolled a 1, your current score is reset to 0\n");
          playerCurrent = 0;
          break;
        }
        playerCurrent += roll;
        printf("Your current score is %d\n", playerCurrent);
        printf("Do you want to roll again? (y/n)\n");
        scanf(" %c", &choice);
      }
    }
    
    playerScore += playerCurrent;
    printf("Your score is now %d\n", playerScore);
    playerCurrent = 0;
    
    if (playerScore >= 100) {
      printf("You win!\n");
      break;
    }
    
    // Computer's turn
    printf("It's the computer's turn!\n");
    while (computerCurrent < 20) {
      roll = rand() % 6 + 1;
      printf("The computer rolled a %d\n", roll);
      if (roll == 1) {
        printf("The computer rolled a 1, its current score is reset to 0\n");
        computerCurrent = 0;
        break;
      }
      computerCurrent += roll;
      printf("The computer's current score is %d\n", computerCurrent);
    }
    
    computerScore += computerCurrent;
    printf("The computer's score is now %d\n", computerScore);
    computerCurrent = 0;
    
    if (computerScore >= 100) {
      printf("The computer wins!\n");
      break;
    }
    
    // Next round
    turn++;
  }
  
  return 0;
}