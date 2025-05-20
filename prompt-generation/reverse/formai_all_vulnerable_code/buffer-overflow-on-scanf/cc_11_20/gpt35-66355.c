//FormAI DATASET v1.0 Category: Game ; Style: creative
/* A game of Rock-Paper-Scissors written in C */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int playerScore = 0, computerScore = 0, choice;
   printf("Welcome to Rock Paper Scissors game!\n");

   while (1) { // continue until a player reaches 5 points
      // get player's choice
      printf("Enter your move (1=Rock, 2=Paper, 3=Scissors): ");
      scanf("%d", &choice);

      // generate computer's choice
      srand(time(NULL)); // use current time as seed for random generator
      int computerChoice = rand() % 3 + 1;

      // display computer's choice
      switch (computerChoice) {
         case 1:
            printf("Computer chooses Rock!\n");
            break;
         case 2:
            printf("Computer chooses Paper!\n");
            break;
         case 3:
            printf("Computer chooses Scissors!\n");
            break;
      }

      // decide winner
      if (choice == computerChoice) {
         printf("It's a tie!\n");
      } else if (choice == 1 && computerChoice == 3 || choice == 2 && computerChoice == 1 || choice == 3 && computerChoice == 2) {
         printf("You win!\n");
         playerScore++;
      } else {
         printf("Computer wins!\n");
         computerScore++;
      }

      // display scores
      printf("Player: %d     Computer: %d\n", playerScore, computerScore);

      // check if game ended
      if (playerScore == 5 || computerScore == 5) {
         break;
      }
   }

   // display final winner
   printf("Game over!\n");
   if (playerScore > computerScore) {
      printf("You win the game!\n");
   } else {
      printf("Computer wins the game!\n");
   }

   return 0;
}