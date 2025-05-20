//FormAI DATASET v1.0 Category: Table Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int playerScore[2] = {0, 0}; //initialize player scores to 0
   int turnScore = 0; //initialize turn score to 0
   int currentPlayer = 0; //initialize current player to player 1
   int diceRoll, choice;
   srand(time(NULL)); //seed random number generator

   printf("Welcome to the Dice Game!\n\n");

   do {
      printf("Player %d's turn.\n", currentPlayer + 1);
      printf("Press 1 to roll the dice, or 0 to hold: ");
      scanf("%d", &choice);

      if (choice == 1) {
         diceRoll = (rand() % 6) + 1; //random number between 1 and 6
         printf("You rolled a %d\n", diceRoll);

         if (diceRoll == 1) { //player loses turn score and ends turn
            printf("Sorry, you rolled a 1. Your turn score of %d is forfeited\n", turnScore);
            turnScore = 0;
            currentPlayer = (currentPlayer + 1) % 2; //switch to other player's turn
         }
         else {
            turnScore += diceRoll;
            printf("Your turn score is now %d\n", turnScore);
            printf("Would you like to roll again or hold (1=roll, 0=hold)? ");
            scanf("%d", &choice);
            if (choice == 0) {
               playerScore[currentPlayer] += turnScore;
               printf("You chose to hold. Your score is now %d\n", playerScore[currentPlayer]);
               turnScore = 0;
               currentPlayer = (currentPlayer + 1) % 2; //switch to other player's turn
            }
         }
      }
      else if (choice == 0) {
         playerScore[currentPlayer] += turnScore;
         printf("You chose to hold. Your score is now %d\n", playerScore[currentPlayer]);
         turnScore = 0;
         currentPlayer = (currentPlayer + 1) % 2; //switch to other player's turn
      }
   } while (playerScore[0] < 100 && playerScore[1] < 100); //continue until one player reaches 100 points

   printf("Game Over!\n");
   printf("Player 1's score: %d\n", playerScore[0]);
   printf("Player 2's score: %d\n", playerScore[1]);
   if (playerScore[0] > playerScore[1])
      printf("Player 1 Wins!\n");
   else
      printf("Player 2 Wins!\n");

   return 0;
}