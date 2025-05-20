//FormAI DATASET v1.0 Category: Table Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initializing variables
  int playerOneScore = 0;
  int playerTwoScore = 0;
  int numRounds = 0;
  int currRound = 0;
  
  // Prompting user for number of rounds to play
  printf("How many rounds would you like to play?\n");
  scanf("%d", &numRounds);
  
  // Looping through rounds
  for (currRound = 1; currRound <= numRounds; currRound++) {
    printf("========== ROUND %d ==========\n", currRound);
    
    // Generating random numbers for player one and two
    srand(time(0));
    int p1Num = rand() % 6 + 1;
    int p2Num = rand() % 6 + 1;
    
    printf("Player One rolled a %d and Player Two rolled a %d\n", p1Num, p2Num);
    
    // Calculating round winner
    if (p1Num > p2Num) {
      printf("Player One wins the round!\n");
      playerOneScore++;
    } else if (p2Num > p1Num) {
      printf("Player Two wins the round!\n");
      playerTwoScore++;
    } else {
      printf("It's a tie!\n");
    }
    
    printf("Player One's score: %d\nPlayer Two's score: %d\n", playerOneScore, playerTwoScore);
  }
  
  // Determining game winner
  if (playerOneScore > playerTwoScore) {
    printf("Player One wins the game with a score of %d to %d!\n", playerOneScore, playerTwoScore);
  } else if (playerTwoScore > playerOneScore) {
    printf("Player Two wins the game with a score of %d to %d!\n", playerTwoScore, playerOneScore);
  } else {
    printf("The game ends in a tie with a score of %d to %d!\n", playerOneScore, playerTwoScore);
  }

  return 0;
}