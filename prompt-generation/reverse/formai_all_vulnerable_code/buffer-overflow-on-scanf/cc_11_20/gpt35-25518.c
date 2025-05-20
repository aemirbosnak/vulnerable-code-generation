//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   //initialize random number generator
   srand(time(NULL));
   
   //initialize game variables
   int player1_score = 0;
   int player2_score = 0;
   int turn_score = 0;
   int current_player = 1;
   
   //print game instructions
   printf("Welcome to Dice Roll Game!\n");
   printf("Each turn you will roll a dice. The number on the dice will be added to your turn score.\n");
   printf("If you roll a 1, your turn score will be reset to 0 and you lose your turn.\n");
   printf("The first player to reach a score of 50 or more wins the game.\n");
   
   //game loop
   while (player1_score < 50 && player2_score < 50) {
      //roll the dice
      int die_roll = rand() % 6 + 1;
      printf("Player %d rolled a %d!\n", current_player, die_roll);
      
      //check for 1
      if (die_roll == 1) {
         printf("Player %d rolled a 1 and lost their turn.\n", current_player);
         current_player = current_player == 1 ? 2 : 1; //switch players
         turn_score = 0; //reset turn score
      }
      else {
         //add to turn score
         turn_score += die_roll;
         printf("Player %d's turn score is now %d.\n", current_player, turn_score);
         
         //ask player if they want to roll again
         char input;
         do {
            printf("Roll again? (y/n) ");
            scanf(" %c", &input);
         } while (input != 'y' && input != 'n');
         
         if (input == 'n') {
            //end turn and add turn score to player's score
            if (current_player == 1) {
               player1_score += turn_score;
               printf("Player 1's score is now %d.\n", player1_score);
            }
            else {
               player2_score += turn_score;
               printf("Player 2's score is now %d.\n", player2_score);
            }
            current_player = current_player == 1 ? 2 : 1; //switch players
            turn_score = 0; //reset turn score
         }
      }
   }
   
   //declare winner
   if (player1_score >= 50) {
      printf("Congratulations, Player 1 wins!\n");
   }
   else {
      printf("Congratulations, Player 2 wins!\n");
   }
   
   return 0;
}