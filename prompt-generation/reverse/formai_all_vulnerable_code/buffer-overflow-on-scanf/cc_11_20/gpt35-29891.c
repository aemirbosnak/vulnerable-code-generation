//FormAI DATASET v1.0 Category: Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

   int player_score = 0, computer_score = 0, rounds = 1;

   srand(time(0));

   while(rounds <= 10){

      int player_choice, computer_choice;

      printf("Round %d\n", rounds);
      printf("Enter your Choice\n");
      printf("1 for Rock\n2 for Paper\n3 for Scissors\n");
      scanf("%d", &player_choice);

      if(player_choice < 1 || player_choice > 3){
         printf("Invalid Choice... Please Try Again\n");
         continue;
      }

      computer_choice = rand() % 3 + 1;

      if(player_choice == 1 && computer_choice == 2){
         computer_score++;
         printf("Computer Wins! Paper Covers the Rock\n");
      }
      else if(player_choice == 1 && computer_choice == 3){
         player_score++;
         printf("You Win! Rock Smashes the Scissors\n");
      }
      else if(player_choice == 2 && computer_choice == 1){
         player_score++;
         printf("You Win! Paper Covers the Rock\n");
      }
      else if(player_choice == 2 && computer_choice == 3){
         computer_score++;
         printf("Computer Wins! Scissors Cuts the Paper\n");
      }
      else if(player_choice == 3 && computer_choice == 1){
         computer_score++;
         printf("Computer Wins! Rock Smashes the Scissors\n");
      }
      else if(player_choice == 3 && computer_choice == 2){
         player_score++;
         printf("You Win! Scissors Cuts the Paper\n");
      }
      else{
         printf("It's a Draw! Try Again\n");
         continue;
      }

      printf("Scoreboard - Player %d : Computer %d\n", player_score, computer_score);
      rounds++;
   }

   if(player_score > computer_score){
      printf("\n\nCongratulation! You Won the Game!\n");
   }
   else if(player_score < computer_score){
      printf("\n\nOops! Computer won the Game!\n");
   }
   else{
      printf("\n\nIts a Draw Game\n");
   }

   return 0;

}